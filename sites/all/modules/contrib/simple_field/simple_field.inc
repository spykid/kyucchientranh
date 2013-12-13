<?php
/**
 * @file
 * Simplefield classes and helper functions used along with the classes.
 *
 * This file is autoloaded, so functions here can only be used once one of the
 * classes has been instantiated.
 */

/**
 * Entity class for Simple Fields.
 */
class SimpleFieldEntity extends Entity {

  // Standard db-backed properties.
  public $id;
  public $type;
  public $field_id;
  public $uid;
  public $field_settings;
  public $instance_settings;
  public $widget_settings;
  public $formatter_settings;
  public $required;

  /**
   * Override default entity label with field's label.
   */
  function defaultLabel() {
    return isset($this->field_settings['label']) ? $this->field_settings['label'] : NULL;
  }

  function defaultUri() {
    return array(
      'path' => 'admin/structure/simple-field/' . $this->identifier(),
      'options' => array(),
    );
  }

  /**
   * Get the type information for this field.
   */
  function getTypeInfo($key = NULL) {
    $info = simple_field_type_info($this->type);
    if (isset($key)) {
      return isset($info[$key]) ? $info[$key] : NULL;
    }
    return $info;
  }

  /**
   * Get the label for this field's type.
   */
  function getTypeLabel() {
    $typeinfo = $this->getTypeInfo();
    return $typeinfo['label'];
  }

  /**
   * Get the settings for this field.
   *
   * @param setting_type
   *   The type of setting ('field', 'instance', 'widget', 'formatter').
   *
   * @return
   *   An array of the given type.
   */
  function getSettings($setting_type) {

    $settings = array();
    // Add settings from the simple field type, but don't allow simple field to override
    // the simple field type settings.
    $setting_key = $setting_type . '_settings';

    if ($this->$setting_key) {
      $settings += $this->$setting_key;
    }

    if ($type_info = $this->getTypeInfo()) {
      $settings += $type_info['defaults'][$setting_key];
    }

    return $settings;
  }

  /**
   * Get the Field API field for this field.
   */
  function getField() {
    return $this->field_id ? field_info_field_by_id($this->field_id) : FALSE;
  }

  /**
   * Get a list of all instances of this field.
   *
   * @param $entity_type
   *   Filter returned instances by entity type.
   * @param $bundle
   *   Filter returned instances by bundle.
   *
   * @return
   *   An array of field instances.
   */
  function getInstances($entity_type = NULL, $bundle = NULL) {
    $field = $this->getField();
    $field_name = $field['field_name'];
    $instances = field_info_instances();

    // Filter the instances by provided type and bundle.
    if (isset($entity_type)) {
      $instances = array(
        $entity_type => isset($instances[$entity_type]) ? $instances[$entity_type] : array(),
      );
      if (isset($bundle)) {
        $instances[$entity_type] = array(
          $bundle => isset($instances[$entity_type][$bundle]) ? $instances[$entity_type][$bundle] : array(),
        );
      }
    }

    // Aggregate instances of this field.
    $field_instances = array();
    if (!empty($field['bundles'])) {
      foreach ($field['bundles'] as $entity_type => $bundles) {
        foreach ($bundles as $bundle) {
          if (isset($instances[$entity_type][$bundle][$field_name])) {
            $field_instances[] = $instances[$entity_type][$bundle][$field_name];
          }
        }
      }
    }
    return $field_instances;
  }

  /**
   * Checks whether this field has data associated with it.
   */
  function hasData() {
    $field = $this->getField();
    return $field && field_has_data($field);
  }
}

/**
 * Entity controller class for Simple Fields.
 */
class SimpleFieldEntityController extends EntityAPIControllerExportable {

  public function export($entity, $prefix = '') {
    $vars = get_object_vars($entity);
    unset($vars[$this->statusKey], $vars[$this->moduleKey], $vars['is_new'], $vars['field_id']);
    if ($this->nameKey != $this->idKey) {
      unset($vars[$this->idKey]);
    }
    return entity_var_json_export($vars, $prefix);
  }

  public function invoke($hook, $entity) {

    if (empty($entity->simple_field_stop_race)) {
      switch ($hook) {
        case 'presave':
          $entity->field_created = !$entity->field_id;
          if (!$entity->field_id) {
            if (!empty($entity->field_name) && ($existing_field = field_info_field($entity->field_name))) {
              $entity->field_id = $existing_field['id'];
            }
            else {
              $field = simple_field_build_field($entity);
              $field = field_create_field($field);
              $entity->field_id = $field['id'];
              $entity->field_name = $field['field_name'];
            }
          }
          break;
        case 'update':
          if (!$entity->field_created) {
            $field = $entity->getField();
            // Merge form settings with those already in the field.
            $field['settings'] = array_merge($field['settings'], $entity->getSettings('field'));

            // Mark field as in process of updating.
            simple_field_field_updated_flag_cache('field', $field['id'], TRUE);

            // Update the field with new settings from this simplefield.
            field_update_field($field);

            // Mark field as not in middle of update.
            simple_field_field_updated_flag_cache('field', $field['id'], FALSE);

            foreach ($entity->getInstances() as $instance) {
              $inst = simple_field_build_instance($instance['entity_type'], $instance['bundle'], $entity);
              $inst += $instance;
              $inst['display'] += $instance['display'];
              $inst['settings'] += $instance['settings'];
              $inst['widget'] += $instance['widget'];
              $inst['widget']['settings'] += $instance['widget']['settings'];

              simple_field_field_updated_flag_cache('instance', $inst['id'], TRUE);
              field_update_instance($inst);
              simple_field_field_updated_flag_cache('instance', $inst['id'], FALSE);
            }
          }
          break;
        case 'delete':
          $in_code = FALSE;
          if (module_exists('features')) {
            $map = features_get_component_map('simple_field');
            $in_code = isset($map[$entity->field_name]);
          }
          if (!$in_code) {//!entity_has_status('simple_field', $entity, ENTITY_IN_CODE)) {
            // Removing Field
            $field = $entity->getField();
            field_delete_field($field['field_name']);
          }
          break;
      }

    }

    return parent::invoke($hook, $entity);
  }


}

/**
 * Entity Features controller class.
 */
class SimpleFieldFeaturesController extends EntityDefaultFeaturesController {

  public function api() {
    $info = parent::api();
//    $info['simple_field']['default_file'] = FEATURES_DEFAULTS_INCLUDED;
    return $info;
  }

  public function export($data, &$export, $module_name = '') {
    $pipe = parent::export($data, $export, $module_name);

    // Entity module will handle exporting the actual simple field entity, but
    // we still need to tell features to export the actual Field module field.
    $instances = field_info_instances();
    foreach ($data as $name) {
      $field = field_info_field($name);

      foreach ($instances as $entity_type => $by_type) {
        foreach ($by_type as $bundle => $insts) {
          foreach ($insts as $inst) {
            if ($inst['field_name'] == $name) {
              $pipe['field'][] = $entity_type . '-' . $bundle . '-' . $name;
            }
          }
        }
      }
    }
    return $pipe;
  }
}

// ----------------------------------------------------------------------------
// Helper functions for working with SimpleField fields and instances.

/**
 * Build a field object for a simple_field entity.
 */
function simple_field_build_field($simplefield) {

  $type_info = $simplefield->getTypeInfo();
  $settings = $simplefield->getSettings('field');

  return array(
    'settings' => $settings,
    'field_name' => empty($settings['label']) ? '' : simple_field_unique_field_name($settings['label'], 'sf_'),
    'translatable' => FALSE,
    'type' => $type_info['field'],
    'cardinality' => $type_info['cardinality'],
  );
}

function simple_field_build_instance($entity_type, $bundle, $simplefield) {

  $field = $simplefield->getField();
  $type_info = $simplefield->getTypeInfo();
  $field_settings = $simplefield->getSettings('field');
  $instance_settings = $simplefield->getSettings('instance');
  $widget_settings = $simplefield->getSettings('widget');


  $instance = array(
    'field_name' => $field['field_name'],
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $field_settings['label'],
    'settings' => $instance_settings,
    'required' => $simplefield->required,
    'description' => $instance_settings['description'],
    'widget' => array(
      'type' => $type_info['type'],
      'settings' => $widget_settings,
    ),
    'display' => array(),
  );

  // If a new instance is being added, then find the proper weight for it.
  if (!field_info_instance($entity_type, $field['field_name'], $bundle)) {
    $settings = field_bundle_settings($entity_type, $bundle);
    $base = 0;
    if (isset($settings['extra_fields']['form']['simple_fields']['weight'])) {
      $base = $settings['extra_fields']['form']['simple_fields']['weight'];
    }

    // If there are other simplefields, find the between max weight and base+1
    $simplefields = simple_field_entity_fields($entity_type, $bundle);
    if ($simplefields) {
      $max = -1000;
      foreach ($simplefields as $sf) {
        $field = $sf->getField();
        $inst = field_info_instance($entity_type, $field['field_name'], $bundle);
        if ($inst['widget']['weight'] > $max) {
          $max = $inst['widget']['weight'];
        }
      }
      $weight = ($base+1+$max)/2;
    }
    else {
      $weight = $base + 0.1;
    }
    $instance['widget']['weight'] = $weight;
  }
  return $instance;
}

/**
 * Helper to take a field label and come up with a semi-readable field name.
 */
function simple_field_unique_field_name($label, $prefix = 'field_') {
  // Make plaintext name from label and limit length.
  $label = $prefix . preg_replace('/(^[0-9])|([^A-Za-z0-9])/', '', $label);
  $label = drupal_strtolower($label); // field names must be lower case
  $label = drupal_substr($label, 0, 32);

  // Append numbers to end of name until unique field found.
  $fields = field_info_fields();
  $name = $label;
  for ($i = 0; isset($fields[$name]) && drupal_strlen($i) < 25; $i++) {
    $name = drupal_substr($label, 0, 32 - drupal_strlen($i)) . $i;
  }

  return $name;
}


// ----------------------------------------------------------------------------
// Helper hooks to maintain data integrity of fields and instances.

/**
 * Implements hook_field_update_field().
 *
 * Proxied from hook in module file.
 */
function _simple_field_field_update_field($field, $prior_field, $has_data) {

  if ($simplefield = simple_field_load_by_field($field['id'])) {
    // Prevent recursive loop by checkif if field is already being updated.
    if (!simple_field_field_updated_flag_cache('field', $field['id'])) {

      if (isset($field['settings'])) {
        // Update the settings on the simplefield.
        $simplefield->field_settings = $field['settings'];
      }

      // Mark simplefield as updating to stop race.
      $simplefield->simple_field_stop_race = TRUE;

      // Save the simple field.
      $simplefield->save();

      // Mark simplefield as done updating.
      unset($simplefield->simple_field_stop_race);
    }
  }
}

/**
 * Implements hook_field_delete_field().
 *
 * Proxied from hook in module file.
 */
function _simple_field_field_delete_field($field) {
  if ($simplefield = simple_field_load_by_field($field['id'])) {
    // Create a new field from default settings and set field_name the same.
    $newfield = simple_field_build_field($simplefield);
    $newfield['field_name'] = $field['field_name'];

    // Save the new field and set the field_id on the simplefield.
    $newfield = field_create_field($newfield);
    $simplefield->field_id = $newfield['id'];

    // Save simplefield with new field_id.
    $simplefield->save();
  }
}

/**
 * Implements hook_field_update_instance().
 *
 * Proxied from hook in module file.
 */
function _simple_field_field_update_instance($instance, $prior_instance) {

  $field = field_info_field($instance['field_name']);
  if ($simplefield = simple_field_load_by_field($field['id'])) {
    if (!simple_field_field_updated_flag_cache('instance', $instance['id'])) {
      if (isset($instance['settings'])) {
        $simplefield->instance_settings = $instance['settings'];
      }
      if (isset($instance['widget']['settings'])) {
        $simplefield->widget_settings = $instance['widget']['settings'];
      }
      if (isset($instance['display']['default']['settings'])) {
        $simplefield->formatter_settings = $instance['display']['default']['settings'];
      }

      $simplefield->required = $instance['required'];
      $simplefield->instance_settings['description'] = $instance['description'];

      $simplefield->simple_field_stop_race = TRUE;
      $simplefield->save();
      unset($simplefield->simple_field_stop_race);
    }
  }
}

/**
 * Cache function to mark fields and instances as being saved in our code.
 *
 * Similar to the 'stop_race' flag on the entity. Here we must use a separate
 * cache function because we cannot add it directly to the instance or field
 * because then it would get serialized in the DB
 *
 * This and stop_race are meant to stop race conditions where updating the simple field
 * triggers a field update, and then the field update triggering a simple field
 * update and so on.
 */
function simple_field_field_updated_flag_cache($type, $id, $val = NULL) {
  $values = &drupal_static(__FUNCTION__);

  if (isset($val)) {
    $values[$type][$id] = $val;
  }

  if (isset($values[$type][$id])) {
    return $values[$type][$id];
  }
  return NULL;
}

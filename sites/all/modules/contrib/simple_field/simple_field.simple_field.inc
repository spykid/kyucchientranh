<?php
/**
 * @file
 * This file has simple field type definition hooks.
 */


/**
 * Implements hook_simple_field_type_info().
 */
function simple_field_simple_field_type_info() {
  return array(
    'simple_field_yesno' => array(
      // There are a ton more options for this, but they are set to defaults.
      // @see simple_field_type_info()
      'label' => t('Yes/No'),
      'help' => t('Display a set of Yes and No radio buttons to allow the user a boolean choice.'),
      'field' => 'list_boolean',
      'cardinality' => 1,
      'defaults' => array(
        'field_settings' => array(
          'allowed_values' => array(
            1 => 'Yes',
            0 => 'No',
          ),
        ),
      ),
    ),
    'simple_field_multichoice_single' => array(
      'label' => t('Multiple Choice (Choose 1 Options)'),
      'help' => t('Enter a list of options and allow the user to select a single options.'),
      'field' => 'list_text',
      'widget' => 'options_buttons',
      'cardinality' => 1,
    ),
    'simple_field_multichoice_multi' => array(
      'label' => t('Multiple Choice (Choose many Options)'),
      'help' => t('Enter a list of options and allow the user to select as many as they would like.'),
      'field' => 'list_text',
      'widget' => 'options_buttons',
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    ),
    'simple_field_short_answer' => array(
      'label' => t('Short Answer'),
      'help' => t('Allow the user to enter a single line of text.'),
      'cardinality' => 1,
      'field' => 'text',
    ),
    'simple_field_long_answer' => array(
      'label' => t('Long Answer'),
      'help' => t('Allow the user to enter a large block of text.'),
      'cardinality' => 1,
      'field' => 'text_long',
      'widget' => 'text_textarea',
    ),
    'simple_field_single_date' => array(
      'label' => t('Date'),
      'help' => t('Allow the user to enter a single Date value.'),
      'field' => 'datestamp',
      'widget' => 'date_text',
      'cardinality' => 1,
      'defaults' => array(
        'field_settings' => array(
          'granularity' => array(
            'year' => 'year',
            'month' => 'month',
            'day' => 'day',
          ),
          'tz_handling' => 'none',
        ),
        'instance_settings' => array(
          'default_value' => 'blank',
        ),
        'widget_settings' => array(
          'input_format_custom' => 'Y-m-d',
        ),
      ),
    ),
    'simple_field_date_range' => array(
      'label' => t('Date Range'),
      'help' => t('Allow the user to enter a Date range with a beginning and ending date.'),
      'field' => 'datestamp',
      'widget' => 'date_text',
      'cardinality' => 1,
      'defaults' => array(
        'field_settings' => array(
          'todate' => 'required',
          'granularity' => array(
            'year' => 'year',
            'month' => 'month',
            'day' => 'day',
          ),
          'tz_handling' => 'none',
        ),
        'instance_settings' => array(
          'default_value' => 'blank',
        ),
        'widget_settings' => array(
          'input_format_custom' => 'Y-m-d',
        ),
      ),
    ),
    'simple_field_integer' => array(
      'label' => t('Integer'),
      'help' => t('Allow the user to enter a single single integer value.'),
      'cardinality' => 1,
      'field' => 'number_integer',
    ),
  );
}


/**
 * Implements hook_simple_field_type_form().
 * Most of this is from the list module.
 *
 * @see list_field_settings_form()
 */
function simple_field_simple_field_type_form($simplefield, $has_data) {
  $form = array();
  $type_info = $simplefield->getTypeInfo();
  $field_settings = $simplefield->getSettings('field');

  switch ($type_info['type']) {
    case 'simple_field_yesno':

      break;
    case 'simple_field_multichoice_single':
    case 'simple_field_multichoice_multi':
      $form += simple_field_allowed_values_form($simplefield, $has_data);
      break;

    case 'simple_field_short_answer':
    case 'simple_field_long_answer':

    case 'simple_field_single_date':

    case 'simple_field_date_range':
  }

  return $form;
}

/**
 * Helper to create allowed_values text boxes.
 */
function simple_field_allowed_values_form($simplefield, $has_data) {
  $type_info = $simplefield->getTypeInfo();
  $field_settings = $simplefield->getSettings('field');

  $form = array();
  if (in_array($type_info['field'], array('list_integer', 'list_float', 'list_text'))) {
    $field = $simplefield->getField();

    if (!$field) {
      // Since the field may not exist if the simplefield is being created, add
      // then build an empty field to represent it for now.
      $field = simple_field_build_field($simplefield);
    }

    $form['field_settings']['allowed_values'] = array(
      '#type' => 'textarea',
      '#title' => t('Allowed values list'),
      '#default_value' => simple_field_list_allowed_values_string($field_settings['allowed_values']),
      '#rows' => 10,
      '#element_validate' => array('list_allowed_values_setting_validate'),
      '#field_type' => $field['type'],
      '#field_has_data' => $has_data,
      '#required' => TRUE,
      '#field' => $field,
    );
  }
  elseif ($type_info['field'] == 'list_boolean') {
    $values = $field_settings['allowed_values'];
    $off_value = array_shift($values);
    $on_value = array_shift($values);
    $form['field_settings']['allowed_values'] = array(
      '#type' => 'value',
      '#description' => '',
      '#value_callback' => 'list_boolean_allowed_values_callback',
    );
    $form['field_settings']['allowed_values']['on'] = array(
      '#type' => 'textfield',
      '#title' => t('On value'),
      '#default_value' => $on_value,
      '#required' => FALSE,
      '#description' => t('If left empty, "1" will be used.'),
      '#parents' => array('field_settings', 'allowed_values_ignored', 'on'),
    );
    $form['field_settings']['allowed_values']['off'] = array(
      '#type' => 'textfield',
      '#title' => t('Off value'),
      '#default_value' => $off_value,
      '#required' => FALSE,
      '#description' => t('If left empty, "0" will be used.'),
      '#parents' => array('field_settings', 'allowed_values_ignored', 'off'),
    );

    // Used in value callback.
    $form['field_settings']['allowed_values']['#on_parents'] = &$form['field_settings']['allowed_values']['on']['#parents'];
    $form['field_settings']['allowed_values']['#off_parents'] = &$form['field_settings']['allowed_values']['off']['#parents'];
  }
  return $form;
}


/**
 * Generates a string representation of an array of 'allowed values'.
 *
 * This string format is suitable for edition in a textarea.
 *
 * This function is our customised version of list_allowed_values_string
 * which shows only the value if the key and vaule are identical.
 *
 * @param $values
 *   An array of values, where array keys are values and array values are
 *   labels.
 *
 * @return
 *   The string representation of the $values array:
 *    - Values are separated by a carriage return.
 *    - Each value is in the format "key|value" or "value"
 *      if the two are different or the same respectively.
 */
function simple_field_list_allowed_values_string($values) {
  $lines = array();
  foreach ($values as $key => $value) {
    $lines[] = ($key === $value ? '' : "$key|") . "$value";
  }
  return implode("\n", $lines);
}

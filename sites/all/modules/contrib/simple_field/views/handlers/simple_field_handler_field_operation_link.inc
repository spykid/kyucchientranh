<?php
/**
 * @file
 * Views handler for showing operation links for the simplefield.
 */

/**
 * Render a link to edit or delete a Simple Field.
 */
class simple_field_handler_field_operation_link extends views_handler_field_entity {

  function render($values) {
    $simplefield = $this->get_value($values);

    $op = isset($this->definition['simplefield_op']) ? $this->definition['simplefield_op'] : 'edit';

    $text = t('Edit');
    $slug = 'edit';
    $perm = 'update';

    switch ($op) {
      case 'clone':
        $text = t('Clone');
        $slug = 'clone';
        $perm = 'create';
        break;

      case 'delete':
        $text = t('Delete');
        $slug = 'delete';
        $perm = 'delete';
        break;
    }

    if (!$simplefield || !entity_access($perm, 'simple_field', $simplefield)) {
      return '';
    }
    $url = "admin/structure/simple-field/manage/" . $simplefield->id . "/$slug";
    return l($text, $url, array('query' => drupal_get_destination()));
  }
}

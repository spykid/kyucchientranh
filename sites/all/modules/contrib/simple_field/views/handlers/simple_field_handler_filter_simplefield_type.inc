<?php
/**
 * @file
 * Views handler for filtering by a specific simplefield type.
 */

/**
 * Create filter for filtering by Simple Field type.
 */
class simple_field_handler_filter_simplefield_type extends views_handler_filter_in_operator {

  function get_value_options() {
    $simple_field_types = simple_field_type_info();
    $options = array();
    foreach ($simple_field_types as $type_id => $data) {
      $options[$type_id] = $data['label'];
    }
    $this->value_options = $options;
  }
}

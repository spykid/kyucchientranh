<?php
/**
 * @file
 * Views handler for showing the field label.
 */

/**
 * Render the label of a Simple Field.
 */
class simple_field_handler_field_simplefield_label extends views_handler_field_entity {

  function render($values) {
    $simplefield = $this->get_value($values);
    return $simplefield->label();
  }
}

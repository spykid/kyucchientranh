<?php
/**
 * @file
 * Views handler for showing the type label for the field.
 */

/**
 * Render the type label of a Simple Field.
 */
class simple_field_handler_field_simplefield_type extends views_handler_field_entity {

  function render($values) {
    $simplefield = $this->get_value($values);
    return $simplefield->getTypeLabel();
  }
}

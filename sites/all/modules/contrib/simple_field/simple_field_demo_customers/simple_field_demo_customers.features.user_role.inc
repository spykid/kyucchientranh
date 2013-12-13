<?php
/**
 * @file
 * simple_field_demo_customers.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function simple_field_demo_customers_user_default_roles() {
  $roles = array();

  // Exported role: customer service rep
  $roles['customer service rep'] = array(
    'name' => 'customer service rep',
    'weight' => '3',
  );

  return $roles;
}

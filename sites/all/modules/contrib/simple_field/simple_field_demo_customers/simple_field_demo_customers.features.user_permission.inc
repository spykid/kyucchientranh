<?php
/**
 * @file
 * simple_field_demo_customers.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function simple_field_demo_customers_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer simple fields
  $permissions['administer simple fields'] = array(
    'name' => 'administer simple fields',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: create all simple field types
  $permissions['create all simple field types'] = array(
    'name' => 'create all simple field types',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: create simple field instances
  $permissions['create simple field instances'] = array(
    'name' => 'create simple field instances',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: create simple fields
  $permissions['create simple fields'] = array(
    'name' => 'create simple fields',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: create simple fields with type simple_field_date_range
  $permissions['create simple fields with type simple_field_date_range'] = array(
    'name' => 'create simple fields with type simple_field_date_range',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_integer
  $permissions['create simple fields with type simple_field_integer'] = array(
    'name' => 'create simple fields with type simple_field_integer',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_long_answer
  $permissions['create simple fields with type simple_field_long_answer'] = array(
    'name' => 'create simple fields with type simple_field_long_answer',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_multichoice_multi
  $permissions['create simple fields with type simple_field_multichoice_multi'] = array(
    'name' => 'create simple fields with type simple_field_multichoice_multi',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_multichoice_single
  $permissions['create simple fields with type simple_field_multichoice_single'] = array(
    'name' => 'create simple fields with type simple_field_multichoice_single',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_short_answer
  $permissions['create simple fields with type simple_field_short_answer'] = array(
    'name' => 'create simple fields with type simple_field_short_answer',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_single_date
  $permissions['create simple fields with type simple_field_single_date'] = array(
    'name' => 'create simple fields with type simple_field_single_date',
    'roles' => array(),
  );

  // Exported permission: create simple fields with type simple_field_yesno
  $permissions['create simple fields with type simple_field_yesno'] = array(
    'name' => 'create simple fields with type simple_field_yesno',
    'roles' => array(),
  );

  // Exported permission: delete all simple field types
  $permissions['delete all simple field types'] = array(
    'name' => 'delete all simple field types',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: delete simple field instances
  $permissions['delete simple field instances'] = array(
    'name' => 'delete simple field instances',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: delete simple fields
  $permissions['delete simple fields'] = array(
    'name' => 'delete simple fields',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: delete simple fields with type simple_field_date_range
  $permissions['delete simple fields with type simple_field_date_range'] = array(
    'name' => 'delete simple fields with type simple_field_date_range',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_integer
  $permissions['delete simple fields with type simple_field_integer'] = array(
    'name' => 'delete simple fields with type simple_field_integer',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_long_answer
  $permissions['delete simple fields with type simple_field_long_answer'] = array(
    'name' => 'delete simple fields with type simple_field_long_answer',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_multichoice_multi
  $permissions['delete simple fields with type simple_field_multichoice_multi'] = array(
    'name' => 'delete simple fields with type simple_field_multichoice_multi',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_multichoice_single
  $permissions['delete simple fields with type simple_field_multichoice_single'] = array(
    'name' => 'delete simple fields with type simple_field_multichoice_single',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_short_answer
  $permissions['delete simple fields with type simple_field_short_answer'] = array(
    'name' => 'delete simple fields with type simple_field_short_answer',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_single_date
  $permissions['delete simple fields with type simple_field_single_date'] = array(
    'name' => 'delete simple fields with type simple_field_single_date',
    'roles' => array(),
  );

  // Exported permission: delete simple fields with type simple_field_yesno
  $permissions['delete simple fields with type simple_field_yesno'] = array(
    'name' => 'delete simple fields with type simple_field_yesno',
    'roles' => array(),
  );

  // Exported permission: list simple field instances
  $permissions['list simple field instances'] = array(
    'name' => 'list simple field instances',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: update all simple field types
  $permissions['update all simple field types'] = array(
    'name' => 'update all simple field types',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: update simple fields
  $permissions['update simple fields'] = array(
    'name' => 'update simple fields',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  // Exported permission: update simple fields with type simple_field_date_range
  $permissions['update simple fields with type simple_field_date_range'] = array(
    'name' => 'update simple fields with type simple_field_date_range',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_integer
  $permissions['update simple fields with type simple_field_integer'] = array(
    'name' => 'update simple fields with type simple_field_integer',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_long_answer
  $permissions['update simple fields with type simple_field_long_answer'] = array(
    'name' => 'update simple fields with type simple_field_long_answer',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_multichoice_multi
  $permissions['update simple fields with type simple_field_multichoice_multi'] = array(
    'name' => 'update simple fields with type simple_field_multichoice_multi',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_multichoice_single
  $permissions['update simple fields with type simple_field_multichoice_single'] = array(
    'name' => 'update simple fields with type simple_field_multichoice_single',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_short_answer
  $permissions['update simple fields with type simple_field_short_answer'] = array(
    'name' => 'update simple fields with type simple_field_short_answer',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_single_date
  $permissions['update simple fields with type simple_field_single_date'] = array(
    'name' => 'update simple fields with type simple_field_single_date',
    'roles' => array(),
  );

  // Exported permission: update simple fields with type simple_field_yesno
  $permissions['update simple fields with type simple_field_yesno'] = array(
    'name' => 'update simple fields with type simple_field_yesno',
    'roles' => array(),
  );

  // Exported permission: view simple fields
  $permissions['view simple fields'] = array(
    'name' => 'view simple fields',
    'roles' => array(
      0 => 'customer service rep',
    ),
    'module' => 'simple_field',
  );

  return $permissions;
}

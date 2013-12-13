<?php
/**
 * @file
 * simple_field_demo_customers.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function simple_field_demo_customers_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:admin/structure/types/manage/customer/simple-fields
  $menu_links['main-menu:admin/structure/types/manage/customer/simple-fields'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/structure/types/manage/customer/simple-fields',
    'router_path' => 'admin/structure/types/manage/%/simple-fields',
    'link_title' => 'Edit Customer Fields',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:customers
  $menu_links['main-menu:customers'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'customers',
    'router_path' => 'customers',
    'link_title' => 'Customers',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '10',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Customers');
  t('Edit Customer Fields');
  t('Home');


  return $menu_links;
}

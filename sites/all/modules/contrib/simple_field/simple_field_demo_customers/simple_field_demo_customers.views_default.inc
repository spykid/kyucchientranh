<?php
/**
 * @file
 * simple_field_demo_customers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function simple_field_demo_customers_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'customers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Customers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Customers';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'sf_phonenumber' => 'sf_phonenumber',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sf_phonenumber' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['sf_language']['id'] = 'sf_language';
  $handler->display->display_options['fields']['sf_language']['table'] = 'field_data_sf_language';
  $handler->display->display_options['fields']['sf_language']['field'] = 'sf_language';
  $handler->display->display_options['fields']['sf_language']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sf_language']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sf_language']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sf_language']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sf_language']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['sf_language']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sf_language']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sf_language']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sf_language']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sf_language']['field_api_classes'] = 0;
  /* Field: Content: Phone Number */
  $handler->display->display_options['fields']['sf_phonenumber']['id'] = 'sf_phonenumber';
  $handler->display->display_options['fields']['sf_phonenumber']['table'] = 'field_data_sf_phonenumber';
  $handler->display->display_options['fields']['sf_phonenumber']['field'] = 'sf_phonenumber';
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['sf_phonenumber']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sf_phonenumber']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sf_phonenumber']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sf_phonenumber']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'customer' => 'customer',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'customers';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Customers';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['customers'] = array(
    t('Master'),
    t('Customers'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Language'),
    t('Phone Number'),
    t('Page'),
  );
  $export['customers'] = $view;

  return $export;
}

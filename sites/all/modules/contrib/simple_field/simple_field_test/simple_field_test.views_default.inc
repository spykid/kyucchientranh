<?php
/**
 * @file
 * Default views used for testing simplefield.
 */

/**
 * Implements hook_views_default_views().
 */
function simple_field_test_views_default_views() {
  $views = array();
  $view = new view;
  $view->name = 'simple_field_test_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'simple_field';
  $view->human_name = 'Simple Field Test View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Simple Fields Test View';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'delete_link' => 'delete_link',
    'edit_link' => 'edit_link',
    'clone_link' => 'clone_link',
    'type_label' => 'type_label',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type_label' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Simple Field: Simple field ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'simple_field';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Simple Field: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'simple_field';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['label']['hide_alter_empty'] = 1;
  /* Field: Simple Field: Type label */
  $handler->display->display_options['fields']['type_label']['id'] = 'type_label';
  $handler->display->display_options['fields']['type_label']['table'] = 'simple_field';
  $handler->display->display_options['fields']['type_label']['field'] = 'type_label';
  $handler->display->display_options['fields']['type_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type_label']['hide_alter_empty'] = 1;
  /* Field: Simple Field: Simple Field edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'simple_field';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  /* Field: Simple Field: Simple Field clone link */
  $handler->display->display_options['fields']['clone_link']['id'] = 'clone_link';
  $handler->display->display_options['fields']['clone_link']['table'] = 'simple_field';
  $handler->display->display_options['fields']['clone_link']['field'] = 'clone_link';
  $handler->display->display_options['fields']['clone_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['clone_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['clone_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['clone_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['clone_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['clone_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['clone_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['clone_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['clone_link']['hide_alter_empty'] = 1;
  /* Field: Simple Field: Simple Field delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'simple_field';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  /* Filter criterion: Simple Field: Type label */
  $handler->display->display_options['filters']['type_label']['id'] = 'type_label';
  $handler->display->display_options['filters']['type_label']['table'] = 'simple_field';
  $handler->display->display_options['filters']['type_label']['field'] = 'type_label';
  $handler->display->display_options['filters']['type_label']['value'] = array(
    'simple_field_yesno' => 'simple_field_yesno',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'simplefieldtestview';

  $views[$view->name] = $view;
  return $views;
}


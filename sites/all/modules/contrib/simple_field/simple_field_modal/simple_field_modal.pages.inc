<?php
/**
 * @file
 * Page callbacks used for modal ajax pages.
 */

/**
 * Page callback that wraps a separate callback in a JS page.
 *
 * @param $page_callback
 *   The page callback to potentially wrap in an ajax reponse.
 * @param ...
 *   Any further arguments will be passed to the page callback.
 *
 * @return
 *   Either a standard renderable array, or a set of ajax commands.
 */
function simple_field_modal_page($page_callback) {

  // Load ctools includes so we can call ctools helper functions.
  ctools_include('ajax');
  ctools_include('modal');

  // Get all function argument after $page_callback.
  $args = func_get_args();
  $args = array_slice($args, 1);

  // Handle all types of form pages. These pages need to be managed so that they
  // will not redirect on submission and instead allow modals to behave as
  // expected.
  if (in_array($page_callback, array('entity_ui_get_form', 'simple_field_add_page', 'simple_field_add_with_instance_page', 'drupal_get_form'))) {
    $form_state = array(
      'ajax' => TRUE, // Read by ctools in a few places.
      're_render' => FALSE, // TODO: Is this a thing in D7?
      'no_redirect' => TRUE, // Disable redirection on submission.
    );

    if ($page_callback == 'entity_ui_get_form') {
      // Directly call entity_ui_get_form in order to properly pass form_state
      if (!isset($args[2])) {
        $args[2] = 'edit';
      }
      $content = entity_ui_get_form($args[0], $args[1], $args[2], $form_state);
      $form_state = $content['#simple_field_form_state'];
    }
    elseif ($page_callback == 'simple_field_add_page') {
      // Override add page to set the action and pass form_state
      $content = simple_field_add_page($args[0], $form_state);
      $content['#action'] = url('admin/structure/simple-field/add/' . $args[0]['type'] . '/ajax');
      $form_state = $content['#simple_field_form_state'];
    }
    elseif ($page_callback == 'simple_field_add_with_instance_page') {
      $entity_type = $args[0];
      $bundle = field_extract_bundle($entity_type, $args[1]);
      $entity_info = entity_get_info($entity_type);
      $bundle_info = $entity_info['bundles'][$bundle];

      $path = isset($bundle_info['admin']['real path']) ? $bundle_info['admin']['real path'] : $bundle_info['admin']['path'];

      // Override add page to set the action and pass form_state
      $content = simple_field_add_with_instance_page($args[0], $args[1], $args[2], $form_state);
      $content['#action'] = url($path . '/simple-fields/add/' . $args[2]['type'] . '/ajax');
      $form_state = $content['#simple_field_form_state'];
    }
    else {
      // Handle the general case of random forms.
      $form_id = array_shift($args);
      $form_state['build_info']['args'] = $args;
      $content = drupal_build_form($form_id, $form_state);
    }


    if (!$form_state['executed']) {
      // Just render the form if it hasn't been submitted.
      $commands = ctools_modal_form_render($form_state, $content);
    }
    else {
      // Automatically close the form and reload the page on submission.
      $commands = array(
        ctools_modal_command_dismiss(),
        ctools_ajax_command_reload(),
      );

      // Allow forms to override the commands with a different set.
      if (!empty($form_state['simple_field_modal_commands'])) {
        $commands = $form_state['simple_field_modal_commands'];
      }
    }
  }
  else {
    // Handle the most general case of simply wrapping content in an ajax
    // response so that it can be rendered properly in a popup.
    $content = call_user_func_array($page_callback, $args);
    $title = drupal_get_title();
    $commands = array(
      ctools_modal_command_display($title, $content),
    );
  }

  // Return a renderable command list. These pages have their delivery
  // callback set to ajax_deliver, so this is rendered at the very end.
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

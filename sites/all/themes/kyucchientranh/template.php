<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function kyucchientranh_preprocess_page(&$variables) {
    if (isset($variables['node']->type)) {
        $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
    }
   
}

function kyucchientranh_override_path_image() {
    global $base_path;
    $output = $base_path . path_to_theme('theme', 'kyucchientrang') . '/images';
    return $output;
}

function kyucchientranh_theme() {
    return array(
        'contact_site_form' => array(
            'render element' => 'form',
            'template' => 'contact-site-form',
            'path' => drupal_get_path('theme', 'kyucchientranh') . '/tpl',
        ),
    );
}

/**
 * Preproccess call to process the site contact form
 */
function kyucchientranh_preprocess_contact_site_form(&$variables) {
    //an example of setting up an extra variable, you can also put this directly in the template
    $variables['name'] = t('Contact');
    $variables['info'] = t('Please fill in the fields below to contact us');
    //this is the contents of the form
 //   $variables['contact'] = drupal_render_children($variables['form']);
}

function _kyucchientranh_preprocess_contact_site_form(&$vars) {
    $form = $vars['form'];
    $form['name']['#title'] = t('Name');
    $form['mail']['#title'] = t('Emmail');
    $vars['contact_title'] = t('Contact us');
    $vars['name'] = render($form['name']);
    $vars['email'] = render($form['mail']);
    $vars['subject'] = render($form['subject']);
    $vars['message'] = render($form['message']);
    $vars['copy'] = render($form['copy']);

    $vars['children'] = drupal_render_children($form);
}


function kyucchientranh_menu_tree__main_menu(&$variables) {
    return '<ul class="sb_menu">' . $variables['tree'] . '</ul>';
}

function kyucchientranh_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';  

  if (
    $element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li>' . $output . $sub_menu . "</li>\n";
    
}

function _kyucchientranh_block_columns($region, $max_column = 3) {
   if (module_exists('context')) {
        $context_blocks = context_get_plugin('reaction', 'block');
        $blocks = $context_blocks->block_list($region);
    }
    else {
        $blocks = block_list($region);
    }
    
    if ($blocks) {
        $column_pointer = 1;
        $columns = array();
        foreach ($blocks as $key => $block) {
            $columns[$column_pointer] .= theme('block', $block);
            $column_pointer++;
            if ($column_pointer > $max_column) $column_pointer = 1;
            
        }
    }
    if ($columns) { // we don't want to do this if there are no columns (for example, if an empty block region is being displayed on the blocks admin page)
    $column_count = count($columns);
    $output .= "<div class=\"block-columns columns-$column_count clearfix\">\n";
    foreach ($columns as $key => $column) {
      switch ($key) {
        case $column_count: $firstlast = ' last'; break;
        case 1: $firstlast = ' first'; break;
        default: $firstlast = '';
      }
      $output .= '<div class= "$key" >' . $column . '</div>';
    }
    $output .= "</div>";
  } 
   
     $output .= _block_get_renderable_array($blocks);
  
 // $output .= drupal_get_content()
  return $output;

}

function kyucchientranh_preprocess_image(&$variables) {
 // $variables['attributes']['class'][] = 'fl';
}
?>

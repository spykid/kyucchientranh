<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function kyucchientranh_preprocess_page(&$variables) {
   if (isset($variables['node']->type)) {
       $variables['theme_hook_suggestions'][] = 'page__'. $variables['node']->type;
   }
}

function kyucchientranh_override_path_image() {
    global $base_path;
    $output = $base_path . path_to_theme('theme', 'kyucchientrang') . '/images'; 
    
    return $output;
}
?>

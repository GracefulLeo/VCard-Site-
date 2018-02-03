<?php

/**
 * Implements template_preprocess_html().
 */
function vcard_preprocess_html(&$variables) {
}

/**
 * Implements template_preprocess_page.
 */
function vcard_preprocess_page(&$variables) {
}

/**
 * Implements template_preprocess_node.
 */
function vcard_preprocess_node(&$variables) {
}

/**
 * Implements template_preprocess_theme.
 */
function vcard_preprocess_vcard_nano_teaser(&$variables) {
  try {
    if ($variables['logo_uri']) {
      $variables['image'] = theme('image_style', [
        'path' => $variables['logo_uri'],
        'style_name' => 'micro_logo',
      ]);
    }
    else {
      $variables['image'] = theme('image', [
        'path' => drupal_get_path('theme', 'vcard') . '/images/business-card-svgrepo-com.svg',
      ]);
    }
  } catch (Exception $e) {
    watchdog('theme', 'vcard_nano_teaser error: @e', ['@e' => $e]);
  }
}

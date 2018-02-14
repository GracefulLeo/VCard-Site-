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

/**
 * Implements template_preprocess_theme.
 */
function vcard_preprocess_vcard_details_view(&$variables) {
  $variables['icon_path'] = drupal_get_path('theme', 'vcard') . '/images';
  $node_wrapper = entity_metadata_wrapper('node', $variables['node']);
  $variables['id'] = $node_wrapper->nid->value();
  $variables['img'] = node_view($variables['node'], 'image');
  $variables['full_name'] =
    $node_wrapper->field_surname->value() . ' ' .
    $node_wrapper->field_name->value() . ' ' .
    $node_wrapper->field_middle_name->value();
  $variables['company'] = $node_wrapper->field_company_name->value();
  $variables['position'] = $node_wrapper->field_position->value();
  $phones = [];
  foreach ($node_wrapper->field_phone->value() as $phone) {
    $phones[] = $phone;
  }
  $variables['phones'] = implode('<br/>', $phones);
  $emails = [];
  foreach ($node_wrapper->field_mail->value() as $mail) {
    $emails[] = $mail;
  }
  $variables['emails'] = implode('<br/>', $emails);
  $variables['site'] = $node_wrapper->field_web_site->value();
  $variables['address'] = $node_wrapper->field_address->value();
}

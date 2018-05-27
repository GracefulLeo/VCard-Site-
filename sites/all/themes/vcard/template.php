<?php

/**
 * Defines path to VCard logotype default image.
 */
define('VCARD_DEFAULT_LOGO_MICRO_IMAGE', drupal_get_path('theme', 'vcard') . '/images/business-card-svgrepo-com.svg');

/**
 * Implements template_preprocess_html.
 */
function vcard_preprocess_html(&$variables) {
  // Block access to site after two 404 error.
  $baned_ips = unserialize(variable_get('baned_ips', 'a:0:{}'));

  $ip = $_SERVER['REMOTE_ADDR'];
  if (in_array($ip, $baned_ips)) {
    die('Matrix has you...');
  }

  $status = drupal_get_http_header("status");
  if ($status == '404 Not Found') {
    // After first "404 error" save suspicious ip.
    // If the ip already exists in "suspicious ips" array save ip to "baned ips".
    $suspicious_ips = variable_get('suspicious_ips', []);
    if (in_array($ip, $suspicious_ips)) {
      array_push($baned_ips, $ip);
      variable_set('baned_ips', serialize($baned_ips));
    }
    else {
      array_push($suspicious_ips, $ip);
      variable_set('suspicious_ips', $suspicious_ips);
    }
  }
}

/**
 * Implements template_preprocess_entity.
 */
function vcard_preprocess_entity(&$variables) {
  if ($variables['entity_type'] === 'vcard' && $variables['view_mode'] === 'image') {
    $variables['page'] = TRUE;
  }
}

/**
 * Implements template_preprocess_theme.
 */
function vcard_preprocess_entity_nano_teaser(&$variables) {
  try {
    if ($variables['logo_uri']) {
      $variables['image'] = theme('image_style', [
        'path' => $variables['logo_uri'],
        'style_name' => 'micro_logo',
      ]);
    }
    else {
      $variables['image'] = theme('image', [
        'path' => VCARD_DEFAULT_LOGO_MICRO_IMAGE,
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
  $vcard_wrapper = entity_metadata_wrapper('vcard', $variables['vcard_entity']);
  $id = $vcard_wrapper->id->value();
  $variables['id'] = $id;
  $variables['base64'] = $vcard_wrapper->base64_vcard->value();
  $variables['full_name'] =
    $vcard_wrapper->surname->value() . ' ' .
    $vcard_wrapper->name->value() . ' ' .
    $vcard_wrapper->middle_name->value();
  $variables['company'] = $vcard_wrapper->company->value();
  $variables['position'] = $vcard_wrapper->position->value();
  $variables['phones'] = $vcard_wrapper->phone->value();
  $variables['emails'] = $vcard_wrapper->email->value();
  $variables['site'] = $vcard_wrapper->web_site->value();
  $variables['address'] = $vcard_wrapper->address->value();
}

/**
 * Implements template_preprocess_views_view.
 */
function vcard_preprocess_views_view(&$variables) {
  if ($variables['view']->name === 'contacts') {
    drupal_add_js(drupal_get_path('theme', 'vcard') . '/js/entity_view_ajax_load.js');
    drupal_add_js(drupal_get_path('theme', 'vcard') . '/js/exposed_auto_submit_fix.js');
  }
}

/**
 * Implements template_preprocess_theme.
 */
function vcard_preprocess_group_details_view(&$variables) {
  $group_wrapper = entity_metadata_wrapper('group', $variables['group']);
  if (!empty($group_wrapper->field_my_contacts)) {
    $variables['contacts'] = [];
    foreach ($group_wrapper->field_my_contacts->value() as $contact) {

      if (!empty($contact->field_logotype)) {
        try {
          $logo = theme('image_style', [
            'path' => $contact->field_logotype[LANGUAGE_NONE][0]['uri'],
            'style_name' => 'micro_logo',
          ]);
        } catch (Exception $e) {
        }
      }
      else {
        try {
          $logo = theme('image', [
            'path' => VCARD_DEFAULT_LOGO_MICRO_IMAGE,
          ]);
        } catch (Exception $e) {
        }
      }

      $full_name = $contact->surname . ' ' . $contact->name;
      if (!empty($contact->middle_name)) {
        $full_name .= ' ' . $contact->middle_name;
      }

      $variables['contacts'][] = [
        'logo' => $logo,
        'full_name' => $full_name,
        'position' => $contact->position,
        'vcard' => $contact->base64_vcard,
      ];
    }
  }
}

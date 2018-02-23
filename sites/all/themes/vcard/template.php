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

      $full_name = $contact->field_surname[LANGUAGE_NONE][0]['value'] . ' ' .
        $contact->field_name[LANGUAGE_NONE][0]['value'];
      if (!empty($contact->field_middle_name)) {
        $full_name .= ' ' . $contact->field_middle_name[LANGUAGE_NONE][0]['value'];
      }

      $vcard = node_view($contact, 'image');

      $variables['contacts'][] = [
        'logo' => $logo,
        'full_name' => $full_name,
        'position' => !empty($contact->field_position) ? $contact->field_position[LANGUAGE_NONE][0]['value'] : '',
        'vcard' => render($vcard),
      ];

    }
  }
}

/**
 * Returns HTML for an individual form element.
 *
 * Combine multiple values into a table with drag-n-drop reordering.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the form element.
 *
 * @return string
 */
function vcard_field_multiple_value_form($variables) {
  $element = $variables['element'];
  $output = '';

  foreach (element_children($element) as $key) {
    $output .= drupal_render($element[$key]);
  }

  return $output;
}

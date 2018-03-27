<?php
/**
 * @file
 * vcard_entity_vcard.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function vcard_entity_vcard_eck_bundle_info() {
  $items = array(
    'vcard_vcard' => array(
      'machine_name' => 'vcard_vcard',
      'entity_type' => 'vcard',
      'name' => 'vcard',
      'label' => 'VCard',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'uid' => 'uid',
          'created' => 'created',
          'changed' => 'changed',
          'logotype' => 'logotype',
          'surname' => 'surname',
          'name' => 'name',
          'middle_name' => 'middle_name',
          'company' => 'company',
          'address' => 'address',
          'position' => 'position',
          'web_site' => 'web_site',
          'phone' => 'phone',
          'email' => 'email',
          'base64_vcard' => 'base64_vcard',
          'social_links' => 'social_links',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function vcard_entity_vcard_eck_entity_type_info() {
  $items = array(
    'vcard' => array(
      'name' => 'vcard',
      'label' => 'VCard',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'logotype' => array(
          'label' => 'Logotype',
          'type' => 'integer',
          'behavior' => 'integer',
        ),
        'surname' => array(
          'label' => 'Surname',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'name' => array(
          'label' => 'Name',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'middle_name' => array(
          'label' => 'Middle name',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'company' => array(
          'label' => 'Company',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'address' => array(
          'label' => 'Address',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'position' => array(
          'label' => 'Position',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'web_site' => array(
          'label' => 'Web site',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'phone' => array(
          'label' => 'Phone',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'email' => array(
          'label' => 'E-mail',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'base64_vcard' => array(
          'label' => 'base64 vcard',
          'type' => 'long_text',
          'behavior' => 'long_text',
        ),
        'social_links' => array(
          'label' => 'Social links',
          'type' => 'long_text',
          'behavior' => 'long_text',
        ),
      ),
    ),
  );
  return $items;
}

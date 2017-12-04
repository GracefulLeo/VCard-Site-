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
      'config' => array(),
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
      'properties' => array(),
    ),
  );
  return $items;
}

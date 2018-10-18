<?php
/**
 * @file
 * vcard_entity_vcard_comment.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function vcard_entity_vcard_comment_eck_bundle_info() {
  $items = array(
    'vcard_comment_vcard_comment' => array(
      'machine_name' => 'vcard_comment_vcard_comment',
      'entity_type' => 'vcard_comment',
      'name' => 'vcard_comment',
      'label' => 'VCard comment',
      'config' => array(
        'managed_properties' => array(
          'json' => 'json',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function vcard_entity_vcard_comment_eck_entity_type_info() {
  $items = array(
    'vcard_comment' => array(
      'name' => 'vcard_comment',
      'label' => 'VCard comment',
      'properties' => array(
        'json' => array(
          'label' => 'json',
          'type' => 'long_text',
          'behavior' => 'long_text',
        ),
      ),
    ),
  );
  return $items;
}

<?php
/**
 * @file
 * vcard_entity_history.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function vcard_entity_history_eck_bundle_info() {
  $items = array(
    'history_history' => array(
      'machine_name' => 'history_history',
      'entity_type' => 'history',
      'name' => 'history',
      'label' => 'History',
      'config' => array(
        'managed_properties' => array(
          'body_teaser' => 'body_teaser',
          'full_body' => 'full_body',
          'vcard_id' => 'vcard_id',
          'created' => 'created',
          'language' => 'language',
          'uid' => 'uid',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function vcard_entity_history_eck_entity_type_info() {
  $items = array(
    'history' => array(
      'name' => 'history',
      'label' => 'History',
      'properties' => array(
        'body_teaser' => array(
          'label' => 'Body teaser',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'full_body' => array(
          'label' => 'Full body',
          'type' => 'long_text',
          'behavior' => 'long_text',
        ),
        'vcard_id' => array(
          'label' => 'VCard ID',
          'type' => 'integer',
          'behavior' => 'integer',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
      ),
    ),
  );
  return $items;
}

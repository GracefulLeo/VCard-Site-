<?php
/**
 * @file
 * vcard_field_my_vcards.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function vcard_field_my_vcards_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_my_vcards'.
  $field_bases['field_my_vcards'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_my_vcards',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'vcard' => 'vcard',
        ),
      ),
      'target_type' => 'vcard',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}

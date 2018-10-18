<?php
/**
 * @file
 * vcard_field_vcard_comment.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function vcard_field_vcard_comment_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_vcard_comment'.
  $field_bases['field_vcard_comment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_vcard_comment',
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
          'vcard_comment' => 'vcard_comment',
        ),
      ),
      'target_type' => 'vcard_comment',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}

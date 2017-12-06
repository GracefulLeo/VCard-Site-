<?php
/**
 * @file
 * vcard_field_groups.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function vcard_field_groups_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_groups'.
  $field_bases['field_groups'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_groups',
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
          'direction' => 'ASC',
          'field' => 'field_group_name:value',
          'type' => 'field',
        ),
        'target_bundles' => array(
          'group' => 'group',
        ),
      ),
      'target_type' => 'group',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}

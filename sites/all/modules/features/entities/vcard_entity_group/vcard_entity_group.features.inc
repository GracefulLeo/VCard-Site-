<?php
/**
 * @file
 * vcard_entity_group.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function vcard_entity_group_eck_bundle_info() {
  $items = array(
    'group_group' => array(
      'machine_name' => 'group_group',
      'entity_type' => 'group',
      'name' => 'group',
      'label' => 'Group',
      'config' => array(
        'managed_properties' => array(
          'changed' => 'changed',
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
function vcard_entity_group_eck_entity_type_info() {
  $items = array(
    'group' => array(
      'name' => 'group',
      'label' => 'Group',
      'properties' => array(
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
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

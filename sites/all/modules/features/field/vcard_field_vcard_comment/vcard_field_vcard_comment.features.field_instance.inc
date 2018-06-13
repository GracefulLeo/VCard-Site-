<?php
/**
 * @file
 * vcard_field_vcard_comment.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function vcard_field_vcard_comment_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_vcard_comment'.
  $field_instances['user-user-field_vcard_comment'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_vcard_comment',
    'label' => 'VCard comment',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('VCard comment');

  return $field_instances;
}

<?php
/**
 * @file
 * vcard_field_my_contacts.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function vcard_field_my_contacts_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_my_contacts'.
  $field_instances['user-user-field_my_contacts'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_my_contacts',
    'label' => 'My Contacts',
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
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('My Contacts');

  return $field_instances;
}

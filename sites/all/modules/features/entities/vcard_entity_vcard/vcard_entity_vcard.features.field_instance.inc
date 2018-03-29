<?php
/**
 * @file
 * vcard_entity_vcard.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function vcard_entity_vcard_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'vcard-vcard-field_logotype'.
  $field_instances['vcard-vcard-field_logotype'] = array(
    'bundle' => 'vcard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'vcard',
    'field_name' => 'field_logotype',
    'label' => 'Logotype',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'vcards',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Logotype');

  return $field_instances;
}

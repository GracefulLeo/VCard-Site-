<?php
/**
 * @file
 * vcard_ct_vcard.features.inc
 */

/**
 * Implements hook_node_info().
 */
function vcard_ct_vcard_node_info() {
  $items = array(
    'vcard' => array(
      'name' => t('VCard'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Person'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

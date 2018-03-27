<?php
/**
 * @file
 * vcard_entity_vcard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vcard_entity_vcard_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add vcard vcard entities'.
  $permissions['eck add vcard vcard entities'] = array(
    'name' => 'eck add vcard vcard entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete vcard vcard entities'.
  $permissions['eck delete vcard vcard entities'] = array(
    'name' => 'eck delete vcard vcard entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit vcard vcard entities'.
  $permissions['eck edit vcard vcard entities'] = array(
    'name' => 'eck edit vcard vcard entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view vcard vcard entities'.
  $permissions['eck view vcard vcard entities'] = array(
    'name' => 'eck view vcard vcard entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  return $permissions;
}

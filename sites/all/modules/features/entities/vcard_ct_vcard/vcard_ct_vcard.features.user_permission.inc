<?php
/**
 * @file
 * vcard_ct_vcard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vcard_ct_vcard_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create vcard content'.
  $permissions['create vcard content'] = array(
    'name' => 'create vcard content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any vcard content'.
  $permissions['delete any vcard content'] = array(
    'name' => 'delete any vcard content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own vcard content'.
  $permissions['delete own vcard content'] = array(
    'name' => 'delete own vcard content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any vcard content'.
  $permissions['edit any vcard content'] = array(
    'name' => 'edit any vcard content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own vcard content'.
  $permissions['edit own vcard content'] = array(
    'name' => 'edit own vcard content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view services'.
  $permissions['view services'] = array(
    'name' => 'view services',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'socialfield',
  );

  return $permissions;
}

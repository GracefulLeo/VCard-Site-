<?php
/**
 * @file
 * vcard_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vcard_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create entity'.
  $permissions['create entity'] = array(
    'name' => 'create entity',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vcard_main',
  );

  // Exported permission: 'delete own entity'.
  $permissions['delete own entity'] = array(
    'name' => 'delete own entity',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vcard_main',
  );

  // Exported permission: 'eck add group group entities'.
  $permissions['eck add group group entities'] = array(
    'name' => 'eck add group group entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add history history entities'.
  $permissions['eck add history history entities'] = array(
    'name' => 'eck add history history entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add vcard vcard entities'.
  $permissions['eck add vcard vcard entities'] = array(
    'name' => 'eck add vcard vcard entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete group group entities'.
  $permissions['eck delete group group entities'] = array(
    'name' => 'eck delete group group entities',
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

  // Exported permission: 'eck edit group group entities'.
  $permissions['eck edit group group entities'] = array(
    'name' => 'eck edit group group entities',
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

  // Exported permission: 'eck view group group entities'.
  $permissions['eck view group group entities'] = array(
    'name' => 'eck view group group entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view history history entities'.
  $permissions['eck view history history entities'] = array(
    'name' => 'eck view history history entities',
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

  // Exported permission: 'edit own entity'.
  $permissions['edit own entity'] = array(
    'name' => 'edit own entity',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vcard_main',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'services',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'services',
  );

  // Exported permission: 'view entities'.
  $permissions['view entities'] = array(
    'name' => 'view entities',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vcard_main',
  );

  return $permissions;
}

<?php
/**
 * @file
 * vcard_entity_group.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vcard_entity_group_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add group group entities'.
  $permissions['eck add group group entities'] = array(
    'name' => 'eck add group group entities',
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

  // Exported permission: 'eck edit group group entities'.
  $permissions['eck edit group group entities'] = array(
    'name' => 'eck edit group group entities',
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

  return $permissions;
}

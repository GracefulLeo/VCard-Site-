<?php
/**
 * @file
 * vcard_menu_main_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function vcard_menu_main_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_contacts:contacts.
  $menu_links['main-menu_contacts:contacts'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contacts',
    'router_path' => 'contacts',
    'link_title' => 'Contacts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contacts:contacts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: main-menu_groups:groups.
  $menu_links['main-menu_groups:groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'Groups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_groups:groups',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: main-menu_history:history.
  $menu_links['main-menu_history:history'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'history',
    'router_path' => 'history',
    'link_title' => 'History',
    'options' => array(
      'identifier' => 'main-menu_history:history',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: main-menu_log-out:logout.
  $menu_links['main-menu_log-out:logout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'logout',
    'router_path' => 'logout',
    'link_title' => 'Log Out',
    'options' => array(
      'identifier' => 'main-menu_log-out:logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-vcards:my-vcards.
  $menu_links['main-menu_my-vcards:my-vcards'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'my-vcards',
    'router_path' => 'my-vcards',
    'link_title' => 'My VCards',
    'options' => array(
      'identifier' => 'main-menu_my-vcards:my-vcards',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_settings:settings.
  $menu_links['main-menu_settings:settings'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'settings',
    'router_path' => 'settings',
    'link_title' => 'Settings',
    'options' => array(
      'identifier' => 'main-menu_settings:settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  t('Groups');
  t('History');
  t('Log Out');
  t('My VCards');
  t('Settings');

  return $menu_links;
}

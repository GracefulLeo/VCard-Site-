<?php
/**
 * @file
 * vcard_views_contacts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vcard_views_contacts_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_vcard';
  $view->human_name = 'Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['id'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['table'] = 'eck_vcard';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['field'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['required'] = TRUE;
  /* Field: VCard: json */
  $handler->display->display_options['fields']['field_json']['id'] = 'field_json';
  $handler->display->display_options['fields']['field_json']['table'] = 'field_data_field_json';
  $handler->display->display_options['fields']['field_json']['field'] = 'field_json';
  $handler->display->display_options['fields']['field_json']['label'] = '';
  $handler->display->display_options['fields']['field_json']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_json']['alter']['text'] = '<img src="[field_json-value]" class="vcard-rendered"/>';
  $handler->display->display_options['fields']['field_json']['element_label_colon'] = FALSE;
  /* Filter criterion: VCard: vcard type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_vcard';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vcard' => 'vcard',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'contacts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['contacts'] = $view;

  return $export;
}

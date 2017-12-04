<?php
/**
 * @file
 * vcard_views_my_vcards.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vcard_views_my_vcards_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_vcards_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_vcard';
  $view->human_name = 'User VCards page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My VCards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="my-vcards/add">Add new VCard</a>';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_my_vcards_user']['id'] = 'reverse_field_my_vcards_user';
  $handler->display->display_options['relationships']['reverse_field_my_vcards_user']['table'] = 'eck_vcard';
  $handler->display->display_options['relationships']['reverse_field_my_vcards_user']['field'] = 'reverse_field_my_vcards_user';
  $handler->display->display_options['relationships']['reverse_field_my_vcards_user']['required'] = TRUE;
  /* Field: VCard: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: VCard: json */
  $handler->display->display_options['fields']['field_json']['id'] = 'field_json';
  $handler->display->display_options['fields']['field_json']['table'] = 'field_data_field_json';
  $handler->display->display_options['fields']['field_json']['field'] = 'field_json';
  $handler->display->display_options['fields']['field_json']['label'] = '';
  $handler->display->display_options['fields']['field_json']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_json']['alter']['text'] = '<img src="[field_json-value]" class="vcard-rendered"/>';
  $handler->display->display_options['fields']['field_json']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="my-vcards/[id]/edit">Edit</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<a href="my-vcards/[id]/clone">Clone</a>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<a href="my-vcards/[id]/remove">Delete</a>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Sort criterion: VCard: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_vcard';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'reverse_field_my_vcards_user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'my-vcards';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My VCards';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['user_vcards_page'] = $view;

  return $export;
}

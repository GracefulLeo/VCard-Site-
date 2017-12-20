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
  $view->base_table = 'node';
  $view->human_name = 'Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['id'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['field'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['required'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: json */
  $handler->display->display_options['fields']['field_json']['id'] = 'field_json';
  $handler->display->display_options['fields']['field_json']['table'] = 'field_data_field_json';
  $handler->display->display_options['fields']['field_json']['field'] = 'field_json';
  $handler->display->display_options['fields']['field_json']['label'] = '';
  $handler->display->display_options['fields']['field_json']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_json']['alter']['text'] = '<img src="[field_json-value]" class="vcard-rendered"/>';
  $handler->display->display_options['fields']['field_json']['element_label_colon'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  /* Field: Content: Company */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_company_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_name']['element_label_colon'] = FALSE;
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_mail']['id'] = 'field_mail';
  $handler->display->display_options['fields']['field_mail']['table'] = 'field_data_field_mail';
  $handler->display->display_options['fields']['field_mail']['field'] = 'field_mail';
  $handler->display->display_options['fields']['field_mail']['label'] = '';
  $handler->display->display_options['fields']['field_mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mail']['type'] = 'email_plain';
  $handler->display->display_options['fields']['field_mail']['delta_offset'] = '0';
  /* Field: Content: Middle name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  /* Field: Content: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['label'] = '';
  $handler->display->display_options['fields']['field_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['element_label_colon'] = FALSE;
  /* Field: Content: Web site */
  $handler->display->display_options['fields']['field_web_site']['id'] = 'field_web_site';
  $handler->display->display_options['fields']['field_web_site']['table'] = 'field_data_field_web_site';
  $handler->display->display_options['fields']['field_web_site']['field'] = 'field_web_site';
  $handler->display->display_options['fields']['field_web_site']['label'] = '';
  $handler->display->display_options['fields']['field_web_site']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_site']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_address' => 'field_address',
    'field_company_name' => 'field_company_name',
    'field_mail' => 'field_mail',
    'field_middle_name' => 'field_middle_name',
    'field_name' => 'field_name',
    'field_phone' => 'field_phone',
    'field_position' => 'field_position',
    'field_surname' => 'field_surname',
    'field_web_site' => 'field_web_site',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_address' => 'field_address',
    'field_company_name' => 'field_company_name',
    'field_mail' => 'field_mail',
    'field_middle_name' => 'field_middle_name',
    'field_name' => 'field_name',
    'field_phone' => 'field_phone',
    'field_position' => 'field_position',
    'field_surname' => 'field_surname',
    'field_web_site' => 'field_web_site',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['path'] = 'contacts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['contacts'] = $view;

  return $export;
}

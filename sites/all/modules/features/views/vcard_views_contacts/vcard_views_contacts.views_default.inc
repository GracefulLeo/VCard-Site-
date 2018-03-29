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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'list-item list-item-vcard';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['id'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['table'] = 'eck_vcard';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['field'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['relationships']['reverse_field_my_contacts_user']['required'] = TRUE;
  /* Relationship: VCard: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_vcard';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: VCard: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Field: Logotype */
  $handler->display->display_options['fields']['field_logotype']['id'] = 'field_logotype';
  $handler->display->display_options['fields']['field_logotype']['table'] = 'field_data_field_logotype';
  $handler->display->display_options['fields']['field_logotype']['field'] = 'field_logotype';
  $handler->display->display_options['fields']['field_logotype']['label'] = '';
  $handler->display->display_options['fields']['field_logotype']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_logotype']['element_class'] = 'logo-micro';
  $handler->display->display_options['fields']['field_logotype']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logotype']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_logotype']['empty'] = '<img src="sites/all/themes/vcard/images/business-card-svgrepo-com.svg">';
  $handler->display->display_options['fields']['field_logotype']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_logotype']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logotype']['settings'] = array(
    'image_style' => 'micro_logo',
    'image_link' => '',
  );
  /* Field: VCard: Surname */
  $handler->display->display_options['fields']['surname']['id'] = 'surname';
  $handler->display->display_options['fields']['surname']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['surname']['field'] = 'surname';
  $handler->display->display_options['fields']['surname']['label'] = '';
  $handler->display->display_options['fields']['surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['surname']['element_label_colon'] = FALSE;
  /* Field: VCard: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: VCard: Middle name */
  $handler->display->display_options['fields']['middle_name']['id'] = 'middle_name';
  $handler->display->display_options['fields']['middle_name']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['middle_name']['field'] = 'middle_name';
  $handler->display->display_options['fields']['middle_name']['label'] = '';
  $handler->display->display_options['fields']['middle_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['middle_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[surname] [name]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'vcard-title';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: VCard: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['label'] = '';
  $handler->display->display_options['fields']['address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  /* Field: VCard: Company */
  $handler->display->display_options['fields']['company']['id'] = 'company';
  $handler->display->display_options['fields']['company']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['company']['field'] = 'company';
  $handler->display->display_options['fields']['company']['label'] = '';
  $handler->display->display_options['fields']['company']['exclude'] = TRUE;
  $handler->display->display_options['fields']['company']['element_label_colon'] = FALSE;
  /* Field: VCard: E-mail */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  /* Field: VCard: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = '';
  $handler->display->display_options['fields']['phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
  /* Field: VCard: Position */
  $handler->display->display_options['fields']['position']['id'] = 'position';
  $handler->display->display_options['fields']['position']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['position']['field'] = 'position';
  $handler->display->display_options['fields']['position']['label'] = '';
  $handler->display->display_options['fields']['position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['position']['element_label_colon'] = FALSE;
  /* Field: VCard: Web site */
  $handler->display->display_options['fields']['web_site']['id'] = 'web_site';
  $handler->display->display_options['fields']['web_site']['table'] = 'eck_vcard';
  $handler->display->display_options['fields']['web_site']['field'] = 'web_site';
  $handler->display->display_options['fields']['web_site']['label'] = '';
  $handler->display->display_options['fields']['web_site']['exclude'] = TRUE;
  $handler->display->display_options['fields']['web_site']['element_label_colon'] = FALSE;
  /* Sort criterion: VCard: Changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'eck_vcard';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: VCard: vcard type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_vcard';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vcard' => 'vcard',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'surname' => 'surname',
    'name' => 'name',
    'middle_name' => 'middle_name',
    'address' => 'address',
    'company' => 'company',
    'email' => 'email',
    'phone' => 'phone',
    'position' => 'position',
    'web_site' => 'web_site',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'reverse_field_my_contacts_user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'contacts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'id' => 'id',
    'field_logotype' => 0,
    'surname' => 0,
    'name' => 0,
    'middle_name' => 0,
    'nothing' => 0,
    'address' => 0,
    'company' => 0,
    'email' => 0,
    'phone' => 0,
    'position' => 0,
    'web_site' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: VCard: Surname */
  $handler->display->display_options['sorts']['surname']['id'] = 'surname';
  $handler->display->display_options['sorts']['surname']['table'] = 'eck_vcard';
  $handler->display->display_options['sorts']['surname']['field'] = 'surname';
  /* Sort criterion: VCard: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'eck_vcard';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $export['contacts'] = $view;

  return $export;
}

<?php
/**
 * @file
 * Functions for Groups functionality.
 */

/**
 * Attach to _entity_page list of Groups and Add button.
 *
 * @param $page
 *
 * @param $user_wrapper
 *
 * @see _entity_page
 */
function _groups_attach_page_content(&$page, $user_wrapper) {
  $my_groups = $user_wrapper->field_groups->value();
  if (!empty($my_groups)) {
    // Sort by "changed", newest first.
    $sorted = [];
    foreach ($my_groups as $key => $group) {
      $sorted[$group->changed] = $key;
    }
    krsort($sorted);

    foreach ($sorted as $key) {
      $logo_uri = '';
      if (!empty($my_groups[$key]->field_logotype)) {
        $logo_uri = $my_groups[$key]->field_logotype[LANGUAGE_NONE][0]['uri'];
      }

      try {
        $page['entity_list_wrapper']['nano']['entity_list'][] = [
          '#markup' => theme('entity_nano_teaser', [
            'entity_type' => 'group',
            'nid' => $my_groups[$key]->id,
            'logo_uri' => $logo_uri,
            'title' => $my_groups[$key]->field_group_name[LANGUAGE_NONE][0]['value'],
          ]),
        ];
      } catch (Exception $e) {
        watchdog('theme', 'entity_nano_teaser error: @e', ['@e' => $e]);
      }
    }
  }

  // "Add new group" link.
  drupal_add_library('system', 'drupal.ajax');

  $page['entity_view_wrapper']['nano']['content']['add'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'add-entity-wrapper',
    ],
  ];
  $page['entity_view_wrapper']['nano']['content']['add']['link'] = [
    '#type' => 'link',
    '#href' => 'group/add/nojs',
    '#title' => 'group_add',
    '#prefix' => '<i class="material-icons">',
    '#suffix' => '</i>',
    '#attributes' => [
      'id' => 'add-new-group',
      'class' => ['use-ajax'],
    ],
  ];
  // @todo Find better attach this js.
  drupal_add_js(drupal_get_path('theme', 'vcard') . '/js/groups.js');
}

/**
 * "Groups" form callback for "add", "edit" pages.
 */
function vcard_main_group_form($form, &$form_state, $id = NULL, $op = NULL) {
  global $user;

  if ($user->uid) {
    if (is_numeric($id)) {
      $group_entity = entity_load_single('group', $id);
    }
    else {
      $group_entity = entity_create('group', ['type' => 'group']);
    }

    field_attach_form('group', $group_entity, $form, $form_state);

    $form['group'] = [
      '#type' => 'value',
      '#value' => $group_entity,
    ];

    $form['submit'] = [
      '#type' => 'submit',
      '#value' => t('Save'),
      '#weight' => 100,
    ];

    $form['#validate'][] = 'vcard_main_group_form_validation';
    $form['#submit'][] = 'vcard_main_group_form_submit';
  }

  return $form;
}

/**
 * Delivery ajax for "Add new group".
 */
function vcard_main_group_add_ajax($ajax) {
  $form = drupal_get_form('vcard_main_group_form');
  $output = drupal_render($form);

  if ($ajax === 'ajax') {
    $commands = [];
    $commands[] = ajax_command_replace('#add-entity-wrapper', $output);

    return [
      '#type' => 'ajax',
      '#commands' => $commands,
    ];
  }
  else {
    return $output;
  }
}

/**
 * "Groups" add/edit form validation.
 */
function vcard_main_group_form_validation($form, &$form_state) {
  field_attach_form_validate('group', $form_state['values']['group'], $form, $form_state);
}

/**
 * "Groups" form submit.
 */
function vcard_main_group_form_submit($form, &$form_state) {
  $group_entity = $form_state['values']['group'];
  field_attach_submit('group', $group_entity, $form, $form_state);
  entity_save('group', $group_entity);

  // Save relations to user.
  _user_entityreference_field_save('field_groups', $group_entity->id);

  drupal_goto('groups');
}

/**
 * Delivery ajax for view Group.
 *
 * @param null $id
 *
 * @return array|mixed
 * @throws \Exception
 */
function vcard_main_group_view_ajax($id = NULL) {
  global $user;

  if (is_numeric($id)) {
    $group_entity = entity_load_single('group', $id);

    return theme('group_details_view', ['group' => $group_entity]);
  }

  return FALSE;
}

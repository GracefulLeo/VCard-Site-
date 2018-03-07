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
  $page['entity_view_wrapper']['nano']['content']['add'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'add-entity-wrapper',
    ],
  ];
  // Enable popup style settings.
  vcard_main_group_ctools_popup_style();
  // Create modal link to popup.
  $page['entity_view_wrapper']['nano']['content']['add']['link'] = [
    '#type' => 'link',
    '#href' => 'group/add/nojs',
    '#title' => 'group_add',
    '#prefix' => '<i class="material-icons">',
    '#suffix' => '</i>',
    '#attributes' => [
      'class' => ['ctools-use-modal', 'ctools-modal-groups-popup'],
    ],
  ];
  drupal_add_js(drupal_get_path('theme', 'vcard') . '/js/groups.js');
}

/**
 * "Groups" form callback for "add", "edit" pages.
 */
function vcard_main_group_form($form, &$form_state, $id = NULL) {
  global $user;

  if ($user->uid) {
    if (is_numeric($id)) {
      $group_entity = entity_load_single('group', $id);
    }
    else {
      $group_entity = entity_create('group', ['type' => 'group']);
    }

    field_attach_form('group', $group_entity, $form, $form_state);

    // Remove "My contacts" field, contacts will add in other popup.
    unset($form['field_my_contacts']);

    // Style fields.
    foreach (['field_group_name', 'field_description'] as $field) {
      $form[$field][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = $form[$field][LANGUAGE_NONE][0]['#title'];
      $form[$field][LANGUAGE_NONE][0]['value']['#title_display'] = 'invisible';
    }

    $form['group'] = [
      '#type' => 'value',
      '#value' => $group_entity,
    ];

    $form['submit'] = [
      '#type' => 'submit',
      '#value' => t('Save'),
      '#weight' => 100,
    ];

    // Add js for rewrite Logotype field.
    $form['#attached'] = [
      'js' => [
        drupal_get_path('module', 'vcard_main') . '/js/field_logotype.js',
      ],
    ];
  }

  return $form;
}

/**
 * Modal ajax callback for "Add new group".
 */
function vcard_main_group_add_ajax($js = NULL) {
  if (!$js) {
    return drupal_get_form('vcard_main_group_form');
  }

  ctools_include('ajax');
  ctools_include('modal');

  $form_state = [
    'ajax' => TRUE,
    'title' => t('Add group'),
  ];

  $output = ctools_modal_form_wrapper('vcard_main_group_form', $form_state);
  print ajax_render($output);
  drupal_exit();
}

/**
 * Popup’s settings function.
 */
function vcard_main_group_ctools_popup_style() {
  static $added = FALSE;
  if ($added == FALSE) {
    $added = TRUE;

    ctools_include('modal');
    ctools_include('ajax');
    ctools_modal_add_js();

    $popup_style = [
      'groups-popup' => [
        'modalSize' => [
          'type' => 'fixed',
          'width' => 420,
          'height' => 'auto',
        ],
        'modalOptions' => [
          'opacity' => (float) 0.8,
          'background-color' => '#084b57',
        ],
        'closeText' => '<i class="material-icons">close</i>',
        'animation' => 'fadeIn',
        'modalTheme' => 'groupsPopupHTML',
        'animationSpeed' => 'slow',
      ],
    ];

    drupal_add_js($popup_style, 'setting');
    ctools_add_js('groups_modal_popup', 'vcard_main');
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

  _close_ctools_modal_popup($form_state);

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
  if (is_numeric($id)) {
    $group_entity = entity_load_single('group', $id);

    return theme('group_details_view', ['group' => $group_entity]);
  }

  return FALSE;
}

/**
 * Return json with group's title and description.
 *
 * @param int $id
 *
 * @return string
 */
function vcard_main_group_credits_ajax($id = NULL) {
  if (is_numeric($id)) {
    $group_entity = entity_load_single('group', $id);

    drupal_json_output([
      'title' => $group_entity->field_group_name[LANGUAGE_NONE][0]['value'],
      'description' => @$group_entity->field_description[LANGUAGE_NONE][0]['value'],
    ]);
  }
}

/**
 * Modal ajax callback for "Edit group".
 */
function vcard_main_group_edit_ajax($id = NULL, $js = NULL) {
  if (!$js) {
    return drupal_get_form('vcard_main_group_form', $id);
  }

  ctools_include('ajax');
  ctools_include('modal');

  $form_state = [
    'ajax' => TRUE,
    'title' => t('Edit group'),
    'build_info' => [
      'args' => [
        $id,
      ],
    ],
  ];

  $output = ctools_modal_form_wrapper('vcard_main_group_form', $form_state);
  print ajax_render($output);
  drupal_exit();
}

/**
 * Manage group's contacts form.
 */
function vcard_main_group_manage_contacts_form($form, &$form_state, $id = NULL) {
  global $user;

  if ($user->uid) {
    if (is_numeric($id)) {
      $group_entity = entity_load_single('group', $id);
    }
    else {
      return MENU_NOT_FOUND;
    }

    field_attach_form('group', $group_entity, $form, $form_state);

    // Remove all fields except "My contacts" field.
    unset($form['field_group_name']);
    unset($form['field_logotype']);
    unset($form['field_description']);

    $form['field_my_contacts'][LANGUAGE_NONE]['#title_display'] = 'invisible';

    $form['group'] = [
      '#type' => 'value',
      '#value' => $group_entity,
    ];

    $form['submit'] = [
      '#type' => 'submit',
      '#value' => t('Save'),
      '#weight' => 100,
    ];
  }

  return $form;
}

/**
 * Manage group's contacts form submit.
 */
function vcard_main_group_manage_contacts_form_submit($form, &$form_state) {
  $group_entity = $form_state['values']['group'];
  field_attach_submit('group', $group_entity, $form, $form_state);
  entity_save('group', $group_entity);

  _close_ctools_modal_popup($form_state);

  drupal_goto('groups');
}

/**
 * "Manage contacts in group" page ajax callback.
 */
function vcard_main_group_manage_contacts_ajax($id = NULL, $js = NULL) {
  if (!$js) {
    return drupal_get_form('vcard_main_group_manage_contacts_form', $id);
  }

  ctools_include('ajax');
  ctools_include('modal');

  $form_state = [
    'ajax' => TRUE,
    'title' => t('Manage contacts'),
    'build_info' => [
      'args' => [
        $id,
      ],
    ],
  ];

  $output = ctools_modal_form_wrapper('vcard_main_group_manage_contacts_form', $form_state);
  print ajax_render($output);
  drupal_exit();
}

/**
 * Page callback for deleting Groups.
 */
function vcard_main_group_remove_form($form, &$form_state, $id) {
  global $user;

  $user_wrapper = entity_metadata_wrapper('user', $user);
  $group_wrapper = entity_metadata_wrapper('group', $id);

  // Check is the group created by user.
  $field_groups = $user_wrapper->field_groups->value();
  $ids = [];
  foreach ($field_groups as $group) {
    $ids[] = $group->id;
  }
  if (!in_array($id, $ids)) {
    drupal_not_found();
    drupal_exit();
  }

  $form['title'] = [
    '#type' => 'item',
    '#markup' => t('Delete group: "%name"?', ['%name' => $group_wrapper->field_group_name->value()]),
  ];

  $form['id'] = [
    '#type' => 'value',
    '#value' => $id,
  ];
  $form['user_wrapper'] = [
    '#type' => 'value',
    '#value' => $user_wrapper,
  ];

  return confirm_form(
    $form,
    t('Are you sure to delete the Group?'),
    'groups',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel'));
}

/**
 * Group remove form submit.
 */
function vcard_main_group_remove_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $id = $form_state['values']['id'];
    $user_wrapper = $form_state['values']['user_wrapper'];

    // Remove relations from "user" first.
    foreach ($user_wrapper->field_groups->value() as $key => $item) {
      if ($item->id === $id) {
        $user_wrapper->field_groups[$key]->set(NULL);
        break;
      }
    }
    $user_wrapper->save();

    // Remove vcard entity.
    entity_delete('group', $id);
  }

  _close_ctools_modal_popup($form_state);

  $form_state['redirect'] = 'groups';
}

function vcard_main_group_remove_ajax($id = NULL, $js = NULL) {
  if (!$js) {
    return drupal_get_form('vcard_main_group_remove_form', $id);
  }

  ctools_include('ajax');
  ctools_include('modal');

  $form_state = [
    'ajax' => TRUE,
    'title' => t('Delete group'),
    'build_info' => [
      'args' => [
        $id,
      ],
    ],
  ];

  $output = ctools_modal_form_wrapper('vcard_main_group_remove_form', $form_state);
  print ajax_render($output);
  drupal_exit();
}

/**
 * Helper function closing popup.
 *
 * @param $form_state
 */
function _close_ctools_modal_popup($form_state) {
  if (isset($form_state['ajax']) && $form_state['ajax'] === TRUE) {
    ctools_include('modal');
    ctools_include('ajax');
    ctools_add_js('ajax-responder');

    // Closing the popup.
    $commands[] = ctools_modal_command_dismiss();
    $commands[] = ctools_ajax_command_reload();
    print ajax_render($commands);
    drupal_exit();
  }
}

class GroupEntityController extends EntityAPIController {

  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    global $user;

    $entities = $ids ? $this->load($ids) : FALSE;
    if (!$entities) {
      // Do nothing, in case invalid or no ids have been passed.
      return;
    }
    $group = end($entities);
    if ($group->uid !== $user->uid && !user_access('administer site configuration')) {
      // User can't delete other user's group.
      return;
    }

    return parent::delete($ids, $transaction);
  }
}

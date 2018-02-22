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
  }
  // "Add new group" link.
  $page['entity_view_wrapper']['nano']['content']['add'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'add-entity-wrapper',
    ],
  ];
  $page['entity_view_wrapper']['nano']['content']['add']['link'] = [
    '#type' => 'link',
    '#href' => 'group/add',
    '#title' => 'group_add',
    '#prefix' => '<i class="material-icons">',
    '#suffix' => '</i>',
    '#attributes' => [
      'id' => 'add-new-group',
    ],
  ];
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
  }

  return $form;
}

/**
 * Delivery ajax for "Add new group".
 *
 * @return string
 */
function vcard_main_group_add_ajax() {
  $form = drupal_get_form('vcard_main_group_form');

  return render($form);
}

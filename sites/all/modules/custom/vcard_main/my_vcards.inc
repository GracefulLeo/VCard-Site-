<?php
/**
 * @file
 * Functions for My-VCards functionality.
 */

/**
 * Attach to _entity_page list of VCards and Add button.
 *
 * @param $page
 *
 * @param $user_wrapper
 *
 * @see _entity_page
 */
function _vcard_attach_page_content(&$page, $user_wrapper) {
  $my_vcards = $user_wrapper->field_my_vcards->value();
  if (!empty($my_vcards)) {
    // Sort by "changed", newest first.
    $sorted = [];
    foreach ($my_vcards as $key => $vcard) {
      $sorted[$vcard->changed] = $key;
    }
    krsort($sorted);

    foreach ($sorted as $key) {
      $logo_uri = '';
      if (!empty($my_vcards[$key]->field_logotype)) {
        $logo_uri = $my_vcards[$key]->field_logotype[LANGUAGE_NONE][0]['uri'];
      }

      try {
        $page['entity_list_wrapper']['nano']['entity_list'][] = [
          '#markup' => theme('entity_nano_teaser', [
            'entity_type' => 'vcard',
            'nid' => $my_vcards[$key]->nid,
            'logo_uri' => $logo_uri,
            'title' => $my_vcards[$key]->title,
          ]),
        ];
      } catch (Exception $e) {
        watchdog('theme', 'entity_nano_teaser error: @e', ['@e' => $e]);
      }
    }
  }
  // "Add new VCard" link.
  $page['entity_view_wrapper']['nano']['content']['add'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'add-entity-wrapper',
    ],
  ];
  $page['entity_view_wrapper']['nano']['content']['add']['link'] = [
    '#type' => 'link',
    '#href' => 'my-vcards/add',
    '#title' => 'add',
    '#prefix' => '<i class="material-icons">',
    '#suffix' => '</i>',
  ];
}

/**
 * Delivery ajax for view VCards.
 *
 * @param null $id
 *
 * @return array|mixed
 * @throws \Exception
 */
function vcard_main_vcard_view_ajax($id = NULL) {
  global $user;

  if (is_numeric($id)) {
    $vcard_node = node_load($id);
    if ($user->uid && $vcard_node) {
      // Check is user author of vcard.
      $editable = FALSE;
      if ($user->uid === $vcard_node->uid) {
        $editable = TRUE;
      }

      return theme('vcard_details_view', [
        'node' => $vcard_node,
        'editable' => $editable,
      ]);
    }
  }

  return FALSE;
}

/**
 * Page callback for add, edit and clone VCards.
 *
 * @param $form
 * @param $form_state
 * @param integer|null $id
 *  VCard existing entity id.
 * @param string|null $op
 *  'edit'
 *  'clone'
 *
 * @return mixed
 */
function vcard_main_my_vcard_form($form, &$form_state, $id = NULL, $op = NULL) {
  global $user;

  // Show elements for authorized users only.
  if ($user->uid) {

    if (is_numeric($id)) {
      $vcard_node = node_load($id);
      if ($user->name !== $vcard_node->name) {
        drupal_not_found();
        drupal_exit();
      }
      if ($op == 'clone') {
        $vcard_node = clone $vcard_node;
        $vcard_node->is_new = TRUE;
        unset($vcard_node->nid);
        unset($vcard_node->vid);
      }
    }
    else {
      $values = [
        'type' => 'vcard',
        'uid' => $user->uid,
        'status' => 1,
        'comment' => 0,
        'promote' => 0,
      ];
      $vcard_node = entity_create('node', $values);
    }

    field_attach_form('node', $vcard_node, $form, $form_state);

    // Extra field for node title property.
    $form['title'] = [
      '#type' => 'textfield',
      '#default_value' => isset($vcard_node->title) ? $vcard_node->title : '',
      '#weight' => -1,
      '#attributes' => [
        'placeholder' => t('VCard name (visible only to you)'),
      ],
    ];

    $form['node'] = [
      '#type' => 'value',
      '#value' => $vcard_node,
    ];

    $form['submit'] = [
      '#type' => 'submit',
      '#value' => t('Save'),
      '#weight' => 100,
      '#attributes' => [
        'id' => 'my-vcard-form-submit',
      ],
    ];

    // Alter fields.
    foreach ($form as $name => &$item) {
      if (strstr($name, 'field_')) {
        if (in_array($item[LANGUAGE_NONE]['#field_name'], [
          'field_phone',
          'field_mail',
        ])) {
          foreach ($item[LANGUAGE_NONE] as $key => &$value) {
            if (!is_numeric($key)) {
              continue;
            }

            // Set placeholders.
            $value_key = $item[LANGUAGE_NONE]['#field_name'] === 'field_mail' ? 'email' : 'value';
            $value[$value_key]['#attributes']['placeholder'] = $item[LANGUAGE_NONE]['#title'];

            // Remove useless weights.
            unset($value['_weight']);
          }
          // Change "add_more" text.
          $item[LANGUAGE_NONE]['add_more']['#value'] = 'add';
          $item[LANGUAGE_NONE]['add_more']['#prefix'] = '<i class="material-icons">';
          $item[LANGUAGE_NONE]['add_more']['#suffix'] = '</i>';
          $item[LANGUAGE_NONE]['add_more']['#weight'] = DRUPAL_WEIGHT_SELECT_MAX;
        }
        elseif (isset($item['#attributes']['class']) && in_array('field-type-text', $item['#attributes']['class'])) {
          // Hide titles and set placeholders.
          $item[LANGUAGE_NONE][0]['value']['#title_display'] = 'invisible';
          $item[LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = $item[LANGUAGE_NONE]['#title'];
        }
      }
    }

    $form['#attached'] = [
      'js' => [
        drupal_get_path('module', 'vcard_main') . '/js/field_logotype.js',
        drupal_get_path('module', 'vcard_main') . '/js/jquery.validate.min.js',
      ],
    ];
    $form['#validate'][] = 'vcard_main_my_vcard_form_validation';
    $form['#submit'][] = 'vcard_main_my_vcard_form_submit';
    $form['#theme'] = ['my_vcard_form'];
  }

  return $form;
}

/**
 * "My VCard" page form validation.
 */
function vcard_main_my_vcard_form_validation($form, &$form_state) {
  field_attach_form_validate('node', $form_state['values']['node'], $form, $form_state);
  node_validate($form_state['values']['node'], $form, $form_state);
}

/**
 * "My VCard" page form submit.
 */
function vcard_main_my_vcard_form_submit($form, &$form_state) {
  // Save VCard entity.
  $vcard_node = $form_state['values']['node'];
  field_attach_submit('node', $vcard_node, $form, $form_state);
  $vcard_node = node_submit($vcard_node);
  try {
    node_save($vcard_node);
  } catch (Exception $e) {
    watchdog('vcard_main_my_vcard_form_submit', '<pre>@e</pre>', ['@e' => print_r($e, TRUE)]);
  }

  // Set surname, name and middle name as node title.
  $vcard_wrapper = entity_metadata_wrapper('node', $vcard_node);
  // Set title to node.
  $title = 'VCard #' . $vcard_node->nid;
  if (!empty($form_state['values']['title'])) {
    $title = $form_state['values']['title'];
  }
  $vcard_wrapper->title->set($title);
  $vcard_wrapper->save();

  // Save relations to user.
  _user_entityreference_field_save('field_my_vcards', $vcard_node->nid);

  drupal_goto('my-vcards');
}

/**
 * Page callback for deleting VCards.
 */
function vcard_main_my_vcard_form_remove($form, &$form_state, $id) {
  global $user;

  $wrapper = entity_metadata_wrapper('node', $id);

  if ($user->name !== $wrapper->value()->name) {
    drupal_not_found();
    drupal_exit();
  }

  $form['image'] = node_view(node_load($id), 'image');

  $form['id'] = [
    '#type' => 'value',
    '#value' => $id,
  ];
  return confirm_form(
    $form,
    t('Are you sure to delete the VCard?'),
    'my-vcards',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel'));
}

/**
 * VCard remove form submit.
 */
function vcard_main_my_vcard_form_remove_submit($form, &$form_state) {
  global $user;

  if ($form_state['values']['confirm']) {
    $id = $form_state['values']['id'];

    // Remove relations from "user" first.
    $wrapper = entity_metadata_wrapper('user', $user);
    foreach ($wrapper->field_my_vcards->value() as $key => $item) {
      if ($item->nid == $id) {
        $wrapper->field_my_vcards[$key]->set(NULL);
        break;
      }
    }
    $wrapper->save();

    // Remove vcard entity.
    node_delete($id);
  }

  $form_state['redirect'] = 'my-vcards';
}

/**
 * Title callback for My VCard operations.
 *
 * @param $op
 *  Edit or Clone.
 *
 * @return string
 */
function vcard_main_my_vcard_form_edit_title($op) {
  return t('@op VCard', ['@op' => $op == 'edit' ? 'Edit' : 'Add']);
}

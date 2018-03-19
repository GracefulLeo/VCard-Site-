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
        // @todo We can remove it from vcard_details_view theme and template.
        'editable' => FALSE,
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

    $social_links_values = FALSE;
    if (isset($vcard_node->field_social_links) && !empty($vcard_node->field_social_links)) {
      $social_links_values = json_decode($vcard_node->field_social_links[LANGUAGE_NONE][0]['value']);
    }
    // Social links.
    $form['social'] = [
      '#type' => 'fieldset',
      '#title' => t('Social links'),
      '#weight' => 15,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      '#attributes' => [
        'class' => ['social-fieldset'],
      ],
    ];
    $form['social']['facebook'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Facebook'),
      ],
      '#field_prefix' => '<span class="service service-facebook"><i class="icon icon-facebook"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->facebook : '',
    ];
    $form['social']['twitter'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Twitter'),
      ],
      '#field_prefix' => '<span class="service service-twitter"><i class="icon icon-twitter"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->twitter : '',
    ];
    $form['social']['google_plus'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Google+'),
      ],
      '#field_prefix' => '<span class="service service-googleplus"><i class="icon icon-gplus"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->google_plus : '',
    ];
    $form['social']['linkedin'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('LinkedIn'),
      ],
      '#field_prefix' => '<span class="service service-linkedin"><i class="icon icon-linkedin"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->linkedin : '',
    ];
    $form['social']['youtube'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('YouTube'),
      ],
      '#field_prefix' => '<span class="service service-youtube"><i class="icon icon-youtube"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->youtube : '',
    ];
    $form['social']['instagram'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Instagram'),
      ],
      '#field_prefix' => '<span class="service service-instagram"><i class="icon icon-instagram"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->instagram : '',
    ];
    $form['social']['vk'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('VKontakte'),
      ],
      '#field_prefix' => '<span class="service service-vk"><i class="icon icon-vkontakte"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->social->vk : '',
    ];

    // Messengers fieldset.
    $form['messengers'] = [
      '#type' => 'fieldset',
      '#title' => t('Messengers'),
      '#weight' => 16,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      '#attributes' => [
        'class' => ['social-fieldset'],
      ],
    ];
    $form['messengers']['skype'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Skype'),
      ],
      '#field_prefix' => '<span class="service service-skype"><i class="icon icon-skype"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->messengers->skype : '',
    ];
    $form['messengers']['viber'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Viber'),
      ],
      '#field_prefix' => '<span class="service service-viber"><i class="icon icon-phone-circled"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->messengers->viber : '',
    ];
    $form['messengers']['whatsapp'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('WhatsApp'),
      ],
      '#field_prefix' => '<span class="service service-whatsapp"><i class="icon icon-whatsapp"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->messengers->whatsapp : '',
    ];
    $form['messengers']['telegram'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Telegram'),
      ],
      '#field_prefix' => '<span class="service service-telegram"><i class="icon icon-telegram"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->messengers->telegram : '',
    ];
    $form['messengers']['fb_messenger'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => t('Facebook messenger'),
      ],
      '#field_prefix' => '<span class="service service-messenger"><i class="icon icon-chat"></i></span>',
      '#default_value' => $social_links_values ? $social_links_values->messengers->fb_messenger : '',
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
            $value['value']['#attributes']['placeholder'] = $item[LANGUAGE_NONE]['#title'];

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
  $vcard_node = $form_state['values']['node'];
  // Save to variable old node and check for changes after VCard update.
  $old_node = isset($vcard_node->nid) ? node_load($vcard_node->nid) : FALSE;

  // Save VCard entity.
  field_attach_submit('node', $vcard_node, $form, $form_state);
  $vcard_node = node_submit($vcard_node);

  $vcard_node->field_social_links[LANGUAGE_NONE][0]['value'] = json_encode([
    'social' => $form_state['values']['social'],
    'messengers' => $form_state['values']['messengers'],
  ]);

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


  // Look for changes on edited VCards.
  if ($old_node) {
    $history = new History();
    $history->setPerson($vcard_wrapper->field_surname->value() . ' ' . $vcard_wrapper->field_name->value());
    $history->setVCardID($vcard_wrapper->nid->value());

    foreach ($old_node as $field_name => $item) {
      if ($field_name !== 'field_base64_vcard' && strstr($field_name, 'field_')) {
        $value_type = $field_name === 'field_logotype' ? 'fid' : 'value';

        // Collect data from fields for comparison.
        $old = $new = [];
        if (!empty($item)) {
          foreach ($item[LANGUAGE_NONE] as $value) {
            $old[] = $value[$value_type];
          }
        }
        if (!empty($vcard_node->{$field_name}[LANGUAGE_NONE])) {
          foreach ($vcard_node->{$field_name}[LANGUAGE_NONE] as $value) {
            $new[] = $value[$value_type];
          }
        }

        if ($old != $new) {
          $history->{$field_name}($old, $new);
        }
      }
    }

    $history->save();
  }


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

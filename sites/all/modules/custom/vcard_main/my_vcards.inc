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

  $page['entity_list_wrapper']['nano']['entity_list'][] = drupal_get_form('vcard_main_build_list_items_form', $my_vcards);

  // "Add new VCard" link.
  $page['entity_view_wrapper']['nano']['content']['view']['add'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'add-entity-wrapper',
    ],
  ];
  $page['entity_view_wrapper']['nano']['content']['view']['add']['link'] = [
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
    $vcard_entity = entity_load_single('vcard', $id);
    if ($user->uid && $vcard_entity) {
      return theme('vcard_details_view', [
        'vcard' => $vcard_entity,
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
      $vcard_entity = entity_load_single('vcard', $id);
      if ((int) $user->uid !== (int) $vcard_entity->uid) {
        drupal_not_found();
        drupal_exit();
      }
      if ($op == 'clone') {
        module_load_include('inc', 'entity', 'includes/entity.ui');
        $vcard_entity = entity_ui_clone_entity('vcard', $vcard_entity);
        unset($vcard_entity->id);
        unset($vcard_entity->uid);
        unset($vcard_entity->created);
        unset($vcard_entity->changed);
      }
    }
    else {
      $vcard_entity = entity_create('vcard', ['type' => 'vcard']);
    }

    // Attach field logotype to container at first, it works with other custom
    // fields weights.
    $form['logo'] = [
      '#type' => 'container',
      '#weigth' => 0,
    ];
    field_attach_form('vcard', $vcard_entity, $form['logo'], $form_state);

    // Build form fields.
    $properties = [
      'title' => t('VCard name (visible only to you)'),
      'surname' => t('Surname'),
      'name' => t('Name'),
      'middle_name' => t('Middle name'),
      'company' => t('Company'),
      'address' => t('Address'),
      'position' => t('Position'),
      'web_site' => t('Web site'),
      'phone' => t('Phone'),
      'email' => t('E-mail'),
    ];
    // Build fields to accordance with properties.
    _form_build_properties($form, $vcard_entity, $properties);
    $form['title']['#weight'] = -1;
    $form['base64_vcard'] = [
      '#type' => 'hidden',
      '#default_value' => isset($vcard_entity->base64_vcard) ? $vcard_entity->base64_vcard : '',
      '#attributes' => [
        'id' => 'base64-vcard',
      ],
    ];

    $form['vcard_entity'] = [
      '#type' => 'value',
      '#value' => $vcard_entity,
    ];

    $social_links_values = FALSE;
    if (isset($vcard_entity->social_links) && !empty($vcard_entity->social_links)) {
      $social_links_values = json_decode($vcard_entity->social_links);
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
    $form['social'][FACEBOOK] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => FACEBOOK,
      ],
      '#field_prefix' => '<span class="service service-facebook"><i class="icon icon-facebook"></i></span>',
      '#default_value' => isset($social_links_values->{FACEBOOK}) ? $social_links_values->{FACEBOOK} : '',
    ];
    $form['social'][TWITTER] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => TWITTER,
      ],
      '#field_prefix' => '<span class="service service-twitter"><i class="icon icon-twitter"></i></span>',
      '#default_value' => isset($social_links_values->{TWITTER}) ? $social_links_values->{TWITTER} : '',
    ];
    $form['social'][GOOGLE_PLUS] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => GOOGLE_PLUS,
      ],
      '#field_prefix' => '<span class="service service-googleplus"><i class="icon icon-gplus"></i></span>',
      '#default_value' => isset($social_links_values->{GOOGLE_PLUS}) ? $social_links_values->{GOOGLE_PLUS} : '',
    ];
    $form['social'][LINKEDIN] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => LINKEDIN,
      ],
      '#field_prefix' => '<span class="service service-linkedin"><i class="icon icon-linkedin"></i></span>',
      '#default_value' => isset($social_links_values->{LINKEDIN}) ? $social_links_values->{LINKEDIN} : '',
    ];
    $form['social'][YOUTUBE] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => YOUTUBE,
      ],
      '#field_prefix' => '<span class="service service-youtube"><i class="icon icon-youtube"></i></span>',
      '#default_value' => isset($social_links_values->{YOUTUBE}) ? $social_links_values->{YOUTUBE} : '',
    ];
    $form['social'][INSTAGRAM] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => INSTAGRAM,
      ],
      '#field_prefix' => '<span class="service service-instagram"><i class="icon icon-instagram"></i></span>',
      '#default_value' => isset($social_links_values->{INSTAGRAM}) ? $social_links_values->{INSTAGRAM} : '',
    ];
    $form['social'][VKONTAKTE] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => VKONTAKTE,
      ],
      '#field_prefix' => '<span class="service service-vk"><i class="icon icon-vkontakte"></i></span>',
      '#default_value' => isset($social_links_values->{VKONTAKTE}) ? $social_links_values->{VKONTAKTE} : '',
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
    $form['messengers'][SKYPE] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => SKYPE,
      ],
      '#field_prefix' => '<span class="service service-skype"><i class="icon icon-skype"></i></span>',
      '#default_value' => isset($social_links_values->{SKYPE}) ? $social_links_values->{SKYPE} : '',
    ];
    $form['messengers'][VIBER] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => VIBER,
      ],
      '#field_prefix' => '<span class="service service-viber"><i class="icon icon-phone-circled"></i></span>',
      '#default_value' => isset($social_links_values->{VIBER}) ? $social_links_values->{VIBER} : '',
    ];
    $form['messengers'][WHATSAPP] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => WHATSAPP,
      ],
      '#field_prefix' => '<span class="service service-whatsapp"><i class="icon icon-whatsapp"></i></span>',
      '#default_value' => isset($social_links_values->{WHATSAPP}) ? $social_links_values->{WHATSAPP} : '',
    ];
    $form['messengers'][TELEGRAM] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => TELEGRAM,
      ],
      '#field_prefix' => '<span class="service service-telegram"><i class="icon icon-telegram"></i></span>',
      '#default_value' => isset($social_links_values->{TELEGRAM}) ? $social_links_values->{TELEGRAM} : '',
    ];
    $form['messengers'][MESSENGER] = [
      '#type' => 'textfield',
      '#attributes' => [
        'placeholder' => MESSENGER,
      ],
      '#field_prefix' => '<span class="service service-messenger"><i class="icon icon-chat"></i></span>',
      '#default_value' => isset($social_links_values->{MESSENGER}) ? $social_links_values->{MESSENGER} : '',
    ];

    $form['submit'] = [
      '#type' => 'submit',
      '#value' => t('Save'),
      '#weight' => 100,
      '#attributes' => [
        'id' => 'my-vcard-form-submit',
      ],
    ];

    $form['#attached'] = [
      'js' => [
        drupal_get_path('module', 'vcard_main') . '/js/field_logotype.js',
        drupal_get_path('module', 'vcard_main') . '/js/jquery.validate.min.js',
      ],
    ];
    $form['#theme'] = ['my_vcard_form'];
  }

  return $form;
}

/**
 * "My VCard" page form validation.
 */
function vcard_main_my_vcard_form_validation($form, &$form_state) {
  field_attach_form_validate('vcard', $form_state['values']['vcard_entity'], $form, $form_state);
}

/**
 * "My VCard" page form submit.
 */
function vcard_main_my_vcard_form_submit($form, &$form_state) {
  global $user;

  $vcard_entity = $form_state['values']['vcard_entity'];
  // Save to variable old entity and check for changes after VCard update.
  $old_vcard = isset($vcard_entity->id) ? entity_load_single('vcard', $vcard_entity->id) : FALSE;

  // Save VCard entity.
  field_attach_submit('vcard', $vcard_entity, $form, $form_state);
  $vcard_wrapper = entity_metadata_wrapper('vcard', $vcard_entity);

  // Save values to properties.
  foreach ($form_state['values'] as $property => $value) {
    if ($vcard_wrapper->__isset($property) && $property !== 'field_logotype') {
      $vcard_wrapper->{$property}->set($value);
    }
  }

  // Set title to vcard.
  if (!empty($form_state['values']['title'])) {
    $title = $form_state['values']['title'];
  }
  else {
    $user_wrapper = entity_metadata_wrapper('user', $user);
    $title = 'VCard #' . ((int) count($user_wrapper->field_my_vcards->value()) + 1);
  }
  $vcard_wrapper->title->set($title);
  $vcard_wrapper->social_links->set(json_encode(
    $form_state['values']['social'] + $form_state['values']['messengers']
  ));
  if (empty($vcard_wrapper->uuid->value())) {
    $vcard_wrapper->uuid->set(generate_uuid());
  }
  $vcard_wrapper->token->set($user->last_login_token);
  $vcard_wrapper->save();

  // Save relations to user.
  _user_entityreference_field_save('field_my_vcards', $vcard_entity->id);


  // Look for changes on edited VCards.
  if ($old_vcard) {
    $history = new History();
    $history->setVCardID($vcard_wrapper->id->value());

    foreach ($old_vcard as $field_name => $item) {
      if ($field_name === 'field_logotype') {
        $old = !empty($old_vcard->field_logotype[LANGUAGE_NONE]) ? $old_vcard->field_logotype[LANGUAGE_NONE][0]['fid'] : '';
        $new = !empty($vcard_entity->field_logotype[LANGUAGE_NONE]) ? $vcard_entity->field_logotype[LANGUAGE_NONE][0]['fid'] : '';
      }
      else {
        $old = $old_vcard->{$field_name};
        $new = $vcard_entity->{$field_name};
      }

      if ($old !== $new) {
        $history->{$field_name}($old, $new);
      }
    }

    $history_id = $history->save()->id;

    // Get user ids who has this VCard in contacts.
    $referenced_user_ids = db_select('field_data_field_my_contacts', 'c')
      ->fields('c', ['entity_id'])
      ->condition('field_my_contacts_target_id', $vcard_entity->id)
      ->execute()
      ->fetchAllKeyed(0, 0);

    // Save to users (who has this VCard) to "field_history" history just created.
    foreach ($referenced_user_ids as $user_id) {
      _user_entityreference_field_save('field_history', $history_id, $user_id);
    }
  }


  drupal_goto('my-vcards');
}

/**
 * Page callback for deleting VCards.
 */
function vcard_main_my_vcard_form_remove($form, &$form_state, $id) {
  global $user;

  $vcard_entity = entity_load_single('vcard', $id);

  if ((int) $user->uid !== (int) $vcard_entity->uid) {
    drupal_not_found();
    drupal_exit();
  }

  $form['container'] = [
    '#type' => 'container',
  ];
  $form['container']['image'] = [
    '#markup' => '<img src="' . $vcard_entity->base64_vcard . '"/>',
  ];

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
      if ($item->id == $id) {
        $wrapper->field_my_vcards[$key]->set(NULL);
        break;
      }
    }
    $wrapper->save();

    // Remove vcard entity.
    entity_delete('vcard', $id);
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

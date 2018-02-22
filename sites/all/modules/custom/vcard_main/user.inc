<?php
/**
 * @file
 * Functions for Logout functionality.
 */

/**
 * "Log Out" page callback.
 */
function vcard_main_logout() {
  module_load_include('inc', 'user', 'user.pages');
  user_logout();
}

/**
 * Implements hook_block_view_alter().
 */
function vcard_main_block_view_alter(&$data, $block) {
  switch ($block->delta) {
    case 'login':
      // Remove unnecessary title.
      unset($data['subject']);
      // Set link after "Log in" button.
      $data['content']['links']['#weight'] = 101;
      // Hide unnecessary links.
      $data['content']['links']['#access'] = FALSE;
      // Set google button on the top of block.
      $data['content']['submit_google']['#weight'] = -1;
      break;
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function vcard_main_form_user_login_block_alter(&$form, &$form_state) {
  $form['name']['#title_display'] = 'invisible';
  $form['name']['#attributes'] = ['placeholder' => t('E-mail')];
  $form['pass']['#title_display'] = 'invisible';
  $form['pass']['#attributes'] = ['placeholder' => t('Password')];
}

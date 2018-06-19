<?php
/**
 * @file
 * Functions for History functionality.
 */

/**
 * "History" page callback.
 */
function vcard_main_history_form($form, &$form_state) {
  return $form;
}

class History {

  private $entity;

  private $count = 0;

  private $fields;

  public function __construct() {
    $entity = entity_create('history', ['type' => 'history']);
    $this->entity = entity_metadata_wrapper('history', $entity);
  }

  public function setVCardID($id) {
    if (is_numeric($id)) {
      $this->entity->vcard_id = (int) $id;
    }
  }

  public function field_logotype($from, $to) {
    $content = FALSE;
    if ($to) {
      $file = file_load($to);
      $image = image_load($file->uri);
      $content = [
        'file' => [
          '#theme' => 'image_style',
          '#style_name' => 'thumbnail',
          '#path' => $image->source,
          '#width' => $image->info['width'],
          '#height' => $image->info['height'],
        ],
      ];
    }
    $this->fields['field_logotype'] = [
      'label' => t('logotype'),
      'from' => '',
      'to' => $content ? drupal_render($content) : '',
    ];
    $this->count++;
  }

  public function surname($from, $to) {
    $this->fields['surname'] = [
      'label' => t('last name'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function name($from, $to) {
    $this->fields['name'] = [
      'label' => t('name'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function middle_name($from, $to) {
    $this->fields['middle_name'] = [
      'label' => t('middle name'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function company($from, $to) {
    $this->fields['company'] = [
      'label' => t('company'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function address($from, $to) {
    $this->fields['address'] = [
      'label' => t('address'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function position($from, $to) {
    $this->fields['position'] = [
      'label' => t('position'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function web_site($from, $to) {
    $this->fields['web_site'] = [
      'label' => t('web site'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function phone($from, $to) {
    $this->fields['phone'] = [
      'label' => t('phone number'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function email($from, $to) {
    $this->fields['mail'] = [
      'label' => t('e-mail'),
      'from' => $from,
      'to' => $to,
    ];
    $this->count++;
  }

  public function social_links($from, $to) {
    $from = (array) json_decode($from);
    $to = (array) json_decode($to);

    $keys = array_keys(array_diff_assoc($from, $to));
    foreach ($keys as $key) {
      $this->fields[$key] = [
        'label' => $key,
        'from' => check_plain($from[$key]),
        'to' => check_plain($to[$key]),
      ];
      $this->count++;
    }
  }

  public function save() {
    if ($this->count) {
      $this->entity->body_teaser->set($this->buildBodyTeaser());
      $this->entity->full_body->set($this->buildFullBody());
      $this->entity->save();

      return $this->entity->value();
    }
  }

  private function buildBodyTeaser() {
    return t('Changed !fields', [
      '!fields' => format_plural($this->count, self::wrapText('1') . ' field', self::wrapText('@count') . ' fields'),
    ]);
  }

  private function buildFullBody() {
    $output = '';

    foreach ($this->fields as $field) {
      $output .= '<p>';
      if (empty($field['to'])) {
        $output .= t('Deleted !label: !from', [
          '!label' => self::wrapText($field['label']),
          '!from' => self::wrapText($field['from']),
        ]);
      }
      elseif (empty($field['from'])) {
        $output .= t('Added !label: !to', [
          '!label' => self::wrapText($field['label']),
          '!to' => self::wrapText($field['to']),
        ]);
      }
      else {
        $output .= t('Changed !label from !from to !to', [
          '!label' => self::wrapText($field['label']),
          '!from' => self::wrapText($field['from']),
          '!to' => self::wrapText($field['to']),
        ]);
      }
      $output .= '</p>';
    }

    return $output;
  }

  private static function wrapText($s) {
    return "<span class='history-blue-text'>$s</span>";
  }

  /**
   * Empty __call() for ignoring calls of nonexistent methods.
   */
  public function __call($name, $arguments) {
  }
}

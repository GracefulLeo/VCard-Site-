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
    $this->fields['field_logotype'] = [
      'label' => t('logotype'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_surname($from, $to) {
    $this->fields['field_surname'] = [
      'label' => t('last name'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_name($from, $to) {
    $this->fields['field_name'] = [
      'label' => t('name'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_middle_name($from, $to) {
    $this->fields['field_middle_name'] = [
      'label' => t('middle name'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_company_name($from, $to) {
    $this->fields['field_company_name'] = [
      'label' => t('company'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_address($from, $to) {
    $this->fields['field_address'] = [
      'label' => t('address'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_position($from, $to) {
    $this->fields['field_position'] = [
      'label' => t('position'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_web_site($from, $to) {
    $this->fields['field_web_site'] = [
      'label' => t('web site'),
      'from' => is_array($from) ? end($from) : $from,
      'to' => is_array($to) ? end($to) : $to,
    ];
    $this->count++;
  }

  public function field_phone($from, $to) {
    $this->fields['field_phone'] = [
      'label' => format_plural(min(count($from), count($to)), 'phone number', 'phone numbers'),
      'from' => implode(', ', $from),
      'to' => implode(', ', $to),
    ];
    $this->count++;
  }

  public function field_mail($from, $to) {
    $this->fields['field_mail'] = [
      'label' => format_plural(min(count($from), count($to)), 'e-mail', 'e-mails'),
      'from' => implode(', ', $from),
      'to' => implode(', ', $to),
    ];
    $this->count++;
  }

  // @todo
  public function field_social_links($from, $to) {

    $this->count++;
  }

  public function save() {
    if ($this->count) {
      $this->entity->body_teaser->set($this->buildBodyTeaser());
      $this->entity->full_body->set($this->buildFullBody());
      $this->entity->save();
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
      if (empty($field['from'])) {
        $output .= t('Added !label: !to', [
          '!label' => self::wrapText($field['label']),
          '!to' => self::wrapText($field['to']),
        ]);
      }
      elseif (empty($field['to'])) {
        $output .= t('Deleted !label: !from', [
          '!label' => self::wrapText($field['label']),
          '!from' => self::wrapText($field['from']),
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
}

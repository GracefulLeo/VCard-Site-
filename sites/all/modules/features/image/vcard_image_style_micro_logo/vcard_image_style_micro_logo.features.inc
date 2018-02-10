<?php
/**
 * @file
 * vcard_image_style_micro_logo.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function vcard_image_style_micro_logo_image_default_styles() {
  $styles = array();

  // Exported image style: micro_logo.
  $styles['micro_logo'] = array(
    'label' => 'Micro logo',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 64,
          'height' => 64,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

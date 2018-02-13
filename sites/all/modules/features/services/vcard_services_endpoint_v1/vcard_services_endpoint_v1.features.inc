<?php
/**
 * @file
 * vcard_services_endpoint_v1.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vcard_services_endpoint_v1_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

<?php
/**
 * @file
 * vista_map.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vista_map_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_google_delay';
  $strongarm->value = '200';
  $export['geocoder_google_delay'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'leaflet_more_maps_custom_maps';
  $strongarm->value = array(
    1 => array(
      'map-key' => 'Bing Hybrid',
      'layer-keys' => array(
        'bing hybrid layer' => 'bing hybrid layer',
      ),
      'reverse-order' => 0,
    ),
    2 => array(
      'map-key' => '',
      'layer-keys' => array(),
      'reverse-order' => 0,
    ),
    3 => array(
      'map-key' => '',
      'layer-keys' => array(),
      'reverse-order' => 0,
    ),
  );
  $export['leaflet_more_maps_custom_maps'] = $strongarm;

  return $export;
}

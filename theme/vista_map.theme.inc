<?php
/**
 * @file
 * Default theme implementations for the map feature..
 */

/**
* Implements hook_theme.
*/
function vista_map_theme($exitsting, $type, $theme, $path) {
  $registry = array();
  $tpl_dir = drupal_get_path('module', 'vista_map') . '/theme';

  // Map icon key.
  $registry['vista_map_icon_key'] = array(
    'variables' => array('key_data' => NULL),
    'template' => 'vista-map-icon-key',
    'path' => $tpl_dir,
  );

  return $registry;
}

/**
 * Implements hook_preprocess_views_views_json_style_simple().
 *
 * Note the naming convention has been violated by views_datasource,
 * thus the hook name is _views_views_ intstead of _views_view_.
 *
 * Adding logic similar to bedrock views to show anonymous user a default
 * profile picture when access to the profile image field is denied.
 *
 * @see vista_profiles_preprocess_bedrock_views_view_fields
 */
function vista_map_preprocess_views_views_json_style_simple(&$vars) {
  $view = $vars['view'];

  // Make sure this is a map popup feed, and that we have user-based view.
  if (($view->name == 'vista_map_popup_feeds') && ($view->base_table == 'users')) {

    // Views datasource delivers all rows at once since it is a JSON feed.
    if (isset($vars['rows']['nodes'])) {

      // Grab the default profile placeholder URI and get a URL to the
      // image style of choice. The JS that consumes this feed renders
      // DOM elements out of the feed contents, i.e we don't want to
      // directly render it, just the the path to the image.
      $default_item = _vista_profiles_get_default_profile_image();
      $display_photo_url = image_style_url('media_thumbnail',
        $default_item['#items'][0]['uri']
      );

      for ($i = 0; $i < count($vars['rows']['nodes']); $i++) {
        // If the profile image field is missing from the row (node),
        // it will just be omitted. Just add it back.
        if (!isset($vars['rows']['nodes'][$i]['userinfo']['field_profile_photo'])) {
          $vars['rows']['nodes'][$i]['userinfo']['field_profile_photo']
            = $display_photo_url;
        }
      }
    }
  }
}

<?php
/**
 * @file
 * vista_map.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function vista_map_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'mapped_user_listing';
  $page->task = 'page';
  $page->admin_title = 'Mapped User Listing';
  $page->admin_description = '';
  $page->path = 'mapped-users/%title/!uids/!grouptitle';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'title' => array(
      'id' => 1,
      'identifier' => 'title',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'uids' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
    'grouptitle' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_mapped_user_listing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'mapped_user_listing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'slate';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%title:html_safe';
  $display->uuid = '682f19f1-8f1f-453a-9fd0-944ecf588043';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-04cb4b8d-7012-41ff-927c-b31d9ca9c447';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'vista_map_popup_feeds-panel_pane_mapped_users';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '%title',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '04cb4b8d-7012-41ff-927c-b31d9ca9c447';
    $display->content['new-04cb4b8d-7012-41ff-927c-b31d9ca9c447'] = $pane;
    $display->panels['main_content'][0] = 'new-04cb4b8d-7012-41ff-927c-b31d9ca9c447';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['mapped_user_listing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'vista_map';
  $page->task = 'page';
  $page->admin_title = 'VISTA Map';
  $page->admin_description = '';
  $page->path = 'map';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Map',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_vista_map_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'vista_map';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'slate';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_header_left' => NULL,
      'content_header_right' => NULL,
      'content_main' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer_left' => NULL,
      'content_footer_right' => NULL,
      'main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c679a064-eb0b-4e9f-87db-4263c335abc3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-60b58e13-8f5c-4149-ab64-41f50023cce0';
    $pane->panel = 'main_content';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:86';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '60b58e13-8f5c-4149-ab64-41f50023cce0';
    $display->content['new-60b58e13-8f5c-4149-ab64-41f50023cce0'] = $pane;
    $display->panels['main_content'][0] = 'new-60b58e13-8f5c-4149-ab64-41f50023cce0';
    $pane = new stdClass();
    $pane->pid = 'new-811d7862-5058-49db-936c-1a9c9750d73e';
    $pane->panel = 'main_content';
    $pane->type = 'block';
    $pane->subtype = 'views-33985972dad8bc76f4be61360dd9d02e';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 1,
      'override_title_text' => 'Filters',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '811d7862-5058-49db-936c-1a9c9750d73e';
    $display->content['new-811d7862-5058-49db-936c-1a9c9750d73e'] = $pane;
    $display->panels['main_content'][1] = 'new-811d7862-5058-49db-936c-1a9c9750d73e';
    $pane = new stdClass();
    $pane->pid = 'new-bc67bec5-3961-4dd3-aa54-cdb38d062fcc';
    $pane->panel = 'main_content';
    $pane->type = 'block';
    $pane->subtype = 'vista_map-vista_map_icon_key';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => 'Legend',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bc67bec5-3961-4dd3-aa54-cdb38d062fcc';
    $display->content['new-bc67bec5-3961-4dd3-aa54-cdb38d062fcc'] = $pane;
    $display->panels['main_content'][2] = 'new-bc67bec5-3961-4dd3-aa54-cdb38d062fcc';
    $pane = new stdClass();
    $pane->pid = 'new-e24958f3-6747-4e87-9099-af4ec9c3ec4a';
    $pane->panel = 'main_content';
    $pane->type = 'leaflet_geojson.map_pane';
    $pane->subtype = 'leaflet_geojson.map_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'map_settings' => array(
        'base' => 'esri-world_topo_map',
        'info' => array(
          'data' => array(
            'leaflet_1' => 'vista_map_data_feeds_map_feed_alumni',
            'leaflet_2' => 'vista_map_data_feeds_map_feed_active',
          ),
          'add_layer' => 'Add another layer',
          'remove_layer' => 'Remove last layer',
        ),
        'height' => '675',
        'override_zoom_center' => 1,
        'custom_zoom_center' => array(
          'zoom' => '4',
          'center' => array(
            'lon' => '-98',
            'lat' => '39',
          ),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e24958f3-6747-4e87-9099-af4ec9c3ec4a';
    $display->content['new-e24958f3-6747-4e87-9099-af4ec9c3ec4a'] = $pane;
    $display->panels['main_content'][3] = 'new-e24958f3-6747-4e87-9099-af4ec9c3ec4a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['vista_map'] = $page;

  return $pages;

}

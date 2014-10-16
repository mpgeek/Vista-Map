<?php
/**
 * @file
 * vista_map.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vista_map_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vista_map_data_feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Vista Map Data Feeds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Map Popup: Single Active User';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'geocluster_lat';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'geocluster_lon';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_profile_location';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_profile_location';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'name';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: Content: Geocluster lat (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_lat']['id'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_lat']['field'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['relationship'] = 'profile';
  $handler->display->display_options['fields']['geocluster_lat']['element_type'] = '0';
  $handler->display->display_options['fields']['geocluster_lat']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['geocluster_lat']['element_default_classes'] = FALSE;
  /* Field: Content: Geocluster lon (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_lon']['id'] = 'geocluster_lon';
  $handler->display->display_options['fields']['geocluster_lon']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_lon']['field'] = 'geocluster_lon';
  /* Field: Content: Geocluster result count (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_count']['id'] = 'geocluster_count';
  $handler->display->display_options['fields']['geocluster_count']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_count']['field'] = 'geocluster_count';
  /* Contextual filter: Custom: Bounding box */
  $handler->display->display_options['arguments']['bbox_argument']['id'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['table'] = 'views';
  $handler->display->display_options['arguments']['bbox_argument']['field'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['bbox_argument']['default_argument_type'] = 'querystring';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bbox_argument']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: User type (og_user_node) */
  $handler->display->display_options['filters']['og_user_node_target_id']['id'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_user_node_target_id']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['value'] = array(
    19 => '19',
    17 => '17',
    15 => '15',
    16 => '16',
  );
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator_id'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['label'] = 'User type (og_user_node)';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['identifier'] = 'og_user_node_target_id';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Profile: Show location on the VISTA map? (field_show_location) */
  $handler->display->display_options['filters']['field_show_location_value']['id'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['table'] = 'field_data_field_show_location';
  $handler->display->display_options['filters']['field_show_location_value']['field'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_show_location_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Field: Focus area (field_focus_area) */
  $handler->display->display_options['filters']['field_focus_area_tid']['id'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['table'] = 'field_data_field_focus_area';
  $handler->display->display_options['filters']['field_focus_area_tid']['field'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_focus_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['operator_id'] = 'field_focus_area_tid_op';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['label'] = 'Focus area (field_focus_area)';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['operator'] = 'field_focus_area_tid_op';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['identifier'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_focus_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_focus_area_tid']['vocabulary'] = 'focus_area';
  $handler->display->display_options['geocluster_enabled'] = 1;
  $handler->display->display_options['geocluster_options'] = array(
    'algorithm' => 'geocluster_mysql',
    'cluster_field' => 'field_profile_location',
    'cluster_distance' => '65',
  );

  /* Display: Map Feed: Alumni */
  $handler = $view->new_display('page', 'Map Feed: Alumni', 'map_feed_alumni');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Alumni';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'geocluster_lat';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'geocluster_lon';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_profile_location';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_profile_location';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'geocluster_count';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_profile_location';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Site Information (field_site_information) */
  $handler->display->display_options['relationships']['field_site_information_value']['id'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['table'] = 'field_data_field_site_information';
  $handler->display->display_options['relationships']['field_site_information_value']['field'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_site_information_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile Lat/Long */
  $handler->display->display_options['fields']['field_profile_location']['id'] = 'field_profile_location';
  $handler->display->display_options['fields']['field_profile_location']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['field_profile_location']['field'] = 'field_profile_location';
  $handler->display->display_options['fields']['field_profile_location']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_location']['label'] = '';
  $handler->display->display_options['fields']['field_profile_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_profile_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_profile_location']['group_column'] = 'geocluster_index_4';
  $handler->display->display_options['fields']['field_profile_location']['field_api_classes'] = TRUE;
  /* Field: Content: Geocluster ids (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_ids']['id'] = 'geocluster_ids';
  $handler->display->display_options['fields']['geocluster_ids']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_ids']['field'] = 'geocluster_ids';
  $handler->display->display_options['fields']['geocluster_ids']['relationship'] = 'profile';
  /* Field: Content: Geocluster lat (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_lat']['id'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_lat']['field'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['relationship'] = 'profile';
  $handler->display->display_options['fields']['geocluster_lat']['element_type'] = '0';
  $handler->display->display_options['fields']['geocluster_lat']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['geocluster_lat']['element_default_classes'] = FALSE;
  /* Field: Content: Geocluster lon (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_lon']['id'] = 'geocluster_lon';
  $handler->display->display_options['fields']['geocluster_lon']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_lon']['field'] = 'geocluster_lon';
  /* Field: Content: Geocluster result count (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_count']['id'] = 'geocluster_count';
  $handler->display->display_options['fields']['geocluster_count']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_count']['field'] = 'geocluster_count';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['group_type'] = 'group_concat';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Custom: Bounding box */
  $handler->display->display_options['arguments']['bbox_argument']['id'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['table'] = 'views';
  $handler->display->display_options['arguments']['bbox_argument']['field'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['bbox_argument']['default_argument_type'] = 'querystring';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bbox_argument']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: User type (og_user_node) */
  $handler->display->display_options['filters']['og_user_node_target_id']['id'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_user_node_target_id']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['value'] = array(
    19 => '19',
  );
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator_id'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['label'] = 'User type (og_user_node)';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['identifier'] = 'og_user_node_target_id';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Profile: Show location on the VISTA map? (field_show_location) */
  $handler->display->display_options['filters']['field_show_location_value']['id'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['table'] = 'field_data_field_show_location';
  $handler->display->display_options['filters']['field_show_location_value']['field'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_show_location_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Field: Focus area (field_focus_area) */
  $handler->display->display_options['filters']['field_focus_area_tid']['id'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['table'] = 'field_data_field_focus_area';
  $handler->display->display_options['filters']['field_focus_area_tid']['field'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_focus_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['operator_id'] = 'field_focus_area_tid_op';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['label'] = 'Focus area (field_focus_area)';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['operator'] = 'field_focus_area_tid_op';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['identifier'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_focus_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_focus_area_tid']['vocabulary'] = 'focus_area';
  /* Filter criterion: Field collection item: Service start (field_profile_service_date) */
  $handler->display->display_options['filters']['field_profile_service_date_value']['id'] = 'field_profile_service_date_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['table'] = 'field_data_field_profile_service_date';
  $handler->display->display_options['filters']['field_profile_service_date_value']['field'] = 'field_profile_service_date_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_profile_service_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['operator_id'] = 'field_profile_service_date_value_op';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['label'] = 'Service start (field_profile_service_date)';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['operator'] = 'field_profile_service_date_value_op';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['identifier'] = 'field_profile_service_date_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_profile_service_date_value']['granularity'] = 'month';
  $handler->display->display_options['filters']['field_profile_service_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_profile_service_date_value']['year_range'] = '-10:+0';
  /* Filter criterion: User: User type (og_user_node) */
  $handler->display->display_options['filters']['og_user_node_target_id_1']['id'] = 'og_user_node_target_id_1';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['value'] = array(
    'all' => 'all',
    19 => '19',
    18 => '18',
    17 => '17',
    15 => '15',
    16 => '16',
  );
  $handler->display->display_options['filters']['og_user_node_target_id_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['operator_id'] = 'og_user_node_target_id_1_op';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['label'] = 'User type (og_user_node)';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['operator'] = 'og_user_node_target_id_1_op';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['identifier'] = 'og_user_node_target_id_1';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['geocluster_enabled'] = 1;
  $handler->display->display_options['geocluster_options'] = array(
    'algorithm' => 'geocluster_mysql',
    'cluster_field' => 'field_profile_location',
    'cluster_distance' => '65',
  );
  $handler->display->display_options['path'] = 'map-feed-alumni';

  /* Display: Cluster Table Block: Alumni */
  $handler = $view->new_display('block', 'Cluster Table Block: Alumni', 'block_cluster_table_alumni');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_profile_location' => 'field_profile_location',
    'name' => 'name',
    'geocluster_ids' => 'geocluster_ids',
    'geocluster_lat' => 'geocluster_lat',
    'geocluster_lon' => 'geocluster_lon',
    'geocluster_count' => 'geocluster_count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_profile_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'geocluster_ids' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'geocluster_lat' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'geocluster_lon' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'geocluster_count' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile Lat/Long */
  $handler->display->display_options['fields']['field_profile_location']['id'] = 'field_profile_location';
  $handler->display->display_options['fields']['field_profile_location']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['field_profile_location']['field'] = 'field_profile_location';
  $handler->display->display_options['fields']['field_profile_location']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_location']['label'] = '';
  $handler->display->display_options['fields']['field_profile_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_profile_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_profile_location']['group_column'] = 'geocluster_index_4';
  $handler->display->display_options['fields']['field_profile_location']['field_api_classes'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['group_type'] = 'group_concat';
  $handler->display->display_options['fields']['name']['label'] = 'User Name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Geocluster ids (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_ids']['id'] = 'geocluster_ids';
  $handler->display->display_options['fields']['geocluster_ids']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_ids']['field'] = 'geocluster_ids';
  $handler->display->display_options['fields']['geocluster_ids']['relationship'] = 'profile';
  /* Field: Content: Geocluster lat (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_lat']['id'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_lat']['field'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['relationship'] = 'profile';
  $handler->display->display_options['fields']['geocluster_lat']['element_type'] = '0';
  $handler->display->display_options['fields']['geocluster_lat']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['geocluster_lat']['element_default_classes'] = FALSE;
  /* Field: Content: Geocluster lon (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_lon']['id'] = 'geocluster_lon';
  $handler->display->display_options['fields']['geocluster_lon']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_lon']['field'] = 'geocluster_lon';
  /* Field: Content: Geocluster result count (field_profile_location) */
  $handler->display->display_options['fields']['geocluster_count']['id'] = 'geocluster_count';
  $handler->display->display_options['fields']['geocluster_count']['table'] = 'field_data_field_profile_location';
  $handler->display->display_options['fields']['geocluster_count']['field'] = 'geocluster_count';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Profile: Show location on the VISTA map? (field_show_location) */
  $handler->display->display_options['filters']['field_show_location_value']['id'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['table'] = 'field_data_field_show_location';
  $handler->display->display_options['filters']['field_show_location_value']['field'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_show_location_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['geocluster_enabled'] = 1;
  $handler->display->display_options['geocluster_options'] = array(
    'algorithm' => 'geocluster_mysql',
    'cluster_field' => 'field_profile_location',
    'cluster_distance' => '65',
  );

  /* Display: Map Feed: Active Vista */
  $handler = $view->new_display('page', 'Map Feed: Active Vista', 'map_feed_active');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Active Vista';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'geocluster_lat';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'geocluster_lon';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_organization_location';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_organization_location';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'geocluster_count';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_organization_location';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Site Information (field_site_information) */
  $handler->display->display_options['relationships']['field_site_information_value']['id'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['table'] = 'field_data_field_site_information';
  $handler->display->display_options['relationships']['field_site_information_value']['field'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_site_information_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_site_information_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Lat/long */
  $handler->display->display_options['fields']['field_organization_location']['id'] = 'field_organization_location';
  $handler->display->display_options['fields']['field_organization_location']['table'] = 'field_data_field_organization_location';
  $handler->display->display_options['fields']['field_organization_location']['field'] = 'field_organization_location';
  $handler->display->display_options['fields']['field_organization_location']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_organization_location']['label'] = '';
  $handler->display->display_options['fields']['field_organization_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_organization_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_organization_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_organization_location']['group_column'] = 'geocluster_index_4';
  $handler->display->display_options['fields']['field_organization_location']['field_api_classes'] = TRUE;
  /* Field: Content: Geocluster ids (field_organization_location) */
  $handler->display->display_options['fields']['geocluster_ids']['id'] = 'geocluster_ids';
  $handler->display->display_options['fields']['geocluster_ids']['table'] = 'field_data_field_organization_location';
  $handler->display->display_options['fields']['geocluster_ids']['field'] = 'geocluster_ids';
  $handler->display->display_options['fields']['geocluster_ids']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['geocluster_ids']['label'] = '';
  $handler->display->display_options['fields']['geocluster_ids']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['geocluster_ids']['element_default_classes'] = FALSE;
  /* Field: Content: Geocluster lat (field_organization_location) */
  $handler->display->display_options['fields']['geocluster_lat']['id'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['table'] = 'field_data_field_organization_location';
  $handler->display->display_options['fields']['geocluster_lat']['field'] = 'geocluster_lat';
  $handler->display->display_options['fields']['geocluster_lat']['relationship'] = 'field_site_information_value';
  /* Field: Content: Geocluster lon (field_organization_location) */
  $handler->display->display_options['fields']['geocluster_lon']['id'] = 'geocluster_lon';
  $handler->display->display_options['fields']['geocluster_lon']['table'] = 'field_data_field_organization_location';
  $handler->display->display_options['fields']['geocluster_lon']['field'] = 'geocluster_lon';
  $handler->display->display_options['fields']['geocluster_lon']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['geocluster_lon']['label'] = '';
  $handler->display->display_options['fields']['geocluster_lon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['geocluster_lon']['element_default_classes'] = FALSE;
  /* Field: Content: Geocluster result count (field_organization_location) */
  $handler->display->display_options['fields']['geocluster_count']['id'] = 'geocluster_count';
  $handler->display->display_options['fields']['geocluster_count']['table'] = 'field_data_field_organization_location';
  $handler->display->display_options['fields']['geocluster_count']['field'] = 'geocluster_count';
  $handler->display->display_options['fields']['geocluster_count']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['geocluster_count']['label'] = '';
  $handler->display->display_options['fields']['geocluster_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['geocluster_count']['element_default_classes'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['group_type'] = 'group_concat';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Custom: Bounding box */
  $handler->display->display_options['arguments']['bbox_argument']['id'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['table'] = 'views';
  $handler->display->display_options['arguments']['bbox_argument']['field'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['bbox_argument']['default_argument_type'] = 'querystring';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bbox_argument']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: User type (og_user_node) */
  $handler->display->display_options['filters']['og_user_node_target_id']['id'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_user_node_target_id']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['value'] = array(
    19 => '19',
    17 => '17',
    15 => '15',
    16 => '16',
  );
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator_id'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['label'] = 'Vista Role';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['identifier'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Profile: Show location on the VISTA map? (field_show_location) */
  $handler->display->display_options['filters']['field_show_location_value']['id'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['table'] = 'field_data_field_show_location';
  $handler->display->display_options['filters']['field_show_location_value']['field'] = 'field_show_location_value';
  $handler->display->display_options['filters']['field_show_location_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_show_location_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Field: Focus area (field_focus_area) */
  $handler->display->display_options['filters']['field_focus_area_tid']['id'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['table'] = 'field_data_field_focus_area';
  $handler->display->display_options['filters']['field_focus_area_tid']['field'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_focus_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['operator_id'] = 'field_focus_area_tid_op';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['label'] = 'Focus area';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['operator'] = 'field_focus_area_tid_op';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['identifier'] = 'field_focus_area_tid';
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_focus_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_focus_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_focus_area_tid']['vocabulary'] = 'focus_area';
  /* Filter criterion: Field collection item: Service start (field_profile_service_date) */
  $handler->display->display_options['filters']['field_profile_service_date_value']['id'] = 'field_profile_service_date_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['table'] = 'field_data_field_profile_service_date';
  $handler->display->display_options['filters']['field_profile_service_date_value']['field'] = 'field_profile_service_date_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_profile_service_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['operator_id'] = 'field_profile_service_date_value_op';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['label'] = 'Service Start';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['operator'] = 'field_profile_service_date_value_op';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['identifier'] = 'field_profile_service_date_value';
  $handler->display->display_options['filters']['field_profile_service_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_profile_service_date_value']['granularity'] = 'month';
  $handler->display->display_options['filters']['field_profile_service_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_profile_service_date_value']['year_range'] = '-10:+0';
  /* Filter criterion: User: User type (og_user_node) */
  $handler->display->display_options['filters']['og_user_node_target_id_1']['id'] = 'og_user_node_target_id_1';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['value'] = array(
    'all' => 'all',
    19 => '19',
    18 => '18',
    17 => '17',
    15 => '15',
    16 => '16',
  );
  $handler->display->display_options['filters']['og_user_node_target_id_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['operator_id'] = 'og_user_node_target_id_1_op';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['label'] = 'Vista Role';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['operator'] = 'og_user_node_target_id_1_op';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['identifier'] = 'og_user_node_target_id_1';
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['og_user_node_target_id_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['geocluster_enabled'] = 1;
  $handler->display->display_options['geocluster_options'] = array(
    'algorithm' => 'geocluster_mysql',
    'cluster_field' => 'field_organization_location',
    'cluster_distance' => '65',
  );
  $handler->display->display_options['path'] = 'map-feed-active';
  $export['vista_map_data_feeds'] = $view;

  $view = new view();
  $view->name = 'vista_map_popup_feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Vista Map Popup Feeds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Listing: Mapped Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = 'userinfo';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['required'] = TRUE;
  /* Field: Profile: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_profile_photo']['field_api_classes'] = TRUE;
  /* Field: User relationships: User relationship add / remove action */
  $handler->display->display_options['fields']['ur_action']['id'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['table'] = 'users';
  $handler->display->display_options['fields']['ur_action']['field'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['label'] = '';
  $handler->display->display_options['fields']['ur_action']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ur_action']['ur-type'] = '1';
  $handler->display->display_options['fields']['ur_action']['ur-actions'] = array(
    'add' => 'add',
    'remove' => 'remove',
    'requested' => 0,
    'received' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Map Popup Feed: Single Active Vista */
  $handler = $view->new_display('page', 'Map Popup Feed: Single Active Vista', 'page_single_active');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map Popup Feed: Single Active';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['required'] = TRUE;
  /* Relationship: Profile: Site Information (field_site_information) */
  $handler->display->display_options['relationships']['field_site_information_value']['id'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['table'] = 'field_data_field_site_information';
  $handler->display->display_options['relationships']['field_site_information_value']['field'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_site_information_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_site_information_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_profile_photo']['field_api_classes'] = TRUE;
  /* Field: User relationships: User relationship add / remove action */
  $handler->display->display_options['fields']['ur_action']['id'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['table'] = 'users';
  $handler->display->display_options['fields']['ur_action']['field'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['label'] = '';
  $handler->display->display_options['fields']['ur_action']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ur_action']['ur-type'] = '1';
  $handler->display->display_options['fields']['ur_action']['ur-actions'] = array(
    'add' => 'add',
    'remove' => 'remove',
    'requested' => 0,
    'received' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field collection item: Service start */
  $handler->display->display_options['fields']['field_profile_service_date']['id'] = 'field_profile_service_date';
  $handler->display->display_options['fields']['field_profile_service_date']['table'] = 'field_data_field_profile_service_date';
  $handler->display->display_options['fields']['field_profile_service_date']['field'] = 'field_profile_service_date';
  $handler->display->display_options['fields']['field_profile_service_date']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_profile_service_date']['label'] = '';
  $handler->display->display_options['fields']['field_profile_service_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_service_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_service_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_service_date']['settings'] = array(
    'format_type' => 'vista_extras_year_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Field: Field collection item: Address - Company */
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['id'] = 'field_organization_address_organisation_name';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['field'] = 'field_organization_address_organisation_name';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['element_default_classes'] = FALSE;
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_citystate';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = TRUE;
  $handler->display->display_options['path'] = 'map-popup-single-active/%';

  /* Display: Map Popup Feed: Single Alum */
  $handler = $view->new_display('page', 'Map Popup Feed: Single Alum', 'page_single_alum');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map Popup Feed: Single Alum';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = 'userinfo';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['required'] = TRUE;
  /* Relationship: Profile: Site Information (field_site_information) */
  $handler->display->display_options['relationships']['field_site_information_value']['id'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['table'] = 'field_data_field_site_information';
  $handler->display->display_options['relationships']['field_site_information_value']['field'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_site_information_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_site_information_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_profile_photo']['field_api_classes'] = TRUE;
  /* Field: User relationships: User relationship add / remove action */
  $handler->display->display_options['fields']['ur_action']['id'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['table'] = 'users';
  $handler->display->display_options['fields']['ur_action']['field'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['label'] = '';
  $handler->display->display_options['fields']['ur_action']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ur_action']['ur-type'] = '1';
  $handler->display->display_options['fields']['ur_action']['ur-actions'] = array(
    'add' => 'add',
    'remove' => 'remove',
    'requested' => 0,
    'received' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Profile: Address */
  $handler->display->display_options['fields']['field_profile_address']['id'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['table'] = 'field_data_field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['field'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_address']['label'] = '';
  $handler->display->display_options['fields']['field_profile_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_profile_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_profile_address']['type'] = 'addressfield_citystate';
  $handler->display->display_options['fields']['field_profile_address']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_profile_address']['field_api_classes'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field collection item: Service start */
  $handler->display->display_options['fields']['field_profile_service_date']['id'] = 'field_profile_service_date';
  $handler->display->display_options['fields']['field_profile_service_date']['table'] = 'field_data_field_profile_service_date';
  $handler->display->display_options['fields']['field_profile_service_date']['field'] = 'field_profile_service_date';
  $handler->display->display_options['fields']['field_profile_service_date']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_profile_service_date']['label'] = '';
  $handler->display->display_options['fields']['field_profile_service_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_service_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_service_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_service_date']['settings'] = array(
    'format_type' => 'vista_extras_year_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Field: Field collection item: Address - Company */
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['id'] = 'field_organization_address_organisation_name';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['field'] = 'field_organization_address_organisation_name';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['element_default_classes'] = FALSE;
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_citystate';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = TRUE;
  $handler->display->display_options['path'] = 'map-popup-single-alum/%';

  /* Display: Map Popup Feed: Multi-Active */
  $handler = $view->new_display('page', 'Map Popup Feed: Multi-Active', 'page_multi_active');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map Popup Feed: Multi-Active';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = 'userinfo';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['required'] = TRUE;
  /* Relationship: Profile: Site Information (field_site_information) */
  $handler->display->display_options['relationships']['field_site_information_value']['id'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['table'] = 'field_data_field_site_information';
  $handler->display->display_options['relationships']['field_site_information_value']['field'] = 'field_site_information_value';
  $handler->display->display_options['relationships']['field_site_information_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_site_information_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field collection item: Address - Company */
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['id'] = 'field_organization_address_organisation_name';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['field'] = 'field_organization_address_organisation_name';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['relationship'] = 'field_site_information_value';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_organisation_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['multiple_values'] = TRUE;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'map-popup-multi-active/%';

  /* Display: Map Popup Feed: Multi-Alum */
  $handler = $view->new_display('page', 'Map Popup Feed: Multi-Alum', 'page_multi_alum');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map Popup Feed: Multi-Active';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = 'userinfo';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Profile: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_profile_address_administrative_area']['id'] = 'field_profile_address_administrative_area';
  $handler->display->display_options['fields']['field_profile_address_administrative_area']['table'] = 'field_data_field_profile_address';
  $handler->display->display_options['fields']['field_profile_address_administrative_area']['field'] = 'field_profile_address_administrative_area';
  $handler->display->display_options['fields']['field_profile_address_administrative_area']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_profile_address_administrative_area']['element_label_colon'] = FALSE;
  /* Field: Profile: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_profile_address_locality']['id'] = 'field_profile_address_locality';
  $handler->display->display_options['fields']['field_profile_address_locality']['table'] = 'field_data_field_profile_address';
  $handler->display->display_options['fields']['field_profile_address_locality']['field'] = 'field_profile_address_locality';
  $handler->display->display_options['fields']['field_profile_address_locality']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_profile_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_address_locality']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['multiple_values'] = TRUE;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'map-popup-multi-alum/%';

  /* Display: Pane: Mapped Users */
  $handler = $view->new_display('panel_pane', 'Pane: Mapped Users', 'panel_pane_mapped_users');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '32';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'dropdown';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_profile_photo' => 'field_profile_photo',
    'ur_action' => 'ur_action',
  );
  $handler->display->display_options['row_options']['dropdown_config'] = array(
    'trigger_element' => 'realname',
    'in_dropdown' => array(
      'field_focus_area' => 'field_focus_area',
      'field_profile_bio' => 'field_profile_bio',
      'view_user' => 'view_user',
      'title' => 0,
      'field_profile_photo' => 0,
      'ur_action' => 0,
      'name' => 0,
      'uid' => 0,
      'realname' => 0,
    ),
    'hover' => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  /* Field: Profile: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => 'content',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Field: User relationships: User relationship add / remove action */
  $handler->display->display_options['fields']['ur_action']['id'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['table'] = 'users';
  $handler->display->display_options['fields']['ur_action']['field'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['label'] = '';
  $handler->display->display_options['fields']['ur_action']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ur_action']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['ur_action']['element_wrapper_class'] = 'ur-action-add';
  $handler->display->display_options['fields']['ur_action']['ur-type'] = '1';
  $handler->display->display_options['fields']['ur_action']['ur-actions'] = array(
    'add' => 'add',
    'remove' => 0,
    'requested' => 0,
    'received' => 0,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['realname']['empty'] = '[name]';
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_bio']['id'] = 'field_profile_bio';
  $handler->display->display_options['fields']['field_profile_bio']['table'] = 'field_data_field_profile_bio';
  $handler->display->display_options['fields']['field_profile_bio']['field'] = 'field_profile_bio';
  $handler->display->display_options['fields']['field_profile_bio']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_bio']['label'] = '';
  $handler->display->display_options['fields']['field_profile_bio']['alter']['max_length'] = '128';
  $handler->display->display_options['fields']['field_profile_bio']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_profile_bio']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_profile_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_bio']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_profile_bio']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Field: Field: Focus area */
  $handler->display->display_options['fields']['field_focus_area']['id'] = 'field_focus_area';
  $handler->display->display_options['fields']['field_focus_area']['table'] = 'field_data_field_focus_area';
  $handler->display->display_options['fields']['field_focus_area']['field'] = 'field_focus_area';
  $handler->display->display_options['fields']['field_focus_area']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_focus_area']['label'] = '';
  $handler->display->display_options['fields']['field_focus_area']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_focus_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_focus_area']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_focus_area']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_focus_area']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_focus_area']['delta_offset'] = '0';
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'View full profile &#187;';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = 'PLACEHOLDER';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['multiple_values'] = TRUE;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['null_1']['title'] = '%3';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['argument'] = 'PLACEHOLDER';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'null' => array(
      'type' => 'panel',
      'context' => 'entity:comment.field_attachment',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Global: Null',
    ),
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:user.uid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
    'null_1' => array(
      'type' => 'panel',
      'context' => 'entity:comment.field_attachment',
      'context_optional' => 0,
      'panel' => '2',
      'fixed' => '',
      'label' => 'Global: Null',
    ),
  );
  $export['vista_map_popup_feeds'] = $view;

  return $export;
}

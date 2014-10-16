; Large-scale mapping build spec.

;; GeoPHP
libraries[geoPHP][download][type] = "git"
libraries[geoPHP][download][url] = "https://github.com/phayes/geoPHP.git"
libraries[geoPHP][download][revision] = "0aae7c3"

projects[geophp][version] = "1.7"

;; Geocoder
projects[geocoder][download][branch] = "7.x-1.x"
projects[geocoder][download][revision] = "c1a79dc"
;; Patching for more useful geocode values alter hook.
;; @see https://drupal.org/node/2156293
projects[geocoder][patch][] = "https://drupal.org/files/issues/geocoder--include-field-instance-settings--2156293-1.patch"
;; Add link to offending entity in watchdog message.
;; @see https://drupal.org/node/2221663
projects[geocoder][patch][] = https://drupal.org/files/issues/geocoder--link-to-offending-entity--2221663-3.patch
;; Add more granular control to drush geocode-backfill
;; @see https://drupal.org/node/2077317
projects[geocoder][patch][] = "https://drupal.org/files/issues/2077317-geocoder-drush-13.patch"

;; Geofield
projects[geofield][version] = "2.1"

;; For large scale mapping we need server-side clustering and async
;; pin reclustering/placement. For that we need a few extra modules
;; and a handfull of patches. This solution is driven by the Geohash
;; implementation provided by Geocluster.
;; @see https://drupal.org/node/1962198

;; Allow hook_field_schema_alter to be implemented: https://drupal.org/node/691932#comment-8797725
projects[drupal][patch][] = "https://drupal.org/files/issues/field-schema-alter-691932-92.patch"
;; Field attach with aggregation bug
;; https://drupal.org/comment/4984276#comment-4984276
projects[drupal][patch][] = https://drupal.org/files/issues/1161708--_field_invoke-trouble-15.patch

;; Add hook_views_post_execute_query to views API for Geocluster.
;; @see http://drupal.org/node/1791796
projects[views][patch][] = http://drupal.org/files/views_post_execute_query_hook.patch
;; Add GROUP_CONCAT aggregate function and query extender.
;; @see http://drupal.org/node/1362524
projects[views][patch][] = https://drupal.org/files/issues/1362524-30.views_.group-concat-aggregate.patch
;; Allow multiple UIDs as views contextual filter.
;; @see https://www.drupal.org/node/1798270
projects[views][patch][] = https://drupal.org/files/Contextual_Filter_UserID_Multiple-1798270-10.patch
;; Fix "an illegal selection" exposed filter bug
;; @see https://www.drupal.org/node/2292467
projects[views][patch][] = https://www.drupal.org/files/issues/views_fix-illegal-choice-exposed-group-filters_2292467-02.patch

projects[views_geojson][download][branch] = "7.x-1.x"
projects[views_geojson][download][revision] = "cc2bc0b"
;; Allow other entities besides nodes to have description field.
;; @see https://drupal.org/node/2082143
projects[views_geojson][patch][] = "https://drupal.org/files/views_geojson-description_property-2082143-1.patch"
;; Add hook views_geojson_render_fields_alter
;; @see http://drupal.org/node/1799870
projects[views_geojson][patch][] = http://drupal.org/files/views_geojson_render_fields_alter.patch
;; Geoofield WKT incompatibility.
;; @see http://drupal.org/node/1794848
projects[views_geojson][patch][] = https://drupal.org/files/1794848-geofield20.patch
;; Fix bounding box not working when location data is loaded over a relationship.
;; @see https://www.drupal.org/node/2202523
projects[views_geojson][patch][] = https://drupal.org/files/issues/views_geojson--bounding-relationship--2202523-3.patch
;; Bounding box for all views.
;; see http://drupal.org/node/2060197
projects[views_geojson][patch][] = https://drupal.org/files/bbox_on_all_views.patch
;; Bounding argument not exported correctly.
;; @see https://drupal.org/node/1864972
projects[views_geojson][patch][] = https://drupal.org/files/issues/views_geojson--bbox-arg-export--1864972-5.patch

;; Server-side clustering.
projects[geocluster][download][branch] = "7.x-1.x"
projects[geocluster][download][revision] = "505fc5c"
;; Move geohash to entity presave for better reliability.
;; @see https://www.drupal.org/node/2020737
projects[geocluster][patch][] = https://drupal.org/files/issues/geocluster--geohash-empty-column-data--2020737-8.patch

;; Leaflet (display engine)
libraries[leaflet][download][type] = get
libraries[leaflet][download][url] = http://leaflet-cdn.s3.amazonaws.com/build/leaflet-0.7.1.zip
libraries[leaflet][directory_name] = leaflet
libraries[leaflet][destination] = libraries

projects[leaflet][download][branch] = "7.x-1.x"
projects[leaflet][download][revision] = "94a9b65"

projects[leaflet_geojson][download][branch] = "7.x-2.x"
projects[leaflet_geojson][revision][revision] = "53f226f"
;; Bounding argument keys should come from their respective data layers.
;; @see https://drupal.org/node/2267687
projects[leaflet_geojson][patch][] = https://drupal.org/files/issues/leaflet_geojson--bounding-argument-key--2267687-1.patch
;; Allow more alter flexibiltiy including access to pane config.
;; @see https://drupal.org/node/2276097
projects[leaflet_geojson][patch][] = https://drupal.org/files/issues/leaflet_geojson--more-alter-flexibiltiy--2276097-1.patch

projects[leaflet_more_maps][version] = "1.9"

;; Leaflet.fullscreen plugin
libraries[leaflet_fullscreen][download][type] = "git"
libraries[leaflet_fullscreen][download][revision] = "2becb29"
libraries[leaflet_fullscreen][download][url] = "https://github.com/Leaflet/Leaflet.fullscreen.git"
libraries[leaflet_fullscreen][directory_name] = "leaflet.fullscreen"

;; Views Datasource
projects[views_datasource][download][branch] = "7.x-1.x"
projects[views_datasource][download][revision] = "c15e455"

;; Sprite animation for loading spinners.
libraries[animate_sprite][download][type] = "git"
libraries[animate_sprite][download][revision] = "46fe3e1"
libraries[animate_sprite][download][url] = "https://github.com/blaiprat/jquery.animateSprite.git"

;; Leaflet awesome markers.
libraries[awesome_markers][download][type] = "git"
libraries[awesome_markers][download][tag] = "v2.0.2"
libraries[awesome_markers][download][url] = "https://github.com/lvoogdt/Leaflet.awesome-markers.git"

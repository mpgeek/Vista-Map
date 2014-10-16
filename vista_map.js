(function ($) {

  // This overrides Drupal.leafletBBox.geoJSONoptions that is referenced
  // in leaflet.bbox.js.
  Drupal.leafletBBox.geoJSONOptions = {
    pointToLayer: function(featureData, latlng) {

      // Set up our image-based icons with Awesome Markers.
      var VistaSingleActive = new L.AwesomeMarkers.icon({
        markerColor: 'red',
        icon: 'user',
        prefix: 'fa'
      });
      var VistaSingleActiveLeader = new L.AwesomeMarkers.icon({
        markerColor: 'orange',
        icon: 'user',
        prefix: 'fa'
      });
      var VistaSingleActiveSupervisor = new L.AwesomeMarkers.icon({
        markerColor: 'blue',
        icon: 'user',
        prefix: 'fa'
      });
      var VistaSingleActiveStateOfficer = new L.AwesomeMarkers.icon({
        markerColor: 'green',
        icon: 'user',
        prefix: 'fa'
      })
      var VistaSingleAlumni = new L.AwesomeMarkers.icon({
        markerColor: 'darkblue',
        icon: 'graduation-cap',
        prefix: 'fa'
      });
      var VistaMonolithic = L.AwesomeMarkers.icon({
        markerColor: 'purple',
        icon: 'users',
        prefix: 'fa'
      });
      var lMarker = null;

      // Clustered points.
      if (featureData.cluster_items > 1) {

        // Monolithic clusters get a styled pin, not a cluster icon.
        if (featureData.properties.is_monolithic) {
          lMarker = new L.marker(latlng, {icon: VistaMonolithic});
        }

        // Near-point clusters get the cluster icon.
        else {
          var number = featureData.cluster_items;
          var c = ' marker-cluster-';
          if (number < 10) {
            c += 'small';
          } else if (number < 100) {
            c += 'medium';
          } else if (number < 1000) {
            c += 'large';
          } else if (number < 10000) {
            c += 'huge';
          } else {
            c += 'giant';
          }
          var icon = new L.DivIcon({
            html: '<div><span>' + number + '</span></div>',
            className: 'marker-cluster' + c,
            iconSize: new L.Point(40, 40)
          });
          lMarker = new L.Marker(latlng, {icon:icon});
        }
      }

      // Single points.
      else {
        if (featureData.properties.is_alumni) {
          lMarker = new L.Marker(latlng, {icon: VistaSingleAlumni});
        }
        else if (featureData.properties.is_active) {
          // Active users get different pins based on group membership.
          // Users who belong to multiple groups get their group_id
          // set by the first membership, unless any of the memberships
          // are state office. The state office membership takes
          // priority in that case.
          var group_id = 0;
          var super_id = "18";
          $.each(featureData.properties.group_id, function(idx, el) {
            if (idx == 0) {
              // Assign the first group id.
              group_id = el;
            }
            else {
              if (el == super_id) {
                // We've found a priority id, just use it.
                group_id = super_id;
                return false;
              }
            }
          });

          switch (group_id) {
            case "16":
              lMarker = new L.Marker(latlng, {icon: VistaSingleActiveLeader});
              break;
            case "17":
              lMarker = new L.Marker(latlng, {icon: VistaSingleActiveSupervisor});
              break;
            case "18":
              lMarker = new L.Marker(latlng, {icon: VistaSingleActiveStateOfficer});
              break;
            default:
              lMarker = new L.Marker(latlng, {icon: VistaSingleActive});
          }
        }
        else {
          // Default leaflet icon.
          lMarker = new L.Marker(latlng);
        }
      }

      return lMarker;
    },

    onEachFeature: function(featureData, layer) {
      layer.on('click', function(e) {
        var $popupContent = $('<div>', {class: 'leaflet-popup-content'});

        if ((featureData.cluster_items > 1) && !featureData.properties.is_monolithic) {
          // Don't show any popup content, just zoom.
          Drupal.leafletBBox.geoJSONOptions.clickOnClustered(e, featureData, layer);
        }
        else {
          // Set up the loading spinner.
          var spinnerTop = e.originalEvent.pageY - $('.loadspinner').height();
          var spinnerLeft = e.originalEvent.pageX - $('.loadspinner').width();
          $('.loadspinner').css({
            top:  spinnerTop + 'px',
            left: spinnerLeft + 'px'
          }).show();

          // Single-point content.
          if (!featureData.properties.is_monolithic) {
            $popupContent.attr('id',
              'leaflet-popup-content-' + featureData.properties.uid
            );

            if (featureData.properties.is_alumni) {
              var jsonURI = '/map-popup-single-alum/' + featureData.properties.uid;
              var $jqxhr = $.getJSON(jsonURI).fail(function() {
                console.log('failed to get JSON');
              });

              // Successful fetch.
              $jqxhr.done(function(data) {
                // There should only be one item.
                $.each(data.nodes, function(idx, item) {

                  // Build single-pin popup content.
                  work_verb = 'Worked';
                  $popupContent = build_popup_content_single_pin(
                    $popupContent, item, work_verb
                  );
                });

                // Bind the popup content and debounce opening fo the bubble.
                layer.bindPopup($popupContent.html());
                open_popup_debounce(layer);
              });
            }
            else {
              if (featureData.properties.is_active) {
                var jsonURI = '/map-popup-single-active/' + featureData.properties.uid;
                var $jqxhr = $.getJSON(jsonURI).fail(function(){
                  console.log('failed to get JSON');
                });

                // Successful fetch.
                $jqxhr.done(function(data) {
                  // There should only be one item.
                  $.each(data.nodes, function(idx, item) {

                    // Build single-pin popup content.
                    work_verb = 'Works';
                    $popupContent = build_popup_content_single_pin(
                      $popupContent, item, work_verb
                    );
                  });

                  // Bind the popup content and debounce opening of the bubble.
                  layer.bindPopup($popupContent.html());
                  open_popup_debounce(layer);
                });
              }
            }
          }
          // Monolithic cluster popups.
          else {
            if (featureData.properties.display_name == 'map_feed_alumni') {
              var jsonURI = 'map-popup-multi-alum/' + featureData.properties.uid;
              var $jqxhr = $.getJSON(jsonURI).fail(function(){
                console.log('failed to get JSON');
              });

              // Successful fetch.
              $jqxhr.done(function(data) {
                // Gather city and state.
                var city = '';
                var state = '';
                var locale = '';
                var alumCount = 0;
                $.each(data.nodes, function(idx,item) {
                  // There is some incomplete data, so build the city and state
                  // from multiple users in the cluster if necessary.
                  if ((item.userinfo.field_profile_address_locality != '') && (city == '')) {
                    city = item.userinfo.field_profile_address_locality;
                  }
                  if ((item.userinfo.field_profile_address_administrative_area != '') && (state == '')) {
                    state = item.userinfo.field_profile_address_administrative_area;
                  }
                  alumCount++;
                });
                if ((city != '') && (state != '')) {
                  locale = city + ', ' + state;
                }
                else if ((city != '') && (state == '')) {
                  locale = city;
                }
                else if ((city == '') && (state != '')) {
                  locale = state;
                }
                else {
                  locale = "Incomplete address info.";
                }
                var groupTitle = 'Alumni in the area';
                var detailListConfig = encodeURIComponent(locale) + '/' + featureData.properties.uid + '/' + encodeURIComponent(groupTitle);

                $popupContent
                  .append($('<div>', {
                    'class': 'group-title'
                  }).text('Alumni in the area'))
                  .append($('<div>', {
                    'class': 'group-locale'
                  }).text(locale))
                  .append($('<div>', {
                    'class': 'group-counts'
                  }).text(alumCount + ' alums'))
                  .append(
                    $('<div>', {
                      'class': 'see-who'
                    }).html(
                      $('<a>', {
                        'href': 'mapped-users/' + detailListConfig,
                        'target': '_blank'
                      }).text('See who they are'))
                    );

                layer.bindPopup($popupContent.html());
                open_popup_debounce(layer)
              });
            }
            else if (featureData.properties.display_name == 'map_feed_active') {
              var jsonURI = 'map-popup-multi-active/' + featureData.properties.uid;
              var $jqxhr = $.getJSON(jsonURI).fail(function(){
                console.log('failed to get JSON');
              });

              // Successful fetch.
              $jqxhr.done(function(data) {
                // Here we have multiple results, but we just need to
                // gather information about each.
                var projectSiteName = null;
                var groups = {};
                $.each(data.nodes, function(idx, item) {
                  // Take the site name from the first result.
                  if (idx == 0) {
                    projectSiteName = item.userinfo.field_organization_address_organisation_name;
                  }

                  if (!(item.userinfo.title in groups)) {
                    groups[item.userinfo.title] = 1;
                  }
                  else {
                    groups[item.userinfo.title] = parseInt(groups[item.userinfo.title]) + 1;
                  }
                });
                var groupTitle = 'Project Site Active Vistas';
                var detailListConfig = projectSiteName + '/' + featureData.properties.uid + '/' + encodeURIComponent(groupTitle);
                $popupContent
                  .append($('<div>', {
                    'class': 'group-title'
                  }).text(groupTitle))
                  .append($('<div>', {
                    'class': 'site-title'
                  }).text(projectSiteName));

                for (var key in groups) {
                  $popupContent
                    .append($('<div>', {
                      'class': 'group-counts'
                    }).text(groups[key] + ' ' + key + ' '));
                }
                $popupContent
                  .append(
                    $('<div>', {
                      'class': 'see-who'
                    }).html(
                      $('<a>', {
                        'href': 'mapped-users/' + detailListConfig,
                        'target': '_blank'
                      }).text('See who they are'))
                  );

                layer.bindPopup($popupContent.html());
                open_popup_debounce(layer)
              });
            }
          }
          $('.loadspinner').fadeOut();
        }
      });

      // Build popup content for a single pin based on the available data. Data
      // availability is driven by what's in the database and the permissions
      // of that data. We only build DOM elments for available data.
      function build_popup_content_single_pin($popupContainer, item, work_verb) {

        // Insufficiently-permissioned users may not be able to see the
        // profile photo, a default image has been provided for such a case.
        // We only want to embed the photo in a link if we have a link
        // to the profile already in the feed for this data point.
        var $profile_url = $(item.userinfo.name).attr('href')
        var $profile_photo = $('<img>', {
          'src': item.userinfo.field_profile_photo,
          'class': 'popup-profile-photo'
        });
        var $profile_photo_content = {};

        if ($profile_url) {
          $profile_photo_content = $('<a>', {
            'href': $(item.userinfo.name).attr('href')
          }).html($profile_photo);
        }
        else {
          $profile_photo_content = $profile_photo;
        }

        // Add profile photo or placeholder. This will always be available.
        $popupContainer.append(
          $('<div>', {
            'class': 'photo-connect'
          }).html($profile_photo_content)
          // Add user relationaship action if it is set.
          .append((item.userinfo.ur_action != '') ? fix_ur_action_redirect(item.userinfo.ur_action) : '')
        );

        // Add group title and username.
        $popupContainer.append(
            $('<div>', {
              'class': 'group-title'
            }).html(item.userinfo.title)
          ).append(
            $('<div>', {
              'class': 'realname'
            }).html(item.userinfo.name)
          );

        // Add the address if it exists.
        if (item.userinfo.field_profile_address) {
          $popupContainer.append(
            $('<div>', {
              'class': 'alum-location'
            }).html($.trim(item.userinfo.field_profile_address))
          );
        }

        // Add the service start date if it exists.
        if (item.userinfo.field_profile_service_date) {
          $popupContainer.append(
            $('<div>', {
              'class': 'service-date'
            }).html('Service start ' + $.trim(item.userinfo.field_profile_service_date))
          );
        }

        // Build the service location string out of available data.
        var service_location = '';
        if (item.userinfo.field_organization_address_organisation_name) {
          service_location += work_verb + ' at ' + $.trim(item.userinfo.field_organization_address_organisation_name);
          if (item.userinfo.field_organization_address) {
            service_location += ' in ' + $.trim(item.userinfo.field_organization_address);
          }
        }
        else if (item.userinfo.field_organization_address) {
          service_location = $.trim(item.userinfo.field_organization_address);
        }

        // Add the location info string.
        $popupContainer.append(
          $('<div>', {
            'class': 'program-location-info'
          }).html(service_location)
        );

        return $popupContainer;
      }

      // Point redirect (?destination) URIs back to
      // the map instead of the URI of the popup view.
      function fix_ur_action_redirect(ur_action) {

        // The relationship action (connect/disconnect) uses the
        // view path to the popup instead of the map as the
        // ?destination, which isn't useful for the user.
        //
        // Changing the redirect destination to the map URI
        // means the redirect returns the user to the
        // map NOT foucused on the current point, i.e. just the
        // default map view. Kinda "meh".
        /* @todo:
         *   consider ajax history so users may get back to
         *   the point under observation when going back/cancelling.
         */
        if ($(ur_action).is('a')) {
          var href = $(ur_action).prop('href');
          var parts = href.split('?destination=');
          return $(ur_action).prop('href', parts[0] + '?destination=map');
        }
        else {
          return ur_action;
        }
      }

      // Debounce opening of info bubbles.
      function open_popup_debounce(layer) {
        // On the first click on a feature after page load, the popup
        // doesn't always open on bind, so force it if it didn't open.
        // If .bind() successfully opened the popup, do nothing (debounce).
        if (!Drupal.leafletBBox.map._popup) {
          layer.openPopup();
        }
      }
    },

    // Clicking on a common cluster just zooms in one step.
    clickOnClustered: function(e, featureData, layer) {
      var map = layer._map;

      // Close any other opened popup.
      if (map._popup) {
        map._popup._source.closePopup();
      }
      map.setView(layer.getLatLng(), map._zoom + 1);
    }
  };

  // Override map load from leaflet.bbox.js so
  // we can register our needed event handlers.
  Drupal.leafletBBox.onMapLoad = function(map) {
    Drupal.leafletBBox.map = map;
    Drupal.leafletBBox.markerGroup = new Array();

    // Intialize empty layers and associated controls.
    var layer_count = 0;
    $.each(Drupal.settings.leafletBBox, function(key, value) {
      if (typeof value.url !== 'undefined') {
        // Add empty layers.
        Drupal.leafletBBox.markerGroup[key] = new L.LayerGroup();
        Drupal.leafletBBox.markerGroup[key].addTo(map);

        // Connect layer controls to layer data.
        Drupal.leafletBBox.overlays[value.layer_title]
          = Drupal.leafletBBox.markerGroup[key];

        layer_count++;
      }
    });

    // If we have more than one data layer, add the control.
    if (layer_count > 1) {
      L.control.layers(null, Drupal.leafletBBox.overlays).addTo(map);
    }

    // Adjust aspect ratio of map.
    Drupal.leafletBBox.dimensionMap();

    // Loading a map is the same as moving/zooming.
    map.on('moveend', Drupal.leafletBBox.moveEnd);
    Drupal.leafletBBox.moveEnd();

    // Hook into zoomstart so popups can be closed to allow reclustering.
    map.on('zoomstart', Drupal.leafletBBox.zoomStart);

    // Hook into popup open so we can center the map display on the pin/popup.
    map.on('popupopen', Drupal.leafletBBox.popupOpen);

    // Attach the loadspinner markup.
    var $loadspinner = $('<div>', {
      'class': 'loadspinner'
    }).attr('id', 'loadspinner');
    $('body').append($loadspinner);

    // Animate the spinner sprite.
    $('.loadspinner').animateSprite({
      columns: 12,
      fps: 12,
      loop: true,
      animations: {
        spin: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
      }
    });
  };

  Drupal.leafletBBox.zoomStart = function(e) {
    // Close any open popups.
    Drupal.leafletBBox.map.closePopup();
  };

  Drupal.leafletBBox.popupOpen = function(e) {
    // Center map on open pin/popup.
    var px = Drupal.leafletBBox.map.project(e.popup._latlng);
    px.y -= e.popup._container.clientHeight/2;
    Drupal.leafletBBox.map.panTo(
      Drupal.leafletBBox.map.unproject(px), {animate: true}
    );
  };

  Drupal.leafletBBox.dimensionMap = function() {
    var map = Drupal.leafletBBox.map;

    // Adjust map height/width proportions.
    var aspectRatio = 1.6;
    var $mapHeight = $('#leaflet-map').height();
    var $mapWidth = $('#leaflet-map').width();
    var idealHeight = Math.round($mapWidth / aspectRatio);

    // Set the ideal aspect ratio for the map pane.
    if ($mapHeight != idealHeight) {
      $('#leaflet-map').height(idealHeight);
      map.invalidateSize(true);
    }
  };

  Drupal.behaviors.vista_map = {
    attach: function (context, settings) {
      $(window).resize(function() {
        Drupal.leafletBBox.dimensionMap();
      });
    }
  }

})(jQuery);

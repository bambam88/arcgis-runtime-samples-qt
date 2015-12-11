// [WriteFile Name=MapRotation, Category=Maps]
// [Legal]
// Copyright 2015 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// [Legal]

#include "MapRotation.h"

#include "Map.h"
#include "MapQuickView.h"
#include "Basemap.h"
#include "Viewpoint.h"
#include "Point.h"
#include "SpatialReference.h"

using namespace Esri::ArcGISRuntime;

MapRotation::MapRotation(QQuickItem* parent) :
    QQuickItem(parent),
    m_map(nullptr),
    m_mapView(nullptr)
{
}

MapRotation::~MapRotation()
{
}

void MapRotation::componentComplete()
{
    QQuickItem::componentComplete();

    // find QML MapView component
    m_mapView = findChild<MapQuickView*>("mapView");

    // create a new basemap instance
    Basemap* basemap = Basemap::streets(this);
    // create a new map instance and set the initial viewpoint
    m_map = new Map(basemap, this);
    Viewpoint initialViewpoint(Point(-11070722, 4658720, SpatialReference(102100)), 55151630);
    m_map->setInitialViewpoint(initialViewpoint);
    // set map on the map view
    m_mapView->setMap(m_map);
}

void MapRotation::setMapViewRotation(double degrees)
{
    m_mapView->setViewpointRotation(degrees);
}
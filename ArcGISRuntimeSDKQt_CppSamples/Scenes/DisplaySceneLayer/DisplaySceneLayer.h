// [WriteFile Name=DisplaySceneLayer, Category=Scenes]
// [Legal]
// Copyright 2016 Esri.

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

#ifndef DISPLAYSCENELAYER_H
#define DISPLAYSCENELAYER_H

namespace Esri
{
    namespace ArcGISRuntime
    {
        class Scene;
        class SceneQuickView;
        class ArcGISSceneLayer;
    }
}

#include <QQuickItem>

class DisplaySceneLayer : public QQuickItem
{
    Q_OBJECT

public:
    DisplaySceneLayer(QQuickItem* parent = 0);
    ~DisplaySceneLayer();

    void componentComplete() Q_DECL_OVERRIDE;

private:
    Esri::ArcGISRuntime::Scene* m_scene;
    Esri::ArcGISRuntime::SceneQuickView* m_sceneView;
    Esri::ArcGISRuntime::ArcGISSceneLayer* m_sceneLayer;
};

#endif // DISPLAYSCENELAYER_H

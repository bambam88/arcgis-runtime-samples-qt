// [WriteFile Name=QueryMapImageSublayer, Category=Layers]
// [Legal]
// Copyright 2018 Esri.

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

import QtQuick 2.6
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import Esri.Samples 1.0

QueryMapImageSublayerSample {
    id: rootRectangle
    clip: true
    width: 800
    height: 600

    property real scaleFactor: (Screen.logicalPixelDensity * 25.4) / (Qt.platform.os === "windows" || Qt.platform.os === "linux" ? 96 : 72)

    // add a mapView component
    MapView {
        anchors.fill: parent
        objectName: "mapView"
    }

    Rectangle {
        anchors {
            fill: controlColumn
            margins: -5 * scaleFactor
        }
        color: "#efefef"
        radius: 5 * scaleFactor
        border {
            color: "darkgray"
            width: 1 * scaleFactor
        }
    }

    Column {
        id: controlColumn
        anchors {
            left: parent.left
            top: parent.top
            margins: 10 * scaleFactor
        }
        spacing: 5 * scaleFactor

        Row {
            spacing: 5 * scaleFactor
            Text {
                id: fieldText
                anchors.verticalCenter: parent.verticalCenter
                text: "POP2000 >"
            }

            TextField {
                id: populationText
                anchors.verticalCenter: parent.verticalCenter
                width: 100 * scaleFactor
                text: "1100000"
                validator: IntValidator{}
            }
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Query in extent"
            onClicked: query(fieldText.text + populationText.text);
        }
    }
}

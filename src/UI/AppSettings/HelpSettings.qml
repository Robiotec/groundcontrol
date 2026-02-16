import QtQuick
import QtQuick.Layouts

import QGroundControl
import QGroundControl.Controls

Rectangle {
    color:          qgcPal.window
    anchors.fill:   parent

    readonly property real _margins: ScreenTools.defaultFontPixelHeight

    QGCPalette { id: qgcPal; colorGroupEnabled: true }

    QGCFlickable {
        anchors.margins:    _margins
        anchors.fill:       parent
        contentWidth:       grid.width
        contentHeight:      grid.height
        clip:               true

        GridLayout {
            id:         grid
            columns:    2

            QGCLabel { text: qsTr("Página Web") }
            QGCLabel {
                linkColor:          qgcPal.text
                text:               "<a href=\"https://www.robiotec.ec\">https://www.robiotec.ec</a>"
                onLinkActivated:    (link) => Qt.openUrlExternally(link)
            }

            QGCLabel { text: qsTr("Instagram") }
            QGCLabel {
                linkColor:          qgcPal.text
                text:               "<a href=\"http://www.instagram.com/robiotec.ec\">http://www.instagram.com/robiotec.ec</a>"
                onLinkActivated:    (link) => Qt.openUrlExternally(link)
            }
        }
    }
}

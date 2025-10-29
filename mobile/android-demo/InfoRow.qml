import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

RowLayout {
    id: root
    
    property string label: ""
    property string value: ""
    property color valueColor: Material.foreground
    
    width: parent.width
    spacing: 10
    
    Text {
        Layout.fillWidth: true
        text: root.label + ":"
        font.pixelSize: 14
        color: Material.foreground
        wrapMode: Text.WordWrap
    }
    
    Text {
        Layout.fillWidth: true
        text: root.value
        font.pixelSize: 14
        font.weight: Font.Medium
        color: root.valueColor
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignRight
    }
}

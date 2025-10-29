import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    
    property alias title: titleText.text
    property alias content: contentLoader.sourceComponent
    default property alias children: contentColumn.children
    
    color: Material.backgroundColor
    border.color: Material.frameColor
    border.width: 1
    radius: 8
    
    // 简单的阴影效果（不依赖QtGraphicalEffects）
    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 2
        anchors.leftMargin: 2
        color: "#10000000"
        radius: parent.radius
        z: -1
    }
    
    Column {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12
        
        // 标题
        Text {
            id: titleText
            font.pixelSize: 18
            font.weight: Font.Medium
            color: Material.foreground
            visible: text !== ""
        }
        
        // 内容区域
        Column {
            id: contentColumn
            width: parent.width
            spacing: 8
        }
        
        // 可选的加载器内容
        Loader {
            id: contentLoader
            width: parent.width
        }
    }
}

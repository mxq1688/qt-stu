import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

RowLayout {
    id: root
    
    property string permission: ""
    property string displayName: ""
    
    width: parent.width
    spacing: 10
    
    Text {
        Layout.fillWidth: true
        text: root.displayName
        font.pixelSize: 14
        color: Material.foreground
    }
    
    Text {
        text: androidHelper.checkPermission(root.permission) ? "已授予" : "未授予"
        font.pixelSize: 12
        color: androidHelper.checkPermission(root.permission) ? 
               Material.color(Material.Green) : Material.color(Material.Red)
    }
    
    Button {
        text: "请求"
        Material.background: Material.accent
        enabled: !androidHelper.checkPermission(root.permission)
        onClicked: androidHelper.requestPermission(root.permission)
    }
}

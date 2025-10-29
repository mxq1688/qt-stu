import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: window
    visible: true
    width: 360
    height: 640
    title: "Qt Android Demo"

    Rectangle {
        anchors.fill: parent
        color: "#f0f0f0"
        
        Column {
            anchors.centerIn: parent
            spacing: 20
            
            Text {
                text: "Qt Android Demo"
                font.pixelSize: 24
                font.bold: true
                color: "#333"
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            Text {
                text: "应用运行成功！"
                font.pixelSize: 16
                color: "#666"
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            Button {
                text: "测试按钮"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    text = "点击成功！"
                }
            }
        }
    }
}

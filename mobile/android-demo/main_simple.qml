import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: window
    visible: true
    width: 360
    height: 640
    title: qsTr("Qt Android Demo")

    // Material主题设置
    Material.theme: Material.Light
    Material.primary: Material.Blue
    Material.accent: Material.Orange

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        // 首页
        Page {
            id: homePage
            ScrollView {
                anchors.fill: parent
                anchors.margins: 16

                ColumnLayout {
                    width: parent.width
                    spacing: 16

                    // 标题
                    Text {
                        text: "Qt Android Demo"
                        font.pixelSize: 24
                        font.bold: true
                        color: Material.foreground
                        Layout.fillWidth: true
                        horizontalAlignment: Text.AlignHCenter
                    }

                    // 功能卡片
                    Card {
                        Layout.fillWidth: true
                        title: "基本功能"
                        description: "这是一个简化的Qt Android演示应用"
                        
                        InfoRow {
                            label: "应用名称"
                            value: "Qt Android Demo"
                        }
                        
                        InfoRow {
                            label: "版本"
                            value: "1.0.0"
                        }
                        
                        InfoRow {
                            label: "状态"
                            value: "运行中"
                        }
                    }

                    Card {
                        Layout.fillWidth: true
                        title: "系统信息"
                        
                        InfoRow {
                            label: "平台"
                            value: "Android"
                        }
                        
                        InfoRow {
                            label: "框架"
                            value: "Qt Quick"
                        }
                        
                        InfoRow {
                            label: "主题"
                            value: "Material Design"
                        }
                    }

                    // 操作按钮
                    Button {
                        text: "显示消息"
                        Layout.fillWidth: true
                        onClicked: {
                            messageDialog.text = "这是一个简化的Qt Android演示应用！"
                            messageDialog.open()
                        }
                    }

                    Button {
                        text: "关于应用"
                        Layout.fillWidth: true
                        onClicked: {
                            aboutDialog.open()
                        }
                    }
                }
            }
        }

        // 设置页面
        Page {
            id: settingsPage
            ScrollView {
                anchors.fill: parent
                anchors.margins: 16

                ColumnLayout {
                    width: parent.width
                    spacing: 16

                    Text {
                        text: "设置"
                        font.pixelSize: 24
                        font.bold: true
                        color: Material.foreground
                        Layout.fillWidth: true
                    }

                    Card {
                        Layout.fillWidth: true
                        title: "应用设置"
                        
                        Switch {
                            id: darkModeSwitch
                            text: "深色模式"
                            Layout.fillWidth: true
                            onToggled: {
                                window.Material.theme = checked ? Material.Dark : Material.Light
                            }
                        }
                    }

                    Card {
                        Layout.fillWidth: true
                        title: "主题设置"
                        
                        ComboBox {
                            id: themeCombo
                            model: ["蓝色", "绿色", "橙色", "紫色"]
                            Layout.fillWidth: true
                            onCurrentTextChanged: {
                                var colors = {
                                    "蓝色": Material.Blue,
                                    "绿色": Material.Green,
                                    "橙色": Material.Orange,
                                    "紫色": Material.Purple
                                }
                                window.Material.primary = colors[currentText] || Material.Blue
                            }
                        }
                    }
                }
            }
        }
    }

    // 底部导航栏
    TabBar {
        id: tabBar
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        TabButton {
            text: "首页"
        }
        TabButton {
            text: "设置"
        }
    }

    // 消息对话框
    Dialog {
        id: messageDialog
        title: "消息"
        property alias text: messageText.text
        
        Text {
            id: messageText
            color: Material.foreground
        }
        
        standardButtons: Dialog.Ok
    }

    // 关于对话框
    Dialog {
        id: aboutDialog
        title: "关于"
        width: 300
        
        Column {
            spacing: 16
            
            Text {
                text: "Qt Android Demo"
                font.pixelSize: 18
                font.bold: true
                color: Material.foreground
            }
            
            Text {
                text: "版本: 1.0.0"
                color: Material.foreground
            }
            
            Text {
                text: "这是一个使用Qt Quick开发的Android应用演示。"
                wrapMode: Text.WordWrap
                color: Material.foreground
            }
        }
        
        standardButtons: Dialog.Ok
    }
}

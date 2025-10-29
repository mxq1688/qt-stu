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

    AndroidHelper {
        id: androidHelper
        
        onPermissionResult: {
            permissionDialog.text = "权限 " + permission + " " + (granted ? "已授予" : "被拒绝")
            permissionDialog.open()
        }
    }

    // 权限结果对话框
    Dialog {
        id: permissionDialog
        title: "权限结果"
        property alias text: messageText.text
        
        Text {
            id: messageText
            color: Material.foreground
        }
        
        standardButtons: Dialog.Ok
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        // 首页 - 基本功能演示
        Page {
            id: homePage
            
            ScrollView {
                anchors.fill: parent
                anchors.margins: 20
                
                ColumnLayout {
                    width: parent.width
                    spacing: 20
                    
                    // 设备信息卡片
                    Card {
                        Layout.fillWidth: true
                        title: "设备信息"
                        
                        Column {
                            width: parent.width
                            spacing: 10
                            
                            InfoRow {
                                label: "设备"
                                value: androidHelper.deviceInfo
                            }
                            
                            InfoRow {
                                label: "网络状态"
                                value: androidHelper.isConnected ? "已连接" : "未连接"
                                valueColor: androidHelper.isConnected ? Material.color(Material.Green) : Material.color(Material.Red)
                            }
                        }
                    }
                    
                    // Android功能测试卡片
                    Card {
                        Layout.fillWidth: true
                        title: "Android功能测试"
                        
                        GridLayout {
                            width: parent.width
                            columns: 2
                            columnSpacing: 10
                            rowSpacing: 10
                            
                            Button {
                                Layout.fillWidth: true
                                text: "显示Toast"
                                Material.background: Material.Blue
                                onClicked: androidHelper.showToast("Hello from Qt!")
                            }
                            
                            Button {
                                Layout.fillWidth: true
                                text: "分享文本"
                                Material.background: Material.Green
                                onClicked: androidHelper.shareText("这是来自Qt Android Demo的分享内容！")
                            }
                            
                            Button {
                                Layout.fillWidth: true
                                text: "震动反馈"
                                Material.background: Material.Orange
                                onClicked: androidHelper.vibrate(200)
                            }
                            
                            Button {
                                Layout.fillWidth: true
                                text: "系统设置"
                                Material.background: Material.Purple
                                onClicked: androidHelper.openSystemSettings()
                            }
                        }
                    }
                    
                    // 权限管理卡片
                    Card {
                        Layout.fillWidth: true
                        title: "权限管理"
                        
                        Column {
                            width: parent.width
                            spacing: 10
                            
                            PermissionRow {
                                permission: "android.permission.CAMERA"
                                displayName: "相机权限"
                            }
                            
                            PermissionRow {
                                permission: "android.permission.WRITE_EXTERNAL_STORAGE"
                                displayName: "存储权限"
                            }
                        }
                    }
                }
            }
        }

        // 系统信息页面
        Page {
            id: infoPage
            
            ScrollView {
                anchors.fill: parent
                anchors.margins: 20
                
                Card {
                    width: parent.width
                    title: "系统详细信息"
                    
                    Column {
                        width: parent.width
                        spacing: 15
                        
                        Repeater {
                            model: {
                                var info = androidHelper.getSystemInfo()
                                var keys = Object.keys(info)
                                var result = []
                                for (var i = 0; i < keys.length; i++) {
                                    result.push({key: keys[i], value: info[keys[i]]})
                                }
                                return result
                            }
                            
                            InfoRow {
                                label: modelData.key
                                value: modelData.value.toString()
                            }
                        }
                        
                        Button {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: "刷新信息"
                            Material.background: Material.Indigo
                            onClicked: {
                                // 触发重新绑定
                                var info = androidHelper.getSystemInfo()
                                console.log("System info refreshed:", JSON.stringify(info))
                            }
                        }
                    }
                }
            }
        }

        // UI组件展示页面
        Page {
            id: uiPage
            
            ScrollView {
                anchors.fill: parent
                anchors.margins: 20
                
                ColumnLayout {
                    width: parent.width
                    spacing: 20
                    
                    Card {
                        Layout.fillWidth: true
                        title: "输入组件"
                        
                        Column {
                            width: parent.width
                            spacing: 15
                            
                            TextField {
                                width: parent.width
                                placeholderText: "请输入文本"
                                Material.accent: Material.Blue
                            }
                            
                            ComboBox {
                                width: parent.width
                                model: ["选项1", "选项2", "选项3"]
                            }
                            
                            Slider {
                                width: parent.width
                                from: 0
                                to: 100
                                value: 50
                            }
                        }
                    }
                    
                    Card {
                        Layout.fillWidth: true
                        title: "开关组件"
                        
                        Column {
                            width: parent.width
                            spacing: 15
                            
                            Switch {
                                text: "启用功能A"
                                checked: true
                            }
                            
                            CheckBox {
                                text: "选项B"
                                checked: false
                            }
                            
                            RadioButton {
                                text: "选项C"
                                checked: false
                            }
                        }
                    }
                    
                    Card {
                        Layout.fillWidth: true
                        title: "进度指示器"
                        
                        Column {
                            width: parent.width
                            spacing: 15
                            
                            ProgressBar {
                                width: parent.width
                                value: 0.6
                            }
                            
                            BusyIndicator {
                                anchors.horizontalCenter: parent.horizontalCenter
                                running: true
                            }
                        }
                    }
                }
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        
        TabButton {
            text: qsTr("首页")
            icon.source: "⚡"
        }
        TabButton {
            text: qsTr("系统")
            icon.source: "📱"
        }
        TabButton {
            text: qsTr("组件")
            icon.source: "🎨"
        }
    }
}

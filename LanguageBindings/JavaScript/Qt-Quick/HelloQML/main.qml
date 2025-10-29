import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: window
    visible: true
    width: 400
    height: 300
    title: "QML JavaScript 开发示例"

    // 属性定义
    property int clickCount: 0
    property string currentTime: ""

    // 定时器，每秒更新时间
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: updateTime()
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        // 标题
        Text {
            Layout.alignment: Qt.AlignHCenter
            text: "QML + JavaScript 演示"
            font.pixelSize: 24
            font.bold: true
            color: "#2c3e50"
        }

        // 时间显示
        Rectangle {
            Layout.preferredWidth: 300
            Layout.preferredHeight: 60
            color: "#ecf0f1"
            radius: 10
            border.color: "#bdc3c7"
            border.width: 1

            Text {
                anchors.centerIn: parent
                text: "当前时间: " + currentTime
                font.pixelSize: 16
                color: "#34495e"
            }
        }

        // 计数器显示
        Rectangle {
            Layout.preferredWidth: 300
            Layout.preferredHeight: 60
            color: clickCount > 0 ? "#e8f5e8" : "#f8f9fa"
            radius: 10
            border.color: clickCount > 0 ? "#27ae60" : "#dee2e6"
            border.width: 2

            Text {
                anchors.centerIn: parent
                text: "点击次数: " + clickCount
                font.pixelSize: 18
                font.bold: true
                color: clickCount > 0 ? "#27ae60" : "#6c757d"
            }
        }

        // 按钮组
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 15

            Button {
                text: "点击 +1"
                font.pixelSize: 14
                Material.background: Material.Blue
                
                onClicked: {
                    clickCount++
                    console.log("点击次数增加到:", clickCount)
                    
                    // 每10次点击显示特殊消息
                    if (clickCount % 10 === 0) {
                        showCelebration()
                    }
                }
            }

            Button {
                text: "重置"
                font.pixelSize: 14
                Material.background: Material.Orange
                
                onClicked: resetCounter()
            }

            Button {
                text: "随机数"
                font.pixelSize: 14
                Material.background: Material.Green
                
                onClicked: generateRandomNumber()
            }
        }

        // 消息显示区域
        Text {
            id: messageText
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: 300
            text: "点击按钮开始体验 QML + JavaScript!"
            font.pixelSize: 14
            color: "#7f8c8d"
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
        }
    }

    // JavaScript 函数
    function updateTime() {
        var now = new Date()
        currentTime = now.toLocaleTimeString()
    }

    function resetCounter() {
        clickCount = 0
        messageText.text = "计数器已重置！"
        messageText.color = "#e74c3c"
        
        // 2秒后恢复默认消息
        resetMessageTimer.start()
    }

    function showCelebration() {
        messageText.text = "🎉 恭喜！您已点击 " + clickCount + " 次了！"
        messageText.color = "#27ae60"
        
        // 动画效果
        celebrationAnimation.start()
    }

    function generateRandomNumber() {
        var randomNum = Math.floor(Math.random() * 100) + 1
        messageText.text = "随机数字: " + randomNum + " (1-100之间)"
        messageText.color = "#8e44ad"
        
        console.log("生成随机数:", randomNum)
    }

    // 定时器：重置消息
    Timer {
        id: resetMessageTimer
        interval: 2000
        onTriggered: {
            messageText.text = "继续点击体验更多功能..."
            messageText.color = "#7f8c8d"
        }
    }

    // 庆祝动画
    SequentialAnimation {
        id: celebrationAnimation
        
        PropertyAnimation {
            target: messageText
            property: "scale"
            from: 1.0
            to: 1.2
            duration: 200
        }
        
        PropertyAnimation {
            target: messageText
            property: "scale"
            from: 1.2
            to: 1.0
            duration: 200
        }
    }

    // 组件完成时的初始化
    Component.onCompleted: {
        console.log("QML 应用启动完成")
        updateTime()
    }

    // 窗口关闭前的处理
    onClosing: {
        console.log("应用即将关闭，总点击次数:", clickCount)
    }
}

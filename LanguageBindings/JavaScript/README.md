# QML + JavaScript 开发指南

QML是Qt的声明式UI语言，JavaScript提供逻辑处理，两者结合创造现代化的跨平台应用。

## 🟨 什么是QML？

QML (Qt Modeling Language) 是一种声明式语言，类似于HTML+CSS+JavaScript的组合：
- **QML** = 界面结构和样式 (类似HTML+CSS)
- **JavaScript** = 业务逻辑和交互 (类似JavaScript)

## 🚀 快速开始

### 1. 创建项目
```bash
# 在Qt Creator中：
# File → New File or Project → Application → Qt Quick Application
```

### 2. 基础示例 (main.qml)
```qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "我的第一个QML应用"
    
    property int counter: 0  // 属性定义
    
    Column {
        anchors.centerIn: parent
        spacing: 20
        
        Text {
            text: "计数: " + counter
            font.pixelSize: 24
        }
        
        Button {
            text: "点击+1"
            onClicked: increment()
        }
    }
    
    // JavaScript函数
    function increment() {
        counter++
        console.log("当前计数:", counter)
    }
}
```

## 📖 核心概念

### 属性绑定
```qml
Rectangle {
    width: 200
    height: width * 0.6  // 自动绑定，width变化时height自动更新
    color: mouseArea.pressed ? "red" : "blue"
}
```

### 信号和槽
```qml
Button {
    text: "点击我"
    onClicked: {
        console.log("按钮被点击")
        doSomething()
    }
}

function doSomething() {
    // JavaScript逻辑
}
```

### 定时器
```qml
Timer {
    interval: 1000  // 1秒
    running: true
    repeat: true
    onTriggered: updateTime()
}

function updateTime() {
    currentTime = new Date().toLocaleTimeString()
}
```

### 动画
```qml
PropertyAnimation {
    target: myRect
    property: "x"
    from: 0
    to: 200
    duration: 1000
}
```

## 🎨 常用控件

```qml
// 文本显示
Text { text: "Hello QML" }

// 输入框
TextField { 
    placeholderText: "请输入..."
    onTextChanged: console.log(text)
}

// 按钮
Button {
    text: "确定" 
    onClicked: doAction()
}

// 列表
ListView {
    model: ["项目1", "项目2", "项目3"]
    delegate: Text { text: modelData }
}
```

## 🔧 JavaScript功能

### 数据处理
```javascript
// 在QML中的JavaScript函数
function processData(items) {
    return items.filter(item => item.active)
                .map(item => item.name)
                .sort()
}

function calculateTotal(prices) {
    return prices.reduce((sum, price) => sum + price, 0)
}
```

### HTTP请求
```javascript
function fetchData(url) {
    var xhr = new XMLHttpRequest()
    xhr.onreadystatechange = function() {
        if (xhr.readyState === XMLHttpRequest.DONE) {
            if (xhr.status === 200) {
                var data = JSON.parse(xhr.responseText)
                handleData(data)
            }
        }
    }
    xhr.open("GET", url)
    xhr.send()
}
```

## 🛠️ 开发工具

### Qt Creator快捷键
- **Ctrl+R** - 运行
- **Ctrl+B** - 构建
- **F4** - 在.h/.cpp/.qml文件间切换
- **Ctrl+Space** - 代码补全

### 调试技巧
```javascript
// 控制台输出
console.log("调试信息:", value)
console.warn("警告信息")
console.error("错误信息")

// 性能测试
console.time("操作耗时")
// ... 执行代码
console.timeEnd("操作耗时")
```

## 📁 项目结构
```
MyQmlApp/
├── main.cpp          # C++入口文件
├── main.qml          # 主QML文件
├── components/       # 自定义组件
│   └── MyButton.qml
├── js/              # JavaScript模块
│   └── utils.js
├── qml.qrc          # 资源文件
└── MyQmlApp.pro     # 项目配置
```

## 🎯 最佳实践

1. **组件化开发** - 将复用的UI拆分为组件
2. **属性绑定** - 善用数据绑定减少手动更新
3. **性能优化** - 避免复杂的JavaScript表达式在绑定中
4. **代码分离** - 复杂逻辑放到.js文件中

## 🔗 学习资源

- [完整示例项目](Examples/HelloQML/) - 可直接运行
- [Qt QML文档](https://doc.qt.io/qt-6/qmlapplications.html)
- [JavaScript参考](https://doc.qt.io/qt-6/qtqml-javascript-expressions.html)

---

**提示**: QML特别适合创建现代化、动画丰富的用户界面，是移动应用和桌面应用的理想选择。
# Node-Qt 开发指南

Node-Qt将Qt框架的强大功能带到Node.js生态系统中，让JavaScript开发者可以创建原生桌面应用。

## 🟢 什么是Node-Qt？

Node-Qt是将Qt库绑定到Node.js的项目，主要包括：
- **qt.js** - Qt的Node.js绑定
- **NodeGUI** - 现代化的Node.js桌面应用框架
- **Neutralino.js** - 轻量级跨平台框架

## 🚀 核心特性

### 1. JavaScript原生
```javascript
// 使用熟悉的JavaScript语法
const { QApplication, QMainWindow, QLabel } = require('@nodegui/nodegui');

const app = new QApplication();
const window = new QMainWindow();
const label = new QLabel();

label.setText('Hello from Node.js!');
window.setCentralWidget(label);
window.show();

app.exec();
```

### 2. NPM生态系统
```bash
# 使用npm安装和管理依赖
npm install @nodegui/nodegui
npm install axios lodash moment
```

### 3. 热重载开发
```javascript
// 开发时支持热重载
if (module.hot) {
    module.hot.accept();
}
```

## 📦 主要项目对比

### NodeGUI (推荐)

**特点**：
- 基于Qt5/Qt6
- CSS样式支持
- React绑定可用
- 现代化API设计

**安装和使用**：
```bash
npm install @nodegui/nodegui

# React版本
npm install @nodegui/react-nodegui
```

**基础示例**：
```javascript
const { QApplication, QMainWindow, QWidget, QLabel, QVBoxLayout, QPushButton } = require('@nodegui/nodegui');

// 创建应用
const app = new QApplication();

// 创建主窗口
const window = new QMainWindow();
window.setWindowTitle('Node-Qt Demo');

// 创建中心部件
const centralWidget = new QWidget();
const layout = new QVBoxLayout();

// 创建控件
const label = new QLabel();
label.setText('Hello from Node.js + Qt!');

const button = new QPushButton();
button.setText('点击我');

let clickCount = 0;
button.addEventListener('clicked', () => {
    clickCount++;
    label.setText(`按钮被点击了 ${clickCount} 次`);
});

// 组装界面
layout.addWidget(label);
layout.addWidget(button);
centralWidget.setLayout(layout);
window.setCentralWidget(centralWidget);

// 显示窗口
window.show();
app.exec();
```

### React NodeGUI

```jsx
import React, { useState } from 'react';
import { Renderer, Window, Text, Button, View } from '@nodegui/react-nodegui';

function App() {
    const [count, setCount] = useState(0);

    return (
        <Window windowTitle="React NodeGUI Demo" minSize={{width: 400, height: 300}}>
            <View>
                <Text>计数: {count}</Text>
                <Button text="点击 +1" on={{ clicked: () => setCount(count + 1) }} />
            </View>
        </Window>
    );
}

Renderer.render(<App />);
```

## 🎨 样式和主题

### CSS样式支持
```javascript
const button = new QPushButton();
button.setText('样式按钮');
button.setStyleSheet(`
    QPushButton {
        background-color: #4CAF50;
        border: none;
        color: white;
        padding: 15px 32px;
        font-size: 16px;
        border-radius: 4px;
    }
    QPushButton:hover {
        background-color: #45a049;
    }
`);
```

### 主题切换
```javascript
// 应用全局样式
app.setStyleSheet(`
    QMainWindow {
        background-color: #2b2b2b;
        color: #ffffff;
    }
    QPushButton {
        background-color: #404040;
        color: #ffffff;
    }
`);
```

## 🛠️ 开发环境

### 项目初始化
```bash
# 创建新项目
mkdir my-node-qt-app
cd my-node-qt-app
npm init -y

# 安装NodeGUI
npm install @nodegui/nodegui

# 开发依赖
npm install --save-dev @nodegui/packer nodemon
```

### package.json配置
```json
{
  "scripts": {
    "start": "node index.js",
    "dev": "nodemon index.js",
    "build": "npx @nodegui/packer pack ./index.js",
    "build-win": "npx @nodegui/packer pack ./index.js --target-os win32",
    "build-mac": "npx @nodegui/packer pack ./index.js --target-os darwin"
  }
}
```

## 📊 与其他方案对比

| 特性 | Node-Qt | Electron | Qt Quick |
|------|---------|----------|----------|
| **运行时** | Qt原生 | Chromium | Qt原生 |
| **内存占用** | 低 | 高 | 低 |
| **启动速度** | 快 | 慢 | 快 |
| **包大小** | 中等 | 大 | 小 |
| **Web技术** | 有限支持 | 完整支持 | QML |
| **性能** | 高 | 中等 | 高 |
| **学习曲线** | 中等 | 低 | 中等 |

## 🎯 适用场景

### ✅ 适合Node-Qt的场景
- 需要原生性能的桌面应用
- 已有Node.js技术栈的团队
- 需要与系统深度集成的应用
- 内存和性能敏感的应用

### ❌ 不适合的场景
- 需要复杂Web界面的应用
- 大量使用DOM操作的项目
- 需要Web技术生态的应用

## 🔧 常用功能示例

### 文件操作
```javascript
const { QFileDialog, QMessageBox } = require('@nodegui/nodegui');
const fs = require('fs');

// 文件对话框
const openFile = () => {
    const fileDialog = new QFileDialog();
    fileDialog.setFileMode(QFileDialog.ExistingFile);
    
    if (fileDialog.exec()) {
        const fileName = fileDialog.selectedFiles()[0];
        const content = fs.readFileSync(fileName, 'utf8');
        // 处理文件内容
    }
};
```

### 系统托盘
```javascript
const { QSystemTrayIcon, QMenu, QAction } = require('@nodegui/nodegui');

const trayIcon = new QSystemTrayIcon();
trayIcon.setIcon('./icon.png');

const menu = new QMenu();
const showAction = new QAction();
showAction.setText('显示');
showAction.addEventListener('triggered', () => {
    window.show();
});

menu.addAction(showAction);
trayIcon.setContextMenu(menu);
trayIcon.show();
```

## 📦 打包部署

```bash
# 打包为可执行文件
npx @nodegui/packer pack ./index.js

# 特定平台打包
npx @nodegui/packer pack ./index.js --target-os win32
npx @nodegui/packer pack ./index.js --target-os darwin
npx @nodegui/packer pack ./index.js --target-os linux
```

## 🔗 学习资源

- [NodeGUI官网](https://nodegui.org/)
- [NodeGUI GitHub](https://github.com/nodegui/nodegui)
- [React NodeGUI](https://react.nodegui.org/)
- [示例项目](https://github.com/nodegui/examples)

## ⚠️ 注意事项

1. **平台支持** - 主要支持桌面平台
2. **社区规模** - 相比Electron社区较小
3. **学习成本** - 需要了解Qt概念
4. **调试工具** - 调试工具不如Web开发丰富

---

**Node-Qt为Node.js开发者提供了创建高性能原生桌面应用的能力**，是Electron的轻量级替代方案。

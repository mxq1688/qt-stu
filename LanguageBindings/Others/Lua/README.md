# Lua Qt 开发指南

lqt (Lua Qt) 提供了Lua语言的Qt绑定，适合轻量级GUI应用和嵌入式开发。

## 🌙 Lua Qt特点

- ✅ 轻量级和高性能
- ✅ 简单易学的语法
- ✅ 嵌入式友好
- ⚠️ 生态系统较小
- ⚠️ 高级功能支持有限

## 📦 安装

```bash
# 从源码编译lqt
git clone https://github.com/mkottman/lqt.git
cd lqt
mkdir build && cd build
cmake ..
make && make install
```

## 🚀 快速开始

```lua
#!/usr/bin/env lua

local Qt = require 'qtcore'
local QtGui = require 'qtgui'

-- 创建应用程序
local app = QtGui.QApplication.new_local(1, {'lua-qt-demo'})

-- 创建主窗口
local window = QtGui.QMainWindow()
window:setWindowTitle("Lua Qt Demo")
window:resize(400, 300)

-- 创建中心部件
local central_widget = QtGui.QWidget()
local layout = QtGui.QVBoxLayout()

-- 创建控件
local label = QtGui.QLabel("Hello, Lua Qt!")
local button = QtGui.QPushButton("点击我")

-- 添加到布局
layout:addWidget(label)
layout:addWidget(button)

central_widget:setLayout(layout)
window:setCentralWidget(central_widget)

-- 连接信号和槽
button.clicked:connect(function()
    label:setText("按钮被点击了！")
end)

-- 显示窗口
window:show()

-- 运行应用程序
app.exec()
```

## 🎮 游戏界面示例

```lua
-- 简单的游戏设置界面
local GameSettings = {}

function GameSettings:new()
    local obj = {}
    setmetatable(obj, self)
    self.__index = self
    
    obj:setup_ui()
    
    return obj
end

function GameSettings:setup_ui()
    self.window = QtGui.QDialog()
    self.window:setWindowTitle("游戏设置")
    
    local layout = QtGui.QFormLayout()
    
    -- 音量滑块
    self.volume_slider = QtGui.QSlider(Qt.Horizontal)
    self.volume_slider:setRange(0, 100)
    self.volume_slider:setValue(50)
    layout:addRow("音量:", self.volume_slider)
    
    -- 分辨率选择
    self.resolution_combo = QtGui.QComboBox()
    self.resolution_combo:addItem("1920x1080")
    self.resolution_combo:addItem("1366x768")
    self.resolution_combo:addItem("1280x720")
    layout:addRow("分辨率:", self.resolution_combo)
    
    -- 全屏选项
    self.fullscreen_check = QtGui.QCheckBox("全屏模式")
    layout:addRow(self.fullscreen_check)
    
    self.window:setLayout(layout)
end

function GameSettings:show()
    self.window:show()
end

-- 使用示例
local settings = GameSettings:new()
settings:show()
```

## 🔗 学习资源

- [lqt项目](https://github.com/mkottman/lqt)
- [Lua官方网站](https://www.lua.org/)
- [Qt文档](https://doc.qt.io/)

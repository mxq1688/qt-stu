# Go Qt 开发指南

Go语言的Qt绑定主要通过therecipe/qt项目实现，提供了完整的Qt API访问。

## 🐹 Go Qt绑定特点

- ✅ 完整的Qt API支持
- ✅ 跨平台编译
- ✅ 并发编程支持
- ✅ 静态链接支持
- ⚠️ 较大的二进制文件
- ⚠️ 编译时间较长

## 📦 安装配置

### 环境要求
```bash
# 安装Go (1.16+)
# 安装Qt (5.13+)
# 设置环境变量
export QT_DIR=/path/to/qt
export QT_VERSION=5.15.2
```

### 安装therecipe/qt
```bash
# 安装qt工具
go install -a -tags=no_env github.com/therecipe/qt/cmd/...

# 初始化项目
qtdeploy -docker build desktop
```

## 🚀 快速开始

### 基础窗口
```go
package main

import (
    "os"
    "github.com/therecipe/qt/core"
    "github.com/therecipe/qt/gui"
    "github.com/therecipe/qt/widgets"
)

func main() {
    app := widgets.NewQApplication(len(os.Args), os.Args)
    
    window := widgets.NewQMainWindow(nil, 0)
    window.SetWindowTitle("Go Qt Demo")
    window.Resize2(800, 600)
    
    centralWidget := widgets.NewQWidget(nil, 0)
    layout := widgets.NewQVBoxLayout()
    
    label := widgets.NewQLabel2("Hello, Go Qt!", nil, 0)
    button := widgets.NewQPushButton2("点击我", nil)
    
    layout.AddWidget(label, 0, 0)
    layout.AddWidget(button, 0, 0)
    
    centralWidget.SetLayout(layout)
    window.SetCentralWidget(centralWidget)
    
    // 信号连接
    button.ConnectClicked(func(checked bool) {
        label.SetText("按钮被点击了！")
    })
    
    window.Show()
    app.Exec()
}
```

### 并发处理
```go
func (w *MainWindow) startBackgroundTask() {
    go func() {
        for i := 0; i <= 100; i++ {
            time.Sleep(50 * time.Millisecond)
            
            // 使用QMetaObject在主线程中更新UI
            core.QMetaObject_InvokeMethod(
                w.progressLabel,
                "setText",
                core.Qt__QueuedConnection,
                core.NewQGenericArgument("QString", 
                    core.NewQVariant14(fmt.Sprintf("进度: %d%%", i))),
            )
        }
    }()
}
```

## 🔗 学习资源

- [therecipe/qt项目](https://github.com/therecipe/qt)
- [Go Qt文档](https://pkg.go.dev/github.com/therecipe/qt)
- [示例代码](https://github.com/therecipe/qt/tree/master/internal/examples)

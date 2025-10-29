# C# Qt 开发指南

C#的Qt绑定主要通过Qt.NET (QtSharp) 项目实现，为.NET开发者提供Qt框架访问。

## 🔷 C# Qt绑定特点

- ✅ 完整的.NET集成
- ✅ 面向对象的API设计
- ✅ 垃圾回收支持
- ✅ Visual Studio集成
- ⚠️ 项目维护活跃度一般
- ⚠️ 文档相对较少

## 📦 安装配置

### NuGet包安装
```xml
<PackageReference Include="QtSharp" Version="0.7.0" />
<PackageReference Include="QtSharp.Libs" Version="0.7.0" />
```

### 项目配置
```xml
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>WinExe</OutputType>
    <TargetFramework>net6.0</TargetFramework>
    <UseWindowsForms>false</UseWindowsForms>
  </PropertyGroup>
</Project>
```

## 🚀 快速开始

### 基础窗口
```csharp
using QtCore;
using QtWidgets;
using System;

namespace CSharpQtDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            var app = new QApplication(args);
            
            var window = new QMainWindow();
            window.WindowTitle = "C# Qt Demo";
            window.Resize(800, 600);
            
            var centralWidget = new QWidget();
            var layout = new QVBoxLayout();
            
            var label = new QLabel("Hello, C# Qt!");
            var button = new QPushButton("点击我");
            
            layout.AddWidget(label);
            layout.AddWidget(button);
            
            centralWidget.Layout = layout;
            window.CentralWidget = centralWidget;
            
            // 事件处理
            button.Clicked += (sender, e) => {
                label.Text = "按钮被点击了！";
            };
            
            window.Show();
            QApplication.Exec();
        }
    }
}
```

### 自定义窗口类
```csharp
public class MainWindow : QMainWindow
{
    private QLabel statusLabel;
    private QPushButton actionButton;
    
    public MainWindow() : base()
    {
        SetupUI();
        ConnectEvents();
    }
    
    private void SetupUI()
    {
        WindowTitle = "C# Qt 应用";
        Resize(600, 400);
        
        var centralWidget = new QWidget();
        var layout = new QVBoxLayout();
        
        statusLabel = new QLabel("准备就绪");
        actionButton = new QPushButton("执行操作");
        
        layout.AddWidget(statusLabel);
        layout.AddWidget(actionButton);
        
        centralWidget.Layout = layout;
        CentralWidget = centralWidget;
    }
    
    private void ConnectEvents()
    {
        actionButton.Clicked += OnActionButtonClicked;
    }
    
    private void OnActionButtonClicked(object sender, EventArgs e)
    {
        statusLabel.Text = $"操作执行于: {DateTime.Now:HH:mm:ss}";
    }
}
```

## 🔗 学习资源

- [QtSharp项目](https://github.com/ddobrev/QtSharp)
- [.NET文档](https://docs.microsoft.com/zh-cn/dotnet/)
- [Qt C# 绑定讨论](https://forum.qt.io/topic/73556/c-bindings)

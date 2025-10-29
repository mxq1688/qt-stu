# Qt Android Demo

一个完整的Qt Android应用开发示例，展示了如何使用Qt Quick和C++开发Android应用程序。

## 项目特性

### 🚀 核心功能
- **Material Design界面**: 使用Qt Quick Controls 2的Material主题
- **多页面导航**: 使用SwipeView和TabBar实现页面切换
- **Android原生集成**: 调用Android系统功能和API
- **权限管理**: 动态请求和检查Android权限
- **网络状态监控**: 实时监控网络连接状态

### 📱 Android特性演示
- Toast消息显示
- 系统分享功能
- 震动反馈
- 打开系统设置
- 设备信息获取
- 权限请求处理

### 🎨 UI组件展示
- 输入组件（TextField、ComboBox、Slider）
- 开关组件（Switch、CheckBox、RadioButton）
- 进度指示器（ProgressBar、BusyIndicator）
- 自定义卡片组件

## 项目结构

```
QtAndroidDemo/
├── QtAndroidDemo.pro          # Qt项目文件
├── main.cpp                   # 应用程序入口
├── androidhelper.h            # Android助手类头文件
├── androidhelper.cpp          # Android助手类实现
├── main.qml                   # 主界面QML文件
├── Card.qml                   # 卡片组件
├── InfoRow.qml                # 信息行组件
├── PermissionRow.qml          # 权限行组件
├── qml.qrc                    # QML资源文件
├── android/                   # Android特定配置
│   ├── AndroidManifest.xml    # Android清单文件
│   └── res/                   # Android资源
│       └── values/
│           ├── libs.xml       # Qt库配置
│           └── strings.xml    # 字符串资源
└── README.md                  # 项目说明文档
```

## 环境要求

### 开发环境
- **Qt版本**: Qt 5.15.x 或 Qt 6.x
- **操作系统**: Windows/macOS/Linux
- **Android NDK**: r21e 或更新版本
- **Java JDK**: JDK 8 或 JDK 11

### Qt模块依赖
- Qt Core
- Qt GUI
- Qt Quick
- Qt Quick Controls 2
- Qt Network
- Qt Android Extras (Qt 5.x) / Qt Core (Qt 6.x)

### Android配置
- **最低SDK版本**: API 23 (Android 6.0)
- **目标SDK版本**: API 33 (Android 13)
- **支持架构**: armeabi-v7a, arm64-v8a

## 编译和运行

### 1. 环境配置
确保已安装并配置好以下工具：
- Qt Creator IDE
- Android SDK和NDK
- Java JDK

### 2. Qt Creator配置
1. 打开Qt Creator
2. 配置Android设备套件 (Android Kit)
3. 设置正确的SDK、NDK和JDK路径

### 3. 项目编译
```bash
# 打开项目
在Qt Creator中打开 QtAndroidDemo.pro

# 选择Android套件
选择合适的Android构建套件

# 编译项目
构建 -> 构建项目
```

### 4. 设备运行
1. 连接Android设备或启动模拟器
2. 启用开发者选项和USB调试
3. 点击运行按钮部署到设备

## 代码说明

### AndroidHelper类
`AndroidHelper`是核心的C++类，提供了Android平台的原生功能接口：

```cpp
// 显示Toast消息
androidHelper.showToast("Hello from Qt!")

// 分享文本内容
androidHelper.shareText("分享的内容")

// 检查权限状态
bool hasPermission = androidHelper.checkPermission("android.permission.CAMERA")

// 请求权限
androidHelper.requestPermission("android.permission.CAMERA")
```

### QML界面结构
- **主界面**: `main.qml` - 包含SwipeView和TabBar导航
- **卡片组件**: `Card.qml` - 可复用的Material Design卡片
- **信息组件**: `InfoRow.qml` - 显示键值对信息
- **权限组件**: `PermissionRow.qml` - 权限状态和请求按钮

## 功能展示

### 页面1：首页功能演示
- 设备信息显示
- 网络状态监控
- Android功能测试按钮
- 权限管理界面

### 页面2：系统信息
- 详细的设备和系统信息
- 动态信息刷新

### 页面3：UI组件展示
- 各种Qt Quick控件演示
- Material Design风格展示

## 权限说明

应用请求的权限包括：
- `INTERNET`: 网络访问
- `ACCESS_NETWORK_STATE`: 网络状态检查
- `WRITE_EXTERNAL_STORAGE`: 存储访问
- `CAMERA`: 相机访问（演示用）
- `VIBRATE`: 震动功能

## 开发技巧

### 1. Android调试
```cpp
#ifdef Q_OS_ANDROID
    // Android特定代码
    QAndroidJniObject::callStaticMethod<void>(...)
#else
    // 桌面平台代码
    qDebug() << "Desktop simulation"
#endif
```

### 2. 权限处理
```cpp
// 检查权限
if (androidHelper.checkPermission("android.permission.CAMERA")) {
    // 权限已授予
} else {
    // 需要请求权限
    androidHelper.requestPermission("android.permission.CAMERA")
}
```

### 3. Material主题配置
```qml
// 在main.qml中设置
Material.theme: Material.Light
Material.primary: Material.Blue
Material.accent: Material.Orange
```

## 常见问题

### Q: 编译时找不到Android相关的头文件
A: 检查Qt版本和Qt Android Extras模块是否正确安装

### Q: 应用在设备上无法启动
A: 检查AndroidManifest.xml中的权限和activity配置

### Q: JNI调用失败
A: 确保NDK版本兼容，检查JNI方法签名是否正确

## 扩展建议

1. **添加更多Android功能**：文件选择、相机拍照、GPS定位
2. **网络功能**：HTTP请求、WebSocket连接
3. **数据存储**：SQLite数据库、文件操作
4. **推送通知**：Firebase Cloud Messaging
5. **性能优化**：异步处理、内存管理

## 参考资料

- [Qt for Android官方文档](https://doc.qt.io/qt-5/android.html)
- [Qt Quick Controls 2](https://doc.qt.io/qt-5/qtquickcontrols2-index.html)
- [Android开发者指南](https://developer.android.com/guide)
- [Material Design规范](https://material.io/design)

## 许可证

本项目仅供学习和演示使用，遵循MIT许可证。

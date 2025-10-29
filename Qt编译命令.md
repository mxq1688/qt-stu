
### Qt编译命令

#### 桌面端编译（macOS/Windows/Linux）
```bash
# 进入项目目录
cd /path/to/project

# 生成Makefile
/Users/meng/Qt/6.7.3/macos/bin/qmake ProjectName.pro

# 编译
make

# 安装（可选）
make install
```

#### Android端编译
```bash
# 进入项目目录
cd /path/to/android-project

# 设置环境变量
export ANDROID_NDK_ROOT="/Users/meng/Library/Android/sdk/ndk/27.1.12297006"
export ANDROID_SDK_ROOT="/Users/meng/Library/Android/sdk"

# 使用Android qmake生成Makefile
/Users/meng/Qt/6.7.3/android_arm64_v8a/bin/qmake ProjectName.pro

# 编译
make

# 安装到Android构建目录
make install INSTALL_ROOT=android-build

# 打包APK
/Users/meng/Qt/6.7.3/macos/bin/androiddeployqt \
    --input android-ProjectName-deployment-settings.json \
    --output android-build \
    --android-platform android-35 \
    --ant

# 安装到设备
adb install -r android-build/build/outputs/apk/debug/android-build-debug.apk

# 启动应用
adb shell am start -n package.name/activity.name
```

#### 常用Qt版本路径
- **Qt 6.7.3 LTS** (推荐稳定版本)
  - macOS: `/Users/meng/Qt/6.7.3/macos/bin/qmake`
  - Android ARM64: `/Users/meng/Qt/6.7.3/android_arm64_v8a/bin/qmake`
  - Android ARMv7: `/Users/meng/Qt/6.7.3/android_armv7/bin/qmake`

#### 环境要求
- **Android开发**：
  - Android SDK: `/Users/meng/Library/Android/sdk`
  - Android NDK: `/Users/meng/Library/Android/sdk/ndk/27.1.12297006`
  - JDK: 已安装并配置JAVA_HOME

#### 注意事项
- Qt 6.10.0存在Android稳定性问题，建议使用Qt 6.7.3 LTS
- Android编译需要设置正确的NDK和SDK路径
- 使用`--ant`参数避免Gradle配置问题
- 确保Android设备已连接并启用USB调试
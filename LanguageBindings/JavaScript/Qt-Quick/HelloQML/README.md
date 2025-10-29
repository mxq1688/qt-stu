# HelloQML 项目运行指南

这是一个Qt Quick + QML的完整示例项目。

## 🚀 快速运行

### 使用Qt Creator（推荐）
1. 打开Qt Creator
2. 选择 "打开项目"
3. 选择 `HelloQML.pro` 文件
4. 点击运行按钮 ▶️

### 命令行编译
```bash
# 生成Makefile
qmake HelloQML.pro

# 编译
make

# 运行
./HelloQML
```

## 📋 环境要求

- Qt 5.15+ 或 Qt 6.x
- Qt Creator（可选但推荐）
- macOS/Windows/Linux

## 🎯 项目特性

这个示例展示了：
- ✅ QML声明式UI语法
- ✅ JavaScript逻辑处理
- ✅ 定时器和实时更新
- ✅ 用户交互和事件处理
- ✅ 属性绑定和动画
- ✅ Material Design风格

## 🔧 故障排除

### qmake命令未找到
```bash
# 检查Qt安装
which qmake

# 如果未安装，使用Homebrew安装
brew install qt6
export PATH="/opt/homebrew/opt/qt@6/bin:$PATH"
```

### 编译错误
- 确保Qt版本 >= 5.15
- 检查是否安装了Qt Quick模块
- 验证C++编译器是否可用

## 📖 学习要点

通过这个项目您将学会：
1. QML基础语法和结构
2. JavaScript在QML中的使用
3. Qt Quick控件的使用
4. 属性绑定和信号槽机制
5. 定时器和动画效果

享受Qt Quick开发吧！🎉

#!/usr/bin/env node

// 纯JavaScript的Qt应用 - 可以直接运行！
try {
    const { QApplication, QMainWindow, QWidget, QVBoxLayout, QLabel, QPushButton } = require('@nodegui/nodegui');
    
    console.log("🚀 启动Node.js Qt应用...");
    
    // 创建应用
    const app = new QApplication();
    
    // 创建主窗口
    const window = new QMainWindow();
    window.setWindowTitle('Hello Node-Qt Demo');
    window.resize(400, 300);
    
    // 创建中心部件
    const centralWidget = new QWidget();
    const layout = new QVBoxLayout();
    
    // 创建控件
    const label = new QLabel();
    label.setText('🎉 这是纯JavaScript的Qt应用！');
    
    const timeLabel = new QLabel();
    const button = new QPushButton();
    button.setText('点击我 +1');
    
    let clickCount = 0;
    
    // 更新时间函数
    function updateTime() {
        const now = new Date();
        timeLabel.setText(`当前时间: ${now.toLocaleTimeString()}`);
    }
    
    // 按钮点击事件
    button.addEventListener('clicked', () => {
        clickCount++;
        label.setText(`🎉 按钮被点击了 ${clickCount} 次！`);
        console.log(`点击次数: ${clickCount}`);
    });
    
    // 定时更新时间
    setInterval(updateTime, 1000);
    updateTime();
    
    // 组装界面
    layout.addWidget(label);
    layout.addWidget(timeLabel);
    layout.addWidget(button);
    
    centralWidget.setLayout(layout);
    window.setCentralWidget(centralWidget);
    
    // 显示窗口
    window.show();
    
    console.log("✅ 应用启动成功！");
    console.log("📝 提示：关闭窗口退出应用");
    
    // 运行应用
    app.exec();
    
} catch (error) {
    console.error("❌ 应用启动失败:");
    
    if (error.code === 'MODULE_NOT_FOUND') {
        console.log("\n🔧 解决方案:");
        console.log("1. 安装依赖: npm install @nodegui/nodegui");
        console.log("2. 或运行: npm run install-deps");
        console.log("3. 然后重新运行: node index.js");
    } else {
        console.error(error.message);
    }
}

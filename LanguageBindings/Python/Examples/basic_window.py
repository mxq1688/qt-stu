#!/usr/bin/env python3
"""
Python Qt 基础窗口示例
演示PyQt5/PySide2的基本用法
"""

import sys
import os

# 尝试导入PyQt5，如果失败则尝试PySide2
try:
    from PyQt5.QtWidgets import (QApplication, QMainWindow, QWidget, 
                                 QVBoxLayout, QLabel, QPushButton, 
                                 QMessageBox)
    from PyQt5.QtCore import Qt
    print("使用 PyQt5")
except ImportError:
    try:
        from PySide2.QtWidgets import (QApplication, QMainWindow, QWidget,
                                       QVBoxLayout, QLabel, QPushButton,
                                       QMessageBox)
        from PySide2.QtCore import Qt
        print("使用 PySide2")
    except ImportError:
        print("错误: 请安装 PyQt5 或 PySide2")
        sys.exit(1)


class MainWindow(QMainWindow):
    """主窗口类"""
    
    def __init__(self):
        super().__init__()
        self.click_count = 0
        self.setup_ui()
        self.connect_signals()
    
    def setup_ui(self):
        """设置用户界面"""
        self.setWindowTitle("Python Qt 基础示例")
        self.setGeometry(100, 100, 400, 300)
        
        # 创建中心部件
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        
        # 创建布局
        layout = QVBoxLayout()
        central_widget.setLayout(layout)
        
        # 创建控件
        self.status_label = QLabel("欢迎使用 Python Qt!")
        self.status_label.setAlignment(Qt.AlignCenter)
        
        self.click_button = QPushButton("点击我")
        self.reset_button = QPushButton("重置")
        self.quit_button = QPushButton("退出")
        
        # 添加控件到布局
        layout.addWidget(self.status_label)
        layout.addWidget(self.click_button)
        layout.addWidget(self.reset_button)
        layout.addWidget(self.quit_button)
        
        # 设置样式
        self.setStyleSheet("""
            QMainWindow {
                background-color: #f0f0f0;
            }
            QLabel {
                font-size: 16px;
                font-weight: bold;
                color: #333;
                padding: 20px;
            }
            QPushButton {
                font-size: 14px;
                padding: 10px;
                margin: 5px;
                border-radius: 5px;
                background-color: #4CAF50;
                color: white;
                border: none;
            }
            QPushButton:hover {
                background-color: #45a049;
            }
            QPushButton:pressed {
                background-color: #3d8b40;
            }
        """)
    
    def connect_signals(self):
        """连接信号和槽"""
        self.click_button.clicked.connect(self.on_click_button)
        self.reset_button.clicked.connect(self.on_reset_button)
        self.quit_button.clicked.connect(self.close)
    
    def on_click_button(self):
        """处理点击按钮事件"""
        self.click_count += 1
        self.status_label.setText(f"按钮被点击了 {self.click_count} 次")
        
        # 每10次点击显示一个消息框
        if self.click_count % 10 == 0:
            QMessageBox.information(
                self, 
                "恭喜", 
                f"您已经点击了 {self.click_count} 次!"
            )
    
    def on_reset_button(self):
        """处理重置按钮事件"""
        self.click_count = 0
        self.status_label.setText("计数器已重置")
    
    def closeEvent(self, event):
        """处理窗口关闭事件"""
        reply = QMessageBox.question(
            self, 
            "确认退出", 
            "您确定要退出应用程序吗?",
            QMessageBox.Yes | QMessageBox.No,
            QMessageBox.No
        )
        
        if reply == QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()


def main():
    """主函数"""
    app = QApplication(sys.argv)
    
    # 设置应用程序信息
    app.setApplicationName("Python Qt Demo")
    app.setApplicationVersion("1.0.0")
    app.setOrganizationName("Qt Learning")
    
    # 创建并显示主窗口
    window = MainWindow()
    window.show()
    
    # 运行应用程序
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

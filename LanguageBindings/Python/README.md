# Python Qt 开发指南

Python是Qt最受欢迎的语言绑定，提供PyQt和PySide两个选择。

## 🐍 选择指南

| 特性 | PyQt5/6 | PySide2/6 |
|------|---------|-----------|
| **开发商** | Riverbank Computing | Qt官方 |
| **许可证** | GPL/商业许可 | LGPL/商业许可 |
| **推荐版本** | PyQt5 (稳定) | PySide6 (官方推荐) |

## 📦 快速安装

```bash
# PyQt5 (推荐新手)
pip install PyQt5 PyQt5-tools

# PySide6 (推荐商业项目)
pip install PySide6 pyside6-tools

# 类型提示
pip install PyQt5-stubs  # 或 PySide6-stubs
```

## 🚀 基础示例

```python
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QPushButton, QVBoxLayout, QWidget

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Python Qt Demo")
        
        # 创建布局和控件
        widget = QWidget()
        layout = QVBoxLayout()
        
        label = QLabel("Hello, Python Qt!")
        button = QPushButton("点击我")
        button.clicked.connect(lambda: label.setText("按钮被点击了！"))
        
        layout.addWidget(label)
        layout.addWidget(button)
        widget.setLayout(layout)
        
        self.setCentralWidget(widget)

# 运行应用
app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec_())
```

## 🛠️ 常用工具

```bash
# Qt Designer (可视化设计)
designer  # PyQt5
pyside6-designer  # PySide6

# UI文件转换
pyuic5 form.ui -o form.py  # PyQt5
pyside6-uic form.ui -o form.py  # PySide6
```

## 🎨 样式设置

```python
# 设置样式表
app.setStyleSheet("""
    QPushButton {
        background-color: #4CAF50;
        color: white;
        border-radius: 5px;
        padding: 10px;
    }
    QPushButton:hover {
        background-color: #45a049;
    }
""")
```

## 🔗 学习资源

- [PyQt5官方教程](https://doc.qt.io/qtforpython/)
- [PySide6文档](https://doc.qt.io/qtforpython/)
- [示例代码](Examples/) - 可直接运行的演示

---

**提示**: 对于商业项目推荐使用PySide，对于学习和开源项目PyQt是很好的选择。
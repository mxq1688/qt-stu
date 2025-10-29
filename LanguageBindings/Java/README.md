# Java Qt 开发指南

Java的Qt绑定通过QtJambi项目实现，为Java开发者提供了完整的Qt框架访问能力。

## ☕ QtJambi特点

- ✅ 完整的Qt API支持
- ✅ Java垃圾回收集成
- ✅ 跨平台部署
- ✅ Maven/Gradle支持
- ⚠️ 性能开销相对较大
- ⚠️ 社区活跃度中等

## 📦 安装配置

### Maven配置
```xml
<dependencies>
    <dependency>
        <groupId>io.qtjambi</groupId>
        <artifactId>qtjambi</artifactId>
        <version>6.4.2</version>
    </dependency>
    <dependency>
        <groupId>io.qtjambi</groupId>
        <artifactId>qtjambi-native-windows-x64</artifactId>
        <version>6.4.2</version>
    </dependency>
</dependencies>
```

### Gradle配置
```gradle
dependencies {
    implementation 'io.qtjambi:qtjambi:6.4.2'
    implementation 'io.qtjambi:qtjambi-native-windows-x64:6.4.2'
}
```

## 🚀 快速开始

### 基础窗口
```java
import io.qt.widgets.*;
import io.qt.core.*;

public class JavaQtDemo extends QObject {
    
    public static void main(String[] args) {
        QApplication.initialize(args);
        
        var window = new QMainWindow();
        window.setWindowTitle("Java Qt Demo");
        window.resize(800, 600);
        
        var centralWidget = new QWidget();
        var layout = new QVBoxLayout();
        
        var label = new QLabel("Hello, Java Qt!");
        var button = new QPushButton("点击我");
        
        layout.addWidget(label);
        layout.addWidget(button);
        
        centralWidget.setLayout(layout);
        window.setCentralWidget(centralWidget);
        
        // 信号连接
        button.clicked.connect(() -> {
            label.setText("按钮被点击了！");
        });
        
        window.show();
        QApplication.exec();
    }
}
```

### 自定义组件
```java
public class CustomWidget extends QWidget {
    private QLabel statusLabel;
    private QPushButton actionButton;
    private int counter = 0;
    
    public CustomWidget() {
        setupUI();
        connectSignals();
    }
    
    private void setupUI() {
        var layout = new QVBoxLayout();
        
        statusLabel = new QLabel("计数器: 0");
        actionButton = new QPushButton("增加");
        
        layout.addWidget(statusLabel);
        layout.addWidget(actionButton);
        
        setLayout(layout);
    }
    
    private void connectSignals() {
        actionButton.clicked.connect(this::incrementCounter);
    }
    
    private void incrementCounter() {
        counter++;
        statusLabel.setText("计数器: " + counter);
    }
    
    // 自定义信号
    public final Signal1<Integer> counterChanged = new Signal1<>();
    
    private void incrementCounter() {
        counter++;
        statusLabel.setText("计数器: " + counter);
        counterChanged.emit(counter);
    }
}
```

## 🔗 学习资源

- [QtJambi官网](https://www.qtjambi.org/)
- [QtJambi GitHub](https://github.com/OmixVisualization/qtjambi)
- [Java文档](https://docs.oracle.com/javase/)
- [Qt官方文档](https://doc.qt.io/)

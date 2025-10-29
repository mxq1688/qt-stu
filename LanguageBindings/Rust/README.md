# Rust Qt 开发指南

Rust语言的Qt绑定虽然相对较新，但提供了内存安全和高性能的Qt应用程序开发方式。

## 🦀 Rust Qt绑定概述

### 主要项目
- **ritual**: 自动生成Qt绑定的工具
- **qt_widgets**: Qt Widgets的Rust绑定
- **qt_core**: Qt Core的Rust绑定
- **qt_gui**: Qt GUI的Rust绑定

### 特点
- ✅ 内存安全
- ✅ 零成本抽象
- ✅ 高性能
- ⚠️ 社区相对较小
- ⚠️ 文档有限

## 📦 环境配置

### 系统要求
```bash
# Ubuntu/Debian
sudo apt install build-essential qt5-default qtbase5-dev

# macOS
brew install qt5

# Windows
# 下载并安装Qt官方安装包
```

### Cargo.toml配置
```toml
[package]
name = "rust-qt-app"
version = "0.1.0"
edition = "2021"

[dependencies]
qt_widgets = "0.5"
qt_core = "0.5"
qt_gui = "0.5"

[build-dependencies]
cpp_build = "0.5"
```

### 构建配置
```rust
// build.rs
use cpp_build;

fn main() {
    cpp_build::Config::new()
        .include("/usr/include/qt5")
        .include("/usr/include/qt5/QtCore")
        .include("/usr/include/qt5/QtWidgets")
        .build("src/main.rs");
}
```

## 🚀 快速开始

### 基础窗口示例
```rust
use qt_widgets::{
    QApplication, QMainWindow, QWidget, QVBoxLayout, 
    QLabel, QPushButton, QMessageBox,
    qt_core::{QString, QBox, QPtr, Slot, SlotOfBool},
};

struct MainWindow {
    widget: QBox<QMainWindow>,
    button: QPtr<QPushButton>,
    label: QPtr<QLabel>,
}

impl MainWindow {
    fn new() -> Self {
        unsafe {
            let app = QApplication::new(&[]);
            
            let mut main_window = QMainWindow::new_0a();
            let central_widget = QWidget::new_0a();
            let layout = QVBoxLayout::new_0a();
            
            // 创建标签
            let label = QLabel::from_q_string(&QString::from_std_str("Hello, Rust Qt!"));
            layout.add_widget(&label);
            
            // 创建按钮
            let button = QPushButton::from_q_string(&QString::from_std_str("点击我"));
            layout.add_widget(&button);
            
            central_widget.set_layout(layout.into_ptr());
            main_window.set_central_widget(central_widget.into_ptr());
            main_window.set_window_title(&QString::from_std_str("Rust Qt Demo"));
            
            MainWindow {
                widget: main_window,
                button: button.into_ptr(),
                label: label.into_ptr(),
            }
        }
    }
    
    fn show(&mut self) {
        unsafe {
            self.widget.show();
        }
    }
    
    fn connect_signals(&mut self) {
        unsafe {
            self.button.clicked().connect(&Slot::new(|| {
                let msg_box = QMessageBox::new();
                msg_box.set_text(&QString::from_std_str("按钮被点击了！"));
                msg_box.exec();
            }));
        }
    }
}

fn main() {
    QApplication::init(|_| unsafe {
        let mut window = MainWindow::new();
        window.connect_signals();
        window.show();
        
        QApplication::exec()
    })
}
```

## 🎯 控件使用示例

### 输入控件
```rust
use qt_widgets::{QLineEdit, QTextEdit, QComboBox, QSpinBox};

struct InputDemo {
    line_edit: QPtr<QLineEdit>,
    text_edit: QPtr<QTextEdit>,
    combo_box: QPtr<QComboBox>,
    spin_box: QPtr<QSpinBox>,
}

impl InputDemo {
    fn new() -> Self {
        unsafe {
            // 单行输入
            let line_edit = QLineEdit::new();
            line_edit.set_placeholder_text(&QString::from_std_str("请输入文本"));
            
            // 多行输入
            let text_edit = QTextEdit::new();
            text_edit.set_placeholder_text(&QString::from_std_str("多行文本输入"));
            
            // 下拉框
            let combo_box = QComboBox::new_0a();
            combo_box.add_item_q_string(&QString::from_std_str("选项1"));
            combo_box.add_item_q_string(&QString::from_std_str("选项2"));
            combo_box.add_item_q_string(&QString::from_std_str("选项3"));
            
            // 数值输入
            let spin_box = QSpinBox::new_0a();
            spin_box.set_minimum(0);
            spin_box.set_maximum(100);
            spin_box.set_value(50);
            
            InputDemo {
                line_edit: line_edit.into_ptr(),
                text_edit: text_edit.into_ptr(),
                combo_box: combo_box.into_ptr(),
                spin_box: spin_box.into_ptr(),
            }
        }
    }
    
    fn get_values(&self) -> (String, String, String, i32) {
        unsafe {
            let line_text = self.line_edit.text().to_std_string();
            let text_content = self.text_edit.to_plain_text().to_std_string();
            let combo_text = self.combo_box.current_text().to_std_string();
            let spin_value = self.spin_box.value();
            
            (line_text, text_content, combo_text, spin_value)
        }
    }
}
```

### 表格控件
```rust
use qt_widgets::{QTableWidget, QTableWidgetItem, QHeaderView};

struct TableDemo {
    table: QBox<QTableWidget>,
}

impl TableDemo {
    fn new() -> Self {
        unsafe {
            let mut table = QTableWidget::new_2a(5, 3);
            
            // 设置表头
            let headers = vec!["姓名", "年龄", "城市"];
            for (i, header) in headers.iter().enumerate() {
                let item = QTableWidgetItem::from_q_string(
                    &QString::from_std_str(header)
                );
                table.set_horizontal_header_item(i as i32, item.into_ptr());
            }
            
            // 填充数据
            let data = vec![
                ("张三", "25", "北京"),
                ("李四", "30", "上海"),
                ("王五", "28", "广州"),
            ];
            
            for (row, (name, age, city)) in data.iter().enumerate() {
                let name_item = QTableWidgetItem::from_q_string(
                    &QString::from_std_str(name)
                );
                let age_item = QTableWidgetItem::from_q_string(
                    &QString::from_std_str(age)
                );
                let city_item = QTableWidgetItem::from_q_string(
                    &QString::from_std_str(city)
                );
                
                table.set_item(row as i32, 0, name_item.into_ptr());
                table.set_item(row as i32, 1, age_item.into_ptr());
                table.set_item(row as i32, 2, city_item.into_ptr());
            }
            
            // 调整列宽
            table.horizontal_header().set_stretch_last_section(true);
            
            TableDemo { table }
        }
    }
}
```

## 🔧 信号和槽

### 连接信号和槽
```rust
use qt_core::{Slot, SlotOfBool, SlotOfQString};

struct SignalSlotDemo {
    button: QPtr<QPushButton>,
    label: QPtr<QLabel>,
    line_edit: QPtr<QLineEdit>,
}

impl SignalSlotDemo {
    fn new() -> Self {
        unsafe {
            let button = QPushButton::from_q_string(&QString::from_std_str("点击"));
            let label = QLabel::from_q_string(&QString::from_std_str("等待点击..."));
            let line_edit = QLineEdit::new();
            
            SignalSlotDemo {
                button: button.into_ptr(),
                label: label.into_ptr(),
                line_edit: line_edit.into_ptr(),
            }
        }
    }
    
    fn connect_signals(&mut self) {
        unsafe {
            // 按钮点击信号
            let label_ptr = self.label.clone();
            self.button.clicked().connect(&Slot::new(move || {
                label_ptr.set_text(&QString::from_std_str("按钮被点击了！"));
            }));
            
            // 文本变化信号
            let label_ptr2 = self.label.clone();
            self.line_edit.text_changed().connect(&SlotOfQString::new(move |text| {
                let display_text = format!("输入内容: {}", text.to_std_string());
                label_ptr2.set_text(&QString::from_std_str(&display_text));
            }));
        }
    }
}
```

### 自定义信号
```rust
use qt_core::{QObject, Signal, SlotOfInt};

#[derive(Default)]
struct Counter {
    count: i32,
    value_changed: Signal<(i32,)>,
}

impl Counter {
    fn new() -> Self {
        Counter {
            count: 0,
            value_changed: Signal::new(),
        }
    }
    
    fn increment(&mut self) {
        self.count += 1;
        self.value_changed.emit((self.count,));
    }
    
    fn decrement(&mut self) {
        self.count -= 1;
        self.value_changed.emit((self.count,));
    }
    
    fn connect_value_changed<F>(&self, slot: F) 
    where F: Fn(i32) + 'static 
    {
        self.value_changed.connect(&SlotOfInt::new(slot));
    }
}
```

## 🎨 样式和主题

### 设置样式表
```rust
use qt_widgets::QApplication;

fn apply_dark_theme(app: &QApplication) {
    unsafe {
        let dark_style = r#"
            QMainWindow {
                background-color: #2b2b2b;
                color: #ffffff;
            }
            QPushButton {
                background-color: #404040;
                border: 1px solid #555555;
                padding: 8px;
                border-radius: 4px;
                color: #ffffff;
            }
            QPushButton:hover {
                background-color: #505050;
            }
            QPushButton:pressed {
                background-color: #353535;
            }
            QLineEdit {
                background-color: #404040;
                border: 1px solid #555555;
                padding: 4px;
                color: #ffffff;
            }
        "#;
        
        app.set_style_sheet(&QString::from_std_str(dark_style));
    }
}
```

### 自定义控件样式
```rust
impl MainWindow {
    fn setup_styles(&mut self) {
        unsafe {
            // 按钮样式
            let button_style = r#"
                QPushButton {
                    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                                stop: 0 #4a90e2, stop: 1 #357abd);
                    border-radius: 6px;
                    font-weight: bold;
                    color: white;
                    min-height: 30px;
                }
            "#;
            self.button.set_style_sheet(&QString::from_std_str(button_style));
            
            // 标签样式
            let label_style = r#"
                QLabel {
                    font-size: 16px;
                    font-weight: bold;
                    color: #333333;
                }
            "#;
            self.label.set_style_sheet(&QString::from_std_str(label_style));
        }
    }
}
```

## 🔄 线程和异步

### 使用std::thread
```rust
use std::thread;
use std::sync::{Arc, Mutex};
use qt_core::{QTimer, Slot};

struct AsyncDemo {
    label: QPtr<QLabel>,
    progress_data: Arc<Mutex<i32>>,
    timer: QBox<QTimer>,
}

impl AsyncDemo {
    fn new() -> Self {
        unsafe {
            let label = QLabel::from_q_string(&QString::from_std_str("准备开始..."));
            let progress_data = Arc::new(Mutex::new(0));
            let timer = QTimer::new_0a();
            
            AsyncDemo {
                label: label.into_ptr(),
                progress_data,
                timer,
            }
        }
    }
    
    fn start_background_task(&mut self) {
        let data = Arc::clone(&self.progress_data);
        
        // 后台线程
        thread::spawn(move || {
            for i in 0..=100 {
                {
                    let mut progress = data.lock().unwrap();
                    *progress = i;
                }
                thread::sleep(std::time::Duration::from_millis(50));
            }
        });
        
        // 定时器更新UI
        let label_ptr = self.label.clone();
        let data_ptr = Arc::clone(&self.progress_data);
        
        unsafe {
            self.timer.timeout().connect(&Slot::new(move || {
                let progress = data_ptr.lock().unwrap();
                let text = format!("进度: {}%", *progress);
                label_ptr.set_text(&QString::from_std_str(&text));
            }));
            
            self.timer.start_1a(100); // 每100ms更新一次
        }
    }
}
```

### 使用tokio异步运行时
```toml
[dependencies]
tokio = { version = "1.0", features = ["full"] }
```

```rust
use tokio::time::{sleep, Duration};

async fn fetch_data_async() -> Result<String, Box<dyn std::error::Error>> {
    // 模拟异步HTTP请求
    sleep(Duration::from_secs(2)).await;
    Ok("异步数据获取成功".to_string())
}

impl AsyncDemo {
    fn start_async_task(&mut self) {
        let label_ptr = self.label.clone();
        
        tokio::spawn(async move {
            match fetch_data_async().await {
                Ok(data) => {
                    unsafe {
                        label_ptr.set_text(&QString::from_std_str(&data));
                    }
                }
                Err(e) => {
                    unsafe {
                        let error_text = format!("错误: {}", e);
                        label_ptr.set_text(&QString::from_std_str(&error_text));
                    }
                }
            }
        });
    }
}
```

## 🛠️ 错误处理

### Result模式
```rust
use std::result::Result;

#[derive(Debug)]
enum AppError {
    QtError(String),
    IoError(std::io::Error),
    ParseError(String),
}

impl From<std::io::Error> for AppError {
    fn from(error: std::io::Error) -> Self {
        AppError::IoError(error)
    }
}

struct SafeWindow {
    widget: QBox<QMainWindow>,
}

impl SafeWindow {
    fn new() -> Result<Self, AppError> {
        unsafe {
            let main_window = QMainWindow::new_0a();
            
            // 可能失败的操作
            if main_window.is_null() {
                return Err(AppError::QtError("无法创建主窗口".to_string()));
            }
            
            Ok(SafeWindow {
                widget: main_window,
            })
        }
    }
    
    fn load_config(&mut self, path: &str) -> Result<(), AppError> {
        let config_content = std::fs::read_to_string(path)?;
        
        let config: serde_json::Value = serde_json::from_str(&config_content)
            .map_err(|e| AppError::ParseError(e.to_string()))?;
        
        // 应用配置
        if let Some(title) = config["title"].as_str() {
            unsafe {
                self.widget.set_window_title(&QString::from_std_str(title));
            }
        }
        
        Ok(())
    }
}
```

## 📦 项目结构

### 推荐的项目结构
```
rust-qt-app/
├── Cargo.toml
├── build.rs
├── src/
│   ├── main.rs
│   ├── ui/
│   │   ├── mod.rs
│   │   ├── main_window.rs
│   │   └── dialogs.rs
│   ├── models/
│   │   ├── mod.rs
│   │   └── data_model.rs
│   ├── utils/
│   │   ├── mod.rs
│   │   └── helpers.rs
│   └── errors.rs
├── resources/
│   └── icons/
└── README.md
```

### 模块化代码
```rust
// src/ui/mod.rs
pub mod main_window;
pub mod dialogs;

pub use main_window::MainWindow;
pub use dialogs::*;

// src/ui/main_window.rs
use qt_widgets::*;

pub struct MainWindow {
    widget: QBox<QMainWindow>,
}

impl MainWindow {
    pub fn new() -> Self {
        // 实现...
    }
    
    pub fn show(&mut self) {
        // 实现...
    }
}
```

## ⚡ 性能优化

### 编译优化
```toml
[profile.release]
opt-level = 3
lto = true
codegen-units = 1
panic = "abort"
```

### 内存管理
```rust
use std::rc::Rc;
use std::cell::RefCell;

// 使用智能指针管理Qt对象生命周期
struct OptimizedApp {
    shared_data: Rc<RefCell<AppData>>,
}

impl OptimizedApp {
    fn new() -> Self {
        OptimizedApp {
            shared_data: Rc::new(RefCell::new(AppData::new())),
        }
    }
    
    fn create_window(&self) -> MainWindow {
        MainWindow::new(Rc::clone(&self.shared_data))
    }
}
```

## 🔗 学习资源

- [ritual项目](https://github.com/rust-qt/ritual) - Qt绑定生成器
- [qt_widgets文档](https://docs.rs/qt_widgets/) - API文档
- [Rust Qt示例](https://github.com/rust-qt/examples) - 示例代码
- [Qt官方文档](https://doc.qt.io/) - Qt框架文档

## ⚠️ 注意事项

1. **安全性**: 大量使用unsafe代码，需要谨慎处理
2. **生命周期**: Qt对象的生命周期管理复杂
3. **文档**: 相比其他语言绑定，文档较少
4. **社区**: 社区规模小，问题解决可能较难
5. **稳定性**: API可能会发生变化

---

Rust Qt绑定适合对性能和内存安全有高要求的项目，但需要投入更多时间学习和调试。对于大多数应用，Python或C++可能是更好的选择。

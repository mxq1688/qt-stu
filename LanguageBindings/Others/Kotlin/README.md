# Kotlin Qt 开发指南

Kotlin作为现代JVM语言，可以通过QtJambi或自定义绑定来使用Qt框架，特别适合Android开发者。

## 🎯 Kotlin Qt特点

- ✅ 现代语言特性（空安全、协程等）
- ✅ 与Java生态系统兼容
- ✅ Android开发者友好
- ✅ 简洁的语法
- ⚠️ Qt绑定相对较新
- ⚠️ 文档和示例较少

## 📦 项目配置

### build.gradle.kts
```kotlin
plugins {
    kotlin("jvm") version "1.8.0"
    application
}

dependencies {
    implementation("io.qtjambi:qtjambi:6.4.2")
    implementation("io.qtjambi:qtjambi-native-windows-x64:6.4.2")
}

application {
    mainClass.set("MainKt")
}
```

## 🚀 快速开始

```kotlin
import io.qt.widgets.*
import io.qt.core.*

class MainWindow : QMainWindow() {
    private val statusLabel = QLabel("准备就绪")
    private val actionButton = QPushButton("执行操作")
    private var counter = 0
    
    init {
        setupUI()
        connectSignals()
    }
    
    private fun setupUI() {
        windowTitle = "Kotlin Qt Demo"
        resize(600, 400)
        
        val centralWidget = QWidget()
        val layout = QVBoxLayout().apply {
            addWidget(statusLabel)
            addWidget(actionButton)
        }
        
        centralWidget.layout = layout
        centralWidget = centralWidget
    }
    
    private fun connectSignals() {
        actionButton.clicked.connect(::onActionClicked)
    }
    
    private fun onActionClicked() {
        counter++
        statusLabel.text = "点击次数: $counter"
    }
}

fun main(args: Array<String>) {
    QApplication.initialize(args)
    
    val window = MainWindow()
    window.show()
    
    QApplication.exec()
}
```

### 使用Kotlin协程
```kotlin
import kotlinx.coroutines.*
import io.qt.core.*

class AsyncDemo : QWidget() {
    private val progressLabel = QLabel("等待开始...")
    private val startButton = QPushButton("开始任务")
    
    init {
        setupUI()
        startButton.clicked.connect(::startAsyncTask)
    }
    
    private fun setupUI() {
        val layout = QVBoxLayout().apply {
            addWidget(progressLabel)
            addWidget(startButton)
        }
        setLayout(layout)
    }
    
    private fun startAsyncTask() {
        startButton.isEnabled = false
        
        // 使用协程执行后台任务
        GlobalScope.launch {
            for (i in 0..100) {
                delay(50)
                
                // 在UI线程中更新界面
                QCoreApplication.invokeLater {
                    progressLabel.text = "进度: $i%"
                    
                    if (i == 100) {
                        startButton.isEnabled = true
                        progressLabel.text = "任务完成！"
                    }
                }
            }
        }
    }
}
```

### 数据类和密封类的应用
```kotlin
data class UserInfo(
    val name: String,
    val age: Int,
    val email: String
)

sealed class AppState {
    object Loading : AppState()
    data class Success(val data: List<UserInfo>) : AppState()
    data class Error(val message: String) : AppState()
}

class UserListWidget : QWidget() {
    private val listWidget = QListWidget()
    private val statusLabel = QLabel()
    
    init {
        setupUI()
    }
    
    private fun setupUI() {
        val layout = QVBoxLayout().apply {
            addWidget(statusLabel)
            addWidget(listWidget)
        }
        setLayout(layout)
    }
    
    fun updateState(state: AppState) {
        when (state) {
            is AppState.Loading -> {
                statusLabel.text = "加载中..."
                listWidget.clear()
            }
            is AppState.Success -> {
                statusLabel.text = "加载完成 (${state.data.size} 项)"
                listWidget.clear()
                state.data.forEach { user ->
                    listWidget.addItem("${user.name} (${user.age}岁)")
                }
            }
            is AppState.Error -> {
                statusLabel.text = "错误: ${state.message}"
                listWidget.clear()
            }
        }
    }
}
```

## 🔗 学习资源

- [Kotlin官方文档](https://kotlinlang.org/docs/)
- [QtJambi文档](https://www.qtjambi.org/)
- [Kotlin协程](https://kotlinlang.org/docs/coroutines-overview.html)

---

Kotlin的现代语言特性使得Qt开发更加简洁和安全，特别适合有Android开发经验的团队。

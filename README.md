### 标准 Qt（Qt 5/6）：面向带操作系统的平台，在其基础上开发应用
- 桌面：Windows / macOS / Linux
- 移动：Android / iOS
- 嵌入式 Linux：树莓派、i.MX、RK、TI 等 SoC 上的 Linux（也算“Linux”阵营）

### 面向无操作系统
- Qt for MCUs（Qt Quick Ultralite）：面向无 MMU 的微控制器（如 STM32H7、i.MX RT），通常跑在裸机或轻量 RTOS（FreeRTOS/Zephyr）；不是完整操作系统，也不等同于标准 Qt。

- WebAssembly：Qt 还能编译到浏览器运行（WASM），但这不属于本地 OS 应用。Qt 可以用 Emscripten 把你的 Qt 程序编译成 .wasm + .js + .html，在浏览器中运行。

### 快速判断
- 有操作系统（Windows/macOS/Linux/Android/iOS/嵌入式 Linux）→ 用 **标准 Qt** 开发应用。
- 没有操作系统/资源紧张的 MCU → 用 **Qt for MCUs**（或 **LVGL/TouchGFX** 等替代）。

### 目录结构
- `Desktop/`：桌面端（Windows/macOS/Linux）相关内容与示例
- `Mobile/`：移动端（Android/iOS）相关内容与示例
- `Embedded/`：嵌入式端（嵌入式 Linux、Qt for MCUs、LVGL/TouchGFX）内容
- `Qt-Mcu/`：Qt for MCUs（QUL）入门与平台移植
- `Others/`：其他（WASM、脚本、共享文档等）

### 示例工程
- Android 最小示例：`Mobile/android-demo/`（Qt Quick + CMake，可直接用 Qt Creator Android Kit 打开）

### 其他语言QT库
- LanguageBindings

# Ruby Qt 开发指南

QtRuby为Ruby开发者提供了Qt框架的访问能力，适合快速原型开发和脚本工具创建。

## 💎 QtRuby特点

- ✅ Ruby动态语言特性
- ✅ 快速开发和原型制作
- ✅ 简洁的语法
- ⚠️ 性能相对较低
- ⚠️ 社区支持有限

## 📦 安装

```bash
# 安装qtruby gem
gem install qtruby4

# 或使用Bundler
echo 'gem "qtruby4"' >> Gemfile
bundle install
```

## 🚀 快速开始

```ruby
#!/usr/bin/env ruby

require 'Qt4'

class MainWindow < Qt::MainWindow
  def initialize
    super
    
    setup_ui
    connect_signals
    
    self.window_title = "Ruby Qt Demo"
    resize(400, 300)
  end
  
  private
  
  def setup_ui
    central_widget = Qt::Widget.new
    layout = Qt::VBoxLayout.new
    
    @label = Qt::Label.new("Hello, Ruby Qt!")
    @button = Qt::PushButton.new("点击我")
    
    layout.add_widget(@label)
    layout.add_widget(@button)
    
    central_widget.layout = layout
    self.central_widget = central_widget
  end
  
  def connect_signals
    @button.connect(SIGNAL('clicked()')) { button_clicked }
  end
  
  def button_clicked
    @label.text = "按钮被点击了！"
  end
end

# 应用程序入口
app = Qt::Application.new(ARGV)
window = MainWindow.new
window.show
app.exec
```

## 🔗 学习资源

- [QtRuby项目](https://techbase.kde.org/Development/Languages/Ruby)
- [Ruby官方文档](https://ruby-doc.org/)

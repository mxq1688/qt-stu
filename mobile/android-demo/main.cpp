#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QObject>
#include <QUrl>
#include <QStringLiteral>
#include <QCoreApplication>
#include <Qt>
#include "androidhelper.h"

int main(int argc, char *argv[])
{
    // Qt 6中高DPI支持已自动启用，无需手动设置
    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    
    // 设置应用信息
    app.setApplicationName("Qt Android Demo");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Qt Learning");
    
    // 设置Material主题
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    
    // 注册AndroidHelper到QML
    qmlRegisterType<AndroidHelper>("AndroidHelper", 1, 0, "AndroidHelper");
    
    // 创建AndroidHelper实例并暴露给QML
    AndroidHelper androidHelper;
    engine.rootContext()->setContextProperty("androidHelper", &androidHelper);
    
    // 加载QML文件
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
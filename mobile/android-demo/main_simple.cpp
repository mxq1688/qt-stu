#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    // 设置应用信息
    app.setApplicationName("Qt Android Demo");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Qt Learning");
    
    // 设置Material主题
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    
    // 加载QML文件
    const QUrl url(QStringLiteral("qrc:/main_simple.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

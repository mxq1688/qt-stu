#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    app.setApplicationName("Qt Android Demo");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Qt Learning");

    QQmlApplicationEngine engine;
    
    // 加载最简单的QML
    const QUrl url(QStringLiteral("qrc:/main_minimal.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    app.setApplicationName("Qt Android Core Demo");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Qt Learning");

    qDebug() << "Qt Android Core Demo started successfully!";
    qDebug() << "Application name:" << app.applicationName();
    qDebug() << "Application version:" << app.applicationVersion();
    qDebug() << "Organization name:" << app.organizationName();

    // 运行5秒后退出
    QTimer::singleShot(5000, &app, &QCoreApplication::quit);
    
    return app.exec();
}

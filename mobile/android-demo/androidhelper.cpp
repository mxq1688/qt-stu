#include "androidhelper.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QObject>
#include <QString>
#include <QVariantMap>

#ifdef Q_OS_ANDROID
#include <QJniObject>
#include <QJniEnvironment>
#include <QCoreApplication>
#endif

AndroidHelper::AndroidHelper(QObject *parent)
    : QObject(parent)
    , m_networkManager(new QNetworkAccessManager(this))
{
    // 初始化网络状态监控
    updateConnectionStatus();
    
    // 定时更新网络状态
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AndroidHelper::updateConnectionStatus);
    timer->start(5000); // 每5秒检查一次
}

void AndroidHelper::showToast(const QString &message)
{
#ifdef Q_OS_ANDROID
    QJniObject javaString = QJniObject::fromString(message);
    QJniObject context = QJniObject(QJniObject::callStaticObjectMethod(
        "org/qtproject/qt/android/QtNative", 
        "activity", 
        "()Landroid/app/Activity;"));
    
    QJniObject toast = QJniObject::callStaticObjectMethod(
        "android/widget/Toast",
        "makeText",
        "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;",
        context.object<jobject>(),
        javaString.object<jstring>(),
        jint(1) // Toast.LENGTH_SHORT
    );
    toast.callMethod<void>("show");
#else
    qDebug() << "Toast:" << message;
#endif
}

void AndroidHelper::shareText(const QString &text)
{
#ifdef Q_OS_ANDROID
    QJniObject javaString = QJniObject::fromString(text);
    QJniObject intent("android/content/Intent");
    
    if (intent.isValid()) {
        QJniObject action = QJniObject::getStaticObjectField(
            "android/content/Intent", "ACTION_SEND", "Ljava/lang/String;");
        intent.callObjectMethod("setAction", "(Ljava/lang/String;)Landroid/content/Intent;", action.object<jstring>());
        
        intent.callObjectMethod("setType", "(Ljava/lang/String;)Landroid/content/Intent;",
                               QJniObject::fromString("text/plain").object<jstring>());
        
        QJniObject extraText = QJniObject::getStaticObjectField(
            "android/content/Intent", "EXTRA_TEXT", "Ljava/lang/String;");
        intent.callObjectMethod("putExtra",
                               "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;",
                               extraText.object<jstring>(), javaString.object<jstring>());
        
        QJniObject chooser = QJniObject::callStaticObjectMethod(
            "android/content/Intent", "createChooser",
            "(Landroid/content/Intent;Ljava/lang/CharSequence;)Landroid/content/Intent;",
            intent.object<jobject>(), QJniObject::fromString("分享到").object<jstring>());
        
        QJniObject context = QJniObject(QJniObject::callStaticObjectMethod(
            "org/qtproject/qt/android/QtNative", 
            "activity", 
            "()Landroid/app/Activity;"));
        context.callMethod<void>(
            "startActivity", "(Landroid/content/Intent;)V", chooser.object<jobject>());
    }
#else
    qDebug() << "Share:" << text;
#endif
}

QVariantMap AndroidHelper::getDeviceInfo()
{
    QVariantMap info;
    
#ifdef Q_OS_ANDROID
    // 获取设备信息
    QJniObject build("android/os/Build");
    info["manufacturer"] = build.getStaticObjectField("MANUFACTURER", "Ljava/lang/String;").toString();
    info["model"] = build.getStaticObjectField("MODEL", "Ljava/lang/String;").toString();
    info["brand"] = build.getStaticObjectField("BRAND", "Ljava/lang/String;").toString();
    info["device"] = build.getStaticObjectField("DEVICE", "Ljava/lang/String;").toString();
    
    QJniObject version("android/os/Build$VERSION");
    info["androidVersion"] = version.getStaticObjectField("RELEASE", "Ljava/lang/String;").toString();
    info["sdkVersion"] = version.getStaticField<jint>("SDK_INT");
#else
    info["manufacturer"] = "Desktop";
    info["model"] = "Computer";
    info["brand"] = "Qt";
    info["device"] = "Desktop";
    info["androidVersion"] = "N/A";
    info["sdkVersion"] = 0;
#endif
    
    return info;
}

void AndroidHelper::updateConnectionStatus()
{
#ifdef Q_OS_ANDROID
    // Qt 6中网络状态检查简化
    bool isOnline = m_networkManager->networkAccessible() == QNetworkAccessManager::Accessible;
    
    if (isOnline != m_isConnected) {
        m_isConnected = isOnline;
        emit connectionStatusChanged(m_isConnected);
    }
#else
    // 桌面版本假设总是连接
    if (!m_isConnected) {
        m_isConnected = true;
        emit connectionStatusChanged(m_isConnected);
    }
#endif
}

bool AndroidHelper::checkPermission(const QString &permission)
{
#ifdef Q_OS_ANDROID
    // Qt 6中权限检查简化
    QJniObject context = QJniObject(QJniObject::callStaticObjectMethod(
        "org/qtproject/qt/android/QtNative", 
        "activity", 
        "()Landroid/app/Activity;"));
    QJniObject packageManager = context.callObjectMethod("getPackageManager", "()Landroid/content/pm/PackageManager;");
    
    jint result = context.callMethod<jint>("checkPermission", 
        "(Ljava/lang/String;Ljava/lang/String;)I",
        QJniObject::fromString(permission).object<jstring>(),
        QJniObject::fromString("").object<jstring>());
    
    return result == 0; // PackageManager.PERMISSION_GRANTED
#else
    Q_UNUSED(permission)
    return true; // 桌面版本假设有所有权限
#endif
}

void AndroidHelper::requestPermission(const QString &permission)
{
#ifdef Q_OS_ANDROID
    // Qt 6中权限请求简化
    bool hasPermission = checkPermission(permission);
    if (!hasPermission) {
        // 这里可以添加权限请求逻辑
        qDebug() << "Requesting permission:" << permission;
    }
    emit permissionResult(permission, hasPermission);
#else
    Q_UNUSED(permission)
    emit permissionResult(permission, true);
#endif
}

void AndroidHelper::openSystemSettings()
{
#ifdef Q_OS_ANDROID
    QJniObject intent("android/content/Intent");
    QJniObject action = QJniObject::fromString("android.settings.APPLICATION_DETAILS_SETTINGS");
    intent.callObjectMethod("setAction", "(Ljava/lang/String;)Landroid/content/Intent;", action.object<jstring>());
    
    // 获取包名
    QJniObject context = QJniObject(QJniObject::callStaticObjectMethod(
        "org/qtproject/qt/android/QtNative", 
        "activity", 
        "()Landroid/app/Activity;"));
    QJniObject packageName = context.callObjectMethod("getPackageName", "()Ljava/lang/String;");
    QJniObject uri = QJniObject::callStaticObjectMethod(
        "android/net/Uri", "fromParts",
        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/net/Uri;",
        QJniObject::fromString("package").object<jstring>(),
        packageName.object<jstring>(),
        QJniObject::fromString("").object<jstring>());
    
    intent.callObjectMethod("setData", "(Landroid/net/Uri;)Landroid/content/Intent;", uri.object<jobject>());
    
    context.callMethod<void>(
        "startActivity", "(Landroid/content/Intent;)V", intent.object<jobject>());
#else
    qDebug() << "Opening system settings...";
#endif
}

void AndroidHelper::vibrate(int milliseconds)
{
#ifdef Q_OS_ANDROID
    QJniObject context = QJniObject(QJniObject::callStaticObjectMethod(
        "org/qtproject/qt/android/QtNative", 
        "activity", 
        "()Landroid/app/Activity;"));
    QJniObject serviceName = QJniObject::getStaticObjectField(
        "android/content/Context", "VIBRATOR_SERVICE", "Ljava/lang/String;");
    
    QJniObject vibrator = context.callObjectMethod(
        "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;", serviceName.object<jstring>());
    
    if (vibrator.isValid()) {
        vibrator.callMethod<void>("vibrate", "(J)V", jlong(milliseconds));
    }
#else
    Q_UNUSED(milliseconds)
    qDebug() << "Vibrating for" << milliseconds << "ms";
#endif
}
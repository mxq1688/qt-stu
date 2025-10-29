#ifndef ANDROIDHELPER_H
#define ANDROIDHELPER_H

#include <QObject>
#include <QString>
#include <QVariant>

class AndroidHelper : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString deviceInfo READ deviceInfo NOTIFY deviceInfoChanged)
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionChanged)
    
public:
    explicit AndroidHelper(QObject *parent = nullptr);
    
    // 获取设备信息
    QString deviceInfo() const;
    
    // 检查网络连接状态
    bool isConnected() const;
    
public slots:
    // 显示Android原生Toast消息
    void showToast(const QString &message);
    
    // 分享文本内容
    void shareText(const QString &text);
    
    // 获取Android系统信息
    QVariantMap getSystemInfo();
    
    // 检查权限
    bool checkPermission(const QString &permission);
    
    // 请求权限
    void requestPermission(const QString &permission);
    
    // 打开系统设置
    void openSystemSettings();
    
    // 振动功能
    void vibrate(int duration = 100);
    
signals:
    void deviceInfoChanged();
    void connectionChanged();
    void permissionResult(const QString &permission, bool granted);
    
private slots:
    void updateConnectionStatus();
    
private:
    QString m_deviceInfo;
    bool m_isConnected;
    
    void initializeAndroidFeatures();
};

#endif // ANDROIDHELPER_H

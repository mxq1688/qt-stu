QT += core

CONFIG += c++17

SOURCES += main_core.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    
    # Android SDK版本配置
    ANDROID_MIN_SDK_VERSION = 28
    ANDROID_TARGET_SDK_VERSION = 33
}

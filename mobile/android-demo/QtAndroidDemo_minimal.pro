QT += quick core gui

CONFIG += c++17

SOURCES += main_minimal.cpp

RESOURCES += qml_minimal.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    
    # Android SDK版本配置
    ANDROID_MIN_SDK_VERSION = 23
    ANDROID_TARGET_SDK_VERSION = 34
}

QT += quick quickcontrols2

CONFIG += c++17

TARGET = HelloQML
TEMPLATE = app

SOURCES += main.cpp

RESOURCES += qml.qrc

# 默认部署规则
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

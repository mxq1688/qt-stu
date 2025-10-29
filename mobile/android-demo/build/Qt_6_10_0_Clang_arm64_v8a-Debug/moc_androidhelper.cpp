/****************************************************************************
** Meta object code from reading C++ file 'androidhelper.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../androidhelper.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'androidhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13AndroidHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto AndroidHelper::qt_create_metaobjectdata<qt_meta_tag_ZN13AndroidHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AndroidHelper",
        "deviceInfoChanged",
        "",
        "connectionChanged",
        "permissionResult",
        "permission",
        "granted",
        "showToast",
        "message",
        "shareText",
        "text",
        "getSystemInfo",
        "QVariantMap",
        "checkPermission",
        "requestPermission",
        "openSystemSettings",
        "vibrate",
        "duration",
        "updateConnectionStatus",
        "deviceInfo",
        "isConnected"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'deviceInfoChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connectionChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'permissionResult'
        QtMocHelpers::SignalData<void(const QString &, bool)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::Bool, 6 },
        }}),
        // Slot 'showToast'
        QtMocHelpers::SlotData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'shareText'
        QtMocHelpers::SlotData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'getSystemInfo'
        QtMocHelpers::SlotData<QVariantMap()>(11, 2, QMC::AccessPublic, 0x80000000 | 12),
        // Slot 'checkPermission'
        QtMocHelpers::SlotData<bool(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 5 },
        }}),
        // Slot 'requestPermission'
        QtMocHelpers::SlotData<void(const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Slot 'openSystemSettings'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'vibrate'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'vibrate'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'updateConnectionStatus'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'deviceInfo'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'isConnected'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AndroidHelper, qt_meta_tag_ZN13AndroidHelperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AndroidHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AndroidHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AndroidHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13AndroidHelperE_t>.metaTypes,
    nullptr
} };

void AndroidHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AndroidHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->deviceInfoChanged(); break;
        case 1: _t->connectionChanged(); break;
        case 2: _t->permissionResult((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 3: _t->showToast((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->shareText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: { QVariantMap _r = _t->getSystemInfo();
            if (_a[0]) *reinterpret_cast<QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->checkPermission((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->requestPermission((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->openSystemSettings(); break;
        case 9: _t->vibrate((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->vibrate(); break;
        case 11: _t->updateConnectionStatus(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AndroidHelper::*)()>(_a, &AndroidHelper::deviceInfoChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AndroidHelper::*)()>(_a, &AndroidHelper::connectionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AndroidHelper::*)(const QString & , bool )>(_a, &AndroidHelper::permissionResult, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->deviceInfo(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isConnected(); break;
        default: break;
        }
    }
}

const QMetaObject *AndroidHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AndroidHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AndroidHelperE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AndroidHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AndroidHelper::deviceInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AndroidHelper::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AndroidHelper::permissionResult(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}
QT_WARNING_POP

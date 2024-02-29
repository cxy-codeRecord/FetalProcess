/****************************************************************************
** Meta object code from reading C++ file 'CWidgetViewManage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interface/WidgetView/CWidgetViewManage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CWidgetViewManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CWidgetViewManage_t {
    QByteArrayData data[9];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CWidgetViewManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CWidgetViewManage_t qt_meta_stringdata_CWidgetViewManage = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CWidgetViewManage"
QT_MOC_LITERAL(1, 18, 20), // "signalRequestService"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 31), // "QSharedPointer<CDataStreamBase>"
QT_MOC_LITERAL(4, 72, 4), // "pack"
QT_MOC_LITERAL(5, 77, 18), // "signalRecvResponse"
QT_MOC_LITERAL(6, 96, 14), // "onRecvResponse"
QT_MOC_LITERAL(7, 111, 8), // "funcName"
QT_MOC_LITERAL(8, 120, 12) // "responsePack"

    },
    "CWidgetViewManage\0signalRequestService\0"
    "\0QSharedPointer<CDataStreamBase>\0pack\0"
    "signalRecvResponse\0onRecvResponse\0"
    "funcName\0responsePack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CWidgetViewManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    7,    8,

       0        // eod
};

void CWidgetViewManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CWidgetViewManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRequestService((*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[1]))); break;
        case 1: _t->signalRecvResponse((*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[1]))); break;
        case 2: _t->onRecvResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CWidgetViewManage::*)(const QSharedPointer<CDataStreamBase> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CWidgetViewManage::signalRequestService)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CWidgetViewManage::*)(const QSharedPointer<CDataStreamBase> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CWidgetViewManage::signalRecvResponse)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CWidgetViewManage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CWidgetViewManage.data,
    qt_meta_data_CWidgetViewManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CWidgetViewManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CWidgetViewManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CWidgetViewManage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CWidgetViewManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CWidgetViewManage::signalRequestService(const QSharedPointer<CDataStreamBase> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CWidgetViewManage::signalRecvResponse(const QSharedPointer<CDataStreamBase> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

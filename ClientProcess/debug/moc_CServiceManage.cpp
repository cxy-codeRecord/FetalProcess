/****************************************************************************
** Meta object code from reading C++ file 'CServiceManage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interface/Service/CServiceManage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CServiceManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CServiceManage_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CServiceManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CServiceManage_t qt_meta_stringdata_CServiceManage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CServiceManage"
QT_MOC_LITERAL(1, 15, 18), // "signalSendResponse"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "funcName"
QT_MOC_LITERAL(4, 44, 31), // "QSharedPointer<CDataStreamBase>"
QT_MOC_LITERAL(5, 76, 12), // "responsePack"
QT_MOC_LITERAL(6, 89, 16), // "onRequestService"
QT_MOC_LITERAL(7, 106, 4) // "pack"

    },
    "CServiceManage\0signalSendResponse\0\0"
    "funcName\0QSharedPointer<CDataStreamBase>\0"
    "responsePack\0onRequestService\0pack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CServiceManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    7,

       0        // eod
};

void CServiceManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CServiceManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSendResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[2]))); break;
        case 1: _t->onRequestService((*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CServiceManage::*)(const QString , const QSharedPointer<CDataStreamBase> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CServiceManage::signalSendResponse)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CServiceManage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CServiceManage.data,
    qt_meta_data_CServiceManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CServiceManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CServiceManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CServiceManage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CServiceManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CServiceManage::signalSendResponse(const QString _t1, const QSharedPointer<CDataStreamBase> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

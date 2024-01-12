/****************************************************************************
** Meta object code from reading C++ file 'CWidgetViewManage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Interface/WidgetView/CWidgetViewManage.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CWidgetViewManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_CWidgetViewManage_t {
    uint offsetsAndSizes[16];
    char stringdata0[18];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[5];
    char stringdata5[20];
    char stringdata6[18];
    char stringdata7[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CWidgetViewManage_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CWidgetViewManage_t qt_meta_stringdata_CWidgetViewManage = {
    {
        QT_MOC_LITERAL(0, 17),  // "CWidgetViewManage"
        QT_MOC_LITERAL(18, 21),  // "signal_RequestService"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 31),  // "QSharedPointer<CDataStreamBase>"
        QT_MOC_LITERAL(73, 4),  // "pack"
        QT_MOC_LITERAL(78, 19),  // "signal_RecvResponse"
        QT_MOC_LITERAL(98, 17),  // "slot_RecvResponse"
        QT_MOC_LITERAL(116, 12)   // "responsePack"
    },
    "CWidgetViewManage",
    "signal_RequestService",
    "",
    "QSharedPointer<CDataStreamBase>",
    "pack",
    "signal_RecvResponse",
    "slot_RecvResponse",
    "responsePack"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CWidgetViewManage[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       5,    1,   35,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   38,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject CWidgetViewManage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CWidgetViewManage.offsetsAndSizes,
    qt_meta_data_CWidgetViewManage,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CWidgetViewManage_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CWidgetViewManage, std::true_type>,
        // method 'signal_RequestService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSharedPointer<CDataStreamBase> &, std::false_type>,
        // method 'signal_RecvResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSharedPointer<CDataStreamBase>, std::false_type>,
        // method 'slot_RecvResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSharedPointer<CDataStreamBase>, std::false_type>
    >,
    nullptr
} };

void CWidgetViewManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CWidgetViewManage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_RequestService((*reinterpret_cast< std::add_pointer_t<QSharedPointer<CDataStreamBase>>>(_a[1]))); break;
        case 1: _t->signal_RecvResponse((*reinterpret_cast< std::add_pointer_t<QSharedPointer<CDataStreamBase>>>(_a[1]))); break;
        case 2: _t->slot_RecvResponse((*reinterpret_cast< std::add_pointer_t<QSharedPointer<CDataStreamBase>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CWidgetViewManage::*)(const QSharedPointer<CDataStreamBase> & );
            if (_t _q_method = &CWidgetViewManage::signal_RequestService; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CWidgetViewManage::*)(const QSharedPointer<CDataStreamBase> );
            if (_t _q_method = &CWidgetViewManage::signal_RecvResponse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CWidgetViewManage::signal_RequestService(const QSharedPointer<CDataStreamBase> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CWidgetViewManage::signal_RecvResponse(const QSharedPointer<CDataStreamBase> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

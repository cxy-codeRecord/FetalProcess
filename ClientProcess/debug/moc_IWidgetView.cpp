/****************************************************************************
** Meta object code from reading C++ file 'IWidgetView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interface/WidgetView/IWidgetView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IWidgetView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IWidgetView_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IWidgetView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IWidgetView_t qt_meta_stringdata_IWidgetView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "IWidgetView"
QT_MOC_LITERAL(1, 12, 20), // "signalRequestService"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 31), // "QSharedPointer<CDataStreamBase>"
QT_MOC_LITERAL(4, 66, 4), // "pack"
QT_MOC_LITERAL(5, 71, 20), // "onRecvResponseHandle"
QT_MOC_LITERAL(6, 92, 8), // "funcName"
QT_MOC_LITERAL(7, 101, 4) // "data"

    },
    "IWidgetView\0signalRequestService\0\0"
    "QSharedPointer<CDataStreamBase>\0pack\0"
    "onRecvResponseHandle\0funcName\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IWidgetView[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   27,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    6,    7,

       0        // eod
};

void IWidgetView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IWidgetView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRequestService((*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[1]))); break;
        case 1: _t->onRecvResponseHandle((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QSharedPointer<CDataStreamBase>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IWidgetView::*)(const QSharedPointer<CDataStreamBase> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IWidgetView::signalRequestService)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IWidgetView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_IWidgetView.data,
    qt_meta_data_IWidgetView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IWidgetView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IWidgetView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IWidgetView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IWidgetView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void IWidgetView::signalRequestService(const QSharedPointer<CDataStreamBase> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

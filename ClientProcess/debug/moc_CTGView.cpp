/****************************************************************************
** Meta object code from reading C++ file 'CTGView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CTGView/CTGView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTGView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CTGView_t {
    QByteArrayData data[17];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTGView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTGView_t qt_meta_stringdata_CTGView = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CTGView"
QT_MOC_LITERAL(1, 8, 22), // "signalPrinterUnitState"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "state"
QT_MOC_LITERAL(4, 38, 13), // "timeoutHandle"
QT_MOC_LITERAL(5, 52, 23), // "updateQuickCustomPlotUI"
QT_MOC_LITERAL(6, 76, 18), // "limitXRangeChanged"
QT_MOC_LITERAL(7, 95, 8), // "QCPRange"
QT_MOC_LITERAL(8, 104, 8), // "newRange"
QT_MOC_LITERAL(9, 113, 8), // "oldRange"
QT_MOC_LITERAL(10, 122, 18), // "limitYRangeChanged"
QT_MOC_LITERAL(11, 141, 10), // "mouseWheel"
QT_MOC_LITERAL(12, 152, 12), // "QWheelEvent*"
QT_MOC_LITERAL(13, 165, 1), // "e"
QT_MOC_LITERAL(14, 167, 9), // "mouseMove"
QT_MOC_LITERAL(15, 177, 12), // "QMouseEvent*"
QT_MOC_LITERAL(16, 190, 22) // "handlePrinterUnitState"

    },
    "CTGView\0signalPrinterUnitState\0\0state\0"
    "timeoutHandle\0updateQuickCustomPlotUI\0"
    "limitXRangeChanged\0QCPRange\0newRange\0"
    "oldRange\0limitYRangeChanged\0mouseWheel\0"
    "QWheelEvent*\0e\0mouseMove\0QMouseEvent*\0"
    "handlePrinterUnitState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTGView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    2,   59,    2, 0x0a /* Public */,
      10,    2,   64,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,
      14,    1,   72,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      16,    1,   75,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   13,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void CTGView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CTGView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPrinterUnitState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->timeoutHandle(); break;
        case 2: _t->updateQuickCustomPlotUI(); break;
        case 3: _t->limitXRangeChanged((*reinterpret_cast< const QCPRange(*)>(_a[1])),(*reinterpret_cast< const QCPRange(*)>(_a[2]))); break;
        case 4: _t->limitYRangeChanged((*reinterpret_cast< const QCPRange(*)>(_a[1])),(*reinterpret_cast< const QCPRange(*)>(_a[2]))); break;
        case 5: _t->mouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->handlePrinterUnitState((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CTGView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTGView::signalPrinterUnitState)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CTGView::staticMetaObject = { {
    &CWidgetView::staticMetaObject,
    qt_meta_stringdata_CTGView.data,
    qt_meta_data_CTGView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CTGView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTGView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTGView.stringdata0))
        return static_cast<void*>(this);
    return CWidgetView::qt_metacast(_clname);
}

int CTGView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWidgetView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CTGView::signalPrinterUnitState(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

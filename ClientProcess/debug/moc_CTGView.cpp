/****************************************************************************
** Meta object code from reading C++ file 'CTGView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CTGView/CTGView.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTGView.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CTGView_t {
    uint offsetsAndSizes[34];
    char stringdata0[8];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[14];
    char stringdata5[24];
    char stringdata6[19];
    char stringdata7[9];
    char stringdata8[9];
    char stringdata9[9];
    char stringdata10[19];
    char stringdata11[11];
    char stringdata12[13];
    char stringdata13[2];
    char stringdata14[10];
    char stringdata15[13];
    char stringdata16[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CTGView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CTGView_t qt_meta_stringdata_CTGView = {
    {
        QT_MOC_LITERAL(0, 7),  // "CTGView"
        QT_MOC_LITERAL(8, 23),  // "signal_printerUnitState"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 5),  // "state"
        QT_MOC_LITERAL(39, 13),  // "timeoutHandle"
        QT_MOC_LITERAL(53, 23),  // "updateQuickCustomPlotUI"
        QT_MOC_LITERAL(77, 18),  // "limitXRangeChanged"
        QT_MOC_LITERAL(96, 8),  // "QCPRange"
        QT_MOC_LITERAL(105, 8),  // "newRange"
        QT_MOC_LITERAL(114, 8),  // "oldRange"
        QT_MOC_LITERAL(123, 18),  // "limitYRangeChanged"
        QT_MOC_LITERAL(142, 10),  // "mouseWheel"
        QT_MOC_LITERAL(153, 12),  // "QWheelEvent*"
        QT_MOC_LITERAL(166, 1),  // "e"
        QT_MOC_LITERAL(168, 9),  // "mouseMove"
        QT_MOC_LITERAL(178, 12),  // "QMouseEvent*"
        QT_MOC_LITERAL(191, 22)   // "handlePrinterUnitState"
    },
    "CTGView",
    "signal_printerUnitState",
    "",
    "state",
    "timeoutHandle",
    "updateQuickCustomPlotUI",
    "limitXRangeChanged",
    "QCPRange",
    "newRange",
    "oldRange",
    "limitYRangeChanged",
    "mouseWheel",
    "QWheelEvent*",
    "e",
    "mouseMove",
    "QMouseEvent*",
    "handlePrinterUnitState"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CTGView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   65,    2, 0x0a,    3 /* Public */,
       5,    0,   66,    2, 0x0a,    4 /* Public */,
       6,    2,   67,    2, 0x0a,    5 /* Public */,
      10,    2,   72,    2, 0x0a,    8 /* Public */,
      11,    1,   77,    2, 0x0a,   11 /* Public */,
      14,    1,   80,    2, 0x0a,   13 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      16,    1,   83,    2, 0x02,   15 /* Public */,

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

Q_CONSTINIT const QMetaObject CTGView::staticMetaObject = { {
    QMetaObject::SuperData::link<CWidgetView::staticMetaObject>(),
    qt_meta_stringdata_CTGView.offsetsAndSizes,
    qt_meta_data_CTGView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CTGView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CTGView, std::true_type>,
        // method 'signal_printerUnitState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'timeoutHandle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateQuickCustomPlotUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'limitXRangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>,
        // method 'limitYRangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>,
        // method 'mouseWheel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWheelEvent *, std::false_type>,
        // method 'mouseMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'handlePrinterUnitState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void CTGView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CTGView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_printerUnitState((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->timeoutHandle(); break;
        case 2: _t->updateQuickCustomPlotUI(); break;
        case 3: _t->limitXRangeChanged((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[2]))); break;
        case 4: _t->limitYRangeChanged((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[2]))); break;
        case 5: _t->mouseWheel((*reinterpret_cast< std::add_pointer_t<QWheelEvent*>>(_a[1]))); break;
        case 6: _t->mouseMove((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 7: _t->handlePrinterUnitState((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CTGView::*)(int );
            if (_t _q_method = &CTGView::signal_printerUnitState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CTGView::signal_printerUnitState(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TravelAgencyGUI_t {
    QByteArrayData data[13];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TravelAgencyGUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TravelAgencyGUI_t qt_meta_stringdata_TravelAgencyGUI = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TravelAgencyGUI"
QT_MOC_LITERAL(1, 16, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "addOffer"
QT_MOC_LITERAL(4, 43, 11), // "removeOffer"
QT_MOC_LITERAL(5, 55, 11), // "updateOffer"
QT_MOC_LITERAL(6, 67, 6), // "reload"
QT_MOC_LITERAL(7, 74, 13), // "vector<Offer>"
QT_MOC_LITERAL(8, 88, 6), // "offers"
QT_MOC_LITERAL(9, 95, 6), // "filter"
QT_MOC_LITERAL(10, 102, 9), // "sortPrice"
QT_MOC_LITERAL(11, 112, 8), // "sortType"
QT_MOC_LITERAL(12, 121, 8) // "sortDest"

    },
    "TravelAgencyGUI\0selectionChanged\0\0"
    "addOffer\0removeOffer\0updateOffer\0"
    "reload\0vector<Offer>\0offers\0filter\0"
    "sortPrice\0sortType\0sortDest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TravelAgencyGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x28 /* Private | MethodCloned */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TravelAgencyGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TravelAgencyGUI *_t = static_cast<TravelAgencyGUI *>(_o);
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->addOffer(); break;
        case 2: _t->removeOffer(); break;
        case 3: _t->updateOffer(); break;
        case 4: _t->reload((*reinterpret_cast< vector<Offer>(*)>(_a[1]))); break;
        case 5: _t->reload(); break;
        case 6: _t->filter(); break;
        case 7: _t->sortPrice(); break;
        case 8: _t->sortType(); break;
        case 9: _t->sortDest(); break;
        default: ;
        }
    }
}

const QMetaObject TravelAgencyGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TravelAgencyGUI.data,
      qt_meta_data_TravelAgencyGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TravelAgencyGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TravelAgencyGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TravelAgencyGUI.stringdata))
        return static_cast<void*>(const_cast< TravelAgencyGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int TravelAgencyGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

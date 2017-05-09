/****************************************************************************
** Meta object code from reading C++ file 'assignmentview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/assignmentview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assignmentview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AssignmentView_t {
    QByteArrayData data[9];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AssignmentView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AssignmentView_t qt_meta_stringdata_AssignmentView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AssignmentView"
QT_MOC_LITERAL(1, 15, 13), // "refresh_cards"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "show_students"
QT_MOC_LITERAL(4, 44, 16), // "show_submissions"
QT_MOC_LITERAL(5, 61, 10), // "assignment"
QT_MOC_LITERAL(6, 72, 7), // "add_new"
QT_MOC_LITERAL(7, 80, 12), // "add_existing"
QT_MOC_LITERAL(8, 93, 2) // "id"

    },
    "AssignmentView\0refresh_cards\0\0"
    "show_students\0show_submissions\0"
    "assignment\0add_new\0add_existing\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AssignmentView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void AssignmentView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AssignmentView *_t = static_cast<AssignmentView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh_cards(); break;
        case 1: _t->show_students(); break;
        case 2: _t->show_submissions((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 3: _t->add_new(); break;
        case 4: _t->add_existing((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AssignmentView::staticMetaObject = {
    { &CardsView::staticMetaObject, qt_meta_stringdata_AssignmentView.data,
      qt_meta_data_AssignmentView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AssignmentView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AssignmentView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AssignmentView.stringdata0))
        return static_cast<void*>(const_cast< AssignmentView*>(this));
    return CardsView::qt_metacast(_clname);
}

int AssignmentView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CardsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

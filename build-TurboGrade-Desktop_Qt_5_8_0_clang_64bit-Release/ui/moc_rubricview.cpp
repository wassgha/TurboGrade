/****************************************************************************
** Meta object code from reading C++ file 'rubricview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/rubricview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rubricview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RubricView_t {
    QByteArrayData data[15];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RubricView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RubricView_t qt_meta_stringdata_RubricView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RubricView"
QT_MOC_LITERAL(1, 11, 13), // "add_criterion"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "add_child"
QT_MOC_LITERAL(4, 36, 10), // "Criterion*"
QT_MOC_LITERAL(5, 47, 6), // "parent"
QT_MOC_LITERAL(6, 54, 9), // "add_guide"
QT_MOC_LITERAL(7, 64, 16), // "remove_criterion"
QT_MOC_LITERAL(8, 81, 9), // "criterion"
QT_MOC_LITERAL(9, 91, 19), // "on_done_btn_clicked"
QT_MOC_LITERAL(10, 111, 28), // "on_suggestion_design_clicked"
QT_MOC_LITERAL(11, 140, 30), // "on_suggestion_compiles_clicked"
QT_MOC_LITERAL(12, 171, 33), // "on_suggestion_extracredit_cli..."
QT_MOC_LITERAL(13, 205, 35), // "on_suggestion_documentation_c..."
QT_MOC_LITERAL(14, 241, 33) // "on_suggestion_correctness_cli..."

    },
    "RubricView\0add_criterion\0\0add_child\0"
    "Criterion*\0parent\0add_guide\0"
    "remove_criterion\0criterion\0"
    "on_done_btn_clicked\0on_suggestion_design_clicked\0"
    "on_suggestion_compiles_clicked\0"
    "on_suggestion_extracredit_clicked\0"
    "on_suggestion_documentation_clicked\0"
    "on_suggestion_correctness_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RubricView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       1,    1,   71,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RubricView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RubricView *_t = static_cast<RubricView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_criterion(); break;
        case 1: _t->add_child(); break;
        case 2: _t->add_criterion((*reinterpret_cast< Criterion*(*)>(_a[1]))); break;
        case 3: _t->add_guide((*reinterpret_cast< Criterion*(*)>(_a[1]))); break;
        case 4: _t->remove_criterion((*reinterpret_cast< Criterion*(*)>(_a[1]))); break;
        case 5: _t->on_done_btn_clicked(); break;
        case 6: _t->on_suggestion_design_clicked(); break;
        case 7: _t->on_suggestion_compiles_clicked(); break;
        case 8: _t->on_suggestion_extracredit_clicked(); break;
        case 9: _t->on_suggestion_documentation_clicked(); break;
        case 10: _t->on_suggestion_correctness_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject RubricView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RubricView.data,
      qt_meta_data_RubricView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RubricView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RubricView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RubricView.stringdata0))
        return static_cast<void*>(const_cast< RubricView*>(this));
    return QDialog::qt_metacast(_clname);
}

int RubricView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

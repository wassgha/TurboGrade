/****************************************************************************
** Meta object code from reading C++ file 'dashboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/dashboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dashboard_t {
    QByteArrayData data[20];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dashboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dashboard_t qt_meta_stringdata_Dashboard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Dashboard"
QT_MOC_LITERAL(1, 10, 23), // "on_tutorial_btn_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "on_sync_now_clicked"
QT_MOC_LITERAL(4, 55, 30), // "on_actionPreferences_triggered"
QT_MOC_LITERAL(5, 86, 12), // "show_courses"
QT_MOC_LITERAL(6, 99, 13), // "show_sections"
QT_MOC_LITERAL(7, 113, 6), // "course"
QT_MOC_LITERAL(8, 120, 16), // "show_assignments"
QT_MOC_LITERAL(9, 137, 7), // "section"
QT_MOC_LITERAL(10, 145, 13), // "show_students"
QT_MOC_LITERAL(11, 159, 16), // "show_submissions"
QT_MOC_LITERAL(12, 176, 10), // "assignment"
QT_MOC_LITERAL(13, 187, 13), // "start_grading"
QT_MOC_LITERAL(14, 201, 10), // "submission"
QT_MOC_LITERAL(15, 212, 14), // "toggle_headers"
QT_MOC_LITERAL(16, 227, 4), // "show"
QT_MOC_LITERAL(17, 232, 21), // "remove_current_widget"
QT_MOC_LITERAL(18, 254, 11), // "update_sync"
QT_MOC_LITERAL(19, 266, 10) // "update_git"

    },
    "Dashboard\0on_tutorial_btn_clicked\0\0"
    "on_sync_now_clicked\0on_actionPreferences_triggered\0"
    "show_courses\0show_sections\0course\0"
    "show_assignments\0section\0show_students\0"
    "show_submissions\0assignment\0start_grading\0"
    "submission\0toggle_headers\0show\0"
    "remove_current_widget\0update_sync\0"
    "update_git"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dashboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       8,    1,   86,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      11,    2,   92,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,
      15,    1,  100,    2, 0x0a /* Public */,
      17,    0,  103,    2, 0x0a /* Public */,
      18,    0,  104,    2, 0x0a /* Public */,
      19,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,    7,
    QMetaType::Void, QMetaType::QObjectStar,    9,
    QMetaType::Void, QMetaType::QObjectStar,    9,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QObjectStar,    9,   12,
    QMetaType::Void, QMetaType::QObjectStar,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dashboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dashboard *_t = static_cast<Dashboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tutorial_btn_clicked(); break;
        case 1: _t->on_sync_now_clicked(); break;
        case 2: _t->on_actionPreferences_triggered(); break;
        case 3: _t->show_courses(); break;
        case 4: _t->show_sections((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 5: _t->show_assignments((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 6: _t->show_students((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 7: _t->show_submissions((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 8: _t->start_grading((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 9: _t->toggle_headers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->remove_current_widget(); break;
        case 11: _t->update_sync(); break;
        case 12: _t->update_git(); break;
        default: ;
        }
    }
}

const QMetaObject Dashboard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Dashboard.data,
      qt_meta_data_Dashboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dashboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dashboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dashboard.stringdata0))
        return static_cast<void*>(const_cast< Dashboard*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Dashboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'gradesubmission.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/gradesubmission.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gradesubmission.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GradeSubmission_t {
    QByteArrayData data[16];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GradeSubmission_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GradeSubmission_t qt_meta_stringdata_GradeSubmission = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GradeSubmission"
QT_MOC_LITERAL(1, 16, 19), // "switched_submission"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "submission"
QT_MOC_LITERAL(4, 48, 16), // "refresh_students"
QT_MOC_LITERAL(5, 65, 14), // "on_run_clicked"
QT_MOC_LITERAL(6, 80, 16), // "finished_running"
QT_MOC_LITERAL(7, 97, 19), // "on_hideName_toggled"
QT_MOC_LITERAL(8, 117, 7), // "checked"
QT_MOC_LITERAL(9, 125, 34), // "on_studentName_currentIndexCh..."
QT_MOC_LITERAL(10, 160, 5), // "index"
QT_MOC_LITERAL(11, 166, 14), // "show_dashboard"
QT_MOC_LITERAL(12, 181, 15), // "next_submission"
QT_MOC_LITERAL(13, 197, 14), // "hide_fireworks"
QT_MOC_LITERAL(14, 212, 19), // "on_finalize_clicked"
QT_MOC_LITERAL(15, 232, 20) // "on_exportpdf_clicked"

    },
    "GradeSubmission\0switched_submission\0"
    "\0submission\0refresh_students\0"
    "on_run_clicked\0finished_running\0"
    "on_hideName_toggled\0checked\0"
    "on_studentName_currentIndexChanged\0"
    "index\0show_dashboard\0next_submission\0"
    "hide_fireworks\0on_finalize_clicked\0"
    "on_exportpdf_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GradeSubmission[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   72,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GradeSubmission::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GradeSubmission *_t = static_cast<GradeSubmission *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switched_submission((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->refresh_students(); break;
        case 2: _t->on_run_clicked(); break;
        case 3: _t->finished_running(); break;
        case 4: _t->on_hideName_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_studentName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->show_dashboard(); break;
        case 7: _t->next_submission(); break;
        case 8: _t->hide_fireworks(); break;
        case 9: _t->on_finalize_clicked(); break;
        case 10: _t->on_exportpdf_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GradeSubmission::*_t)(QObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GradeSubmission::switched_submission)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GradeSubmission::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GradeSubmission.data,
      qt_meta_data_GradeSubmission,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GradeSubmission::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GradeSubmission::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GradeSubmission.stringdata0))
        return static_cast<void*>(const_cast< GradeSubmission*>(this));
    return QWidget::qt_metacast(_clname);
}

int GradeSubmission::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GradeSubmission::switched_submission(QObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'criteriongradecard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/criteriongradecard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'criteriongradecard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CriterionGradeCard_t {
    QByteArrayData data[9];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CriterionGradeCard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CriterionGradeCard_t qt_meta_stringdata_CriterionGradeCard = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CriterionGradeCard"
QT_MOC_LITERAL(1, 19, 13), // "grade_changed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "show_comment"
QT_MOC_LITERAL(4, 47, 8), // "Comment*"
QT_MOC_LITERAL(5, 56, 7), // "comment"
QT_MOC_LITERAL(6, 64, 21), // "on_grade_valueChanged"
QT_MOC_LITERAL(7, 86, 5), // "grade"
QT_MOC_LITERAL(8, 92, 24) // "on_show_comments_clicked"

    },
    "CriterionGradeCard\0grade_changed\0\0"
    "show_comment\0Comment*\0comment\0"
    "on_grade_valueChanged\0grade\0"
    "on_show_comments_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CriterionGradeCard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       6,    1,   38,    2, 0x08 /* Private */,
       8,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void CriterionGradeCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CriterionGradeCard *_t = static_cast<CriterionGradeCard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->grade_changed(); break;
        case 1: _t->show_comment((*reinterpret_cast< Comment*(*)>(_a[1]))); break;
        case 2: _t->on_grade_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_show_comments_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CriterionGradeCard::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CriterionGradeCard::grade_changed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CriterionGradeCard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CriterionGradeCard.data,
      qt_meta_data_CriterionGradeCard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CriterionGradeCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CriterionGradeCard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CriterionGradeCard.stringdata0))
        return static_cast<void*>(const_cast< CriterionGradeCard*>(this));
    return QWidget::qt_metacast(_clname);
}

int CriterionGradeCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CriterionGradeCard::grade_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

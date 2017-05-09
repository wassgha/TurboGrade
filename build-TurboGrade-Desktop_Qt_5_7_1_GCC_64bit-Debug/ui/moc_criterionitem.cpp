/****************************************************************************
** Meta object code from reading C++ file 'criterionitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/criterionitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'criterionitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CriterionItem_t {
    QByteArrayData data[10];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CriterionItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CriterionItem_t qt_meta_stringdata_CriterionItem = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CriterionItem"
QT_MOC_LITERAL(1, 14, 11), // "added_child"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "Criterion*"
QT_MOC_LITERAL(4, 38, 9), // "criterion"
QT_MOC_LITERAL(5, 48, 11), // "added_guide"
QT_MOC_LITERAL(6, 60, 17), // "removed_criterion"
QT_MOC_LITERAL(7, 78, 9), // "add_child"
QT_MOC_LITERAL(8, 88, 9), // "add_guide"
QT_MOC_LITERAL(9, 98, 16) // "remove_criterion"

    },
    "CriterionItem\0added_child\0\0Criterion*\0"
    "criterion\0added_guide\0removed_criterion\0"
    "add_child\0add_guide\0remove_criterion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CriterionItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   53,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CriterionItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CriterionItem *_t = static_cast<CriterionItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->added_child((*reinterpret_cast< Criterion*(*)>(_a[1]))); break;
        case 1: _t->added_guide((*reinterpret_cast< Criterion*(*)>(_a[1]))); break;
        case 2: _t->removed_criterion((*reinterpret_cast< Criterion*(*)>(_a[1]))); break;
        case 3: _t->add_child(); break;
        case 4: _t->add_guide(); break;
        case 5: _t->remove_criterion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CriterionItem::*_t)(Criterion * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CriterionItem::added_child)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CriterionItem::*_t)(Criterion * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CriterionItem::added_guide)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CriterionItem::*_t)(Criterion * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CriterionItem::removed_criterion)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CriterionItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CriterionItem.data,
      qt_meta_data_CriterionItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CriterionItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CriterionItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CriterionItem.stringdata0))
        return static_cast<void*>(const_cast< CriterionItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int CriterionItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CriterionItem::added_child(Criterion * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CriterionItem::added_guide(Criterion * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CriterionItem::removed_criterion(Criterion * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'commentcard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/commentcard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commentcard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommentCard_t {
    QByteArrayData data[16];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommentCard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommentCard_t qt_meta_stringdata_CommentCard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CommentCard"
QT_MOC_LITERAL(1, 12, 9), // "mouseOver"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "Comment*"
QT_MOC_LITERAL(4, 32, 7), // "comment"
QT_MOC_LITERAL(5, 40, 8), // "mouseOut"
QT_MOC_LITERAL(6, 49, 7), // "clicked"
QT_MOC_LITERAL(7, 57, 10), // "enterEvent"
QT_MOC_LITERAL(8, 68, 7), // "QEvent*"
QT_MOC_LITERAL(9, 76, 5), // "event"
QT_MOC_LITERAL(10, 82, 10), // "leaveEvent"
QT_MOC_LITERAL(11, 93, 15), // "mousePressEvent"
QT_MOC_LITERAL(12, 109, 12), // "QMouseEvent*"
QT_MOC_LITERAL(13, 122, 21), // "on_delete_btn_clicked"
QT_MOC_LITERAL(14, 144, 9), // "highlight"
QT_MOC_LITERAL(15, 154, 11) // "unhighlight"

    },
    "CommentCard\0mouseOver\0\0Comment*\0comment\0"
    "mouseOut\0clicked\0enterEvent\0QEvent*\0"
    "event\0leaveEvent\0mousePressEvent\0"
    "QMouseEvent*\0on_delete_btn_clicked\0"
    "highlight\0unhighlight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommentCard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   68,    2, 0x08 /* Private */,
      10,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x0a /* Public */,
      15,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 12,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CommentCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommentCard *_t = static_cast<CommentCard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseOver((*reinterpret_cast< Comment*(*)>(_a[1]))); break;
        case 1: _t->mouseOut((*reinterpret_cast< Comment*(*)>(_a[1]))); break;
        case 2: _t->clicked((*reinterpret_cast< Comment*(*)>(_a[1]))); break;
        case 3: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 4: _t->leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->on_delete_btn_clicked(); break;
        case 7: _t->highlight(); break;
        case 8: _t->unhighlight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CommentCard::*_t)(Comment * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommentCard::mouseOver)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CommentCard::*_t)(Comment * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommentCard::mouseOut)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CommentCard::*_t)(Comment * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommentCard::clicked)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CommentCard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CommentCard.data,
      qt_meta_data_CommentCard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommentCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommentCard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommentCard.stringdata0))
        return static_cast<void*>(const_cast< CommentCard*>(this));
    return QWidget::qt_metacast(_clname);
}

int CommentCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CommentCard::mouseOver(Comment * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommentCard::mouseOut(Comment * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommentCard::clicked(Comment * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

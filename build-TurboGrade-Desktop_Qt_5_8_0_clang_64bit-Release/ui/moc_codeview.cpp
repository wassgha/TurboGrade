/****************************************************************************
** Meta object code from reading C++ file 'codeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TurboGrade/ui/codeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CodeView_t {
    QByteArrayData data[15];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodeView_t qt_meta_stringdata_CodeView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CodeView"
QT_MOC_LITERAL(1, 9, 12), // "getSelection"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "loadFile"
QT_MOC_LITERAL(4, 32, 4), // "item"
QT_MOC_LITERAL(5, 37, 16), // "finished_loading"
QT_MOC_LITERAL(6, 54, 11), // "add_comment"
QT_MOC_LITERAL(7, 66, 17), // "highlight_comment"
QT_MOC_LITERAL(8, 84, 8), // "Comment*"
QT_MOC_LITERAL(9, 93, 7), // "comment"
QT_MOC_LITERAL(10, 101, 20), // "unhighlight_comments"
QT_MOC_LITERAL(11, 122, 14), // "auto_completed"
QT_MOC_LITERAL(12, 137, 5), // "index"
QT_MOC_LITERAL(13, 143, 31), // "on_general_comments_textChanged"
QT_MOC_LITERAL(14, 175, 31) // "on_save_general_comment_clicked"

    },
    "CodeView\0getSelection\0\0loadFile\0item\0"
    "finished_loading\0add_comment\0"
    "highlight_comment\0Comment*\0comment\0"
    "unhighlight_comments\0auto_completed\0"
    "index\0on_general_comments_textChanged\0"
    "on_save_general_comment_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,
      13,    0,   72,    2, 0x08 /* Private */,
      14,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CodeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CodeView *_t = static_cast<CodeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getSelection(); break;
        case 1: _t->loadFile((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->finished_loading(); break;
        case 3: _t->add_comment(); break;
        case 4: _t->highlight_comment((*reinterpret_cast< Comment*(*)>(_a[1]))); break;
        case 5: _t->unhighlight_comments(); break;
        case 6: _t->auto_completed((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_general_comments_textChanged(); break;
        case 8: _t->on_save_general_comment_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CodeView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CodeView.data,
      qt_meta_data_CodeView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CodeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CodeView.stringdata0))
        return static_cast<void*>(const_cast< CodeView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CodeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QRCode_Generator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_generateButton_pressed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 25), // "on_saveFileButton_pressed"
QT_MOC_LITERAL(4, 64, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(5, 96, 4), // "arg1"
QT_MOC_LITERAL(6, 101, 6), // "hexadd"
QT_MOC_LITERAL(7, 108, 6), // "string"
QT_MOC_LITERAL(8, 115, 4), // "hex1"
QT_MOC_LITERAL(9, 120, 4), // "hex2"
QT_MOC_LITERAL(10, 125, 7), // "dec2hex"
QT_MOC_LITERAL(11, 133, 1), // "a"
QT_MOC_LITERAL(12, 135, 7), // "hex2dec"
QT_MOC_LITERAL(13, 143, 6), // "hexstr"
QT_MOC_LITERAL(14, 150, 25), // "on_generateButton_clicked"
QT_MOC_LITERAL(15, 176, 22), // "on_MergeButton_clicked"
QT_MOC_LITERAL(16, 199, 22), // "on_SplitButton_clicked"
QT_MOC_LITERAL(17, 222, 22), // "on_MergeButton_pressed"
QT_MOC_LITERAL(18, 245, 24) // "on_SplitButton_2_clicked"

    },
    "MainWindow\0on_generateButton_pressed\0"
    "\0on_saveFileButton_pressed\0"
    "on_comboBox_currentIndexChanged\0arg1\0"
    "hexadd\0string\0hex1\0hex2\0dec2hex\0a\0"
    "hex2dec\0hexstr\0on_generateButton_clicked\0"
    "on_MergeButton_clicked\0on_SplitButton_clicked\0"
    "on_MergeButton_pressed\0on_SplitButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
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
       4,    1,   71,    2, 0x08 /* Private */,
       6,    2,   74,    2, 0x08 /* Private */,
      10,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,
      15,    0,   86,    2, 0x08 /* Private */,
      16,    0,   87,    2, 0x08 /* Private */,
      17,    0,   88,    2, 0x08 /* Private */,
      18,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QString, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    0x80000000 | 7, QMetaType::Long,   11,
    QMetaType::Long, 0x80000000 | 7,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_generateButton_pressed(); break;
        case 1: _t->on_saveFileButton_pressed(); break;
        case 2: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;

        case 6: _t->on_generateButton_clicked(); break;
        case 7: _t->on_MergeButton_clicked(); break;
        case 8: _t->on_SplitButton_clicked(); break;
        case 9: _t->on_MergeButton_pressed(); break;
        case 10: _t->on_SplitButton_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

/****************************************************************************
** Meta object code from reading C++ file 'launcher.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../launcher.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'launcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSlauncherENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSlauncherENDCLASS = QtMocHelpers::stringData(
    "launcher",
    "f_showhide",
    "",
    "on_AppsButton_clicked",
    "on_GamesButton_clicked",
    "on_SettingsButton_clicked",
    "on_SteamState_clicked",
    "checked",
    "Add_App_Button",
    "std::string",
    "name",
    "dir",
    "args",
    "type",
    "n",
    "cont"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlauncherENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[9];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[23];
    char stringdata5[26];
    char stringdata6[22];
    char stringdata7[8];
    char stringdata8[15];
    char stringdata9[12];
    char stringdata10[5];
    char stringdata11[4];
    char stringdata12[5];
    char stringdata13[5];
    char stringdata14[2];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlauncherENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlauncherENDCLASS_t qt_meta_stringdata_CLASSlauncherENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "launcher"
        QT_MOC_LITERAL(9, 10),  // "f_showhide"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 21),  // "on_AppsButton_clicked"
        QT_MOC_LITERAL(43, 22),  // "on_GamesButton_clicked"
        QT_MOC_LITERAL(66, 25),  // "on_SettingsButton_clicked"
        QT_MOC_LITERAL(92, 21),  // "on_SteamState_clicked"
        QT_MOC_LITERAL(114, 7),  // "checked"
        QT_MOC_LITERAL(122, 14),  // "Add_App_Button"
        QT_MOC_LITERAL(137, 11),  // "std::string"
        QT_MOC_LITERAL(149, 4),  // "name"
        QT_MOC_LITERAL(154, 3),  // "dir"
        QT_MOC_LITERAL(158, 4),  // "args"
        QT_MOC_LITERAL(163, 4),  // "type"
        QT_MOC_LITERAL(168, 1),  // "n"
        QT_MOC_LITERAL(170, 4)   // "cont"
    },
    "launcher",
    "f_showhide",
    "",
    "on_AppsButton_clicked",
    "on_GamesButton_clicked",
    "on_SettingsButton_clicked",
    "on_SteamState_clicked",
    "checked",
    "Add_App_Button",
    "std::string",
    "name",
    "dir",
    "args",
    "type",
    "n",
    "cont"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlauncherENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x108,    2 /* Private | MethodIsConst  */,
       4,    0,   52,    2, 0x108,    3 /* Private | MethodIsConst  */,
       5,    0,   53,    2, 0x108,    4 /* Private | MethodIsConst  */,
       6,    1,   54,    2, 0x108,    5 /* Private | MethodIsConst  */,
       8,    6,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, QMetaType::Int, QMetaType::Int,   10,   11,   12,   13,   14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject launcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSlauncherENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlauncherENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlauncherENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<launcher, std::true_type>,
        // method 'f_showhide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_AppsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_GamesButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SettingsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SteamState_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'Add_App_Button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>
    >,
    nullptr
} };

void launcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<launcher *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->f_showhide(); break;
        case 1: _t->on_AppsButton_clicked(); break;
        case 2: _t->on_GamesButton_clicked(); break;
        case 3: _t->on_SettingsButton_clicked(); break;
        case 4: _t->on_SteamState_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->Add_App_Button((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObject *launcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *launcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlauncherENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int launcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'coordinator.h'
**
** Created: Mon 23. Dec 11:44:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game/coordinator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coordinator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Coordinator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      27,   24,   12,   12, 0x0a,
      41,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Coordinator[] = {
    "Coordinator\0\0runGameH()\0sk\0runGameC(int)\0"
    "runMenu()\0"
};

void Coordinator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Coordinator *_t = static_cast<Coordinator *>(_o);
        switch (_id) {
        case 0: _t->runGameH(); break;
        case 1: _t->runGameC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->runMenu(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Coordinator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Coordinator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Coordinator,
      qt_meta_data_Coordinator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Coordinator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Coordinator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Coordinator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Coordinator))
        return static_cast<void*>(const_cast< Coordinator*>(this));
    return QObject::qt_metacast(_clname);
}

int Coordinator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
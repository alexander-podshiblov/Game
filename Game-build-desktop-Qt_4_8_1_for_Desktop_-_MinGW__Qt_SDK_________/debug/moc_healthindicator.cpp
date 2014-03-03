/****************************************************************************
** Meta object code from reading C++ file 'healthindicator.h'
**
** Created: Sun 2. Mar 18:34:49 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game/healthindicator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'healthindicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HealthIndicator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   17,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HealthIndicator[] = {
    "HealthIndicator\0\0h\0setHealth(int)\0"
};

void HealthIndicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HealthIndicator *_t = static_cast<HealthIndicator *>(_o);
        switch (_id) {
        case 0: _t->setHealth((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HealthIndicator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HealthIndicator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HealthIndicator,
      qt_meta_data_HealthIndicator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HealthIndicator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HealthIndicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HealthIndicator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HealthIndicator))
        return static_cast<void*>(const_cast< HealthIndicator*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< HealthIndicator*>(this));
    return QObject::qt_metacast(_clname);
}

int HealthIndicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

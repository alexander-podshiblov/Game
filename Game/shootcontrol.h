#pragma once
#include <QObject>

class ShootControl : public QObject
{
    Q_OBJECT
public:
    ShootControl();
    int whoShoot();
    bool isReadyForShoot();
private:
    int firePlayer;
    bool isReady;
signals:

    
public slots:
    void wasShoot();
    void setReady();
};


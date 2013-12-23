#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "gun.h"
#include "firebutton.h"
#include <QTimer>
#include <QSound>
#include <QMovie>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "math.h"
#include "bullet.h"
#include "clouds.h"
#include "healthindicator.h"
#include "shootcontrol.h"
#include "powercontroller.h"

const int horizon = 550;
const int hOfField = 600;
const int wOfField = 1680;
const int indent = 300;
const int graundStart = -200;
const int graundFinish = wOfField + 200;
const int stepBlack = 20;


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(int mod);
    ~Scene();
    void setWidth(double w);
    void setSkill(int s);
private:
    Gun *gun1;
    Gun *gun2;

    HealthIndicator *health1;
    HealthIndicator *health2;

    QSound *boomSound;
    QSound *explosionSound;
    QSound *miss;

    QTimer *timer;

    QGraphicsProxyWidget *boom;
    QLabel *viewBoom;

    QGraphicsProxyWidget *explosion;
    QLabel *viewExplosion;

    QGraphicsProxyWidget *crash;
    QLabel *viewCrash;

    QGraphicsProxyWidget *hit;
    QLabel *viewHit;

    Clouds *clouds;

    ShootControl *control;

    PowerController *pContr1;
    PowerController *pContr2;

    double width;

    bool isFinished;

    int gameMod;

    double tab[31][3];

    bool autoShooStart;
    double stepOfAutoAim;
    int c;

    int skill;
protected:
    virtual void keyPressEvent(QKeyEvent *event);

signals:
    void returnToMenu();
    
public slots:
    void doFire(int player);
    void doExplosion(int eX);
    void doHit(int hx, int hy, int numOfGun);
    void doCrash(int player);
    void doAutoShoot();

};

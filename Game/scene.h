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
#include "bomb.h"
#include "ball.h"
#include "rocket.h"
#include "clouds.h"
#include "healthindicator.h"
#include "shootcontrol.h"
#include "powercontroller.h"
#include "bulletindicator.h"

//const int horizon = 550;
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
    void changeInd(int p);
    void showWinner(int p);

    Gun *gun1;
    Gun *gun2;

    HealthIndicator *health1;
    HealthIndicator *health2;

    BulletIndicator *bInd1;
    BulletIndicator *bInd2;

    QSound *boomSound;
    QSound *explosionSound;
    QSound *miss;

    QTimer *timer;

    QGraphicsProxyWidget *pInd1;
    QLabel *viewPInd1;

    QGraphicsProxyWidget *pInd2;
    QLabel *viewPInd2;

    QGraphicsProxyWidget *pIndc;
    QLabel *viewPIndc;

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
    double tab_rocket[31][3];
    double tab_bomb[31][3];

    bool autoShooStart;
    double stepOfAutoAim;
    int c;

    int skill;
    int numOfBullet;


protected:
    virtual void keyPressEvent(QKeyEvent *event);

signals:
    void returnToMenu();
    
public slots:
    void doFire(int player);
    void doExplosion(int eX, int rad, int damage);
    void doHit(int hx, int hy, int numOfGun, int damage);
    void doCrash(int player);
    void doAutoShoot();

};

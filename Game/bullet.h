#pragma once
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include "gun.h"

const int horizon = 550;

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bullet(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2);
    virtual ~Bullet();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) = 0;
    virtual QRectF boundingRect() const = 0;
    virtual QPainterPath shape() const = 0;
    void shieldMet();

protected:
    virtual void advance(int phase) = 0;
    int vX;
    int vY;
    int startX;
    int startY;
    double t;
    double resis;
    double resisFactor;
    Gun *gun1;
    Gun *gun2;
    int numOfDamage;
    int radius;

signals:
    void explosion(int eX, int rad, int damage);
    void hit(int hx, int hy, int numOfGun, int damage);


};

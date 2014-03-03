#pragma once
#include "bullet.h"


class Ball : public Bullet
{
    Q_OBJECT
public:
    Ball(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;

protected:
    void advance(int phase);
/** int vX;
    int vY;
    int startX;
    int startY;
    double t;
    double resis;
    Gun *gun1;
    Gun *gun2;*/

signals:
    //void explosion(int eX);
    //void hit(int hx, int hy, int numOfGun);
};

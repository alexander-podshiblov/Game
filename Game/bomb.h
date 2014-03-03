#pragma once
#include "bullet.h"

class Bomb : public Bullet
{
    Q_OBJECT
public:
    Bomb(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;

protected:
    void advance(int phase);
};

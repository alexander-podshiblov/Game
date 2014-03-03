#pragma once
#include "bullet.h"

class Rocket : public Bullet
{
    Q_OBJECT
public:
    Rocket(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    
protected:
    void advance(int phase);

private:
    int shooter;
    double angToRotate;
    
};


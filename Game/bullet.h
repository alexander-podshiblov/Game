#pragma once
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include "scene.h"

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bullet(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;

protected:
    void advance(int phase);

private:
    int vX;
    int vY;
    int startX;
    int startY;
    double t;
    double resis;
    Gun *gun1;
    Gun *gun2;

signals:
    void explosion(int eX);
    void hit(int hx, int hy, int numOfGun);


};

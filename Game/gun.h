#pragma once
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QGraphicsSceneEvent>
#include <QGraphicsScene>
#include "math.h"

static const double ConvInAng = 180 / 3.141592653589793;

class Gun : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Gun(int player);
    ///
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    ///
    void setAngle(double a);
    double getAngle();
    QPoint getPosForEx();
    QPoint getSpeed(double factor);
    void setDamage(int damage);

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:

signals:
    void healthChanged(int h);
    void crashed(int player);

private:
    int numOfPlayer;
    int border1;
    int border2;
    double angle;
    bool canRotate;
    double angleFR(int lx, int ly, int x, int y);
    int health;
};


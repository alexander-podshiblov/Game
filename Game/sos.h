#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include "shootcontrol.h"

class Sos : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Sos(int p, ShootControl *c);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    bool bonusIsUsed();
    void activateCompBonus();

signals:
    void getBonus(int p);


protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool isUsed;
    ShootControl *control;
    int player;
};

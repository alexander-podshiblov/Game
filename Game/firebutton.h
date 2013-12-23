#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneEvent>
#include <QObject>
#include "shootcontrol.h"

class FireButton : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    FireButton(int p, ShootControl *c);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

signals:
    void fire(int n);


protected:
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool isPressed;
    int player;
    QPixmap normal;
    QPixmap pressed;
    ShootControl *control;
};

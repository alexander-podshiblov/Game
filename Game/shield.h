#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "bullet.h"

class Shield : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Shield(int p);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void setBullet(Bullet *b);
    void destroyShield();
signals:
    void crashed(int p);
private:
    int stepsToBuild;
    int player;
    Bullet *bullet;
protected:
    void advance(int phase);

public slots:
    void bulletCrashed();

    
};

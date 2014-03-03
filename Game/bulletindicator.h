#pragma once
#include <QGraphicsSceneEvent>
#include <QGraphicsItem>
#include <QPainter>

class BulletIndicator : public  QGraphicsItem
{
public:
    BulletIndicator();
    void setKindOfBullet(int num);
    int getKindOfBullet();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setControllability(bool a);

private:
    int kindOfBullet;
    bool isControlled;
    

    

    
};


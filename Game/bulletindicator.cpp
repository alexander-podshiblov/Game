#include "bulletindicator.h"

BulletIndicator::BulletIndicator()
{
    kindOfBullet = 1;
    isControlled = true;
}

void BulletIndicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLinearGradient gradient(0, -20, 0, 20);
    gradient.setColorAt(0, QColor(220, 220, 220, 255));
    gradient.setColorAt(1, QColor(90, 90, 90, 255));
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(-53, -25, 106, 50, 8, 8);

    gradient.setColorAt(0, QColor("white"));
    gradient.setColorAt(1, QColor(120, 120, 120, 255));
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(-50, -22, 100, 44, 5, 5);

    painter->setBrush(QColor(255, 83, 0, 100));
    painter->drawRoundedRect(-44 + 30 * (kindOfBullet - 1), -14, 28, 28, 4, 4);



    painter->setBrush(QColor("black"));
    painter->drawEllipse(-36, -6, 12, 12);
    painter->setBrush(QColor("red"));
    painter->drawEllipse(-37, -2, 4, 4);
    painter->drawEllipse(-27, -2, 4, 4);
    painter->drawEllipse(-32, -7, 4, 4);
    painter->drawEllipse(-32, 3, 4, 4);

    //
    painter->setBrush(QColor(0, 200, 100, 255));
    painter->drawEllipse(-10, -3, 20, 6);
    painter->setBrush(QColor(0, 150, 75, 255));
    painter->drawEllipse(-10, -5, 8, 4);
    painter->drawEllipse(-10, 1, 8, 4);

    //
    painter->setBrush(QColor(50, 50, 50, 255));
    painter->drawEllipse(20, -10, 20, 20);
    painter->setBrush(QColor(150, 150, 150, 255));
    painter->drawEllipse(28, -2, 4, 4);
    painter->drawEllipse(18, -2, 4, 4);
    painter->drawEllipse(38, -2, 4, 4);
    painter->drawEllipse(28, -12, 4, 4);
    painter->drawEllipse(28, 8, 4, 4);
    painter->drawEllipse(35, -9, 4, 4);
    painter->drawEllipse(35, 5, 4, 4);
    painter->drawEllipse(21, -9, 4, 4);
    painter->drawEllipse(21, 5, 4, 4);



}

QRectF BulletIndicator::boundingRect() const
{
    return QRectF(- 50, - 25, 100, 50);
}

void BulletIndicator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (isControlled == true)
    {
        int xPos = event->pos().x();
        if(xPos < - 15)
            kindOfBullet = 1;
        else if (xPos > 15)
            kindOfBullet = 3;
        else
            kindOfBullet = 2;
        update(boundingRect());
    }
}

int BulletIndicator::getKindOfBullet()
{
    return kindOfBullet;
}

void BulletIndicator::setControllability(bool a)
{
    isControlled = a;
}

void BulletIndicator::setKindOfBullet(int num)
{
    kindOfBullet = num;
}

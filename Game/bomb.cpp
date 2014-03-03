#include "bomb.h"

Bomb::Bomb(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2):Bullet(sX, sY, speedX, speedY, res, g1, g2)
{
    numOfDamage = 40;
    radius = 100;

    setPos(sX - 5, sY - 5);
}

void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{


    painter->setBrush(QColor(50, 50, 50, 255));
    painter->drawEllipse(-10, -10, 20, 20);
    painter->setBrush(QColor(150, 150, 150, 255));
    painter->drawEllipse(-2, -2, 4, 4);
    painter->drawEllipse(-12, -2, 4, 4);
    painter->drawEllipse(8, -2, 4, 4);
    painter->drawEllipse(-2, -12, 4, 4);
    painter->drawEllipse(-2, 8, 4, 4);
    painter->drawEllipse(5, -9, 4, 4);
    painter->drawEllipse(5, 5, 4, 4);
    painter->drawEllipse(-9, -9, 4, 4);
    painter->drawEllipse(-9, 5, 4, 4);


}

QRectF Bomb::boundingRect() const
{
    return QRectF(-12, -12, 24, 24);
}

void Bomb::advance(int phase)
{
    if (resis > 0)
    {
        if (vX > 0)
            resisFactor = 0.5;
        else
            resisFactor = 2;
    }
    else if (resis < 0)
    {
        if (vX > 0)
            resisFactor = 2;
        else
            resisFactor = 0.5;
    }
    else
        resisFactor = 1;



    if (!phase)
        return;
    else if (collidesWithItem(gun1))
    {
        emit hit(x(), y(), 1, numOfDamage);
        scene()->removeItem(this);
        delete this;
    }
    else if (collidesWithItem(gun2))
    {
        emit hit(x(), y(), 2, numOfDamage);
        scene()->removeItem(this);
        delete this;
    }
    else if (y() > horizon - 5)
    {
        emit explosion(x(), radius, numOfDamage);
        scene()->removeItem(this);
        delete this;
    }
    else
    {



        double newX = t * vX + resis * t * t/2 * resisFactor;
        double newY = t * vY - t * t;
        newY = newY * (- 1);

        rotate(1);

        setPos(startX + newX, startY + newY);
        t = t + 0.3;




    }
}

QPainterPath Bomb::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    path.addEllipse(-12, -2, 4, 4);
    path.addEllipse(8, -2, 4, 4);
    path.addEllipse(-2, -12, 4, 4);
    path.addEllipse(-2, 8, 4, 4);
    path.addEllipse(5, -9, 4, 4);
    path.addEllipse(5, 5, 4, 4);
    path.addEllipse(-9, -9, 4, 4);
    path.addEllipse(-9, 5, 4, 4);
    return path;
}

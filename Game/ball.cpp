#include "ball.h"

Ball::Ball(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2):Bullet(sX, sY, speedX, speedY, res, g1, g2)
{
    numOfDamage = 25;
    radius = 75;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColor("black"));
    painter->drawEllipse(-6, -6, 12, 12);
    painter->setBrush(QColor("red"));
    painter->drawEllipse(-7, -2, 4, 4);
    painter->drawEllipse(3, -2, 4, 4);
    painter->drawEllipse(-2, -7, 4, 4);
    painter->drawEllipse(-2, 3, 4, 4);

}

QRectF Ball::boundingRect() const
{
    return QRectF(-7, -7, 14, 14);
}

void Ball::advance(int phase)
{
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
        double newX = t * vX + resis * t * t/2;
        double newY = t * vY - t * t;
        newY = newY * (- 1);
        setPos(startX + newX, startY + newY);
        t = t + 0.3;

        rotate(1);


    }
}

QPainterPath Ball::shape() const
{
    QPainterPath path;
    path.addEllipse(-5, -5, 10, 10);
    path.addEllipse(-7, -2, 4, 4);
    path.addEllipse(3, -2, 4, 4);
    path.addEllipse(-2, -7, 4, 4);
    path.addEllipse(-2, 3, 4, 4);
    return path;
}

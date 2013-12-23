#include "bullet.h"

Bullet::Bullet(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2)
{
    gun1 = g1;
    gun2 = g2;
    startX = sX;
    startY = sY;
    setPos(sX - 5, sY - 5);
    t = 0;
    vX = speedX;
    vY = speedY;
    resis = res;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColor("black"));
    painter->drawEllipse(-5, -5, 10, 10);

}

QRectF Bullet::boundingRect() const
{
    return QRectF(-5, -5, 10, 10);
}

void Bullet::advance(int phase)
{
    if (!phase)
        return;
    else if (collidesWithItem(gun1))
    {
        emit hit(x(), y(), 1);
        scene()->removeItem(this);
        delete this;
    }
    else if (collidesWithItem(gun2))
    {
        emit hit(x(), y(), 2);
        scene()->removeItem(this);
        delete this;
    }
    else if (y() > horizon - 5)
    {
        emit explosion(x());
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




    }
}

QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addEllipse(-5, -5, 10, 10);
    return path;
}

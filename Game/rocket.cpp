#include "rocket.h"
#include "math.h"


Rocket::Rocket(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2):Bullet(sX, sY, speedX, speedY, res, g1, g2)
{
    if (startX > 840)
        shooter = 2;
    else
        shooter = 1;

    numOfDamage = 12;
    radius = 50;

    setPos(sX - 5, sY - 5);

    angToRotate = - atan(vY / (vX + 0.0001)) * ConvInAng;

    if (shooter == 2)
        angToRotate = - 180 + angToRotate;


    setRotation(angToRotate);

}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{


    painter->setBrush(QColor(0, 200, 100, 255));
    painter->drawEllipse(-10, -3, 20, 6);
    painter->setBrush(QColor(0, 150, 75, 255));
    painter->drawEllipse(-10, -5, 8, 4);
    painter->drawEllipse(-10, 1, 8, 4);

    setRotation(angToRotate);


}

QRectF Rocket::boundingRect() const
{
    return QRectF(-10, -5, 20, 10);
}

void Rocket::advance(int phase)
{
    if (resis > 0)
    {
        if (vX > 0)
            resisFactor = 2;
        else
            resisFactor = 0.5;
    }
    else if (resis < 0)
    {
        if (vX > 0)
            resisFactor = 0.5;
        else
            resisFactor = 2;
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


        angToRotate = - atan((y() - (startY + newY)) / ((startX + newX) - x())) * ConvInAng;
        if (shooter == 2)
            angToRotate = - 180 + angToRotate;

        setPos(startX + newX, startY + newY);
        t = t + 0.3;




    }
}

QPainterPath Rocket::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -3, 20, 6);
    path.addEllipse(-10, -5, 8, 4);
    path.addEllipse(-10, 1, 8, 4);
    return path;
}

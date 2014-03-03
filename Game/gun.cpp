#include "gun.h"
Gun::Gun(int player)
{
    if (player == 1)
    {
        border1 = 90;
        border2 = 0;
    }
    else
    {
        border1 = 180;
        border2 = 90;
    }
    numOfPlayer = player;
    angle = 90;
    canRotate = false;
    health = 100;
}

void Gun::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);

    QLinearGradient gradient(-8, 0, 8, 0);
    if (numOfPlayer == 1)
    {
        gradient.setColorAt(0, QColor(150, 150, 150, 255));
        gradient.setColorAt(1, QColor(0, 0, 0, 255));
    }
    else
    {
        gradient.setColorAt(1, QColor(150, 150, 150, 255));
        gradient.setColorAt(0, QColor(0, 0, 0, 255));
    }



    painter->setBrush(QBrush(gradient));
    painter->drawEllipse(-8, -50, 15, 55);
    painter->drawEllipse(-8, -50, 15, 10);


    painter->setBrush(QColor("black"));
    painter->drawEllipse(-6, -48, 10, 5);

}

QRectF Gun::boundingRect() const
{
    return QRectF(- 50, - 50, 100, 100);
}

void Gun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        canRotate = true;
    }
}

void Gun::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (canRotate)
    {
        int x = event->pos().x();
        int y = event->pos().y();
        int lx = event->lastPos().x();
        int ly = event->lastPos().y();
        double angleForSet = angleFR(lx, ly, x, y) + angle;
        if (angleForSet <= border2)
            setAngle(border2);
        else if (angleForSet >= border1)
            setAngle(border1);
        else
            setAngle(angleForSet);


    }
}

void Gun::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        canRotate = false;
    }
}

void Gun::setAngle(double a)
{

    double rotAngle = angle - a;
    angle = a;
    rotate(rotAngle);
}

double Gun::getAngle()
{
    return angle;
}


double Gun::angleFR(int lx, int ly, int x, int y)
{
    double lengthl = sqrt(pow(lx, 2) + pow(ly, 2));
    double length = sqrt(pow(x, 2) + pow(y, 2));
    double angl = acos(lx / lengthl) * ConvInAng;
    double ang = acos(x / length) * ConvInAng;
    return ang - angl;
}

QPoint Gun::getPosForEx()
{
    double ang = getAngle() / ConvInAng;
    double px = 50 * cos(ang);
    double py = sqrt(2500 - px * px);
    py = y() - py * 1.4;
    px = px * 1.4 + x();
    return QPoint(px, py);
}

QPoint Gun::getSpeed(double factor)
{
    double ang = getAngle() / ConvInAng;
    double px = 50 * cos(ang);
    double py = sqrt(2500 - px * px);
    return QPoint(px * factor, py * factor);
}

void Gun::setDamage(int damage)
{
    health = health - damage;
    if (health > 0)
        emit healthChanged(health);
    else
    {
        emit healthChanged(0);
        emit crashed(numOfPlayer);
        scene()->removeItem(this);
    }
}

QPainterPath Gun::shape() const
{
    QPainterPath path;
    path.addEllipse(-8, -50, 15, 55);
    path.addEllipse(-8, -50, 15, 10);
    path.addEllipse(-10, -10, 20, 20);
    return path;

}

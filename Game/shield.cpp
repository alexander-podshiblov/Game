#include "shield.h"

Shield::Shield(int p)
{
    player = p;
    stepsToBuild = 0;
    bullet = NULL;
}

void Shield::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    double a = 0.05 * stepsToBuild;

    int coordX = 70;
    if (player == 2)
        coordX = 20;

    QRadialGradient gradient(coordX, -60, 70);
    gradient.setColorAt(0, QColor(220, 220, 0, 70));
    gradient.setColorAt(1, QColor(0, 0, 220, 70));
    painter->setBrush(QBrush(gradient));
    //painter->setBrush(QColor(0, 0, 200, 50));

    if (player == 1)
        painter->drawEllipse(-50 * a, -70 * a, 150 * a, 80 * a);
    else
        painter->drawEllipse(-100 * a, -70 * a, 150 * a, 80 * a);

}

QRectF Shield::boundingRect() const
{
    if (player == 1)
        return QRectF(-50, -70, 150, 80);
    else
        return QRectF(-100, -70, 150, 80);
}

QPainterPath Shield::shape() const
{
    QPainterPath path;
    if (player == 1)
        path.addEllipse(-50, -70, 150, 80);
    else
        path.addEllipse(-100, -70, 150, 80);
    return path;
}

void Shield::advance(int phase)
{
    if (!phase)
        return;
    else if(stepsToBuild < 20)
    {
        stepsToBuild++;
        update(boundingRect());
    }
    else if (collidesWithItem(bullet))
    {
        bullet->shieldMet();
        destroyShield();
    }

}

void Shield::destroyShield()
{
    scene()->removeItem(this);
    emit crashed(player);
    delete this;
}

void Shield::bulletCrashed()
{
    bullet = NULL;
}

void Shield::setBullet(Bullet *b)
{
    bullet = b;
}

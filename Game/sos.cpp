#include "sos.h"

Sos::Sos(int p, ShootControl *c)
{
    isUsed = false;
    control = c;
    player = p;
}

void Sos::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLinearGradient gradient(0, -11, 0, 25);
    gradient.setColorAt(0, QColor("white"));
    gradient.setColorAt(1, QColor(120, 120, 120, 255));
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(-53, -17, 106, 34, 8, 8);
    if (isUsed)
    {
        painter->drawPixmap(- 53, - 15, 106, 30, QPixmap(":/sos2.gif"));
    }
    else
    {
        painter->drawPixmap(- 53, - 15, 106, 30, QPixmap(":/sos.gif"));
    }



}

bool Sos::bonusIsUsed()
{
    return isUsed;
}

QRectF Sos::boundingRect() const
{
    return QRectF(- 53, - 17, 106, 34);
}

void Sos::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (player != 3 && !isUsed && player == control->whoShoot() && control->isReadyForShoot())
    {
        isUsed = true;
        emit getBonus(player);
        update(boundingRect());
    }
}

void Sos::activateCompBonus()
{
    if (player == 3 != isUsed)
    {
        isUsed = true;
        emit getBonus(2);
        update(boundingRect());
    }
}

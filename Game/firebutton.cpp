#include "firebutton.h"

FireButton::FireButton(int p, ShootControl *c)
{
    player = p;
    isPressed = false;
    normal = QPixmap(":/NormalFire.gif");
    pressed = QPixmap(":/PressedFire.gif");
    control = c;


}

void FireButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (isPressed)
        painter->drawPixmap(- 25, - 25, 50, 50, pressed);
    else
        painter->drawPixmap(- 25, - 25, 50, 50, normal);

}

QRectF FireButton::boundingRect() const
{
    return QRectF(- 25, - 25, 50, 50);
}

void FireButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (control->isReadyForShoot() && control->whoShoot() == player)
    {
        emit fire(player);
        isPressed = true;
        update(QRectF(- 25, - 25, 50, 50));
    }
}

void FireButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    if (isPressed && control->isReadyForShoot() && control->whoShoot() == player)
    {
        emit fire(player);
        isPressed = false;
        update(QRectF(- 25, - 25, 50, 50));
    }
}

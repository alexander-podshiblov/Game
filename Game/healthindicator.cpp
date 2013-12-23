#include "healthindicator.h"

HealthIndicator::HealthIndicator(int h)
{
    health = h;
}

void HealthIndicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLinearGradient gradient(0, -4, 0, 5);
    gradient.setColorAt(0, QColor("white"));
    gradient.setColorAt(1, QColor(120, 120, 120, 255));
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(-53, -8, 106, 16, 8, 8);
    QColor color;
    if (health == 0)
        return;
    else if (health > 66)
        color.setRgb(0, 255, 0, 255);
    else if (health < 33)
        color.setRgb(255, 0, 0, 255);
    else
        color.setRgb(255, 255, 0, 255);

    gradient.setColorAt(1, color);
    color.setAlpha(10);
    gradient.setColorAt(0, color);

    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(-50, -5, health, 10, 5, 5);

}

QRectF HealthIndicator::boundingRect() const
{
    return QRectF(-53, -8, 106, 16);
}

void HealthIndicator::setHealth(int h)
{
    health = h;
}

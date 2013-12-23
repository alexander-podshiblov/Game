#include "clouds.h"
#include <QPainter>


Clouds::Clouds(int wi, int he)
{
    w = wi;
    h = he;
    width = 0;
    for (int i = 0; i < 15; i++)
    {
        cloud[i] = new QGraphicsPixmapItem(QPixmap(":/cloud.gif"), this);
        cloud[i]->setPos(qrand() % w - 78, qrand() % h - 50);

    }
}

QRectF Clouds::boundingRect() const
{
    return QRectF(0, 0, w, h);
}

void Clouds::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawText(0,0, QString::number(width, 'f', 3));
}

void Clouds::setWidth(double w)
{
    width = w;
    update(boundingRect());
}

void Clouds::advance(int phase)
{
    if (!phase)
        return;
    else
    {
        for (int i = 0; i < 15; i++)
        {
            if (cloud[i]->x() + 78 < 0)
                cloud[i]->setPos(w - 78, qrand() % h - 50);
            else if (cloud[i]->x() + 78 > w)
                cloud[i]->setPos(0 - 78, qrand() % h - 50);
            else
                cloud[i]->setX(cloud[i]->x() + width * 3.0);
        }
    }
}

Clouds::~Clouds()
{
    for (int i =0; i < 15; i++)
    {
        delete cloud[i];
    }
}

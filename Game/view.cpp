#include "view.h"
#include <QPushButton>
#include <QBitmap>

View::View(QWidget *parent) :
    QGraphicsView(parent)
{
    setDragMode(QGraphicsView::ScrollHandDrag);

}


void View::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        scale(qreal(1.05), qreal(1.05));
    }
    else
    {
        scale(1 / qreal(1.05), 1 / qreal(1.05));
    }
}


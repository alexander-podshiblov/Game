#include "powercontroller.h"
#include "math.h"
PowerController::PowerController(int p)
{
    player = p;
    isStarted = false;
    factorOfPower = 0.75;
    df = 0.05;
    activeAuto = false;
    needFactor = 1.0;


    QLinearGradient gradient(0, -4, 0, 5);
    gradient.setColorAt(0, QColor("white"));
    gradient.setColorAt(1, QColor(0, 255, 0, 255));
    ball = new QGraphicsEllipseItem(-5, -5, 10, 10, this);
    ball->setBrush(QBrush(gradient));
}

void PowerController::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLinearGradient gradient(0, -5, 0, 5);
    gradient.setColorAt(0, QColor("white"));
    gradient.setColorAt(1, QColor(120, 120, 120, 255));
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(-53, -8, 106, 16, 8, 8);

    gradient.setColorAt(1, QColor(90, 90, 90, 255));
    painter->drawRoundedRect(-50, -5, 100, 10, 5, 5);
}

QRectF PowerController::boundingRect() const
{
    return QRectF(- 50, -8, 100, 120);
}

double PowerController::getFactor()
{
    return factorOfPower;
}

void PowerController::start(int p)
{
    if(!isStarted)
    {
        isStarted = true;
    }
    else
    {
        isStarted = false;
        emit fire(player);
    }
}

void PowerController::startAuto(int p, double factor)
{
    if(!isStarted)
    {
        needFactor = factor;
        isStarted = true;
        activeAuto = true;
    }

}

void PowerController::advance(int phase)
{
    if(!phase)
        return;
    else if(isStarted)
    {
        factorOfPower = factorOfPower + df;

        if (fabs(factorOfPower - 1.5) < 0.02)
        {
            factorOfPower = 1.5;
            df = df * (-1);
        }
        else if (fabs(factorOfPower) < 0.02)
        {
            factorOfPower = 0;
            df = df * (-1);
        }
        ball->setX(factorOfPower * 60 - 45);
        QLinearGradient gradient(0, -4, 0, 5);
        gradient.setColorAt(0, QColor("white"));
        gradient.setColorAt(1, QColor(170 * factorOfPower, 0, 255 - 170 * factorOfPower, 255));
        ball->setBrush(QBrush(gradient));
        if(activeAuto && fabs(factorOfPower - needFactor) < 0.02)
        {
            isStarted = false;
            activeAuto = false;
            emit fire(player);
        }

    }
}



PowerController::~PowerController()
{
    delete ball;
}

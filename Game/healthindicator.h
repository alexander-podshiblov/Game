#pragma once
#include <QGraphicsItem>
#include <QPainter>

class HealthIndicator : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    HealthIndicator(int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

private:
    int health;

signals:
    
public slots:
    void setHealth(int h);

    
};


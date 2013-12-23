#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class PowerController : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    PowerController(int p);
    ~PowerController();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    double getFactor();

signals:
    void fire(int p);
public slots:
    void start(int p);
    void startAuto(int p, double factor);

protected:
    void advance(int phase);

    //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    bool isStarted;
    double factorOfPower;
    int player;
    double df;
    bool activeAuto;
    double needFactor;
    QGraphicsEllipseItem *ball;
};


#pragma once
#include <QGraphicsItem>


class Clouds : public QGraphicsItem
{
public:
    Clouds(int wi, int he);
    ~Clouds();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void setWidth(double w);
protected:
    void advance(int phase);

private:
    QGraphicsPixmapItem *cloud[15];
    double width;
    int w;
    int h;
};


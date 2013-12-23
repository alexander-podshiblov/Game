#pragma once

#include <QGraphicsView>
#include <QMouseEvent>
#include "scene.h"


class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *event);


private:

public slots:

signals:
};

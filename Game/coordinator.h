#pragma once
#include "mainwindow.h"
#include <QGraphicsView>
#include <QObject>
#include "view.h"
#include "scene.h"

class Coordinator : public QObject
{
    Q_OBJECT
public:
    Coordinator(MainWindow *m, View *v);

private:
    MainWindow *menu;
    QGraphicsView *view;

public slots:
    void runGameH();
    void runGameC(int sk);
    void runMenu();




};


#include <QApplication>
#include "mainwindow.h"
#include "scene.h"
#include <QGraphicsView>
#include "coordinator.h"
#include <QTimer>
#include "view.h"
#include <QMovie>
#include <QLabel>
#include <QTime>
int main(int argc, char *argv[])
{




    QApplication a(argc, argv);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    MainWindow *window = new MainWindow();
    View *v = new View;







    Coordinator *c = new Coordinator(window, v);



    QObject::connect(window, SIGNAL(human()), c, SLOT(runGameH()));
    QObject::connect(window, SIGNAL(computer(int)), c, SLOT(runGameC(int)));
    QObject::connect(window, SIGNAL(pressedExit()), &a, SLOT(quit()));
    window->show();




    return a.exec();


/*
    Gun *g = new Gun(2);
    FILE *f = fopen("tab_rocket.txt", "w");
    for (double j = -1.5; j < 1.6; j = j + 0.1)
    {
    for (int i = 180; i >= 90; i--)
    {
      for(double fa = 0; fa <= 1.5; fa = fa + 0.1)
      {
        g->setAngle(i);
        double ang = g->getAngle() / ConvInAng;
        double px = 50 * cos(ang);
        double py = sqrt(2500 - px * px);
        py = py * 1.2;
        px = px * 1.2;
        double vX = g->getSpeed(fa).x();
        double vY = g->getSpeed(fa).y();
        double t = 0.01;
        bool c = true;

        while(c)
        {
            double newY = t * vY - t * t;
            newY = newY * (- 1);
            if (newY >= py)
                c = false;
            t = t + 0.1;

        }

        t = t - 0.1;
//
        double resisFactor = 1;
        if (j > 0)
        {
                resisFactor = 0.5;
        }
        else if (j < 0)
        {
                resisFactor = 2;
        }

//
        double x = t * vX + j * (t * t)/2 * resisFactor + px + wOfField - indent;
        if (abs(x - indent) <= 6.0)
        {
            fprintf(f, "%f %f %i \n", j, fa, i);
            printf("%f %f %i \n", j, fa, i);
            i = 0;
            break;
        }

      }

    }
    }

    fclose(f);

    return 0;
*/
}

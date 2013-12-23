#include "coordinator.h"

Coordinator::Coordinator(MainWindow *m, View *v)
{
    menu = m;
    view = v;
}

void Coordinator::runGameH()
{
    view->setGeometry(20, 50, 1300, hOfField + 10);

    Scene *s = new Scene(1);
    view->setScene(s);
    view->show();
    menu->close();
    connect(s, SIGNAL(returnToMenu()), this, SLOT(runMenu()));
}

void Coordinator::runGameC(int sk)
{
    view->setGeometry(20, 50, 1300, hOfField + 10);

    Scene *s = new Scene(2);
    s->setSkill(sk);
    view->setScene(s);
    view->show();
    menu->close();
    connect(s, SIGNAL(returnToMenu()), this, SLOT(runMenu()));
}

void Coordinator::runMenu()
{
    view->close();
    menu->buildMenu();
    menu->show();
}

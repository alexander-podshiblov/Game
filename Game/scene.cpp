#include "scene.h"
#include "stdio.h"


Scene::Scene(int mod)
{
    FILE *f = fopen("tab.txt", "r");
    for (int i = 0; i < 31; i++)
    {
        fscanf(f, "%lf%lf%lf", &tab[i][0], &tab[i][1], &tab[i][2]);

    }
    fclose(f);

    skill = 6;

    autoShooStart = false;

    isFinished = false;
    gameMod = mod;

    setSceneRect(0, 0, wOfField, hOfField);
    QLinearGradient gradient(0, 0, 0, horizon);
    gradient.setColorAt(0, QColor(150, 200, 250, 185));
    gradient.setColorAt(1, QColor(215, 215, 150, 150));




    clouds = new Clouds(graundFinish - graundStart, horizon - 200);
    clouds->setPos(graundStart, 0);
    setWidth((qrand() % 30 - 15.0) / 10.0);
    addItem(clouds);



    setBackgroundBrush(QBrush(gradient));
    addEllipse(-200 ,horizon - 20, wOfField + 400, 40, QPen(QColor("black"), 1), QColor(200, 150, 30, 140));


    control = new ShootControl();

    FireButton *z = new FireButton(1, control);
    z->setPos(indent, 250);
    addItem(z);

    FireButton *z2;
    if (gameMod != 2)
    {
        z2 = new FireButton(2,control);
        z2->setPos(wOfField - indent, 250);
        addItem(z2);
    }


    boomSound = new QSound("shoot.wav", 0);
    explosionSound = new QSound("explosion.wav", 0);
    miss = new QSound("miss.wav", 0);


    QGraphicsPixmapItem *wheel = new QGraphicsPixmapItem(QPixmap(":/wheel.gif"));
    wheel->setX(indent - 7);
    wheel->setY(horizon - 20);
    addItem(wheel);
    gun1 = new Gun(1);
    gun1->setPos(indent, horizon - 10);
    gun1->setAngle(45);
    addItem(gun1);
    connect(gun1, SIGNAL(crashed(int)), this, SLOT(doCrash(int)));
    QGraphicsPixmapItem *wheel2 = new QGraphicsPixmapItem(QPixmap(":/wheel.gif"));
    wheel2->setX(indent - 10);
    wheel2->setY(horizon - 20);
    addItem(wheel2);




    QGraphicsPixmapItem *wheel3 = new QGraphicsPixmapItem(QPixmap(":/wheel.gif"));
    wheel3->setX(wOfField - indent - 13);
    wheel3->setY(horizon - 20);
    addItem(wheel3);
    gun2 = new Gun(2);
    gun2->setPos(wOfField - indent, horizon - 10);
    gun2->setAngle(135);
    addItem(gun2);

    connect(gun2, SIGNAL(crashed(int)), this, SLOT(doCrash(int)));
    QGraphicsPixmapItem *wheel4 = new QGraphicsPixmapItem(QPixmap(":/wheel.gif"));
    wheel4->setX(wOfField - indent - 10);
    wheel4->setY(horizon - 20);
    addItem(wheel4);



////////
    health1 = new HealthIndicator(100);
    health1->setPos(indent, horizon - 120);
    addItem(health1);
    connect(gun1, SIGNAL(healthChanged(int)), health1, SLOT(setHealth(int)));

    health2 = new HealthIndicator(100);
    health2->setPos(wOfField - indent, horizon - 120);
    addItem(health2);
    connect(gun2, SIGNAL(healthChanged(int)), health2, SLOT(setHealth(int)));

///////
    pContr1 = new PowerController(1);
    pContr1->setPos(indent, horizon - 140);
    addItem(pContr1);
    connect(z, SIGNAL(fire(int)), pContr1, SLOT(start(int)));
    connect(pContr1, SIGNAL(fire(int)), this, SLOT(doFire(int)));


    pContr2 = new PowerController(2);
    pContr2->setPos(wOfField - indent, horizon - 140);
    addItem(pContr2);
    if (gameMod != 2)
        connect(z2, SIGNAL(fire(int)), pContr2, SLOT(start(int)));
    connect(pContr2, SIGNAL(fire(int)), this, SLOT(doFire(int)));

    ///////
    QMovie *m = new QMovie("123.gif");
    viewBoom = new QLabel();
    viewBoom->setMovie(m);
    viewBoom->setGeometry(0, -32, 96, 64);
    viewBoom->setAttribute(Qt::WA_NoBackground);
    boom = addWidget(viewBoom);

///////
    m = new QMovie("exp.gif");
    viewExplosion = new QLabel();
    viewExplosion->setMovie(m);
    viewExplosion->setGeometry(-24, -112, 48, 112);
    viewExplosion->setAttribute(Qt::WA_NoBackground);
    explosion = addWidget(viewExplosion);

    m = new QMovie("crash.gif");
    viewCrash = new QLabel();
    viewCrash->setMovie(m);
    viewCrash->setGeometry(-95, -300, 190, 322);
    viewCrash->setAttribute(Qt::WA_NoBackground);
    crash = addWidget(viewCrash);

    m = new QMovie("hit.gif");
    viewHit = new QLabel();
    viewHit->setMovie(m);
    viewHit->setGeometry(-35, -52, 71, 100);
    viewHit->setAttribute(Qt::WA_NoBackground);
    hit = addWidget(viewHit);

//////
    timer = new QTimer();
    timer->setInterval(30);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
//////

}


void Scene::doFire(int player)
{
    if (!isFinished)
    {
        Gun *g;
        double factor;
        if (player == 1)
        {
            g = gun1;
            factor = pContr1->getFactor();
        }
        else
        {
            g = gun2;
            factor = pContr2->getFactor();
        }


        Bullet * bull = new Bullet(g->getPosForEx().x(), g->getPosForEx().y(), g->getSpeed(factor).x(), g->getSpeed(factor).y(), width, gun1, gun2);
        addItem(bull);
        connect(bull, SIGNAL(explosion(int)), this, SLOT(doExplosion(int)));
        connect(bull, SIGNAL(hit(int,int,int)), this, SLOT(doHit(int,int,int)));


    ///////////////
        viewBoom->movie()->stop();
        QPoint p;
        p = g->getPosForEx();
        boom->setPos(p.x(), p.y() - 32);
        boom->setTransform(QTransform().translate(0, 32).rotate(- g->getAngle()).translate(-0, -32));
        boomSound->play();
        viewBoom->movie()->start();
        control->wasShoot();
    }

}

void Scene::doExplosion(int eX)
{
    if (eX > graundStart && eX < graundFinish)
    {
        viewExplosion->movie()->stop();
        explosion->setPos(eX - 24, horizon - 112);
        explosionSound->play();
        viewExplosion->movie()->start();
        int p;
        int r;
        if (fabs(gun1->x() - eX) < fabs(gun2->x() - eX))
        {
            p = 1;
            r = fabs(gun1->x() - eX);
        }
        else
        {
            p = 2;
            r = fabs(gun2->x() - eX);
        }
        if (r < 75)
        {
            double d = 1.0 / 3.0 * (75.0 - r);
            Gun *g;
            if (p == 1)
                g = gun1;
            else
                g = gun2;

            g->setDamage(d);
            if (p == 1)
                health1->update(health1->boundingRect());
            else
                health2->update(health2->boundingRect());
        }
    }
    else
    {
        miss->play();
    }
    control->setReady();
    setWidth((qrand() % 30 - 15.0) / 10.0);

    if (gameMod == 2 && control->whoShoot() == 2)
        doAutoShoot();

}

void Scene::setWidth(double w)
{
    width = w;
    clouds->setWidth(w);

}

void Scene::doHit(int hx, int hy, int numOfGun)
{
    viewHit->movie()->stop();
    hit->setPos(hx - 35, hy - 52);
    explosionSound->play();
    viewHit->movie()->start();

    Gun *g;
    if (numOfGun == 1)
        g = gun1;
    else
        g = gun2;

    g->setDamage(25);
    if (numOfGun == 1)
        health1->update(health1->boundingRect());
    else
        health2->update(health2->boundingRect());
    control->setReady();
    setWidth((qrand() % 30 - 15.0) / 10.0);
////
    if (gameMod == 2 && control->whoShoot() == 2)
        doAutoShoot();

}

void Scene::doCrash(int player)
{
    isFinished = true;
    timer->stop();
    if (player == 1)
    {
        crash->setPos(indent - 95, horizon - 300);
    }
    else
    {
        crash->setPos(wOfField - indent - 95, horizon - 300);
    }
    viewCrash->movie()->start();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        emit returnToMenu();
        delete this;
    }
}

Scene::~Scene()
{
    delete boomSound;
    delete explosionSound;
    delete miss;

    delete timer;


    delete viewBoom;

    delete viewExplosion;

    delete viewCrash;

    delete viewHit;

    delete  control;

    delete pContr1;
    delete pContr2;

    QList<QGraphicsItem *> a = items();
    while(!a.isEmpty())
    {
        removeItem(a.first());
        a.removeFirst();
    }
}

void Scene::doAutoShoot()
{
    if(!autoShooStart)
    {
        connect(timer, SIGNAL(timeout()), this, SLOT(doAutoShoot()));
        autoShooStart = true;
        c = 0;
        int i = (width + 1.5) * 10.0;
        stepOfAutoAim = (tab[i][2] - gun2->getAngle()) / 20;
    }
    else if (c < 19)
    {
        c++;
        gun2->setAngle(gun2->getAngle() + stepOfAutoAim);
    }
    else
    {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(doAutoShoot()));
        autoShooStart = false;
        int i = (width + 1.5) * 10.0;
        double delta = 0;
        if (skill != 0)
            delta = (qrand() % (2 * skill)) - skill;
        gun2->setAngle(tab[i][2] + delta);
        pContr2->startAuto(2, tab[i][1]);

    }

}

void Scene::setSkill(int s)
{
    skill = s;
}



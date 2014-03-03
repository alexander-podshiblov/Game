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

    f = fopen("tab_rocket.txt", "r");
    for (int i = 0; i < 31; i++)
    {
        fscanf(f, "%lf%lf%lf", &tab_rocket[i][0], &tab_rocket[i][1], &tab_rocket[i][2]);

    }
    fclose(f);

    f = fopen("tab_bomb.txt", "r");
    for (int i = 0; i < 31; i++)
    {
        fscanf(f, "%lf%lf%lf", &tab_bomb[i][0], &tab_bomb[i][1], &tab_bomb[i][2]);

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

    sh1 = NULL;
    sh2 = NULL;

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
    QGraphicsPixmapItem *player1 = new QGraphicsPixmapItem(QPixmap(":/player1.gif"));
    player1->setPos(indent - 80, 150);
    addItem(player1);

    if (gameMod == 1)
    {
        QGraphicsPixmapItem *player2 = new QGraphicsPixmapItem(QPixmap(":/player2.gif"));
        player2->setPos(wOfField - indent - 80, 150);
        addItem(player2);
    }
    else if (gameMod == 2)
    {
        QGraphicsPixmapItem *computer = new QGraphicsPixmapItem(QPixmap(":/computer.gif"));
        computer->setPos(wOfField - indent - 120, 150);
        addItem(computer);
    }








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
    sosButton1 = new Sos(1, control);
    sosButton1->setPos(indent, 373);
    addItem(sosButton1);

    int p = 2;
    if (gameMod == 2)
        p = 3;

    sosButton2 = new Sos(p, control);
    sosButton2->setPos(wOfField - indent, 373);
    addItem(sosButton2);

    connect(sosButton1, SIGNAL(getBonus(int)), this, SLOT(setShield(int)));
    connect(sosButton2, SIGNAL(getBonus(int)), this, SLOT(setShield(int)));

///////
    bInd1 = new BulletIndicator();
    bInd1->setPos(indent, 320);
    addItem(bInd1);

    bInd2 = new BulletIndicator();
    bInd2->setPos(wOfField - indent, 320);
    if (gameMod == 2)
        bInd2->setControllability(false);
    addItem(bInd2);


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
///////
    m = new QMovie("aind1.gif");
    viewPInd1 = new QLabel();
    viewPInd1->setMovie(m);
    viewPInd1->setGeometry(-250, 0, 500, 150);
    viewPInd1->setAttribute(Qt::WA_NoBackground);
    pInd1 = addWidget(viewPInd1);

    pInd1->setPos(wOfField / 2 - 250, 50);

    viewPInd1->movie()->stop();
    viewPInd1->movie()->start();

    if (gameMod == 1)
    {
        m = new QMovie("aind2.gif");
        viewPInd2 = new QLabel();
        viewPInd2->setMovie(m);
        viewPInd2->setGeometry(-250, 0, 500, 150);
        viewPInd2->setAttribute(Qt::WA_NoBackground);
        pInd2 = addWidget(viewPInd2);

        pInd2->setPos(wOfField / 2 - 250, 50);
    }
    else
    {
        m = new QMovie("aindc.gif");
        viewPIndc = new QLabel();
        viewPIndc->setMovie(m);
        viewPIndc->setGeometry(-250, 0, 500, 150);
        viewPIndc->setAttribute(Qt::WA_NoBackground);
        pIndc = addWidget(viewPIndc);

        pIndc->setPos(wOfField / 2 - 250, 50);
    }
//////
    timer = new QTimer();
    timer->setInterval(30);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
//////


}

void Scene::showWinner(int p)
{
    QMovie *m;
    QMovie *s = new QMovie("salute.gif");
    QLabel *viewSalute = new QLabel();
    viewSalute->setMovie(s);
    viewSalute->setGeometry(-70, 0, 139, 146);
    viewSalute->setAttribute(Qt::WA_NoBackground);
    QGraphicsProxyWidget *salute = addWidget(viewSalute);

    int coord = wOfField - indent;
    if (p == 1)
    {
        m = new QMovie("win1.gif");
        coord = indent;
    }
    else if (p == 2)
    {
        m = new QMovie("win2.gif");
    }
    else
    {
        m = new QMovie("winc.gif");
    }

    salute->setPos(coord - 70, horizon - 150);

    QLabel *viewWinner = new QLabel();
    viewWinner->setMovie(m);
    viewWinner->setGeometry(-250, 0, 500, 150);
    viewWinner->setAttribute(Qt::WA_NoBackground);
    QGraphicsProxyWidget *winner = addWidget(viewWinner);

    winner->setPos(wOfField / 2 - 250, 50);

    viewWinner->show();
    viewWinner->movie()->start();
    viewSalute->show();
    viewSalute->movie()->start();
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


        Bullet *bull;
        BulletIndicator *tempBI;
        if (control->whoShoot() == 1)
            tempBI = bInd1;
        else if (control->whoShoot() == 2)
            tempBI = bInd2;



        if (tempBI->getKindOfBullet() == 1)
            bull = new Ball(g->getPosForEx().x(), g->getPosForEx().y(), g->getSpeed(factor).x(), g->getSpeed(factor).y(), width, gun1, gun2);
        else if (tempBI->getKindOfBullet() == 2)
            bull = new Rocket(g->getPosForEx().x(), g->getPosForEx().y(), g->getSpeed(factor).x(), g->getSpeed(factor).y(), width, gun1, gun2);
        else
            bull = new Bomb(g->getPosForEx().x(), g->getPosForEx().y(), g->getSpeed(factor).x(), g->getSpeed(factor).y(), width, gun1, gun2);

        addItem(bull);
        connect(bull, SIGNAL(explosion(int, int, int)), this, SLOT(doExplosion(int, int, int)));
        connect(bull, SIGNAL(hit(int,int,int, int)), this, SLOT(doHit(int,int,int, int)));

        if (player == 1 && sh2 != NULL)
        {
            sh2->setBullet(bull);
            connect(bull, SIGNAL(explosion(int, int, int)), sh2, SLOT(bulletCrashed()));
            connect(bull, SIGNAL(hit(int,int,int, int)), sh2, SLOT(bulletCrashed()));
        }
        else if (player == 2 && sh1 != NULL)
        {
            sh1->setBullet(bull);
            connect(bull, SIGNAL(explosion(int, int, int)), sh1, SLOT(bulletCrashed()));
            connect(bull, SIGNAL(hit(int,int,int, int)), sh1, SLOT(bulletCrashed()));
        }

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

void Scene::changeInd(int p)
{
    if (p == 1)
    {
        if (gameMod == 2)
        {
            viewPIndc->movie()->stop();
            viewPIndc->hide();
        }
        else
        {
            viewPInd2->movie()->stop();
            viewPInd2->hide();
        }

        viewPInd1->show();
        viewPInd1->movie()->start();
    }
    else if (p == 2)
    {
        viewPInd1->movie()->stop();
        viewPInd1->hide();

        if (gameMod == 2)
        {
            viewPIndc->show();
            viewPIndc->movie()->start();
        }
        else
        {
            viewPInd2->show();
            viewPInd2->movie()->start();
        }
    }
    else
    {
        if (gameMod == 2)
        {
            viewPIndc->movie()->stop();
            viewPIndc->hide();
        }
        else
        {
            viewPInd2->movie()->stop();
            viewPInd2->hide();
        }
        viewPInd1->movie()->stop();
        viewPInd1->hide();

    }

}

void Scene::doExplosion(int eX, int rad, int damage)
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
        if (r < rad)
        {
            double d = damage * (rad - r) / rad;
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

    changeInd(control->whoShoot());

    if (gameMod == 2 && control->whoShoot() == 2)
        doAutoShoot();



}

void Scene::setWidth(double w)
{
    width = w;
    clouds->setWidth(w);

}

void Scene::doHit(int hx, int hy, int numOfGun, int damage)
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

    g->setDamage(damage);
    if (numOfGun == 1)
        health1->update(health1->boundingRect());
    else
        health2->update(health2->boundingRect());
    control->setReady();
    setWidth((qrand() % 30 - 15.0) / 10.0);
////
    if (health1->getHealth() > 0 && health2->getHealth() > 0)
        changeInd(control->whoShoot());
    else
        changeInd(0);

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
        if (gameMod == 1)
            showWinner(2);
        else
            showWinner(3);
    }
    else
    {
        crash->setPos(wOfField - indent - 95, horizon - 300);
        showWinner(1);
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
        if(!sosButton2->bonusIsUsed())
        {
            if (qrand() % 100 < 100 - health2->getHealth())
                sosButton2->activateCompBonus();
        }




        numOfBullet = qrand() % 3 + 1;
        if (width > 0.9 && numOfBullet == 3)
            numOfBullet = qrand() % 2 + 1;

        bInd2->setKindOfBullet(numOfBullet);

        connect(timer, SIGNAL(timeout()), this, SLOT(doAutoShoot()));
        autoShooStart = true;
        c = 0;
        int i = (width + 1.5) * 10.0;
        if (numOfBullet == 1)
            stepOfAutoAim = (tab[i][2] - gun2->getAngle()) / 20;
        else if (numOfBullet == 2)
            stepOfAutoAim = (tab_rocket[i][2] - gun2->getAngle()) / 20;
        else
            stepOfAutoAim = (tab_bomb[i][2] - gun2->getAngle()) / 20;
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

        if (numOfBullet == 1)
        {
            gun2->setAngle(tab[i][2] + delta);
            pContr2->startAuto(2, tab[i][1]);
        }
        else if (numOfBullet == 2)
        {
            gun2->setAngle(tab_rocket[i][2] + delta);
            pContr2->startAuto(2, tab_rocket[i][1]);
        }
        else
        {
            gun2->setAngle(tab_bomb[i][2] + delta);
            pContr2->startAuto(2, tab_bomb[i][1]);
        }
    }

}

void Scene::setSkill(int s)
{
    skill = s;
}

void Scene::setShield(int p)
{
    Shield *sh = new Shield(p);
    int coordX = indent;
    if (p == 2)
        coordX = wOfField - indent;
    sh->setPos(coordX, horizon);
    addItem(sh);

    if (p == 1)
        sh1 = sh;
    else
        sh2 = sh;

    connect(sh, SIGNAL(crashed(int)), this, SLOT(crashShield(int)));
}

void Scene::crashShield(int p)
{
    if (p == 1)
        sh1 = NULL;
    else
        sh2 = NULL;
}



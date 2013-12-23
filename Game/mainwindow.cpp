#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    startButton = new QPushButton("VS Human", this);
    startButton->setGeometry(this->width() / 2 - 35, this->height() / 2 - 40, 70, 20);
    connect(startButton, SIGNAL(clicked()), this, SIGNAL(human()));

    startButton2 = new QPushButton("VS Computer", this);
    startButton2->setGeometry(this->width() / 2 - 35, this->height() / 2 - 15, 70, 20);
    connect(startButton2, SIGNAL(clicked()), this, SLOT(chooseDiff()));


    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(this->width() / 2 - 35, this->height() / 2 + 10, 70, 20);
    connect(exitButton, SIGNAL(clicked()), this, SIGNAL(pressedExit()));

    easy = new QPushButton("Easy", this);
    easy->setGeometry(this->width() / 2 - 35, this->height() / 2 - 40, 70, 20);
    connect(easy, SIGNAL(clicked()), this, SLOT(computerE()));

    normal = new QPushButton("Normal", this);
    normal->setGeometry(this->width() / 2 - 35, this->height() / 2 - 15, 70, 20);
    connect(normal, SIGNAL(clicked()), this, SLOT(computerN()));

    hard = new QPushButton("Hard", this);
    hard->setGeometry(this->width() / 2 - 35, this->height() / 2 + 10, 70, 20);
    connect(hard, SIGNAL(clicked()), this, SLOT(computerH()));

    death = new QPushButton("Death", this);
    death->setGeometry(this->width() / 2 - 35, this->height() / 2 + 35, 70, 20);
    connect(death, SIGNAL(clicked()), this, SLOT(computerD()));

    back = new QPushButton("Back", this);
    back->setGeometry(this->width() / 2 - 35, this->height() / 2 + 60, 70, 20);
    connect(back, SIGNAL(clicked()), this, SLOT(buildMenu()));

    easy->close();
    normal->close();
    hard->close();
    death->close();
    back->close();
}

void MainWindow::buildMenu()
{
    easy->close();
    normal->close();
    hard->close();
    death->close();
    back->close();
    startButton->show();
    startButton2->show();
    exitButton->show();



}
void MainWindow::chooseDiff()
{
    startButton->close();
    startButton2->close();
    exitButton->close();


    easy->show();

    normal->show();

    hard->show();

    death->show();

    back->show();
}

void MainWindow::computerE()
{
    emit computer(6);
}

void MainWindow::computerN()
{
    emit computer(4);
}

void MainWindow::computerH()
{
    emit computer(2);
}

void MainWindow::computerD()
{
    emit computer(0);
}


MainWindow::~MainWindow()
{
    delete startButton;
    delete exitButton;
    delete ui;
}

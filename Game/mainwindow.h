#include <QMainWindow>
#include <QPushButton>
#pragma once

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void chooseDiff();
    void computerE();
    void computerN();
    void computerH();
    void computerD();
    void buildMenu();
private:
    Ui::MainWindow *ui;
    QPushButton *startButton;
    QPushButton *startButton2;
    QPushButton *exitButton;
    QPushButton *easy;
    QPushButton *normal;
    QPushButton *hard;
    QPushButton *death;
    QPushButton *back;

signals:
    void human();
    void computer(int s);

    void pressedExit();
};

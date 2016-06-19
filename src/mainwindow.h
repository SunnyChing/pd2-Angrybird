#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QLabel>
#include <Qpaintevent>
#include <QPointF>

#include "gameitem.h"
#include "land.h"
#include "bird.h"
#include "bird1.h"
#include "bird2.h"
#include "bird3.h"
#include "bird4.h"
#include "wood.h"
#include "pig.h"
#include "contactlistener.h"
#include "qpushbutton.h"

#define GAIN_VX 0.4
#define GAIN_VY -0.3
#define BIRDNUMBER 5
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *scene;
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    //void paintEvent(QPaintEvent *event);
    void setGame();
    void setparam();
    int score=0;

signals:
    //Signal for closing the game
   void quitGame();

private slots:
    void tick();
    QPointF getBirdPosition();
    // For debug slot
    void QUITSLOT();
    void restart();
private:
    Ui::MainWindow *ui;
    b2World *world;
    QList<GameItem *> itemList;
    Mycontactlistener *contactlisten;
    QTimer timer;
    QPushButton * bt_restart;
    GameItem *birdie[BIRDNUMBER];
    Wood *wood[2],*wood1;
    GameItem *pig[2];
    QLabel *score_dipl;
    QGraphicsPixmapItem *sling;

    float x_1, y_1, x_2, y_2,x_3, y_3;
    int moveflag, changeflag,bird_ind,m2,m1,m3,m4,isfly;
    int b[4]={1};  //bird extinct index
    void nextbird();



};

#endif // MAINWINDOW_H

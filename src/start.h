#ifndef START_H
#define START_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QPushButton>
#include<QObject>
#include<Qdebug>
#include"mainwindow.h"


class Start:public QGraphicsView
{
    Q_OBJECT
public:
    Start();
    ~Start(){qDebug()<<"startwindow close";}
    QGraphicsScene * startscene;
    QPushButton * bt_start,*bt_exit;

signals:
    //Signal for closing the game
    void quitGame();

public slots:
   void CloseStartView();
   void OpenGame();
   void QUITSLOT();
};


#endif // START_H

#ifndef BIRD1_H
#define BIRD1_H
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include "gameitem.h"
#include "mainwindow.h"
#include "QDebug"
#define BIRD1_DENSITY 10.0f
#define BIRD1_FRICTION 0.2f
#define BIRD1_RESTITUTION 0.5f

class Bird1 :public GameItem
{
public:
    Bird1(float x, float y, float radius, b2World *world, QGraphicsScene *scene);
    ~Bird1(){qDebug()<<"delete blue bird";}
    virtual void shoot2();
    virtual void remove();
    Bird1 *bird11, *bird12;
    QGraphicsScene *scene1;
    b2CircleShape bodyshape;
    int isshoot2=0;


};
#endif // BIRD1_H

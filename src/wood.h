#ifndef WOOD_H
#define WOOD_H

#include <QGraphicsScene>
#include "gameitem.h"
#include "bird.h"

#define WOOD_DENSITY 8.0f
#define WOOD_FRICTION 0.6f
#define WOOD_RESTITUTION 0.5f

class Wood:public GameItem
{

public:
    Wood(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void turn();
};

#endif // WOOD_H

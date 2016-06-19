#ifndef SLING_H
#define SLING_H

#include <QGraphicsScene>
#include "gameitem.h"
class Sling: public GameItem
{
public:
    Sling(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setposition(float x, float y);

    b2BodyDef bodydef;
};

#endif // SLING_H

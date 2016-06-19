#ifndef BIRD4_H
#define BIRD4_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Bird4 : public GameItem
{
public:
    Bird4(float x, float y, float radius,  b2World *world, QGraphicsScene *scene);
    virtual void shoot2();
    virtual void remove();
};

#endif // BIRD4_H

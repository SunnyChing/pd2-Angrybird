#ifndef BIRD2_H
#define BIRD2_H


#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD2_DENSITY 10.0f
#define BIRD2_FRICTION 0.2f
#define BIRD2_RESTITUTION 0.5f

class Bird2 : public GameItem
{
public:
    Bird2(float x, float y, float radius,  b2World *world, QGraphicsScene *scene);
    virtual void shoot2();
    virtual void remove();

};
#endif // BIRD2_H

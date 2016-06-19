#ifndef BIRD3_H
#define BIRD3_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD3_DENSITY 10.0f
#define BIRD3_FRICTION 0.2f
#define BIRD3_RESTITUTION 0.5f

class Bird3 : public GameItem
{
public:
    Bird3(float x, float y, float radius,  b2World *world, QGraphicsScene *scene);
    virtual void shoot2();
    virtual void remove();
    QGraphicsScene *scene1;

};
#endif // BIRD3_H

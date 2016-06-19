#ifndef PIG_H
#define PIG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define PIG_DENSITY 200.0f
#define PIG_FRICTION 0.5f
#define PIG_RESTITUTION 0.5f

class Pig : public GameItem
{
public:
    Pig(float x, float y, float radius, b2World *world, QGraphicsScene *scene);
    int pigkilled;
public slots:
    virtual void remove();

};
#endif // PIG_H

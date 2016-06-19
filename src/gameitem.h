#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include <QTimer>
#include "myuserdata.h"
#include "contactlistener.h"

class GameItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    void setLinearVelocity(b2Vec2 velocity);
    virtual void shoot2();

    QPointF getBirdPostion();
    b2Body *g_body;
    b2World *g_world;
    bodyUserData *mystruct;
public slots:
    void paint();
    virtual void remove(); //remove gameitem
    // TODO virtual void collide();

protected:

    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    QTimer timerpaint;

    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H

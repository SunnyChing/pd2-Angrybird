#include "gameitem.h"
#include "mainwindow.h"
#include <iostream>

extern MainWindow *w;

GameItem::GameItem(b2World *world):
    g_body(NULL),g_world(world)
{
    timerpaint.start(100/6);
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

void GameItem::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
   // std::cout << static_cast<char*>(pos) << std::endl;
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y+g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.setPos(mappedPoint);
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}

void GameItem::shoot2()
{

}

void GameItem::remove()
{

}

QPointF GameItem::getBirdPostion()
{
       QPointF pos;
        pos.setX(this->g_body->GetPosition().x);
        pos.setY(this->g_body->GetPosition().y);
        return  pos;

}


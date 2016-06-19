#include "sling.h"
#include <iostream>
Sling::Sling(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene): GameItem(world)
{
    //set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size= QSizeF(w-7,h);

    // Create Body

    bodydef.userData = this;
    bodydef.type=b2_staticBody;
    bodydef.position.Set(x,y);
    g_body =world->CreateBody(&bodydef);

   b2PolygonShape bodybox;
    bodybox.SetAsBox(w/2,h);
    g_body->CreateFixture(&bodybox,0.95f);

    scene->addItem(&g_pixmap);
    paint();

}

void Sling::setposition(float x, float y)
{
    bodydef.position.Set(x,y);
    g_body->SetTransform(b2Vec2(x,y),0);
    std::cout<<x<<std::endl;
}

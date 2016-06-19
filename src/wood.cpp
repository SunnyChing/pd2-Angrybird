#include "wood.h"

Wood::Wood(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    //set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size= QSizeF(w/2,h/2);

    //create body
    b2BodyDef bodydef;
    bodydef.type= b2_dynamicBody;
    bodydef.position.Set(x,y);
    g_body = world->CreateBody(&bodydef);

    b2FixtureDef fixturedef;
     b2PolygonShape bodybox;
    fixturedef.shape = &bodybox ;
    bodybox.SetAsBox(w/2,h/2);
    fixturedef.density = WOOD_DENSITY;
    fixturedef.friction = WOOD_FRICTION;
    fixturedef.restitution = WOOD_RESTITUTION;
    g_body->SetAngularDamping(3);

    setTransformOriginPoint(w/2,h/2);
    setTransformationMode(Qt::SmoothTransformation);

    g_body->CreateFixture(&fixturedef);

    //add userdata
    mystruct=new bodyUserData;
    mystruct->BODYID=QString("wood");
    mystruct->MaxImpulse= 20;
    g_body->SetUserData(mystruct);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
    paint();
}

void Wood::turn()
{

}

#include "bird4.h"

 extern QGraphicsScene *scene;
Bird4::Bird4(float x, float y, float radius, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(QPixmap(":/image/bird4.png").scaled(55,60));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);


    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    setTransformOriginPoint(radius/2,radius/2);

    //add userdata
    mystruct=new bodyUserData;
    mystruct->BODYID=QString("bird");
    mystruct->MaxImpulse= 20;
    g_body->SetUserData(mystruct);


    // Bound timer
    connect(&timerpaint, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);

}


void Bird4::shoot2()
{
    g_pixmap.setPixmap(QPixmap(":/image/bird4-.png").scaled(55,60));
    setLinearVelocity(2*g_body->GetLinearVelocity());

}

void Bird4::remove()
{

}

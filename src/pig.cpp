#include"pig.h"
#include<QDebug>
Pig::Pig(float x, float y, float radius,  b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(QPixmap(":/image/pig.png").scaled(65,70));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);

    g_body = world->CreateBody(&bodydef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = PIG_DENSITY;
    fixturedef.friction = PIG_FRICTION;
    fixturedef.restitution = PIG_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);


    //add userdata
    mystruct=new bodyUserData;
    mystruct->BODYID=QString("pig");
    mystruct->MaxImpulse= 200;
    g_body->SetUserData(mystruct);

    // Bound timer
    connect(&timerpaint, SIGNAL(timeout()), this,SLOT(paint()));
    connect(&timerpaint,SIGNAL(timeout()),this,SLOT(remove()));
    scene->addItem(&g_pixmap);
}

void Pig::remove()
{
    bodyUserData *pigdata=(bodyUserData*)this->g_body->GetUserData();
    if(pigdata->MaxImpulse<=100&&pigdata->MaxImpulse>0) g_pixmap.setPixmap(QPixmap(":/image/pig_2.png").scaled(60,70));
    if(pigdata->MaxImpulse<200&&pigdata->MaxImpulse>100) g_pixmap.setPixmap(QPixmap(":/image/pig_1.png").scaled(60,70));
    if(pigdata->MaxImpulse<0){
        delete this;
        pigkilled++;
    }
}


#include "bird1.h"
#include "start.h"
#include"mainwindow.h"

//extern QGraphicsScene* scene;
//extern MainWindow* w;
Bird1::Bird1( float x, float y, float radius,b2World *world,QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(QPixmap(":/image/bird2.png").scaled(55,60));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);
    scene1=scene;
    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    g_body = g_world->CreateBody(&bodydef);

    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD1_DENSITY;
    fixturedef.friction = BIRD1_FRICTION;
    fixturedef.restitution = BIRD1_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    //add userdata
    mystruct=new bodyUserData;
    mystruct->BODYID=QString("bird");
    mystruct->MaxImpulse= 20;
    g_body->SetUserData(mystruct);


    // Bound timer
    connect(&timerpaint, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);


}

void Bird1::shoot2()
{
    isshoot2=1;

    bird11 =new Bird1(this->g_body->GetPosition().x,this->g_body->GetPosition().y+1,0.05f,g_world,scene1);
    bird11->g_pixmap.setPixmap(QPixmap(":/image/bird2.png").scaled(45,45));
    bird12 =new Bird1(this->g_body->GetPosition().x,this->g_body->GetPosition().y-1,0.05f,g_world,scene1);
    bird12->g_pixmap.setPixmap(QPixmap(":/image/bird2.png").scaled(45,45));
    bird11->g_body->SetType(b2_dynamicBody);
    bird12->g_body->SetType(b2_dynamicBody);
    bird11->g_pixmap.setTransformOriginPoint(22.5,22.5);
    bird12->g_pixmap.setTransformOriginPoint(bird12->g_pixmap.boundingRect().width()/2,bird12->g_pixmap.boundingRect().height()/2);

    bird11->g_body->SetLinearVelocity(b2Vec2(this->g_body->GetLinearVelocity().x,this->g_body->GetLinearVelocity().y));
    bird12->g_body->SetLinearVelocity(b2Vec2(this->g_body->GetLinearVelocity().x/2,this->g_body->GetLinearVelocity().y));
}

void Bird1::remove()
{
        if(isshoot2==1){

            delete bird11;
            delete bird12;
        }
}


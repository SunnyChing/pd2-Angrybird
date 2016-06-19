#include "contactlistener.h"
#include "QDebug"
#include "qmainwindow.h"
extern int score;

void Mycontactlistener::BeginContact(b2Contact *contact)
{
    b2Fixture* a =contact->GetFixtureA();
    b2Fixture* b= contact->GetFixtureB();

    //if(a->GetBody()->GetMass()==0||b->GetBody()->GetMass()==0){return;}

    bodyUserData* a_userdata=(bodyUserData*)a->GetBody()->GetUserData();
    bodyUserData* b_userdata=(bodyUserData*)b->GetBody()->GetUserData();

    //bird with other
    if(a_userdata->BODYID == QString("bird"))
    {
          if(b_userdata->BODYID == QString("pig"))
          {
              qDebug()<<"pig";
          }
          if(b_userdata->BODYID == QString("wood"))
          {
                  //qDebug()<<"wood";
          }
    }
    if(b_userdata->BODYID == QString("bird"))
    {
          if(a_userdata->BODYID == QString("pig")){

              qDebug()<<"pig";
          }
          if(a_userdata->BODYID == QString("wood"))
          {
                  //qDebug()<<"wood";
          }

    }

    //pig with other
    if(a_userdata->BODYID==QString("pig")){
          /*if(b_userdata->BODYID==QString("land")){
              qDebug()<<"land";
          }*/
          if(b_userdata->BODYID==QString("wood")){
                qDebug()<<"wood";
          }
    }
    if(b_userdata->BODYID==QString("pig")){
          /*if(a_userdata->BODYID==QString("land")){
              qDebug()<<"land";
          }*/
          if(a_userdata->BODYID==QString("wood")){
                  qDebug()<<"wood";
          }
    }
}

void Mycontactlistener::EndContact(b2Contact *contact)
{

}

void Mycontactlistener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{

}

void Mycontactlistener::PostSolve(b2Contact *contact, const b2ContactImpulse* impulse)
{
    b2Fixture* a =contact->GetFixtureA();
    b2Fixture* b= contact->GetFixtureB();

    if(a->GetBody()->GetMass()==0||b->GetBody()->GetMass()==0){return;}

    bodyUserData* a_userdata=(bodyUserData*)a->GetBody()->GetUserData();
    bodyUserData* b_userdata=(bodyUserData*)b->GetBody()->GetUserData();

    //Solve for impulse exert on Pig
    if(a_userdata->BODYID==QString("bird"))
    {
          if(b_userdata->BODYID==QString("pig"))
          {
              qDebug()<<"hit";
              exertImpulse=impulse->normalImpulses[0];
              qDebug()<<exertImpulse;
              a_userdata->MaxImpulse-=exertImpulse;
              exertImpulse=0;

          }
    }

    if(b_userdata->BODYID==QString("bird"))
    {
          if(a_userdata->BODYID==QString("pig"))
          {
              qDebug()<<"hit";
              exertImpulse=impulse->normalImpulses[0];
              qDebug()<<exertImpulse;
              a_userdata->MaxImpulse-=exertImpulse;

              //add score
              addscore+=(int)exertImpulse*50;
              exertImpulse=0;

          }

    }

    //pig with wood
    if(a_userdata->BODYID==QString("pig")){
          /*if(b_userdata->BODYID==QString("land")){
              qDebug()<<"land";
          }*/
          if(b_userdata->BODYID==QString("wood")){
                qDebug()<<"hitwood";
                exertImpulse=impulse->normalImpulses[0];
                qDebug()<<exertImpulse;
                a_userdata->MaxImpulse-=exertImpulse;

          }
    }
    if(b_userdata->BODYID==QString("pig")){
          /*if(a_userdata->BODYID==QString("land")){
              qDebug()<<"land";
          }*/
          if(a_userdata->BODYID==QString("wood")){
                  qDebug()<<"hitwood";
                  exertImpulse=impulse->normalImpulses[0];
                  qDebug()<<exertImpulse;
                  a_userdata->MaxImpulse-=exertImpulse;

          }
    }
}


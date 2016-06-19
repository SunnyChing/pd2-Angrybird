#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include "myuserdata.h"

class Mycontactlistener:public b2ContactListener{
public:
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
    void PostSolve(b2Contact *contact, const b2ContactImpulse* impulse);

    float exertImpulse;
    int addscore;
};
#endif // CONTACTLISTENER_H

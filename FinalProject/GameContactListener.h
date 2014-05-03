#include<Box2D/Box2D.h>
#include "GameFunctions.h"

class GameContactListener: public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact){}

	void EndContact(b2Contact* contact){}

	void preSolve(b2Contact* contact, const b2Manifold* oldManifold){}	

	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){}
};
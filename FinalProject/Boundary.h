#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "View.h"
#include <Box2D/Box2D.h>

class Boundary
{
public:
	Boundary();
	~Boundary();
	bool Initialize(View* view, b2World* world, float screenWidth, float screenHeight);
	void Update();

private:
	b2World* world;
	View* view;
	const b2Vec2 bLeftBoundary;
	const b2Vec2 bRightBoundary;

	float width;
	float height;
	bool initialized;
};

#endif
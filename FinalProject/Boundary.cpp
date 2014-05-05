#include "Boundary.h"
#include "GameFunctions.h"

Boundary::Boundary()
{
	this->world = NULL;
	this->width = 0.0f;
	this->height = 0.0f;
	initialized = false;
}

bool Boundary::Initialize(View* view, b2World* world, float screenWidth, float screenHeight)
{
	this->world = world;
	this->width = screenWidth;
	this->height = screenHeight;
	this->view = view;

	int tabWidth = 50;

	const b2Vec2 vBottomLeft = b2Vec2(RW2PW(0-(screenWidth/2)), RW2PW((screenHeight/2) - tabWidth));
	const b2Vec2 vBottomRight = b2Vec2(RW2PW(screenWidth/2),RW2PW((screenHeight/2) - tabWidth));
	b2BodyDef bd;
	b2Body* edge = world->CreateBody(&bd);
	b2EdgeShape shape;

	shape.Set(vBottomLeft,vBottomRight);
	edge->CreateFixture(&shape,0);
	initialized = true;
	return initialized;
}

void Boundary::Update()
{

}
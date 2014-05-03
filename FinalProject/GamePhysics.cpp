#include "GamePhysics.h"
#include "Definitions.h"


GamePhysics::GamePhysics()
{
}

GamePhysics::~GamePhysics(){}

bool GamePhysics::Initialize(/*float radius, float mass, float epsilon, float friction, */std::string key, std::string type, std::string shape,float density, float restitution, float angDamp, float linDamp, float angForce, float linForce)
{
	this->id = key;
	this->type = type;
	this->shape = shape;
	this->density = density;
	this->restitution = restitution;
	this->angDamp = angDamp;
	this->linDamp = linDamp;
	this->angForce = angForce;
	this->linForce = linForce;

	initialized = true;

	return initialized;

}

std::string GamePhysics::GetKey()
{
	return this->id;
}
std::string GamePhysics::GetType()
{
	return this->type;
}

std::string GamePhysics::GetShape()
{
	return this->shape;
}

float GamePhysics::GetDensity()
{
	return density;

}

float GamePhysics::GetRestitution()
{
	return restitution;
}

float GamePhysics::GetAngDamp()
{
	return angDamp;
}

float GamePhysics::GetLinDamp()
{
	return linDamp;
}

float GamePhysics::GetAngForce()
{
	return angForce;
}

float GamePhysics::GetLinForce()
{
	return linForce;
}

bool GamePhysics::IsInitialized()
{
	return initialized;
}

//float GamePhysics::GetRadius()
//{
//	return radius;
//}
//
//float GamePhysics::GetMass()
//{
//	return mass;
//}
//
//float GamePhysics::GetEpsilon()
//{
//	return epsilon;
//}
//
//float GamePhysics::GetFriction()
//{
//	return friction;
//}
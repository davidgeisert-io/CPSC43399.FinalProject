#ifndef GAMESPHYSICS_H
#define GAMESPHYSICS_H

#include <string>
#include "Definitions.h"
#include "View.h"

class GamePhysics{
public:

	GamePhysics();
	~GamePhysics();

	bool Initialize(/*float radius, float mass, float epsilon, float friction, */std::string key, std::string type, std::string shape, float density, float restitution, float angDamp, float linDamp, float angForce, float linForce);
	bool IsInitialized();

	//float GetRadius();
	//float GetMass();
	//float GetEpsilon();
	//float GetFriction();
	std::string GetKey();
	std::string GetType();
	std::string GetShape();
	float GetDensity();
	float GetRestitution();
	float GetAngDamp();
	float GetLinDamp();
	float GetAngForce();
	float GetLinForce();

private:

	std::string id;
	std::string type;
	std::string shape;
	float density;
	float restitution;
	float angDamp;
	float linDamp;
	float angForce;
	float linForce;
	//float radius;
	//float mass;
	//float epsilon;
	//float friction;

	bool initialized;

};

#endif
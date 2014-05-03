#ifndef PHYSICSASSETLIBRARY
#define PHYSICSASSETLIBRARY

#include<map>
#include<string>
#include "GamePhysics.h"

class PhysicsAssetLibrary
{

public:
	PhysicsAssetLibrary();
	bool Initialize();
	bool IsInitialized();
	GamePhysics* Search(std::string);
	void Add(std::string key, std::string type, std::string shape, float density, float restitution, float angDamp, float linDamp, float angForce, float linForce);
private:
	std::map<std::string,GamePhysics*> library;

};

#endif
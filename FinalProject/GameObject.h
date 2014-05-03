#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <string>
#include <Box2D/Dynamics/b2Body.h>
#include "GameSprite.h"
#include "Definitions.h"
#include "GamePhysics.h"

class GameAssetLibrary;
class ArtAssetLibrary;
class PhysicsAssetLibrary;

class GameObject
{

public:
    GameObject();
	~GameObject();

	b2Body* GetPhysicsBody();
	GamePhysics* GetPhysics();

	bool IsDead();
	std::string GetId();
	void KillObject(bool);	
	void SetSprite(std::string key);
    
    bool Initialize(std::string key, InputDevice* iDevice, std::vector<GameObject*>* objects, GameAssetLibrary* gLibrary, ArtAssetLibrary* aLibrary, PhysicsAssetLibrary* pLibrary, 
		b2World* world, float x, float y, float angle);

	virtual bool PostInitialize();
	
	bool IsInitialized();	

    virtual GameObject* Update (float gameTime) = NULL;
    virtual void Draw(float gameTime, View* view) = NULL;

protected:

	InputDevice* iDevice;
	GameAssetLibrary* gLibrary;
	ArtAssetLibrary* aLibrary;
	PhysicsAssetLibrary* pLibrary;
	std::vector<GameObject*>* objects;
	GamePhysics* physics;
	bool initialized;
	b2World* world;

	std::string id;
	bool dead;

	GameSprite* sprite;

	b2Body* body;
	
};

#endif
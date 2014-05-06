#ifndef SPAWNER_H
#define SPAWNER_H

#include "GameObject.h"
#include <string>

enum SpawnSide
{
	left,
	right
};

class Spawner
{
public:
	Spawner();
	~Spawner();
	virtual GameObject* Update(float gameTime);
	bool Initialize(std::string type, std::string position, float x, std::vector<GameObject*>* gameObjects,
		InputDevice* iDevice, GameAssetLibrary* gameAssets, ArtAssetLibrary* artAssets, PhysicsAssetLibrary* pLibrary, Environment* environment, View* view,
		float quantity, float spawnRate, float max, float width, float height, float health);
	bool IsInitialized(){return initialized;}
	bool IsDead(){return dead;}

private:
	
	float width;
	float height;
	float health;

	float maxObjects;
	float maxQuantity;
	float qtySpawned;
	float spawnRate;
	float lastSpawn;
	float currentFrame;
	float triggerDistance;
	
	std::string type;
	SpawnSide spawnSide;
	InputDevice* iDevice;
	GameAssetLibrary* gAssets;
	ArtAssetLibrary* aLibrary;
	PhysicsAssetLibrary* pLibrary;
	Environment* environment;
	View* view;

	std::vector<GameObject*>* gameObjects;
	D3DXVECTOR3 position;
	bool triggered;
	bool dead;
	bool initialized;
};

#endif
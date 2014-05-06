#include "Spawner.h"
#include "Zombie.h"
#include "GameFunctions.h"
#include "GameAssetLibrary.h"

Spawner::Spawner()
{
	spawnRate = 0.0f;
	qtySpawned = 0.0f;
	maxQuantity = 0.0f;
	lastSpawn = 0.0f;
	width = 0.0f;
	height = 0.0f;
	health = 0.0f;
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	currentFrame = 0.0f;
	maxObjects = 0.0f;
	triggered = false;
	dead = false;
	initialized = false;
}

Spawner::~Spawner()
{
	iDevice = NULL;
	gAssets = NULL;
	aLibrary = NULL;
	pLibrary = NULL;
	environment = NULL;
	view = NULL;
	gameObjects = NULL;
}

bool Spawner::Initialize(std::string type, std::string spawnSide, float x, std::vector<GameObject*>* gameObjects, InputDevice* iDevice, GameAssetLibrary* gameAssets,
						 ArtAssetLibrary* artAssets, PhysicsAssetLibrary* pLibrary, Environment* environment, View* view, float quantity, float spawnRate, float max, float width, float height, float health)
{
	this->type = type;
	this->spawnSide = spawnSide == "Right"
		? right
		: left;
	this->gameObjects = gameObjects;
	this->iDevice = iDevice;
	this->gAssets = gameAssets;
	this->aLibrary = artAssets;
	this->pLibrary = pLibrary;
	this->environment = environment;
	this->maxQuantity = quantity;
	this->spawnRate = spawnRate;
	this->width = width;
	this->height = height;
	this->health = health;
	this->view = view;
	this->maxObjects = max;


	position.x = x;
	position.y = (view->GetScreenDimensions().y)/2;
	if(this->spawnSide == right)
	{
		triggerDistance = view->GetScreenDimensions().x/2;
	}
	else
	{
		triggerDistance = 0 - view->GetScreenDimensions().x/2;
	}


	initialized = true;
	return initialized;
}

GameObject* Spawner::Update(float gameTime)
{
	GameObject* object = NULL;

	if(position.x - (environment->GetPlayerPosition().x) <= triggerDistance)
	{
		triggered = true;
	}

	if(triggered)
	{
		object = gAssets->Create(type);
		object->Initialize(type, iDevice, gameObjects, gAssets, aLibrary, pLibrary, environment, view, position.x, position.y, 0.0f, width, height, health);
		object->PostInitialize();
		qtySpawned++;
	}

	if(qtySpawned >= maxObjects)
	{
		dead = true;
	}
	currentFrame ++;
	return object;
}
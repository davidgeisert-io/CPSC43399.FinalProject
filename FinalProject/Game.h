#ifndef GAME_H
#define GAME_H

#include <math.h>
#include <vector>
#include <Box2D/Box2D.h>
#include "PhysicsAssetLibrary.h"
#include "GameObject.h"
#include "LevelParser.h"
#include "ObjectFactory.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "GameContactListener.h"
#include "Box2DDebugDraw.h"
#include "Boundary.h"
#include "Environment.h"
#include "Spawner.h"

class Game
{

public:

    //Constructor/Destructor
    Game();
    ~Game();

    //Game Functions
    bool Initialize(HWND hWnd, HINSTANCE hInstance, int width, int height);
    void Run();
    void Update();
    void Draw();
    void DeleteObjects();
    void DetectCollisions();
	void UpdateDebugStatus();

private:
    bool LoadLevel();
	bool pause;

    GraphicsDevice* gDevice;
    InputDevice* iDevice;
	GameAssetLibrary* gameInventory;
	ArtAssetLibrary* artAssets;
	PhysicsAssetLibrary* pLibrary;

	View* gameView;
    std::vector<GameObject*> gameObjects;
	std::vector<Spawner*> spawners;

	const b2Vec2 gravity;
	b2World* world;
    LevelParser* levelParser;
    
    
    float gameTime;
	float stepTime;
	float toggleTime;

    bool initialized;
	GameContactListener gcl;
	Box2DDebugDraw* debugDraw;
	Boundary* boundary;
	Environment* environment;

	void TogglePause();
};

#endif
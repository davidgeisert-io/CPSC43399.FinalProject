#include "Game.h"

Game::Game():gravity(0,5)
{
	gDevice=NULL;
	iDevice=NULL;
	artAssets = NULL;
	gameInventory = NULL;
	gameTime = 0.0f;
	stepTime = 0.0f;
	toggleTime = 0.0f;
	pause = false;
}


Game::~Game()
{

	if (gameInventory)
	{
		delete gameInventory;
		gameInventory = NULL;
	}

	if (artAssets)
	{
		delete artAssets;
		artAssets = NULL;
	}

	if (levelParser)
	{
		delete levelParser;
		levelParser = NULL;
	}

	if (gameView)
	{
		delete gameView;
		gameView = NULL;
	}

	if(gDevice)
	{
		delete gDevice;
		gDevice = NULL;
	}

	if(iDevice)
	{
		delete iDevice;
		iDevice = NULL;
	}

	if(world)
	{
		delete world;
		world = NULL;
	}
}

bool Game::Initialize(HWND hWnd, HINSTANCE hInstance, int width, int height)
{
	gameTime = 0.0f;

	stepTime = 0.08f;

	gDevice = new GraphicsDevice();
	if(!gDevice->Initialize(hWnd, true))
	{
		return false;
	}

	iDevice = new InputDevice();
	if(!iDevice->Initialize(hInstance,hWnd))
	{
		return false;
	}

	gameInventory = new GameAssetLibrary();
	if(!gameInventory->Initialize())
	{
		return false;
	}

	artAssets = new ArtAssetLibrary();
	if(!artAssets->Initialize(gDevice))
	{
		return false;
	}

	pLibrary = new PhysicsAssetLibrary();
	if(!pLibrary->Initialize())
	{
		return false;
	}


	gameView = new View();
	if(!gameView->Initialize(width, height, 0.0f))
	{
		return false;
	}	


	world = new b2World(gravity);

	boundary = new Boundary();
	if(!boundary->Initialize(gameView, world, width, height))
	{
		return false;
	}

	debugDraw = new Box2DDebugDraw();
	if(debugDraw->Initialize(gDevice->GetDevice(), gameView))
	{
		world->SetDebugDraw(debugDraw);
	}

	environment = new Environment();
	if(!environment->Initialize(world))
	{
		return false;
	}

	levelParser = new LevelParser();
	if(!LoadLevel())
	{
		return false;
	}

	world->SetContactListener(&gcl);
	environment->PostInitialize();

	return true;

}

bool Game::LoadLevel()
{
	levelParser->Load("level.xml", &gameObjects, &spawners, iDevice, gameInventory, artAssets, pLibrary, world, gameView, environment);
	if(!gameObjects.size() > 0)
	{
		return false;
	}
	return true;
}

void Game::Run()
{
	Update();

	Draw();
	gameTime+=stepTime;
}

void Game::Update()
{
	if(iDevice)
	{
		iDevice->Update();
	}

	//If you press pause/break button, game objects will not update but gameTime will continue to increment
	if(iDevice->GetKeyboardState()[DIK_PAUSE] & 0x80 )
	{
		TogglePause();
	}

	UpdateDebugStatus();

	gameView->Update(gameTime, iDevice);

	if(!pause)
	{
		std::vector<GameObject*> newObjects;
		for(auto object = gameObjects.begin(); object != gameObjects.end(); object++)
		{
			if((*object) && (*object)->IsInitialized())
			{
				GameObject* newObject = (*object)->Update(gameTime);
				if(newObject != NULL)
				{
					newObjects.push_back(newObject);
				}
			}
		}

		for(auto spawner = spawners.begin(); spawner != spawners.end(); spawner++)
		{
			if((*spawner) && (*spawner)->IsInitialized())
			{
				GameObject* newObject = (*spawner)->Update(gameTime);
				if(newObject != NULL)
				{
					newObjects.push_back(newObject);
				}
			}
		}

		for(auto object = newObjects.begin(); object != newObjects.end(); object++)
		{
			gameObjects.push_back(*object);
		}

		DeleteObjects();
		world->Step(1.0f/60.0f, 6, 2);
	}

}

void Game::DeleteObjects()
{
	for(auto object = gameObjects.begin(); object != gameObjects.end();)
	{
		if((*object)->IsDead())
		{
			delete (*object);
			object = gameObjects.erase(object);
		}
		else
		{
			object++;
		}
	}

	for (auto spawner = spawners.begin(); spawner != spawners.end();)
	{
		if((*spawner)->IsDead())
		{
			delete (*spawner);
			spawner = spawners.erase(spawner);
		}
		else
		{
			spawner++;
		}
	}
}

void Game::Draw()
{
	gDevice->Clear(D3DCOLOR_XRGB(0, 0, 0));
	gDevice->Begin();    

	for(auto object = gameObjects.begin(); object != gameObjects.end(); object++)
	{
		if((*object) && (*object)->IsInitialized())
		{
			(*object)->Draw(gameTime, gameView);
		}
	}

	world->DrawDebugData();

	gDevice->End();
	gDevice->Present();

}

void Game::UpdateDebugStatus()
{
	if(iDevice->GetKeyboardState()[DIK_1] & 0x80) 
	{
		//get the flags
		uint32 flags = debugDraw->GetFlags();
		flags ^= debugDraw->e_aabbBit;	//toggle the AABB bit
		debugDraw->SetFlags(flags);		//set the flags back

		Sleep(200);						//allow me to lift my finger before updating again
	}

	if(iDevice->GetKeyboardState()[DIK_2] & 0x80) 
	{
		//get the flags
		uint32 flags = debugDraw->GetFlags();
		flags ^= debugDraw->e_centerOfMassBit;	//toggle the AABB bit
		debugDraw->SetFlags(flags);		//set the flags back

		Sleep(200);						//allow me to lift my finger before updating again
	}

	if(iDevice->GetKeyboardState()[DIK_3] & 0x80) 
	{
		//get the flags
		uint32 flags = debugDraw->GetFlags();
		flags ^= debugDraw->e_jointBit;	//toggle the AABB bit
		debugDraw->SetFlags(flags);		//set the flags back

		Sleep(200);						//allow me to lift my finger before updating again
	}

	if(iDevice->GetKeyboardState()[DIK_4] & 0x80) 
	{
		//get the flags
		uint32 flags = debugDraw->GetFlags();
		flags ^= debugDraw->e_shapeBit;	//toggle the AABB bit
		debugDraw->SetFlags(flags);		//set the flags back

		Sleep(200);						//allow me to lift my finger before updating again
	}
}

void Game::TogglePause()
{
	pause = pause
		? false
		: true;
	Sleep(200);
}
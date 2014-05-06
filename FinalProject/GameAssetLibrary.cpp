#include "GameAssetLibrary.h"
#include "PlayerFactory.h"
#include "SpawnerFactory.h"
#include "ZombieFactory.h"

GameAssetLibrary::GameAssetLibrary()
{
}

bool GameAssetLibrary::Initialize()
{
    return true;
}

GameObject* GameAssetLibrary::Create(std::string query)
{
    return (((*library.find(query)).second)->Create());
}

void GameAssetLibrary::Insert(std::string type)
{
	if(type == "Player")
	{
		library["Player"] = (ObjectFactory*)(new PlayerFactory());
	}

	if (type == "Zombie")
	{
		library["Zombie"] = (ObjectFactory*)(new ZombieFactory());
	}

	if (type == "Spawner")
	{
		library ["Spawner"] = (ObjectFactory*)(new SpawnerFactory());
	}
}
#include "GameAssetLibrary.h"
#include "PlayerFactory.h"

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
}
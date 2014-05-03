#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary()
{
}

bool ArtAssetLibrary::Initialize(GraphicsDevice* gDevice)
{   
	this->gDevice = gDevice;
    return true;
}

void ArtAssetLibrary::Add(std::string key, std::string dir, int width, int height)
{
	GameSprite* sprite = new GameSprite();
	if(sprite->Initialize(this->gDevice->device, dir, width, height))
	{
		library[key] = sprite;
	}
}

ArtAssetLibrary::~ArtAssetLibrary()
{

}

GameSprite* ArtAssetLibrary::Search(std::string query)
{
    return ((*library.find(query)).second);
}
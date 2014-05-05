#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary()
{
}

bool ArtAssetLibrary::Initialize(GraphicsDevice* gDevice)
{   
	this->gDevice = gDevice;
    return true;
}

SpriteContainer* ArtAssetLibrary::Search(std::string query)
{
    return ((*library.find(query)).second);
}

void ArtAssetLibrary::AddContainer(std::string containerKey)
{
	SpriteContainer* container = new SpriteContainer();
	container->Initialize(containerKey, gDevice);
	library[containerKey] = container;
}

void ArtAssetLibrary::AddSpriteToContainer(std::string type, std::string key, std::string id, std::string dir, float width, float height)
{
	((*library.find(type)).second)->AddSprite(key, id, dir, width, height);
}

void ArtAssetLibrary::PostInitializeContainer(std::string key)
{
	((*library.find(key)).second)->PostInitialize();
}
#ifndef ARTASSET_H
#define ARTASSET_H

#include <map>
#include <string>
#include "GameSprite.h"
#include "SpriteContainer.h"
#include "GraphicsDevice.h"

class ArtAssetLibrary
{
public:
    ArtAssetLibrary();
    SpriteContainer* Search(std::string query);
    bool Initialize(GraphicsDevice* gDevice);
	void AddContainer(std::string containerKey);
	void AddSpriteToContainer(std::string type, std::string key, std::string id, std::string dir, float width, float height);
	void PostInitializeContainer(std::string key);

private:
	GraphicsDevice* gDevice;
    std::map<std::string, SpriteContainer*> library;
};

#endif
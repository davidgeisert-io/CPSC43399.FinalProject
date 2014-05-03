#ifndef ARTASSET_H
#define ARTASSET_H

#include <map>
#include <string>
#include "GameSprite.h"
#include "GraphicsDevice.h"

class ArtAssetLibrary
{
public:
    ArtAssetLibrary();
    ~ArtAssetLibrary();
    GameSprite* Search(std::string query);
    bool Initialize(GraphicsDevice* gDevice);
	void Add(std::string key, std::string dir, int width, int height);
private:
	GraphicsDevice* gDevice;
    std::map<std::string, GameSprite*> library;
};

#endif
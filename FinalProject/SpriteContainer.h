#ifndef SPRITECONTAINER_H
#define SPRITECONTAINER_H

#include <string>
#include <map>
#include "GameSprite.h"
#include "GraphicsDevice.h"

class SpriteContainer
{
public:
	SpriteContainer();
	std::string GetID() {return id;}
	void AddSprite(std::string key, std::string id, std::string dir, float width, float height);
	GameSprite* GetCurrentSprite();
	GameSprite* GetNextSprite();
	GameSprite* GetPreviousSprite();
	GameSprite* GetDefaultSprite();
	void ChangeSpriteLoop(std::string key);
	bool Initialize(std::string id, GraphicsDevice* gDevice);
	bool PostInitialize();

private:

	bool initialized;
	bool postInitialized;
	std::string id;
	std::map <std::string, GameSprite*> animations;
	GameSprite* currentSprite;

	GraphicsDevice* gDevice;
};

#endif
#include "SpriteContainer.h"

bool SpriteContainer::Initialize(std::string id, GraphicsDevice* gDevice)
{
	if(!initialized)
	{
		this->id = id;
		this->gDevice = gDevice;
		initialized = true;
	}
	return initialized;
}

bool SpriteContainer::PostInitialize()
{
	if(!postInitialized)
	{
		for(auto iter = animations.begin(); iter != animations.end(); iter++)
		{
			GameSprite* start = iter->second;
			GameSprite* current = start;

			while(current->GetNextSprite())
			{
				current = current->GetNextSprite();
			}
			start->SetPreviousSprite(current);
			current->SetNextSprite(start);
		}
	}
	postInitialized = true;
	return postInitialized;
}

void SpriteContainer::AddSprite(std::string key, std::string id, std::string dir, float width, float height)
{
	GameSprite* sprite = new GameSprite();
	sprite->Initialize(id, gDevice->device, dir, width, height);

	if (animations.find(key) == animations.end())
	{		
		animations[key] = sprite;
	}
	else
	{
		GameSprite* current = (*animations.find(key)).second;
		while(current->GetNextSprite())
		{
			current = current->GetNextSprite();
		}
		sprite->SetPreviousSprite(current);
		current->SetNextSprite(sprite);
	}
}

GameSprite* SpriteContainer::GetCurrentSprite()
{
	return currentSprite;
}

GameSprite* SpriteContainer::GetNextSprite()
{
	this->currentSprite = currentSprite->GetNextSprite();
	return currentSprite;
}

GameSprite* SpriteContainer::GetPreviousSprite()
{
	this->currentSprite = currentSprite->GetPreviousSprite();
	return currentSprite;
}

void SpriteContainer::ChangeSpriteLoop(std::string key)
{
	currentSprite = animations[key];
}

GameSprite* SpriteContainer::GetDefaultSprite()
{
	//This is very unsafe!!! could cause infinite loop!! consider error checking!!!
	while(currentSprite->GetId() != "Default")
	{
		currentSprite = currentSprite->GetNextSprite();
	}
	return currentSprite;
}
#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <iostream>
#include <d3dx9.h>
#include <string>
#include <Box2D/Box2D.h>
#include "InputDevice.h"
#include "View.h"

extern InputDevice* iDevice;

class GameSprite
{
public:

    GameSprite();

    ~GameSprite();

    bool Initialize(std::string id, LPDIRECT3DDEVICE9 device, std::string filePath, int width, int height);
    bool IsInitialized();
	float GetWidth(){ return this->width;}
	float GetHeight(){ return this->height;}
    virtual void Draw(float gameTime, View* gameView, b2Body* body);

	void SetPreviousSprite(GameSprite* sprite);
	void SetNextSprite(GameSprite* sprite);

	GameSprite* GetNextSprite() {return nextSprite;}
	GameSprite* GetPreviousSprite() {return previousSprite;}
	std::string GetId() {return id;}

private:
	std::string id;
    LPDIRECT3DTEXTURE9 tex;
    LPD3DXSPRITE sprite;
	GameSprite* nextSprite;
	GameSprite* previousSprite;

    float angle;
    float scale;

    D3DCOLOR color;
    bool initialized;

    float width;
    float height;
};

#endif
#ifndef LEVELPARSER_H
#define LEVELPARSER_H

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <Box2D/Box2D.h>

#include "ArtAssetLibrary.h"
#include "GameAssetLibrary.h"
#include "PhysicsAssetLibrary.h"
#include "InputDevice.h"
#include "TinyXml/tinyxml.h"
#include "GameObject.h"

class LevelParser
{

public:
    ~LevelParser();
    void Load(const char* fileName, std::vector<GameObject*>* gameObjects, InputDevice* iDevice, GameAssetLibrary* gameAssets, ArtAssetLibrary* artAsset, PhysicsAssetLibrary* pLibrary, b2World* world);
    
};

#endif
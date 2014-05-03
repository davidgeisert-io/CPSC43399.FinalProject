#ifndef GAMEASSETLIBRARY_H
#define GAMEASSETLIBRARY_H

#include <map>
#include "ObjectFactory.h"


class GameAssetLibrary
{
public:
    GameAssetLibrary();
    bool Initialize();
    GameObject* Create(std::string query);
	void Insert(std::string type);

private:
    std::map<std::string, ObjectFactory*> library;
};

#endif
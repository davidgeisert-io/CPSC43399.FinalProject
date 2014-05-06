#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include<map>
#include "GameObject.h"
#include "Player.h"
#include "Spawner.h"
#include "Zombie.h"

class ObjectFactory
{
public:
    virtual GameObject* Create() = NULL;
};

#endif
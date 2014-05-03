#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include<map>
#include "GameObject.h"
#include "Player.h"

class ObjectFactory
{
public:
    virtual GameObject* Create() = NULL;
};

#endif
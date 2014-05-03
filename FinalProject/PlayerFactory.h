#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "ObjectFactory.h"

class PlayerFactory : public ObjectFactory
{
public:
    virtual GameObject* Create();
};

#endif
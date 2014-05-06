#ifndef SPAWNERFACTORY_H
#define SPAWNERFACTORY_H

#include "ObjectFactory.h"

class SpawnerFactory : public ObjectFactory
{
public:
	virtual GameObject* Create();
};

#endif

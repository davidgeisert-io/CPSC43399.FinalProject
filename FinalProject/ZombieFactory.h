#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include "ObjectFactory.h"

class ZombieFactory : public ObjectFactory
{
public:
	virtual GameObject* Create();
};

#endif

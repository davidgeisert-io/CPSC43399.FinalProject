#include "ZombieFactory.h"

GameObject* ZombieFactory::Create()
{
	return ((GameObject*) (new Zombie()));
}
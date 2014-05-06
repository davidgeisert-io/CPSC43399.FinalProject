#include "SpawnerFactory.h"

GameObject* SpawnerFactory::Create()
{
	return ((GameObject*) (new Spawner()));
}
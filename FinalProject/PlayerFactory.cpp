#include "PlayerFactory.h"

GameObject* PlayerFactory::Create()
{
    return ((GameObject*) (new Player()));
}
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Definitions.h"
#include <vector>
#include <math.h>


class Player : public GameObject
{
public:

    Player();
	GameObject* Update(float gameTime);
    void Draw(float, View*);
	GameObject* Fire();
    
private:
	int charge;
	int chargeTime;
	float delta;
};

#endif 
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <math.h>
#include "GameObject.h"
#include "Definitions.h"

class Player : public GameObject
{
public:

    Player();
	GameObject* Update(float gameTime);
    void Draw(float, View*);
	GameObject* Fire();
	void CycleSprite();
	bool PostInitialize();

private:
	int charge;
	int chargeTime;
	float delta;
};

#endif 
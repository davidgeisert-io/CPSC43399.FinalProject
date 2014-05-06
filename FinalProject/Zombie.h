#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "GameObject.h"

class Zombie : public GameObject
{
public:
	Zombie();
	virtual GameObject* Update(float gameTime);
	virtual void  Draw(float gameTime, View* view);
	bool PostInitialize();
	void CycleSprite();
private:

};

#endif
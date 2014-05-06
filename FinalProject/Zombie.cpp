#include "Zombie.h"
#include "GameFunctions.h"

Zombie::Zombie()
{
	id = "Zombie";
	this->maxSpriteFrame = 8;
	this->lastSpriteFrame = 0;
}

GameObject* Zombie::Update(float gameTime)
{
	b2Vec2 playerPos = environment->GetPlayerPosition();
	float distance = body->GetPosition().x - playerPos.x;
	if(distance > 0)
	{
		b2Vec2 newPos(body->GetPosition().x - RW2PW(0.5f), body->GetPosition().y);
		body->SetTransform(newPos, body->GetAngle());
	}
	else if(distance < 0)
	{
		b2Vec2 newPos(body->GetPosition().x + RW2PW(0.5f), body->GetPosition().y);
		body->SetTransform(newPos, body->GetAngle());
	}
	currentFrame++;
	return NULL;
}

void  Zombie::Draw(float gameTime, View* view)
{
	sprite->Draw(0.0f, view, body);
}

bool Zombie::PostInitialize()
{
	spriteContainer->ChangeSpriteLoop("MoveLeft");
	sprite = spriteContainer->GetDefaultSprite();
	return true;
}

void Zombie::CycleSprite()
{
	if(currentFrame-lastSpriteFrame >= maxSpriteFrame)
	{
		sprite = spriteContainer->GetNextSprite();
		lastSpriteFrame = currentFrame;
	}	
}
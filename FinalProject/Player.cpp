#include "Player.h"
#include "GameAssetLibrary.h"
#include "GameFunctions.h"


Player::Player()
{
	charge = 10;
	chargeTime = 10;
	id = "Player";
	this->maxSpriteFrame = 8;
	this->lastSpriteFrame = 0;
}

GameObject* Player::Update(float gameTime)
{
	if(charge <chargeTime)
	{
		charge++;
	}

	/*if(iDevice->IsAPressed())
	{
		body->SetAngularVelocity(body->GetAngularVelocity()-physics->GetAngForce());
	}

	if(iDevice->IsDPressed())
	{
		body->SetAngularVelocity(body->GetAngularVelocity()+physics->GetAngForce());
	}*/

	if(iDevice->IsDPressed())
	{
		b2Vec2 force;
		force.x = body->GetPosition().x + RW2PW(8.0f);
		force.y = body->GetPosition().y;
		body->SetTransform(force, body->GetAngle());
		CycleSprite();
	}

	if(iDevice->IsAPressed())
	{
		b2Vec2 force;
		force.x = body->GetPosition().x - RW2PW(8.0f);
		force.y = body->GetPosition().y;
		body->SetTransform(force, body->GetAngle());
	}

	//if((iDevice->IsSpacePressed()) & (charge>=chargeTime))
	//{
	//	return Fire();
	//}

	currentFrame++;
	return NULL;
}

GameObject* Player::Fire()
{
	charge=0;
	D3DXVECTOR3 bProject;
	bProject.x=0.0;
	bProject.y=-1.0;
	bProject.z=0.0;

	D3DXMATRIX bMat;
	D3DXMatrixRotationZ(&bMat,body->GetAngle());

	D3DXVECTOR3 bGradient;
	bGradient.x = 0.0f;
	bGradient.y = 1.0f;

	D3DXVec3TransformCoord(&bGradient, &bProject, &bMat);

	float offset = sprite->GetHeight()/2.0f;
	if(sprite->GetWidth()/2.0f > offset)
	{
		offset = sprite->GetWidth();
	}
	D3DXVECTOR3 initPosition;
	initPosition.x = bGradient.x*offset + PW2RW(body->GetPosition().x);
	initPosition.y = bGradient.y*offset + PW2RW(body->GetPosition().y);
		
	//std::string key("Bullet");
	//GameObject* bullet = gLibrary->Create(key);

	//if(bullet->Initialize(key, iDevice, objects, gLibrary, aLibrary, pLibrary, world, initPosition.x, initPosition.y, body->GetAngle()))
	//{
	//	b2Vec2 force;
	//	force.x=-bullet->GetPhysics()->GetLinForce()*cos(body->GetAngle()+3.14159f/2.0f);
	//	force.y=-bullet->GetPhysics()->GetLinForce()*sin(body->GetAngle()+3.14159f/2.0f);

	//	bullet->GetPhysicsBody()->ApplyForce(force,body->GetPosition(), true);
	//	return bullet;

	//}
	currentFrame++;
	return NULL;
}

bool Player::PostInitialize()
{
	spriteContainer->ChangeSpriteLoop("MoveRight");
	sprite = spriteContainer->GetDefaultSprite();
	view->SetObjectTracking(this->body);
	return true;
}

void Player::Draw(float gameTime, View* view)
{
    sprite->Draw(0.0f, view, body);
}

void Player::CycleSprite()
{
	if(currentFrame-lastSpriteFrame >= maxSpriteFrame)
	{
		sprite = spriteContainer->GetNextSprite();
		lastSpriteFrame = currentFrame;
	}	
}
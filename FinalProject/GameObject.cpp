#include "GameObject.h"
#include "GameAssetLibrary.h"
#include "ArtAssetLibrary.h"
#include "PhysicsAssetLibrary.h"
#include "GameFunctions.h"


GameObject::GameObject()
{	
	gLibrary = NULL;
	aLibrary = NULL;
	pLibrary = NULL;
    physics = NULL;
	body = NULL;
	sprite = NULL;
	initialized = false;
	dead = false;
	currentFrame = 0;
}

GameObject::~GameObject()
{
	gLibrary = NULL;
	aLibrary = NULL;
	pLibrary = NULL;
	physics = NULL;

	if(body)
	{
		world->DestroyBody(body);
		body = NULL;
	}
}

std::string GameObject::GetId()
{
	return id;
}

bool GameObject::IsDead()
{
	return this->dead;
}

b2Body* GameObject::GetPhysicsBody()
{
	return this->body;
}

GamePhysics* GameObject::GetPhysics()
{
	return physics;
}

void GameObject::KillObject(bool isdead)
{
	this->dead = isdead;
}

bool GameObject::Initialize(std::string key, InputDevice* iDevice, std::vector<GameObject*>* objects, GameAssetLibrary* gLibrary, ArtAssetLibrary* aLibrary, PhysicsAssetLibrary* pLibrary, 
							b2World* world, float x, float y, float angle, float width, float height)
{
    this->iDevice = iDevice;
	this->objects = objects;

	this->gLibrary = gLibrary;
	this->aLibrary = aLibrary;
	this->pLibrary = pLibrary;

    this->spriteContainer = aLibrary->Search(key);

	this->physics = pLibrary->Search(key);
	this->world = world;

	b2BodyDef bd;

	bd.type = physics->GetType() == "dynamic" 
		? b2_dynamicBody
		: b2_staticBody;

	bd.position.Set(RW2PW(x), RW2PW(y));
	bd.angle = angle;
	bd.userData = this;
	
	body = this->world->CreateBody(&bd);

	b2PolygonShape polyShape;	
	polyShape.SetAsBox(RW2PW(width/2.0f),RW2PW(height/2.0f));		

	b2CircleShape circleShape;
	circleShape.m_radius = RW2PW(width/2.0f);

	b2FixtureDef fixtureDef;
	if(physics->GetShape().compare("poly")==0)
	{
		fixtureDef.shape = &polyShape;
	}
	else
	{
		fixtureDef.shape = &circleShape;
	}

	fixtureDef.density = physics->GetDensity();
	fixtureDef.restitution = physics->GetRestitution();
	
	body->SetAngularDamping(physics->GetAngDamp());
	body->SetLinearDamping(physics->GetLinDamp());

	body->SetUserData(this);

	body->CreateFixture(&fixtureDef);

	initialized = true;

	return initialized;
}

bool GameObject::PostInitialize()
{
	return true;
}

bool GameObject::IsInitialized()
{
    return this->initialized;
}


void GameObject::CycleSprite()
{

}
#include "PhysicsAssetLibrary.h"

PhysicsAssetLibrary::PhysicsAssetLibrary(){}

bool PhysicsAssetLibrary::Initialize(){
	
	//GamePhysics* carrier = new GamePhysics();
	//if(carrier->Initialize(13.0f,10.0f,0.5f,5.0f)){
	//	library["Carrier"] = carrier;
	//}

	//GamePhysics* infantry = new GamePhysics();
	//if(infantry->Initialize(8.0f,1.0f,0.3f,0.8f)){
	//	library["Infantry"] = infantry;
	//}

	//GamePhysics* rock = new GamePhysics();
	//if(rock->Initialize(15.0,80.0,0.9f,5.0f)){
	//	library["Rock"] = rock;
	//}

	//GamePhysics* bullet = new GamePhysics();
	//if(bullet->Initialize(3.0f,0.01f,0.9f,0.0f)){
	//	library["Bullet"] = bullet;
	//}

	//GamePhysics* player = new GamePhysics();
	//if(player->Initialize(8.0f,1.0f,0.3f,0.8f)){
	//	library["Player"] = player;
	//}

	return true;
}

void PhysicsAssetLibrary::Add(std::string key, std::string type, std::string shape, float density, float restitution, float angDamp, float linDamp, float angForce, float linForce)
{
	GamePhysics* phys = new GamePhysics();
	if(phys->Initialize(key, type, shape, density, restitution, angDamp, linDamp, angForce, linForce))
	{
		library[key] = phys;
	}
}


GamePhysics* PhysicsAssetLibrary::Search(std::string query){
	return((*library.find(query)).second);
}
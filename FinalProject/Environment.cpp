#include "Environment.h"
#include "GameObject.h"
#include "GameFunctions.h"
#include "RayCastCallback.h"

Environment::Environment()
{
	world = NULL;
}

bool Environment::Initialize(b2World* world)
{
	this->world = world;
	SearchStepSize = 27.0f;
	ApproachRadius = 27.0f;
	numChildren = 4.0f;
	return true;
}

void Environment::PostInitialize()
{
	for(auto b = world->GetBodyList(); b; b = b->GetNext())
	{
		GameObject* gObject= (GameObject*)(b->GetUserData());
		if(gObject && gObject->GetId() == "Player")
		{
			playerBody = gObject->GetPhysicsBody();
			break;
		}
	}
}

void Environment::Update()
{
	
}

std::vector<b2Body*> Environment::GetVisibleObjects(b2Body* body)
{
	float viewAngle = body->GetAngle();
	std::vector<b2Body*> visibleBodies;
	return visibleBodies;
}

b2World* Environment::GetWorld()
{
	return this->world;
}

b2Vec2 Environment::GetPlayerPosition()
{

	return this->playerBody->GetPosition();
}

//std::vector<SearchNode*> Environment::GetSurroundingTiles(SearchNode* currentTile)
//{
//	std::vector<SearchNode*> nodeCandidates;
//	std::vector<SearchNode*> newNodes;
//	b2Vec2 left;
//	left.x = currentTile->GetCenter().x - RW2PW(ApproachRadius * 2);
//	left.y = currentTile->GetCenter().y;
//
//	b2Vec2 right;
//	right.x = currentTile->GetCenter().x + RW2PW(ApproachRadius * 2);
//	right.y = currentTile->GetCenter().y;
//
//	b2Vec2 top;
//	top.x = currentTile->GetCenter().x;
//	top.y = currentTile->GetCenter().y + RW2PW(ApproachRadius * 2);
//
//	b2Vec2 bottom;
//	bottom.x = currentTile->GetCenter().x;
//	bottom.x = currentTile->GetCenter().y - RW2PW(ApproachRadius * 2);
//
//	b2Vec2 topLeft;
//	topLeft.x = left.x;
//	topLeft.y = left.y + RW2PW(ApproachRadius * 2);
//
//	b2Vec2 topRight;
//	topRight.x = right.x;
//	topRight.y = right.y + RW2PW(ApproachRadius * 2);
//
//	b2Vec2 bottomLeft;
//	bottomLeft.x = left.x;
//	bottomLeft.y = left.y - RW2PW(ApproachRadius * 2);
//
//	b2Vec2 bottomRight;
//	bottomRight.x = right.x;
//	bottomRight.y = right.y - RW2PW(ApproachRadius * 2);
//
//	nodeCandidates.push_back(new SearchNode(left, ApproachRadius, currentTile->GetPathCost() +  PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(left, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(right, ApproachRadius,currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(right, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(top, ApproachRadius, currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(top, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(bottom, ApproachRadius, currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(bottom, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(topLeft, ApproachRadius, currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(topLeft, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(topRight, ApproachRadius, currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(topRight, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(bottomLeft, ApproachRadius, currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(bottomLeft, playerPosition))));
//	nodeCandidates.push_back(new SearchNode(bottomRight, ApproachRadius, currentTile->GetPathCost() + PW2RW(GetDistance(left, currentTile->GetCenter())), PW2RW(GetDistance(bottomRight, playerPosition))));
//
//	for(auto node = nodeCandidates.begin(); node != nodeCandidates.end(); node++)
//	{
//		b2RayCastInput input;
//		input.p1 = (*node)->GetCenter();
//		input.p2 = playerPosition;
//		input.maxFraction = RW2PW(ApproachRadius);
//		RayCastCallback callback;
//		world->RayCast(&callback, input.p1, input.p2);
//		if(callback.GetFraction())
//		{
//			float32 frac = callback.GetFraction();
//			if(callback.GetFixture()){
//				b2Fixture* intersection = callback.GetFixture();
//				GameObject* gObject = (GameObject*) intersection->GetBody()->GetUserData();
//				if(gObject->GetId() == "Tree" || gObject->GetId() == "Rock")
//				{
//					continue;
//				}
//			}
//		}
//		newNodes.push_back(*node);
//	}
//
//	return newNodes;
//}

SearchNode* Environment::GetInitialNode(b2Vec2 center)
{
	SearchNode* node = new SearchNode(center, ApproachRadius, 0, PW2RW(GetDistance(center, playerBody->GetPosition())));
	return node;
}

float Environment::GetDistance(b2Vec2 p1, b2Vec2 p2)
{
	float distX = abs(p1.x - p2.x);
	float distY = abs(p1.y - p2.y);
	float distance = sqrt(pow(distX, 2) + pow(distY, 2));
	return distance;
}
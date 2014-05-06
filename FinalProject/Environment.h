#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <Box2D/Box2D.h>
#include <vector>
#include "SearchNode.h"

class Environment
{
public:
	Environment();
	bool Initialize(b2World* world);
	void PostInitialize();
	void Update();
	std::vector<b2Body*> GetVisibleObjects(b2Body* body);
	b2World* GetWorld();
	b2Vec2 GetPlayerPosition();
	//std::vector<SearchNode*> GetSurroundingTiles(SearchNode* currentTile);
	SearchNode* GetInitialNode(b2Vec2 center);
	float GetDistance(b2Vec2 p1, b2Vec2 p2);

private:

	float SearchStepSize;
	float ApproachRadius;
	float numChildren;
	b2World* world;
	bool RayCast(b2RayCastOutput* output, b2RayCastInput& input);
	b2Body* playerBody;
};
#endif
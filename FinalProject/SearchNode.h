#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include <Box2D/Box2D.h>

class SearchNode
{
public:
	SearchNode(b2Vec2 center, float radius, float g, float h)
	{
		this->center = center;
		this->radius = radius;
		this->pathCost = g;
		this->futureCost = h;
		this->f = g + h;
		this->parentNode = NULL;
		this->childNode = NULL;
		searchStepSize = 27;
	}

	~SearchNode(){}

	void SetParent(SearchNode* parent)
	{
		parentNode = parent;
		pathCost = searchStepSize + parent->GetPathCost();
	}

	void SetChild(SearchNode* child)
	{
		childNode = child;
	}

	SearchNode* GetParent()
	{
		return parentNode;
	}

	SearchNode* GetChild()
	{
		return childNode;
	}

	float GetFValue()
	{
		return f;
	}

	float GetPathCost()
	{
		return pathCost;
	}

	b2Vec2 GetCenter()
	{
		return center;
	}

	float GetRadius()
	{
		return radius;
	}

private:
	float f, pathCost, futureCost, radius;
	SearchNode* parentNode;
	SearchNode* childNode;
	b2Vec2 center;
	float searchStepSize;

};

#endif
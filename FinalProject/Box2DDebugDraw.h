#pragma once


#include <Box2D\Box2D.h>
#include "GameFunctions.h"
#include "View.h"
#include <d3dx9.h>

class Box2DDebugDraw : public b2Draw 
{

	public:	
		Box2DDebugDraw();
		~Box2DDebugDraw();

		bool Initialize(LPDIRECT3DDEVICE9 device, View* gameView);

		void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
		void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
		void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color);
		void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color);
		void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color);
		void DrawTransform(const b2Transform &xf);


	private:
		bool checkDevice();
		void saveMatrix();
		void restoreMatrix();
		View* gameView;

		LPDIRECT3DDEVICE9 _dev;
		D3DXMATRIX backupMatrix;
		int circleAccuracy;

};
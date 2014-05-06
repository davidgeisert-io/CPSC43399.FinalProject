#ifndef VIEW_H
#define VIEW_H

#define _USE_MATH_DEFINES

#include<cmath>
#include<d3dx9.h>
#include <Box2D/Box2D.h>
#include "InputDevice.h"

class View
{
public:
    View();
    ~View();
    bool Initialize(float xCenter, float yCenter, float angle);
    bool IsInitialized();
    
    void Update(float GameTime, InputDevice* iDevice);
	void SetObjectTracking(b2Body* body);
	void TrackObject();

	D3DXVECTOR3 GetPosition(){return position;}
	D3DXVECTOR3 GetPreviousPosition(){return previousPosition;}
    D3DXVECTOR3 GetCenter(){return center;}
    D3DXVECTOR3 GetScreenDimensions(){return screenDimensions;}

    float GetAngle(){return angle;}


private:
    D3DXVECTOR3 position;
	D3DXVECTOR3 previousPosition;
    D3DXVECTOR3 center;
	D3DXVECTOR3 screenDimensions;

	float xOffset;
    float angle;
	b2Body* trackedBody;
	
    bool isInitialized;
	bool otEnabled;
};

#endif
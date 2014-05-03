#ifndef VIEW_H
#define VIEW_H

#define _USE_MATH_DEFINES

#include<cmath>
#include<d3dx9.h>
#include "InputDevice.h"

class View
{
public:
    View();
    ~View();
    bool Initialize(float xCenter, float yCenter, float angle);
    bool IsInitialized();
    
    void Update(float GameTime, InputDevice* iDevice);

    D3DXVECTOR3 GetPosition();
    D3DXVECTOR3 GetCenter();
    float GetAngle();

private:
    D3DXVECTOR3 position;
    D3DXVECTOR3 center;
    float angle;
    float theta;

    bool isInitialized;
};

#endif
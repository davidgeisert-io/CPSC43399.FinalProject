#include "View.h"


View::View()
{
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;

    center.x = 0.0f;
    center.y = 0.0f;
    center.z = 0.0f;

    angle = 0.0;

    isInitialized = false;
}

View::~View()
{

}

bool View::Initialize(float xCenter, float yCenter, float angle)
{
    center.x = xCenter;
    center.y = yCenter;
    center.z = 0.0f;
    this->angle = 0.0f;
    return true;
    return(isInitialized);
}

void View::Update(float GameTime, InputDevice* iDevice)
{
    if(iDevice->IsLeftArrowPressed())
    {
        //outsource to xml
        angle -= 0.02f;
    }

    if(iDevice->IsRightArrowPressed())
    {
        //outsource to xml
        angle += .02f;
    }

    if(iDevice->IsUpArrowPressed() || iDevice->IsDownArrowPressed())
    {
        //outsource to xml
        D3DXVECTOR3 XCoord;
        XCoord.x = 0.0;
        XCoord.y = -1.0;
        XCoord.z = 0.0;

        D3DXMATRIX mat;
        D3DXMatrixRotationZ(&mat, angle);
                
        D3DXVECTOR3 RotCoord;
        D3DXVec3TransformCoord(&RotCoord, &XCoord, &mat);

        float scale = 3.0;
        RotCoord *= scale;

        position = iDevice->IsUpArrowPressed() ? 
            position + RotCoord 
            : position - RotCoord;

    }
}

D3DXVECTOR3 View::GetPosition()
{
    return position;
}

D3DXVECTOR3 View::GetCenter()
{ 
    return center;
}

float View::GetAngle()
{
    return angle;
}

bool View::IsInitialized()
{
    return(isInitialized);
}
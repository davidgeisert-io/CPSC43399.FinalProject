#include "View.h"
#include "GameFunctions.h"

View::View()
{
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
	previousPosition.x = 0.0f;
	previousPosition.y = 0.0f;
	previousPosition.z = 0.0f;

    center.x = 0.0f;
    center.y = 0.0f;
    center.z = 0.0f;

	screenDimensions.x = 0.0f;
	screenDimensions.y= 0.0f;
	screenDimensions.z = 0.0f;

    angle = 0.0;
	otEnabled = false;
    isInitialized = false;
}

View::~View()
{

}

bool View::Initialize(float screenWidth, float screenHeight, float angle)
{
	screenDimensions.x = screenWidth;
	screenDimensions.y = screenHeight;
    center.x = screenWidth/2;
    center.y = screenHeight/2;
    center.z = 0.0f;
	xOffset = center.x - position.x;
    this->angle = 0.0f;
    return true;
    return(isInitialized);
}

void View::Update(float GameTime, InputDevice* iDevice)
{
	if(otEnabled)
	{
		TrackObject();
	}
}

bool View::IsInitialized()
{
    return(isInitialized);
}

void View::SetObjectTracking(b2Body* body)
{
	trackedBody = body;
	otEnabled = true;
}

void View::TrackObject()
{
	float xPos = PW2RW(trackedBody->GetPosition().x);
	if(xPos >= 0)
	{
		previousPosition = position;
		position.x = xPos;
	}
}
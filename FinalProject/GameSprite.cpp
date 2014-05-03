#include "GameSprite.h"
#include "GameFunctions.h"



GameSprite::GameSprite()
{
    width = 0.0f;
    height = 0.0f;
    color = D3DCOLOR_ARGB(255,255,255,255);
    initialized=false;
}

GameSprite::~GameSprite()
{
    if(sprite)
    {
        sprite->Release();
        sprite=NULL;
    }

    if(tex)
    {
        tex->Release();
        tex=NULL;
    }
}

bool GameSprite::Initialize(LPDIRECT3DDEVICE9 device, std::string filePath, int width, int height)
{
    this->width = width;
    this->height = height;

    if(!SUCCEEDED(D3DXCreateTextureFromFileEx(device, filePath.c_str() ,width,height,D3DX_DEFAULT, 0, D3DFMT_UNKNOWN,	D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &tex)))
    {
        std::string s = "There was an issue creating the texture. Make sure the requested image is available. Requested image: " + filePath;
        MessageBox(NULL, s.c_str(), NULL, NULL);
        return false;
    }

    if(!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
    {
        MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
    }
    initialized = true;
    return true;
}

bool GameSprite::IsInitialized()
{
    return(initialized);
}

void GameSprite::Draw(float gameTime, View* gameView, b2Body* body)
{   
	D3DXVECTOR3 objectPosition;
	objectPosition.x = PW2RW(body->GetPosition().x);
	objectPosition.y = PW2RW(body->GetPosition().y);
	objectPosition.z = 0.0f;
	float objectAngle = body->GetAngle();

    D3DXVECTOR3 CameraPosition = gameView->GetPosition();
    float CameraAngle = gameView->GetAngle();    
	D3DXVECTOR3 WindowCenter = gameView->GetCenter();

    sprite->Begin(D3DXSPRITE_ALPHABLEND);

    D3DXMATRIX matrix;
    D3DXMatrixRotationZ(&matrix, -CameraAngle);

    D3DXVECTOR3 RenderDifference;
    RenderDifference = objectPosition - CameraPosition;

    D3DXVECTOR3 RenderRotation;
    D3DXVec3TransformCoord(&RenderRotation, &RenderDifference, &matrix);

    D3DXMATRIX matTransform;
    D3DXMatrixTransformation2D(&matTransform, NULL, NULL, NULL, &D3DXVECTOR2(width/2, height/2), objectAngle-CameraAngle, &D3DXVECTOR2(WindowCenter.x + RenderRotation.x - width/2, WindowCenter.y + RenderRotation.y - height/2));

    sprite->SetTransform(&matTransform);


    sprite->Draw(tex, NULL, NULL, NULL, color);
    sprite->End();
}
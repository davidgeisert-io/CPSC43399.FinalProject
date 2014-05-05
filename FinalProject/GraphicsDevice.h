#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H
#include <d3d9.h>

class GraphicsDevice
{
public:
    GraphicsDevice();
    ~GraphicsDevice();

    bool Initialize(HWND hWnd, bool windowed);
    void Clear(D3DCOLOR color);
    void Begin();
    void End();
    void Present();
	LPDIRECT3DDEVICE9 GetDevice(); 

    LPDIRECT3DDEVICE9 device;

private:
	bool initialized;
    LPDIRECT3D9 direct3d;
};

#endif
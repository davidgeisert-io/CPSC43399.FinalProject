#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

class InputDevice
{
public:
    InputDevice();
    ~InputDevice();

    bool Initialize(HINSTANCE hinst, HWND hwnd);
    bool Update();
	unsigned char* GetKeyboardState();
    bool IsLeftArrowPressed();
    bool IsRightArrowPressed();

    bool IsUpArrowPressed();
    bool IsDownArrowPressed();

    bool IsWPressed();
    bool IsAPressed();
    bool IsSPressed();
    bool IsDPressed();

    bool IsSpacePressed();

private:
    bool ReadKeyboard();
    void ProcessInput();

    IDirectInput8* directInput;
    IDirectInputDevice8* keyboard;

    unsigned char keyboardState[256];
};
#endif
#include "InputDevice.h"

#define KEYDOWN(name, key) (name[key] & 0x80)

InputDevice::InputDevice()
{
    directInput = NULL;
    keyboard = NULL;
}

InputDevice::~InputDevice()
{

    if(directInput)
    {
        directInput->Release();
        directInput = NULL;
    }

    if(keyboard)
    {
        keyboard->Unacquire();
        keyboard->Release();
        keyboard = NULL;
    }

}


bool InputDevice::Initialize(HINSTANCE hinst, HWND hwnd)
{

    if(!SUCCEEDED(DirectInput8Create(hinst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, NULL)))
    {
        return false;
    }

    if(!SUCCEEDED(directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL)))
    {
        return false;
    }

    if(!SUCCEEDED(keyboard->SetDataFormat(&c_dfDIKeyboard)))
    {
        return false;
    }

    if(!SUCCEEDED(keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE)))
    {
        return false;
    }

    auto something = keyboard->Acquire();
    if(!SUCCEEDED(keyboard->Acquire()))
    {
        return false;
    }


    return true;

}

bool InputDevice::Update()
{

    if(!ReadKeyboard())
    {
        return false;
    }

    return true;

}


bool InputDevice::ReadKeyboard(){

    HRESULT result = keyboard->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);

    if(!SUCCEEDED(result))
    {

        if((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
        {
            keyboard->Acquire();
        }
        else
        {
            return false;
        }
    }

    return true;

}


bool InputDevice::IsLeftArrowPressed()
{

    if(KEYDOWN(keyboardState, DIK_LEFT))
    {
        return true;
    }

    return false;

}

bool InputDevice::IsRightArrowPressed()
{

    if(KEYDOWN(keyboardState, DIK_RIGHT))
    {
        return true;
    }

    return false;

}


bool InputDevice::IsUpArrowPressed()
{
    if(KEYDOWN(keyboardState, DIK_UP)){
        return true;
    }

    return false;
}

bool InputDevice::IsDownArrowPressed()
{
    if(KEYDOWN(keyboardState, DIK_DOWN))
    {
        return true;
    }

    return false;
}


bool InputDevice::IsWPressed()
{
    if(KEYDOWN(keyboardState, DIK_W))
    {
        return true;
    }
    return false;
}

bool InputDevice::IsAPressed()
{
    if(KEYDOWN(keyboardState, DIK_A))
    {
        return true;
    }
    return false;
}

bool InputDevice::IsSPressed()
{
    if(KEYDOWN(keyboardState, DIK_S))
    {
        return true;
    }
    return false;
}

bool InputDevice::IsDPressed()
{
    if(KEYDOWN(keyboardState, DIK_D))
    {
        return true;
    }
    return false;
}

bool InputDevice::IsSpacePressed()
{
    if(KEYDOWN(keyboardState, DIK_SPACE))
    {
        return true;
    }
    return false;
}

unsigned char* InputDevice::GetKeyboardState()
{
	return keyboardState;
}
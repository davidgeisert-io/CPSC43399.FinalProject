/*
David Geisert
Final Project
*/

#include <windows.h>
#include <ctime>
#include "Game.h"
#include "GraphicsDevice.h"


bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCTSTR className, LPCTSTR windowTitle, int width, int height, HWND& hWnd);
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCTSTR className, LPCTSTR windowTitle, int x, int y, int width, int height, HWND& hWnd);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int width = 1280;
int height = 720;

Game* game;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    bool done = false;
    HWND hWnd;

    if(GenerateWindow(hInstance, nCmdShow, "Win32Window", "Main Game Window", 0, 0, width, height, hWnd))
    {      
        MSG msg;
        game = new Game();

        if (game -> Initialize(hWnd, hInstance, width, height))
        {
            srand((unsigned)time(0));
            
            bool done = false;

            while(!done)
            {
                while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                if(msg.message == WM_QUIT)
                {
                    done = true;
                }
                else
                {
                    game->Run();
                }
            }

            delete game;

            return msg.wParam;

        }

    }
    return 0;
}

bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCTSTR className, LPCTSTR windowTitle, int width, int height, HWND& hWnd)
{
    return GenerateWindow(hInstance, nCmdShow, className, windowTitle, (GetSystemMetrics(SM_CXSCREEN) - width) / 2, (GetSystemMetrics(SM_CYSCREEN) - height) / 2, width, height, hWnd);
}

bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCTSTR className, LPCTSTR windowTitle, int x, int y, int width, int height, HWND& hWnd)
{
    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = className;
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

    if(!RegisterClassEx(&wc))
    {
        return false;
    }

    hWnd = CreateWindowEx(NULL, className, windowTitle, WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_MINIMIZEBOX, x, y, width, height, NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    return true;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        break;
    }
    return DefWindowProc (hWnd, message, wParam, lParam);
}
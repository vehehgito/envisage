// ###########################
// Platform Global Variables
// ###########################

static bool running = true;

// ###########################
// Platform Functions
// ###########################

bool platform_create_window(int width, int height, char* title);
void platform_update_window();

// ###########################
// Windows Platform
// ###########################

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

// ###########################
// Windows Globals
// ###########################

static HWND window; 

// ###########################
// Platform Implementation
// ###########################
bool platform_create_window(int width, int height, char* title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;
    wc.lpfnWndProc = DefWindowProcA;

    if(!RegisterClassA(&wc))
    {
        MessageBoxA(NULL, "Failed to register window class", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(0, title,
                                "Envisage",
                                dwStyle, 
                                100, 100, 
                                width, height,
                                NULL,
                                NULL,
                                instance,
                                NULL);

    if(window == NULL)
    {
        return false;
    }

    ShowWindow(window, SW_SHOW);

    return true;
}

void platform_update_window()
{
    MSG msg;
    while(PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

#endif

int main()
{
    platform_create_window(1200, 720, "Volt Engine v1.0.0");

    while(running)
    {
        platform_update_window();
    }

    return 0;
}
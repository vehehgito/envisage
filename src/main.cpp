#include "volt_lib.h"
#include "platform.h"

// ###########################
// Windows Platform
// ###########################

#ifdef _WIN32
#include "win32_platform.cpp"
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
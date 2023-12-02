#include "platform.h"

#include "volt_lib.h"

#define APIENTRY
#define GL_GLEXT_PROTOTYPES
#include "glcorearb.h"

// ###########################
//      Windows Platform
// ###########################

#ifdef _WIN32
#include "win32_platform.cpp"
#endif

#include "gl_renderer.cpp"

int main()
{   
    BumpAllocator transientStorage = make_bump_allocator(MB(50));

    platform_create_window(1200, 720, "Volt Engine v1.0.0");

    gl_init(BumpAllocator* transientStorage);

    while(running)
    {
        platform_update_window();
    }

    return 0;
}
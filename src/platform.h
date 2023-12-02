#pragma once

// ###########################
//  Platform Global Variables
// ###########################

static bool running = true;

// ###########################
//      Platform Funcs
// ###########################

bool platform_create_window(int width, int height, char* title);
void platform_update_window();
void* platform_load_gl_function(char* funName);
void platform_swap_buffers();

#pragma once

// ###########################
// Platform Global Variables
// ###########################

static bool running = true;

// ###########################
// Platform Functions
// ###########################

bool platform_create_window(int width, int height, char* title);
void platform_update_window();

#include <iostream>
#include "raylib.h"
#include "constants.hpp"


int main()
{
    // Initialization ----------------------------------------------------------

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(constants::screenWidth, constants::screenHeight, "Raylib Template");

    SetTargetFPS(GetMonitorRefreshRate(0));

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update --------------------------------------------------------------

        // Draw ----------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization -------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}

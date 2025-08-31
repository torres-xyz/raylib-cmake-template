#include <iostream>
#include <random> // for std::mt19937 and std::random_device
#include "constants.hpp"
#include "random.hpp"
#include "raylib.h"

int main()
{
    // Initialization ----------------------------------------------------------
    std::cout << "Random Number: " << Random::get(1,10) << "\n";

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(constants::screenWidth, constants::screenHeight,
               "Raylib Template");

    SetTargetFPS(GetMonitorRefreshRate(0));

    const Texture2D mewTex = LoadTexture("resources/mew.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update --------------------------------------------------------------


        // Draw ----------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(mewTex,
                    constants::screenWidth / 2 - mewTex.width / 2,
                    constants::screenHeight / 2 - mewTex.height / 2,
                    WHITE);

        DrawPixel(100, 10, BLACK);

        EndDrawing();
    }

    // De-Initialization -------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}

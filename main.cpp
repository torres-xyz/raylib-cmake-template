#include <iostream>
#include <random> // for std::random_device
#include "constants.hpp"
#include "raylib.h"
#include "raylib-cpp.hpp"
// #include "imgui.h"
// #include "rlImGui.h"
#include "cmake-build-debug/_deps/dear_imgui-src/imgui.h"
#include "cmake-build-debug/_deps/rlimgui-src/rlImGui.h"

int main()
{
    // Initialization ----------------------------------------------------------
    std::random_device rd{};
    SetRandomSeed(rd());

    SetConfigFlags(FLAG_VSYNC_HINT);
    raylib::Window window(constants::screenWidth, constants::screenHeight,
                          "Raylib-cpp Template");
    // InitWindow(constants::screenWidth, constants::screenHeight, "Raylib Template");

    SetTargetFPS(GetMonitorRefreshRate(0));
    rlImGuiSetup(true);

    const raylib::Texture2D mewTex("resources/mew.png");

    // Main game loop
    while (!window.ShouldClose()) // Detect window close button or ESC key
    {
        // Update --------------------------------------------------------------


        // Draw ----------------------------------------------------------------
        BeginDrawing();
        window.ClearBackground(RAYWHITE);
        // start ImGui Conent
        rlImGuiBegin();

        // show ImGui Content
        bool open = true;
        ImGui::ShowDemoWindow(&open);

        if (ImGui::Begin("Test Window", &open))
        {
            ImGui::TextUnformatted(ICON_FA_JEDI);

            rlImGuiImage(&mewTex);
        }
        ImGui::End();

        // end ImGui Content
        rlImGuiEnd();

        mewTex.Draw(constants::screenWidth / 2 - mewTex.width / 2,
                    constants::screenHeight / 2 - mewTex.height / 2,
                    WHITE);

        DrawPixel(100, 10, BLACK);

        EndDrawing();
    }

    // De-Initialization -------------------------------------------------------
    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

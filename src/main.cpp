#include <iostream>
#include <random> // for std::random_device
#include "constants.hpp"
// #include "raylib.h"
#include "raylib-cpp.hpp"
#include "imgui.h"
#include "rlImGui.h"

int main()
{
    // Initialization ----------------------------------------------------------
    std::random_device rd{};
    SetRandomSeed(rd());

    SetConfigFlags(FLAG_VSYNC_HINT);
    raylib::Window window(constants::windowScreenWidth, constants::windowScreenHeight,
                          "Raylib-cpp Template");

    SetTargetFPS(GetMonitorRefreshRate(0));

#if (DEBUG)
    rlImGuiSetup(true);
#endif

    const raylib::Texture2D mewTex("resources/mew.png");


    // Main game loop
    while (!window.ShouldClose()) // Detect window close button or ESC key
    {
        // Update --------------------------------------------------------------


        // Draw ----------------------------------------------------------------
        window.ClearBackground(RAYWHITE);

#if (DEBUG)
        // start ImGui Content
        rlImGuiBegin();

        // show ImGui Content
        bool open = false;
        ImGui::SetNextWindowPos(ImVec2(constants::windowScreenWidth - constants::imguiSideBarWidth, 0));
        ImGui::SetNextWindowSize(ImVec2(constants::imguiSideBarWidth, constants::windowScreenHeight));
        if (ImGui::Begin("Test Window", &open,
                         ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar))
        {
            ImGui::TextUnformatted("My Text inside the window");
            ImGui::TextUnformatted("My Text inside the window");
            ImGui::TextUnformatted("My Text inside the window");
            rlImGuiImage(&mewTex);
        }
        ImGui::End();

        // end ImGui Content
        rlImGuiEnd();

        raylib::Rectangle newRect{
            constants::screenWidth * 0.5,
            constants::screenHeight * 0.5,
            constants::screenWidth * 0.5,
            constants::screenHeight * 0.5
        };
        newRect.Draw(BLACK);
#endif

        mewTex.Draw(constants::screenWidth / 2 - mewTex.width / 2,
                    constants::screenHeight / 2 - mewTex.height / 2,
                    WHITE);


        EndDrawing();
    }

    // De-Initialization -------------------------------------------------------
    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

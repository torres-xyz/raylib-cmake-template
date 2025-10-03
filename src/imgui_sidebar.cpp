#include "imgui_sidebar.hpp"

void DrawSideBar()
{
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
        // rlImGuiImage(&mewTex);
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
}

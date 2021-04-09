#define _CRT_SECURE_NO_WARNINGS
#include "Include.h"
#include "CreateWndProc.h"
#include "WIndowProcess.h"
#include <vector>
#include <sstream>
#include "../fnv1a.h"
#include <time.h>

using namespace ImGui;
float screen_max[]{ GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

ImVec2 operator-(const ImVec2& l, const ImVec2& r) { return{ l.x - r.x, l.y - r.y }; }
ImVec2 operator+(const ImVec2& l, const ImVec2& r) { return{ l.x + r.x, l.y + r.y }; }


int main()
{
    /* First argument if window pos - position, where will be rendered window and size, how big window will be */
    window.init( ImVec2{ 0, 0 }, ImVec2{ screen_max[0], screen_max[1] } );
    auto& IO = GetIO();

    ImFontConfig font_config;
    font_config.OversampleH = 1; //or 2 is the same
    font_config.OversampleV = 1;
    font_config.PixelSnapH = 1;

    static const ImWchar ranges[] =
    {
        0x0020, 0x00FF, // Basic Latin + Latin Supplement
        0x0400, 0x044F, // Cyrillic
        0,
    };

    g_Menu.Default = IO.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/verdana.ttf", 14.f, &font_config);

    /* DIRECTX & wndproc initialization */
    m_directx.  init32(); 
    window.     process_msg();
    /* code shutdown  UPD: fixed crash in time of process closing & (device lost) */ 
    m_directx.  finish();

    return 0;
};

namespace global_menu {

    void init() {
   

        //configurate menu :
        static const auto   background = ImGui::GetBackgroundDrawList();
        static const auto   foreground = ImGui::GetForegroundDrawList();
        const  auto         opened     = GetKeyState(VK_INSERT) & 1;

        //debug background (purple)
        background->AddRectFilled(ImVec2(0, 0), ImVec2(4000, 4000), ImColor(25, 25, 25), 0.0);

        //on toogle check
		if (!opened)
			return;
      
        //flags - 
        static const WORD dw_window_flags = 0;
		ImGui::SetNextWindowSize(ImVec2(620 * 1.05, 410 * 1.05));

        auto& style = ImGui::GetStyle();
		if (Begin("My menu", nullptr, dw_window_flags))
		{


		}
		End();
		

    }


};

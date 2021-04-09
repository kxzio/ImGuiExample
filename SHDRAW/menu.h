#pragma once
#include <d3d9.h>
#include <d3dx9tex.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

namespace global_menu {

	void init();

};

class extra {
public:
	ImFont* Default;
};
inline extra g_Menu;

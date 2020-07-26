/*
	INTERFACE GRENDERABLE
*/

#ifndef GRENDERABLE
#define GRENDERABLE

#include <windows.h>
#include "../../basic/bdt_color.hpp"

namespace bdt {
namespace graphic {

class GRenderable {
protected:

	GRenderable() {}

public:

	static void _set_pos(int x, int y) {	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),COORD{x,y});	}
	static void _set_color(Color foreground, Color background) {	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background<<4|foreground);	}
	static void _set_visible(bool visible) {	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),new CONSOLE_CURSOR_INFO{0,visible});	}

	virtual void render() = 0;
	
};

}
}

#endif
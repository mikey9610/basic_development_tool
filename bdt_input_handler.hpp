/*
	CLASS INPUTHANDLER
*/

#ifndef INPUTHANDLER
#define INPUTHANDLER

#include <conio.h>
#include "bdt_keyconstant.hpp"

namespace bdt {

typedef const int KEY_INPUT;

class InputHandler {
protected:

	virtual int set_key_command(KEY_INPUT key_input) = 0;

public:
	
	static const int NO_INPUT = -100;

	int handle_input(bool wait) {
		if(!kbhit() && !wait)	return NO_INPUT;

		int key = getch();
		if(key == KEY::SPECIAL) {
			key = getch();
			switch(key) {
			case KEY::LEFT:
				key = KEY::D_LEFT;
				break;
			case KEY::RIGHT:
				key = KEY::D_RIGHT;
				break;
			case KEY::UP:
				key = KEY::D_UP;
				break;
			case KEY::DOWN:
				key = KEY::D_DOWN;
				break;
			case KEY::ESC:
				key = KEY::ESC;
				break;
			}
		}
		return set_key_command(key);
	}
	
};

}

#endif
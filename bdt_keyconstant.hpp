/*
	CLASS KEYCONSTANT
*/

#ifndef KEYCONSTANT
#define KEYCONSTANT

namespace bdt {

class KEY {
public:
	static const int LEFT = 75;
	static const int RIGHT = 77;
	static const int UP = 72;
	static const int DOWN = 80;

	static const int SPECIAL = 224;
	static const int ESC = 27;
	static const int ENTER = 13;

	static const int D_LEFT = -1;
	static const int D_RIGHT = -2;
	static const int D_UP = -3;
	static const int D_DOWN = -4;
};

}

#endif
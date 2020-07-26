/*
	CLASS COLOR
*/

#ifndef COLOR
#define COLOR

namespace bdt {

enum Color {
	C_BLACK			= 0,
	C_BLUE			= 1,
	C_GREEN			= 2,
	C_CYAN			= 3,
	C_RED			= 4,
	C_MAGENTA		= 5,
	C_YELLOW		= 6,
	C_WHITE			= 7,

	C_BRIGHT		= 8,

	C_BRIGHT_BLACK	= 8,
	C_BRIGHT_BLUE	= 9,
	C_BRIGHT_GREEN	= 10,
	C_BRIGHT_CYAN	= 11,
	C_BRIGHT_RED	= 12,
	C_BRIGHT_MAGENTA= 13,
	C_BRIGHT_YELLOW	= 14,
	C_BRIGHT_WHITE	= 15
};

inline Color mix(const Color c1, const Color c2) {	return (Color)(c1|c2);	}

inline Color brighten(const Color c) {	return (Color)(c|C_BRIGHT);	}

inline Color darken(const Color c) {	return (Color)(c&~C_BRIGHT);	}

}

#endif
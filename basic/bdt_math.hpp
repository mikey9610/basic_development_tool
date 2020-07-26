/*
	STATIC CLASS MATH
*/

#ifndef MATH
#define MATH

namespace bdt {

class math {
private:

	math() {}

public:
	
	inline static int _div_in_row(int total, int denom) {	return (total%denom==0) ? total/denom : total/denom+1;	}
	
};
	
}

#endif
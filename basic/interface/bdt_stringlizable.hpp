/*
	INTERFACE STRINGLIZABLE
*/

#ifndef STRINGLIZABLE
#define STRINGLIZABLE

#include <iostream>
using namespace std;

namespace bdt {

class Stringlizable {
public:

	virtual string to_string() const = 0;
	
};

}

#endif
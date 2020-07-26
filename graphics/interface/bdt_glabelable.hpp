/*
	INTERFACE GLABELABLE
*/

#ifndef GLABELABLE
#define GLABELABLE

#include <iostream>
using namespace std;
#include "../bdt_grectangle.hpp"
#include "bdt_grenderable.hpp"

namespace bdt {
namespace graphic {

class GLabelable {
protected:

	string label_;

	int lines_;
	int length_;
	
	const int PREFERRED = -1;

	GLabelable(string label="")
	 :	label_(label),
	 	lines_(PREFERRED),
		length_(PREFERRED) {}

	void render(GRectangle*);

public:	

	inline string get_label() const {	return this->label_;	}
	inline void set_label(string label) {	this->label_ = label;	}

	inline void set_label_lines(int lines) {	this->lines_ = (lines<1||lines>label_.length())?PREFERRED:lines;	}
	inline void set_label_length(int length) {	this->length_ = (length<1||length>label_.length())?PREFERRED:length;	}

};

}
}

#endif
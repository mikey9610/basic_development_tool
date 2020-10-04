/*
	INTERFACE LABELABLE
*/

#ifndef LABELABLE
#define LABELABLE

#include "../basic/bdt_math.hpp"
#include "../graphics/bdt_grectangle.hpp"
#include "bdt_renderable.hpp"
using namespace bdt::graphic;

namespace bdt {

class Labelable {
protected:

	string label_;

	int lines_;
	int length_;
	
	static const int PREFERRED = -1;

	Labelable(const string label="")
	 :	label_(label),
	 	lines_(PREFERRED),
		length_(PREFERRED) {}

	inline void render(GRectangle* bounds) {
		if(bounds == nullptr)	return;
		
		if(lines_ > bounds->get_height())
			lines_ = bounds->get_height();

		if(length_ > bounds->get_width() || length_ == PREFERRED)
			length_ = bounds->get_width();

		if(lines_ == PREFERRED) {
			if(label_.length() > bounds->get_width()*bounds->get_height()) 
				lines_ = bounds->get_height();
			else
				this->lines_ = math::_div_in_row(label_.length(),length_);
		}
		else		
			length_ = math::_div_in_row(label_.length(),lines_);
			
		for(int row=0;row<lines_;row++) {
			Renderable::_set_pos(bounds->get_x()+(bounds->get_width()-length_)/2 , bounds->get_y()+(bounds->get_height()-lines_)/2+row);
			for(int col=0;col<length_&&row*length_+col<label_.length();col++)
				cout << label_[row*length_+col];
		}
	}

public:	

	inline string get_label() const {	return this->label_;	}
	inline void set_label(string label) {	this->label_ = label;	}

	inline void set_label_lines(int lines) {	this->lines_ = (lines<1||lines>label_.length())?PREFERRED:lines;	}
	inline void set_label_length(int length) {	this->length_ = (length<1||length>label_.length())?PREFERRED:length;	}

};

}

#endif
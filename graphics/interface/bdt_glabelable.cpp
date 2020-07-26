/*
	INTERFACE GLABELABLE
*/

#include "../../basic/bdt_math.hpp"
#include "bdt_glabelable.hpp"
using namespace bdt::graphic;

void GLabelable::render(GRectangle* bounds) {
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
		GRenderable::_set_pos(bounds->get_x()+(bounds->get_width()-length_)/2 , bounds->get_y()+(bounds->get_height()-lines_)/2+row);
		for(int col=0;col<length_&&row*length_+col<label_.length();col++)
			cout << label_[row*length_+col];
	}
}
/*
	INTERFACE GCOMPONENT
*/

#include "bdt_gcomponent.hpp"
using namespace bdt::graphic;

GRectangle* GComponent::get_abs_bounds() {
	if(parent_ != nullptr) {
		GRectangle* abs_bounds;
		GRectangle* tmp = new GRectangle(this->get_bounds());
		tmp->translate(parent_->get_x(),parent_->get_y());
		abs_bounds = parent_->get_intersection(*tmp);
		delete tmp;
		return abs_bounds;
	}
	else
		return new GRectangle(this->get_bounds());
}
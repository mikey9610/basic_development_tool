/*
	INTERFACE GCOMPONENT
*/

#include "bdt_gcomponent.hpp"
using namespace bdt::graphic;

GRectangle* GComponent::get_abs_bounds() {
	return (parent_ == nullptr) ? new GRectangle(this->get_bounds()) : parent_->get_intersection(this->get_bounds());
}
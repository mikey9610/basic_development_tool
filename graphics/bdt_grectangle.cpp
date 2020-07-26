/*
	CLASS GRECTANGLE
*/

#include "../basic/bdt_comparison.hpp"
#include "bdt_grectangle.hpp"
using namespace bdt::graphic;

GRectangle* GRectangle::get_intersection(const GRectangle& r) const  {
	if(intersects(r)) {
		int startX = cmp::_bigger(x_,r.x_);
		int startY = cmp::_bigger(y_,r.y_);
		int endX = cmp::_smaller(x_+width_,r.x_+r.width_);
		int endY = cmp::_smaller(y_+height_,r.y_+r.height_);
		return new GRectangle(startX,startY,endX-startX,endY-startY);	
	}
	else return nullptr;
}
	
GRectangle* GRectangle::get_union(const GRectangle&r) const  {
	int startX = cmp::_smaller(x_,r.x_);
	int startY = cmp::_smaller(y_,r.y_);
	int endX = cmp::_bigger(x_+width_,r.x_+r.width_);
	int endY = cmp::_bigger(y_+height_,r.y_+r.height_);	
	return new GRectangle(startX,startY,endX-startX,endY-startY);	
}
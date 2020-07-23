/*
	CLASS GRECTANGLE
*/

#include "../basic/comparison.hpp"
#include "bdt_grectangle.hpp"
using namespace bdt::graphic;

GRectangle* GRectangle::get_intersection(const GRectangle& r) const  {
	if(intersects(r)) {
		int startX = cmp::bigger(x_,r.x_);
		int startY = cmp::bigger(y_,r.y_);
		int endX = cmp::smaller(x_+width_,r.x_+r.width_);
		int endY = cmp::smaller(y_+height_,r.y_+r.height_);
		return new GRectangle(startX,startY,endX-startX,endY-startY);	
	}
	else return nullptr;
}
	
GRectangle* GRectangle::get_union(const GRectangle&r) const  {
	int startX = cmp::smaller(x_,r.x_);
	int startY = cmp::smaller(y_,r.y_);
	int endX = cmp::bigger(x_+width_,r.x_+r.width_);
	int endY = cmp::bigger(y_+height_,r.y_+r.height_);	
	return new GRectangle(startX,startY,endX-startX,endY-startY);	
}
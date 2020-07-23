/*
	CLASS GRECTANGLE
*/

#ifndef GRECTANGLE
#define GRECTANGLE

#include "bdt_gpoint.hpp"
#include "bdt_gdimension.hpp"

namespace bdt {
namespace graphic {

class GRectangle : public GPoint, public GDimension {
public:

	GRectangle()
	 : GPoint(0,0), GDimension(0,0) {}
	GRectangle(int width, int height)
	 : GPoint(0,0), GDimension(width,height) {}
	GRectangle(GDimension d)
	 : GPoint(0,0), GDimension(d) {}
	GRectangle(GPoint p)
	 : GPoint(p), GDimension(0,0) {}
	GRectangle(GPoint p, GDimension d)
	 : GPoint(p), GDimension(d) {}
	GRectangle(int x, int y, int width, int height)
	 : GPoint(x,y), GDimension(width,height) {}
	
	inline GRectangle get_bounds() const {	return *this;	}

	inline void set_bounds(int x, int y, int width, int height) {
		set_location(x,y);
		set_size(width,height);
	}
	inline void set_bounds(GRectangle r) {
		set_location(r.get_location());
		set_size(r.get_size());
	}

	inline bool contains(int x, int y) const {
		return x>=x_ && x<x_+width_ && y>=y_ && y<y_+height_;
	}
	inline bool contains(GPoint p) const {
		return contains(p.get_x(),p.get_y());
	}
	inline bool contains(int x, int y, int width, int height) const {
		return contains(x,y) && contains(x+width-1,y+height-1);
	}
	inline bool contains(GRectangle r) const {
		return contains(r.x_,r.y_,r.width_,r.height_);
	}

	inline bool intersects(const GRectangle& r) const {
		return x_ < r.x_+r.width_ && x_+width_ > r.x_ && y_ < r.y_+r.height_ && y_+height_ > r.y_; 
	}

	GRectangle* get_intersection(const GRectangle&) const ;
	
	GRectangle* get_union(const GRectangle&) const ;
	

	virtual string to_string() const override {	
		return GPoint::to_string() + GDimension::to_string();
	}
};

}
}

#endif
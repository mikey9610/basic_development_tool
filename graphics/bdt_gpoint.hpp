/*
	CLASS GPOINT
*/

#ifndef GPOINT
#define GPOINT

#include <stdexcept>
#include "../basic/interface/bdt_stringlizable.hpp"

namespace bdt {
namespace graphic {

class GPoint : virtual public Stringlizable {
protected:

	int x_;
	int y_;

public:

	GPoint()
	 : x_(0), y_(0) {}
	GPoint(int x, int y)
	 : x_(x), y_(y) {}

	inline int get_x() const {	return this->x_;	}
	inline int get_y() const {	return this->y_;	}
	inline GPoint get_location() const {	return *this;	}

	inline void set_x(int x) {	(x<0)?throw out_of_range("error : x must not be negative"):this->x_ = x;	}
	inline void set_y(int y) {	(y<0)?throw out_of_range("error : y must not be negative"):this->y_ = y;	}
	inline void set_location(int x, int y) {	
		set_x(x);
		set_y(y);
	}
	inline void set_location(GPoint p) {
		set_x(p.x_);
		set_y(p.y_);
	}

	inline void translate(int dx, int dy) {
		set_x(x_+dx);
		set_y(y_+dy);
	}

	virtual string to_string() const override {	
		return "("+std::to_string(x_)+","+std::to_string(y_)+")";
	}
};

}
}

#endif
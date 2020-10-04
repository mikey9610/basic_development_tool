/*
	CLASS GDIMENSION
*/

#ifndef GDIMENSION
#define GDIMENSION

#include <stdexcept>
#include "../interface/bdt_stringlizable.hpp"

namespace bdt {
namespace graphic {

class GDimension : virtual public Stringlizable {
protected:

	int width_;
	int height_;

public:

	GDimension()
	 : width_(0), height_(0) {}
	GDimension(int width, int height)
	 : width_(width), height_(height) {}

	inline int get_width() const {	return this->width_;	}
	inline int get_height() const {	return this->height_;	}
	inline GDimension get_size() const {	return *this;	}

	inline void set_width(int width) {		(width<0)?throw out_of_range("error : width must not be negative"):this->width_ = width;	}
	inline void set_height(int height) {	(height<0)?throw out_of_range("error : height must not be negative"):this->height_ = height;	}
	inline void set_size(int width, int height) {	
		set_width(width);
		set_height(height);
	}
	inline void set_size(GDimension d) {
		set_width(d.width_);
		set_height(d.height_);
	}

	virtual string to_string() const override {	
		return "<"+std::to_string(width_)+"w"+std::to_string(height_)+"h>";
	}
};

}
}

#endif
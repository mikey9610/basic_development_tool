/*
	INTERFACE GCOMPONENT
*/

#ifndef GCOMPONENT
#define GCOMPONENT

#include "../bdt_grectangle.hpp"
#include "bdt_grenderable.hpp"

namespace bdt {
namespace graphic {

class GComponent : virtual public GRectangle, virtual public GRenderable {

	friend class GContainer;

protected:

	Color foreground_;
	Color background_;

	bool enabled_;
	
	bool visible_;

	GComponent* parent_;

	GComponent()
	 :	foreground_(C_BRIGHT_WHITE),
		background_(C_BLACK),
		enabled_(true),
		visible_(true),
		parent_(nullptr) {}

	GRectangle* get_abs_bounds();
	
	inline void set_parent(GComponent* parent) {	this->parent_ = parent;	}

public:	
	
	inline Color get_foreground() const {	return this->foreground_;	}
	inline Color get_background() const {	return this->background_;	}
	inline bool is_enabled() const {	return this->enabled_;	}
	inline bool is_visible() const {	return this->visible_;	}
	
	inline void set_foreground(Color foreground) {	this->foreground_ = foreground;	}
	inline void set_background(Color background) {	this->background_ = background;	}
	inline void set_enabled(bool enabled) {	this->enabled_ = enabled;	}
	inline void set_visible(bool visible) {	this->visible_ = visible;	}
	
	virtual void render() override {
		GRectangle* abs_bounds = get_abs_bounds();
		if(abs_bounds == nullptr)	return;
		if(this->visible_ == false)	return;
		
		GRenderable::_set_color(foreground_,background_);
		for(int h=0; h<abs_bounds->get_height(); h++) {
			GRenderable::_set_pos(abs_bounds->get_x(),abs_bounds->get_y()+h);
			for(int w=0; w<abs_bounds->get_width(); w++)	cout << " ";			
		}
	}

	virtual string to_string() const override {	return "";	}

};

}
}

#endif
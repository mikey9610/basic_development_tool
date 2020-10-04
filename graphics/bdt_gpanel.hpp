/*
	CLASS GPANEL
*/

#ifndef GPANEL
#define GPANEL

#include "../basic/bdt_grid.hpp"
#include "bdt_gcomponent.hpp"

namespace bdt {
namespace graphic {

class GPanel : virtual public GComponent {
protected:

	bool grid_;

public:	

	GPanel()
	 :	GComponent(),
	 	grid_(true) {}

	inline void set_grid(bool grid) {	this->grid_ = grid;	}

	// override Renderable
	virtual void render() {
		GComponent::render();
		if(grid_) {
			auto abs_bounds = get_abs_bounds();
			Renderable::_set_color(foreground_,background_);
			bdt::Grid::render_border(abs_bounds->get_x(),abs_bounds->get_y(),1,width_-4,1,height_-2,false);
		}		
	}

	// override Stringlizable
	virtual string to_string() const override {	return "GPanel";	}

};

}
}

#endif
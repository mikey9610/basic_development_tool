/*
	CLASS GBUTTON
*/

#ifndef GBUTTON
#define GBUTTON

#include "bdt_gcomponent.hpp"
#include "../interface/bdt_labelable.hpp"

namespace bdt {
namespace graphic {

class GButton : virtual public GComponent, virtual public Labelable {
protected:

	bool enabled_;

	virtual void perform()=0;

public:	

	GButton()
	 :	GComponent(),
	 	Labelable(),
		enabled_(true) {}

	inline bool is_enabled() const {	return this->enabled_;	}
	inline void set_enabled(bool enabled) {	this->enabled_ = enabled;	}

	inline void click() {
		if(!enabled_)	return;
		this->perform();
	}

	// override Labelable
	virtual void render() final {
		GComponent::render();
		Labelable::render(this->get_abs_bounds());
	}

	// override Stringlizable
	virtual string to_string() const final {	return "GButton";	}

};

}
}

#endif
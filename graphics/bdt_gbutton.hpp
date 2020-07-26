/*
	CLASS GBUTTON
*/

#ifndef GBUTTON
#define GBUTTON

#include "interface/bdt_gcomponent.hpp"
#include "interface/bdt_glabelable.hpp"

namespace bdt {
namespace graphic {

class GButton : virtual public GComponent, virtual public GLabelable {
protected:


public:	
	GButton()
	 :	GComponent() {}

	virtual void render() override {
		GComponent::render();
		GLabelable::render(this->get_abs_bounds());
	}

	virtual string to_string() const override {	return "GButton";	}

};

}
}

#endif
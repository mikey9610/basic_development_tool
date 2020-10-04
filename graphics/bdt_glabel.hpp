/*
	CLASS GLABEL
*/

#ifndef GLABEL
#define GLABEL

#include "bdt_gcomponent.hpp"
#include "../interface/bdt_labelable.hpp"

namespace bdt {
namespace graphic {

class GLabel : virtual public GComponent, virtual public Labelable {
protected:

public:	

	GLabel(const string label="")
	 :	GComponent(),
	 	Labelable(label) {}

	// override Labelable
	virtual void render() override {
		GComponent::render();
		Labelable::render(this->get_abs_bounds());
	}

	// override Stringlizable
	virtual string to_string() const override {	return "GLabel";	}

};

}
}

#endif
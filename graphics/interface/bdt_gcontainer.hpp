/*
	INTERFACE GCONTAINER
*/

#ifndef GCONTAINER
#define GCONTAINER

#include <vector>
#include "bdt_gcomponent.hpp"

namespace bdt {
namespace graphic {

class GContainer : virtual public GComponent {
protected:

	GContainer()
	 :	GComponent() {}

	std::vector<GComponent*> contents_;

public:	

	inline void add(GComponent* comp) {
		this->contents_.push_back(comp);
		comp->set_parent(this);
	}
	
	virtual void render() override {
		if(this->visible_ == false)	return;
		GComponent::render();
		for(auto& comp : contents_)	comp->render();
	}

	virtual string to_string() const override {	return "";	}

};

}
}

#endif
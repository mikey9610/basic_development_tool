/*
	CLASS GPANEL
*/

#ifndef GPANEL
#define GPANEL

#include "interface/bdt_gcontainer.hpp"

namespace bdt {
namespace graphic {

class GPanel : virtual public GContainer {
public:	

	GPanel()
	 :	GContainer() {}

	virtual string to_string() const override {	return "GPanel";	}

};

}
}

#endif
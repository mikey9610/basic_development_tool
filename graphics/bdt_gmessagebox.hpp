/*
	INTERFACE GMessageBox
*/

#ifndef GMESSAGEBOX
#define GMESSAGEBOX

#include "bdt_gpanel.hpp"
#include "bdt_glabel.hpp"

namespace bdt {
namespace graphic {

class GMessageBox {
private:

	GMessageBox() {}

public:	

	inline static void showMessageDialog(GRectangle bounds, const string message) {
		GPanel box;
		box.set_bounds(bounds);
		GLabel label(message);
		label.set_bounds(2,1,bounds.get_width()-4,bounds.get_height()-2);
		box.add(&label);
		box.render();
		getchar();
	}

	inline static int showOptionDialog() {}

};

}
}

#endif
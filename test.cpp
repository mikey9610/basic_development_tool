#include "graphics/bdt_gbutton.hpp"
#include "graphics/bdt_gpanel.hpp"
using namespace bdt::graphic;
using namespace bdt;

int main() {
	GPanel panel1;
	GButton button1;

	panel1.set_bounds(4,4,20,8);
	panel1.set_foreground(C_RED);
	panel1.set_background(C_GREEN);

	button1.set_bounds(5,5,10,4);
	button1.set_foreground(C_BRIGHT_WHITE);
	button1.set_background(C_BLUE);
	button1.set_label("MYAD");
	button1.set_label_lines(4);


	panel1.add(&button1);
	panel1.render();

	getchar();
	getchar();

	return 0;
}
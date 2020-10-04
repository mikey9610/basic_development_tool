#include "graphics/bdt_gbutton.hpp"
#include "graphics/bdt_gpanel.hpp"
#include "graphics/bdt_gmessagebox.hpp"
using namespace bdt::graphic;
using namespace bdt;

#include <conio.h>


class myButton : public GButton {
protected:
	virtual void perform() override {
		GMessageBox::showMessageDialog(GRectangle(10,10,20,4),"You Pressed The Warning Button!!");
	}
};

int main() {
	GPanel panel1;
	myButton button1;

	panel1.set_bounds(0,0,40,20);
	panel1.set_foreground(C_BLACK);
	panel1.set_background(C_BRIGHT_WHITE);

	button1.set_bounds(15,8,10,3);
	button1.set_foreground(C_BRIGHT_WHITE);
	button1.set_background(C_RED);
	button1.set_label("WARNING!");
	button1.set_label_lines(1);

	panel1.add(&button1);
	panel1.render();

	getchar();
		button1.click();

	getchar();

	return 0;
}
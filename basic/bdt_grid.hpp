/*
	CLASS GRID
*/

#ifndef GRID
#define GRID

#include <iostream>
#include "../interface/bdt_renderable.hpp"
using namespace std;

namespace bdt {

class Grid {
public:	

	inline static void render_border(int x, int y, int col, int col_size, int row, int row_size, bool fill) {
		col_size = (col_size%2==0)?col_size:col_size+1;
		int width = (col_size+2)*col;
		int height = (row_size+1)*row;

		for(int dy=0;dy<=height;dy++) {
			for(int dx=0;dx<=width;dx+=2) {
				Renderable::_set_pos(x+dx,y+dy);
				if(dx==0) {
					if(dy==0)	cout << "¦£ ";
					else if(dy==height)	cout << "¦¦ ";
					else if(dy%(row_size+1)==0)			cout << "¦§ ";
					else	cout << "¦¢ ";
				}
				else if(dx==width) {
					if(dy==0)		cout << "¦¤ ";
					else if(dy==height)	cout << "¦¥ ";
					else if(dy%(row_size+1)==0)			cout << "¦© ";
					else	cout << "¦¢ ";
				}
				else if(dx%(col_size+2)==0) {
					if(dy==0)		cout << "¦¨ ";
					else if(dy==height)	cout << "¦ª ";
					else if(dy%(row_size+1)==0)			cout << "¦« ";
					else	cout << "¦¢ ";
				}
				else {
					if(dy==0)		cout << "¦¡ ";
					else if(dy==height)	cout << "¦¡ ";
					else if(dy%(row_size+1)==0)			cout << "¦¡ ";
					else if(fill)	cout << "  ";
				}			
			}
		}
	}

};

}

#endif
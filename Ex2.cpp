#include "Simple_window.h"
#include "Graph.h"

struct box :Shape
{
	box(Point xy, int ww, int hh, int r);

	void draw_lines() const;

private:
	Line lx1, lx2, ly1, ly2;
	Arc ac1, ac2, ac3, ac4;
};

box::box(Point xy, int ww, int hh, int r)
{
	lx1 = Line{ Point{ xy.x + r,xy.y },Point{ xy.x + ww - r,xy.y } };
	lx2 = Line{ Point{ xy.x + r,xy.y + hh } ,Point{ xy.x + ww - r,xy.y + hh } }

	ly1 = Line{ Point{ xy.x,xy.y + r },Point{ xy.x,xy.y + hh - r } };
	ly2 = Line{ Point{ xy.x + ww ,xy.y + r },Point{ xy.x + ww,xy.y + hh - r } };

	ac1 = Arc{ Point{xy.x + r,xy.y + r},r,90,180 };
	ac2 = Arc{ Point{xy.x + ww - r,xy.y + r},r,0,90 };
	ac3 = Arc{ Point{xy.x + r,xy.y + hh - r},r,180,270 };
	ac4 = Arc{ Point{xy.x + ww - r,xy.y + hh - r},r,270,360 };

}

void box::draw_lines() const
{
	lx1.draw_lines();
	lx2.draw_lines();
	ly1.draw_lines();
	ly2.draw_lines();

	ac1.draw_lines();
	ac2.draw_lines();
	ac3.draw_lines();
	ac4.draw_lines();

}

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{100,100},800,800,"My canvas" };

	Box b1 = { Point{100,100},200,200 };

	win.attach(b1);
	win.wait_for_button();


	return 0;
}
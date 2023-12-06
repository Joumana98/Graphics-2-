#include "Simple_window.h"
#include "Graph.h"

struct Labeled_Box :Box
{
	Labeled_Box(Point xy, int w, int l, int r, string s);

	void draw_lines() const();
	Text get_label() const { return lab; }


private:
	Text lab;

};

int main()
{
	using namespace graph_lib;

	Simple_window win{ Point{20,100},800,600,"My canvas" };

	Labeled_Box b1 = { Point{150,50},100,50,10,"Window" };
	Labeled_Box b2 = { Point{300,50},150,50,10,"Line_style" };
	Labeled_Box b3 = { Point{500,50},100,50,10,"Color" };

	Labeled_Box b4 = { Point{100,150},200,50,10,"Simple_window" };
	Labeled_Box b5 = { Point{350,100},100,50,10,"Shape" };
	Labeled_Box b6 = { Point{500,150},100,50,10,"Point" };

	Labeled_Box b7 = { Point{50,250},100,50,10,"Line" };
	Labeled_Box b8 = { Point{200,250},100,50,10,"Lines" };
	Labeled_Box b9 = { Point{350,250},100,50,10,"Polygon" };

	Arrow ar1{ Point{200,150},Point{200,100} };

	win.attach(b1);
	win.attach(b2);
	win.attach(b3);
	win.attach(b4);
	win.attach(b5);
	win.attach(b6);
	win.attach(b7);
	win.attach(b8);
	win.attach(b9);
	win.attach(ar1);


	win.wait_for_button();
	return 0;
}

Labeled_Box::Labeled_Box(Point xy, int w, int l, int r, string s) : Box{ xy,w,l,r }
{
	Point position = { xy.x * (1 + 0.25),xy.y(1 - 0.25) };
	lab = Text{ position, s };
}

void Labeled_Box::draw_lines() const()
{
	Box::draw_lines(); // draw the oustide box;
	lab.draw_lines(); // write the label inside the box
}

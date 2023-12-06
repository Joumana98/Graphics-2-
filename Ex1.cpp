#include "../std_lib_facilites.h"
#include "Simple_window.h"
#include "Graph.h"

struct Arc :Circle
{
	Arc(Point c, int rr, int s, int e);

	void draw_lines() const;

private:
	int beg;
	int end;
};

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},800,600 };

	Arc a1 = { Point {200,200},100,0,90 };
	a1.set_color(Color::red);
	Arc a2 = { Point {200,200},50,45,135 };
	a2.set_color(Color::blue);

	win.attach(a1);
	win.attach(a2);

	win.wait_for_button();


	return 0;
}

Arc::Arc(Point c, int rr, int s, int e) :Circle{ c,rr }
{
	if (s >= 0 && s <= 360)
		beg = s;
	else
		error("Invalid start angle of an Arc!");
	if (e >= 0 && e <= 360)
		end = e;
	else
		error("Invalid ending angle of an Arc!");
}

void Arc::draw_lines() const
{
	fl_draw(point(0).x, point(0).y, r + r, r + r, beg, end);
}

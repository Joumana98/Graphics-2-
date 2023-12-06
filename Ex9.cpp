#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},600,400,"My canvas" };

	Pint center{ 400,300 }
	Ellipse e = { center,300,200 };

	Axis x_axis{ Axis::x,center,400,20,"x axis" };
	Axis y_axis{ Axix::y,center,300,15,"y axis" };

	Mark m1 = { e.focus1(),"x" };
	Mark m2 = { e.focus2(),"x" };

	Point p{ e.center().x,e.center().y - e.minor() };
	Mark m3{ p,"x" };

	Line l1{ e.focus1(),p };
	Line l2{ e.focus2(),p };

	win.attach(e);
	win.attach(x_axis);
	win.attach(y_axis);
	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	win.attach(l1);
	win.attach(l2);

	win.wait_for_button();

	return 0;
}

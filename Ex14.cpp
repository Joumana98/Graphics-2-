#include "Simple_window.h"
#include "Graph.h"

struct Poly :Closed_polyline
{
	Poly(initializer_list<Point> lst);
};


int main()
{
	using namepace Graph_lib;

	Simple_window win{ Point{20,100},800,600,"My canvas" };

	Poly pl{ {100,100},{150,200},{250,250},{300,200} };
	win.attch(pl);

	win.wait_for_button();

	return 0;
}

Poly::Poly(initializer_list<Point> lst)
{
	for (int i = 0; i < lst.size(); i++)
		Polygon::add(lst[i]);
}
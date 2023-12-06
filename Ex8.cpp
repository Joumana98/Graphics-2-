#include "../std_lib_facilites.h"
#include "Simple_window.h"
#include "Graph.h"

struct Regular_polygone :Shape
{
	Regular_polygone(Point center, int r, int s);

	Point center() const;
	int distance_to_corner() const;

private:
	int sides;
	int r;
};

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},600,400,"My canvas" };

	Regular_polyline rgp1 = { Point{100,100},50,6 };
	Regular_polyline rgp2 = { Point{300,300},50,4 };

	win.attach(rgp1);
	win.attach(rgp2);

	win.wait_for_button();

	return 0;
}

Regular_polygone::Regular_polygone(Point center, int rr, int s)
{
	if (s > 2)
		sides = s;
	else
		error("Numbr of regular polygone's sides should be greater than 2.");

	if (rr > 0)
		r = rr;
	else
		error("The distance fro the center to a corner should be positive.");

	double angle = 360.0 / double(s);

	for (int O = angle; O < 360; O += angle)
		add(Point{ center.x + r * cos(O),center.y + r * sin(O) });

}

Point Regular_polygone::center() const
{
	double angle = 360.0 / double(s);
	return Point{ point(0).x - r * cos(angle),point(0).y - r * sin(angle) };
}

int Regular_polygone::distance_to_corner() const
{
	return r;
}
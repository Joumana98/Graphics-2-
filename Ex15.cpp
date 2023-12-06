#include "../std_lib_facilites.h"
#include "Simple_window.h"
#include "Graph.h"

struct Star :Closed_polyline
{
	Star(Point center, int p, int s);

	void draw_lines() const;

private:
	int points;
	int side;
};

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},800,600,"My canvas" };



	return 0;
}

Star::Star(Point center, int p, int s)
{
	if (p > 2)
		points = s;
	else
		error("Number of points in a Star should be greater than 2.");

	if (s > 0)
		side = s;
	else
		error("The side of a Star should be positive.");

	double angle = 360.0 / double(p);

	for (int O1 = angle, int O2 = angle / 2; O1 < 360, O2 < 360; O1 += angle, O2 += angle)
	{
		add(Point{ center.x + r * cos(O1),center.y - r * sin(O1) });
		add(Point{ center.x + r / 2 * cos(O2),center.y - r / 2 * sin(O2) });
	}

}

void Star::draw_lines() const
{
	Closed_polyline::draw_lines();
}
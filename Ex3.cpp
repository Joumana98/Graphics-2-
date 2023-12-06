#include "../std_lib_facilites.h"
#include "Simple_window.h"
#include "Graph.h"

const double PI = 3.14;

struct Arrow :Shape
{
	Arrow(Point p1, Point p2);
	void draw_lines();

private:
	Line ar;
	Open_polyline arrowHead;
};

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},800,600,"My canvas" };

	Arrow arr = { Point{100,400},Point{400,200} };
	win.attach(arr);

	win.wait_for_button();


	return 0;
}

Arrow::Arrow(Point p1, Point p2)
{
	ar = Line{ p1,p2 };
	double length = pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
	double d = 0.1 * length;

	double angle = atan2(p2.y - p1.y, p2.x - p1.x) + PI / 6.0;


	double x1 = p2.x + d * cos(angle - PI / 6.0);
	double y1 = p2.y + d * sin(angle - PI / 6.0);
	double x2 = p2.x + d * cos(angle + PI / 6.0);
	double y2 = p2.y + d * sin(angle + PI / 6.0);

	arrowHead = Open_polyline{ {x1 ,y1 },p2,{x2 , y2} };

}
void Arrow::draw_lines()
{
	ar.draw_lines();
	arrowHead.draw_lines();
}

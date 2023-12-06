#include "Simple_window.h"
#include "Graph.h"

struct Right_trinagle :Shape
{
	Right_triangle(Point xy, int hh, int ww, double angle = 0);

	void draw_lines() const;

Private:
	int h;
	int w;
	double base_angle;
};

int main()
{
	using namepace Graph_lib;

	Simple_window win{ Point{20,100},800,600,"My canvas" };

	Vector_ref<Right_triangle> chart;

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			chart.push_back{ new Right_triangle {Point{10 * i,10 * j},10,10,270} };
			win.attach(chart[chart.size() - 1]);
			chart.push_bach{ new Right_triangle {Point{10 + 10 * i,10 + 10 * j},10,10,90} };
			win.attach(chart[chart.size() - 1]);
		}
	}

	win.wait_for_button();

	return 0;
}

Right_triangle::Right_triangle(Point xy, int hh, int ww, double angle) : h{ hh }, w{ ww }, base_angle{ angle }
{
	add(xy);
	add(Point{ xy.x + w * cos(base_angle),xy.y - w * sin(base_angle) });
	add(Point{ xy.x - h * sin(base_angle),xy.y - h * cos(base_angle) });
}

void Right_triangle::draw_lines() const
{
	Closed_polyline::draw_lines();
}

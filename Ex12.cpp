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
	chart.push_bach(Point{ 400,400 }, 100, 100, 0);
	chart[0].set_color(Color{ 0 });
	win.attach(chart[0]);

	int angle = 45;
	for (int i = 1; i < 8; i++)
	{
		chart.push_bach(chart[chart.size() - 1].point(1), 100, 100, angle);
		chart[chart.size() - 1].set_color(Color{ i });
		win.attach(chart[chart.size() - 1]);
		angle += 45;
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

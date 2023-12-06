#include "../std_lib_facilites.h"
#include "Simple_window.h"
#include "Graph.h"

struct Regular_hexagon :Shape
{
	Regular_hexagon(Point center, int r);

	Point center() const;
	int distance_to_corner() const;
};

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},600,400,"My canvas" };

	Regular_hexagon h = { Point{300,300},50 };
	h.set_color(Color::red);
	h.set_style(Line_style::dash);

	Vector_ref<Regular_hexagon> tiles;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
		{
			tiles.push_back(new Regular_hexagon{ Point{300 + 300 * i,300 + 200 * j},100 });
			win.attach(tiles[tiles.size() - 1]);
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
		{
			tiles.push_back(new Regular_hexagon{ Point{450 + 300 * i,300 - 50 * sqrt(3) + 200 * j},100 });
			win.attach(tiles[tiles.size() - 1]);
		}

	win.wait_for_button();


	return 0;
}

Regular_hexagon::Regular_hexagon(Point center, int r)
{
	double to_y = r * sqrt(3) / 2.0;
	double to_x = r / 2.0;

	add(center.x - r, center.y);
	add(center.x - to_x, center.y - to_y);
	add(center().x + to_x, center().y - to_y);
	add(center().x + r, center.y);
	add(center.x + to_x, center.y + to_y);
	add(center.x - to_x, center.y + to_y);
}

Point Regular_hexagon::center() const
{
	return Point{ point(0).x + 2 * (point(1) - point(0)),point(0).y };
}
int Regular_hexagon::distance_to_corner() const
{
	return 2 * (point(1) - point(0));
}

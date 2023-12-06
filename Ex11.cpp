#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100}800,600,"My canvas" };

	Vector_ref <Rectangle> chart;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			chart.push_back(new Rectangle{ Point{20 * i,20 * j},20,20 });
			chart[chart.size() - 1].set_fill_color(Color{ 16 * i + j });
			chart[chart.size() - 1].set_color(Color::invisible);
			win.attach(chart[chart.size() - 1]);

		}
	}
	win.wait_for_button();


	return 0;
}
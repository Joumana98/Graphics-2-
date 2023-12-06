#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Grah_lib;

	Simple_window win{ Point{20,100},800,600,"My canvas" };

	Circle c{ Point{300,300},150 };

	for (int O = 0; O < 360; O += 10)
	{
		Mark m{ Point{c.center().x + c.radius() * cos(O),c.center().y - c.radius() * sin(O)} };
		win.attach(c);
		win.attach(m);
		win.wait_for_button();
	}
	return 0;
}

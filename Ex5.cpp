#include "Simple_window.h"
#include "Graph.h"

Point n(Circle c)
{
	return Point{ c.point(0).x + c.radius(),c.point(0).y };
}
Point s(Circle c)
{
	return Point{ c.point(0).x + c.radius(),c.point(0).y + 2 * c.radius() };
}
Point e(Circle c)
{
	return Point{ c.point(0).x + 2 * c.radius(),c.point(0).y + c.radius() };
}
Point w((Circle c)
{
	return Point{ c.point(0).x,c.point(0).y + c.radius() };
}
Point center(Circle c)
{
	return c.center();
}
Point ne(Circle c)
{
	return Point{ c.point(0).x,c.point(0).y };
}
Point se(Circle c)
{
	return Point{ c.point(0).x + 2 * c.radius() ,c.point(0).y + 2 * c.radius() };
}
Point sw(Circle c)
{
	return Point{ c.point(0).x,c.point(0).y + 2 * c.radius() };
}
Point nw(Circle c)
{
	return c.point(0);
}

//----------------------------------------------------------------------------------------------------------
Point n(Ellipse e)
{
	return Point{ e.point(0).x + e.major(),e.point(0).y };
}
Point s(Ellipse e)
{
	return Point{ e.point(0).x + e.major(),e.point(0).y + 2 * e.minor() };
}
Point e(Ellipse e)
{
	return Point{ e.point(0).x + 2 * e.major(),e.point(0).y + e.minor() };
}
Point w(Ellipse e)
{
	return Point{ e.point(0).x,e.point(0).y + e.minor() };
}
}
Point center(Ellipse e)
{
	return e.center();
}
Point ne(Ellipse e)
{
	return Point{ e.point(0).x + 2 * e.major(),e.point(0).y };
}
Point se(Ellipse e)
{
	return Point{ e.point(0).x + 2 * e.major(),e.point(0).y + 2 * e.minor() };
}
Point sw(Ellipse e)
{
	return Point{ e.point(0).x,e.point(0).y + 2 * e.minor() };
}
Point nw(Ellipse e)
{
	return e.point(0);
}

//-----------------------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},600,400,"My window" };

	Circle c{ Point{200,200},100 };
	win.attach(c);

	Mark m1{ n(c),"x" };
	Mark m2{ s(c),"x" };
	Mark m3{ e(c),"x" };
	Mark m4{ w(c),"x" };
	Mark m5{ center(c),"x" };
	Mark m6{ ne(c),"x" };
	Mark m7{ nw(c),"x" };
	Mark m8{ se(c),"x" };
	Mark m9{ sw(c),"x" };

	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	win.attach(m4);
	win.attach(m5);
	win.attach(m6);
	win.attach(m7);
	win.attach(m8);
	win.attach(m9);

	Ellipse e{ Point{400,400},100,50 };
	win.attach(e);

	Mark m11{ n(e),"x" };
	Mark m22{ s(e),"x" };
	Mark m33{ e(e),"x" };
	Mark m44{ w(e),"x" };
	Mark m55{ center(e),"x" };
	Mark m66{ ne(e),"x" };
	Mark m77{ nw(e),"x" };
	Mark m88{ se(e),"x" };
	Mark m99{ sw(e),"x" };

	win.attach(m11);
	win.attach(m22);
	win.attach(m33);
	win.attach(m44);
	win.attach(m55);
	win.attach(m66);
	win.attach(m77);
	win.attach(m88);
	win.attach(m99);

	win.wait_for_button();

	return 0;
}

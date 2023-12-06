#include "Simple_window.h"
#include "Graph.h"

Point n(Rectangle rec)
{
	return Point{ rec.point(0).x + rec.width() / 2.0,rec.point(0).y };
}
Point s(Rectangle rec)
{
	return Point{ rec.point(0).x + rec.width() / 2.0,rec.point(0).y + rec.height() };
}
Point e(Rectangle rec)
{
	return Point{ rec.point(0).x + rec.width(),rec.point(0).y + rec.height() / 2.0 };
}
Point w(Rectangle rec)
{
	return Point{ rec.point(0).x,rec.point(0).y + height() / 2.0 };
}
Point center(Rectangle rec)
{
	return Point{ rec.point(0).x + rec.width() / 2.0,rec.point(0).y + rec.height() / 2.0 };
}
Point ne(Rectangle rec)
{
	return Point{ rec.point(0).x + rec.height(),rec.point(0).y };
}
Point se(Rectangle rec)
{
	return Point{ rec.point(0).x + rec.width(),rec.point(0).y + rec.height() };
}
Point sw(Rectangle rec)
{
	return Point{ rec.point(0).x ,rec.point(0).y + rec.height() };
}
Point nw(Rectangle rec)
{
	return rec.point(0);
}

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{20,100},600,400,"My window" };

	Rectangle r{ Point{100,100},200,100 };
	win.attach(r);

	Mark m1{ n(r),"x" };
	Mark m2{ s(r),"x" };
	Mark m3{ e(r),"x" };
	Mark m4{ w(r),"x" };
	Mark m5{ center(r),"x" };
	Mark m6{ ne(r),"x" };
	Mark m7{ nw(r),"x" };
	Mark m8{ se(r),"x" };
	Mark m9{ sw(r),"x" };

	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	win.attach(m4);
	win.attach(m5);
	win.attach(m6);
	win.attach(m7);
	win.attach(m8);
	win.attach(m9);

	win.wait_for_button();

	return 0;
}
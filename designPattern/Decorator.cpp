#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
#if 0
using namespace std;
class Shape
{
public:
	virtual void  draw() = 0;
};
class Rectangle : public Shape
{
public: 
	void draw() { cout << "drawing Rectangle " << endl; }
};
class Circle : public Shape
{
public: 
	void draw() { cout << "drawing Circle " << endl; }
};

class ShapeDecorator :public Shape
{
public:
	Shape* decoratedshape;
	ShapeDecorator(Shape* s):decoratedshape(s) {}
	void draw() { decoratedshape->draw(); }
};
class RedShapeDecorator :public ShapeDecorator
{
public:
	RedShapeDecorator(Shape* p):ShapeDecorator(p){}
	void draw() {
		decoratedshape->draw();
		setBorderColor(decoratedshape);
	}
	void setBorderColor(Shape *s)
	{
		cout << "Setting Border color red " << s << endl;
	}
};
void decoratorDemo()
{
	Shape* circle = new Circle;
	Shape* redCircle = new RedShapeDecorator(new Circle);
	Shape* redRectangle = new RedShapeDecorator(new Rectangle);
	// draw nprmal circle
	circle->draw();
	// draw cicle with red border
	redCircle->draw();
	//draw red rectangle
	redRectangle->draw();
}
#endif
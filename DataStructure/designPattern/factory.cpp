#include "stdafx.h"
#include<iostream>
#if 1
using namespace std;
class Shape { public:	virtual void draw() {} };
class Rectangle :public Shape { void draw() { cout << "draw rectangle" << endl; } };
class Square :public Shape { void draw() { cout << "draw square" << endl; } };
class Circle :public Shape { void draw() { cout << "draw circle" << endl; } };

class ShapeFactory1 {
public:
	Shape* getShape(string s)
	{
		if (s == "circle")
			return new Circle;
		else if (s == "square")
			return new Square;
		else if (s == "rectangle")
			return new Rectangle;
		else return NULL;
	}
};
void FactoryDemo()
{
	Shape *shape = NULL;
	ShapeFactory1* sf = new ShapeFactory1;
	shape = sf->getShape("circle");
	shape->draw();
	shape = sf->getShape("square");
	shape->draw();
}
class Color { public:virtual void draw() {} };
class Red :public Color { public: void draw() { cout << "Red color" << endl; } };
class Green :public Color { public: void draw() { cout << "Green color" << endl; } };
class Blue :public Color { public: void draw() { cout << "Blue color" << endl; } };
class AbstractFactory
{
public:
	virtual	Shape* getShape(string) = 0;
	virtual	Color* getColor(string) = 0;
};
class ShapeFactory :public AbstractFactory
{
public:
	Shape* getShape(string s)
	{
		if (s == "circle")
			return new Circle;
		else if (s == "square")
			return new Square;
		else if (s == "rectangle")
			return new Rectangle;
		else return NULL;
	}
	Color* getColor(string s)
	{
		return NULL;
	}
};
class ColorFactory : public AbstractFactory
{
public:
	Color* getColor(string s)
	{
		if (s == "red")
			return new Red;
		else if (s == "blue")
			return new Blue;
		else if (s == "green")
			return new Green;
		else return NULL;
	}
	Shape* getShape(string s) { return NULL; }
};
class FactoryProducer
{
public:
	AbstractFactory* getFactory(string s)
	{
		if (s == "color")
			return new ColorFactory;
		else if (s == "shape")
			return new ShapeFactory;
		else return NULL;
	}
};
void AbstractFactoryDemo()
{
	FactoryProducer fp;
	AbstractFactory* shapefactory = fp.getFactory("shape");
	Shape* circle = shapefactory->getShape("circle");
	circle->draw();
	AbstractFactory* colorfactory = fp.getFactory("color");
	Color * red = colorfactory->getColor("red");
	red->draw();
}
#endif
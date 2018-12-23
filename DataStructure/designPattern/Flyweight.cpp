#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class Shape
{
public:
	virtual void  draw() = 0;
};

class Circle : public Shape
{
	int x, y, r;
	string color;
public: 
	Circle(string c):color(c),x(0),y(0),r(0){}
	void setXYR(int a, int b, int c) { x = a; y = b; r = c; }
	void draw() { cout << "drawing Circle with color ("<<color<<") "<<" [ " << x << "," << y << "]" << " with radius = " << r << endl; }
};

class ShapeFactory 
{
public:
	static map<string, Shape*> m;
	static Shape* getCircle(string c)
	{
		Shape * s = m[c];
		if (s) return s;
		cout << "Creating circle of color "<<c << endl;
		s = new Circle(c);
		m[c] = s;
		return s;

	}
};
map<string, Shape*> ShapeFactory::m;
void flyweightDemo()
{
	string colors[] =	{ "Red", "Green", "Blue", "White", "Black" };
	for (int i = 0; i < 20; ++i)
	{
		Circle *c = (Circle*)ShapeFactory::getCircle(colors[rand() % 4]);
		c->setXYR(rand()%50, rand()%50, rand() % 10);
		c->draw();
	}
}
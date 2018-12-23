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

class Square : public Shape
{
public:
	void draw() { cout << "drawing Square " << endl; }
};
class ShapeMaker
{
	Shape* circle;
	Shape* square;
	Shape* rectangle;
public:
	ShapeMaker() { circle = new Circle; square = new Square; rectangle = new Rectangle; }
	void DrawCircle() { circle->draw(); }
	void DrawSquare() { square->draw(); }
	void DrawRectangle() { rectangle->draw(); }
};
void facadeDemo()
{
	ShapeMaker s;
	s.DrawCircle();
	s.DrawRectangle();
	s.DrawSquare();
}
#endif
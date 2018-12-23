#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#if 0
using namespace std;
class DrawAPI {public:	virtual void drawCircle(int r, int x, int y) = 0;};
class RedCircle : public DrawAPI {public: 	void drawCircle(int r, int x, int y) { cout << "Drawing red circle radious " << r << " cordinate " << x << " " << y << endl; }};
class GreenCircle : public DrawAPI{public:	void drawCircle(int r, int x, int y) { cout << "Drawing green circle radious " << r << " cordinate " << x << " " << y << endl; }};
class Shape {public:	DrawAPI* drawApi;	Shape(DrawAPI* dapi=NULL) { drawApi = dapi; }	virtual void draw() {}};
class Circle :public Shape
{
private:
	int x, y, r;
public:
	Circle(int x,int y, int r, DrawAPI* drawApi):Shape(drawApi)
	{
		this->x = x; this->y = y; this->r = r;
	}
	void draw()
	{
		drawApi->drawCircle(r,x,y);
	}
};
void bridgeDemo()
{
	Shape* greenCircle = new	Circle(100, 100, 10, new GreenCircle);
	Shape* redCircle = new	Circle(100, 100, 10, new RedCircle);
	redCircle->draw();
	greenCircle->draw();
}
#endif
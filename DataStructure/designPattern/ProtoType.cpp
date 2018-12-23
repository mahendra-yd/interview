// designPattern.cpp : Defines the entry point for the console application.
// create clone item using copy constructor and return don't go for costly operation like db connection or network connection just share resources.
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#if 1
//extern "C"
using namespace std;
class Shape
{
private:
	int id;
protected:
	string type;
public:
	virtual void draw() = 0;
	string getType() { return type; }
	int getID() { return id; }
	void setID(int sid) { id = sid; }
	virtual Shape * clone() = 0;
};
class Rectangle :public Shape 
{
public: 
	Shape* clone() { return new Rectangle(*this); }
	Rectangle(Rectangle& r) { type = r.type; setID(r.getID() + 1); }
	Rectangle() { type = "rectangle"; } 
	void draw() { cout << "draw rectangle" << endl; } 
};
class Square :public Shape
{ 
public: 
	Square(Square& r) { type = r.type; setID(r.getID() + 1); }
	Shape* clone() { return new Square(*this); }
	Square() { type = "square"; }
	void draw() { cout << "draw square" << endl; } 
};
class Circle :public Shape 
{ 
public: 
	Circle(Circle& r) {
		type = r.type; 
		setID(r.getID() + 1); }
	Shape* clone() { return new Circle(*this); }
	Circle() { type = "circle"; }
	void draw() { cout << "draw circle" << endl; } 
};
enum constShape { Erectangle, Esquare, Ecircle };
class ShapeCache
{
public:
	static	std::map<constShape, Shape*> hash;
static	void loadCache()
	{
		Rectangle* re =  new Rectangle;
		Square* sq = new Square;
		Circle* cr =  new Circle;
		re->setID(Erectangle);
		sq->setID(Esquare);
		cr->setID(Ecircle);
		hash[Erectangle] = re;
		hash[Esquare] = sq;
		hash[Ecircle] =cr;
	}
	static	Shape* getShape(constShape shapeId) {
		if (hash.size() == 0)
			loadCache();
		Shape* shape = hash[shapeId];
		return shape->clone();
	}
};

std::map<constShape, Shape*> ShapeCache::hash;
void prototypedemo()
{
	Shape* getClonedShape = ShapeCache::getShape(Ecircle);
	getClonedShape->draw();
	cout<<getClonedShape->getID();
}
#endif
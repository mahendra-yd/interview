#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#if 1
using namespace std;
class Packing
{
public:
	virtual	string pack() = 0;// { return NULL; }
};
class Wrapper :public Packing
{
public:
	string pack() { return "wrapper"; }
};
class Bottle :public Packing
{
public:
	string pack() { return "bottle"; }
};

class Item
{
public:
	virtual string name() = 0;// { return NULL; }
	virtual Packing* packing() = 0;// { return NULL; }
	virtual float price() = 0;// { return 0; }
};
class Burger :public Item
{
public:
	Packing*	packing() { return new Wrapper; }
};
class ColdDrink :public Item
{
public:
	Packing* packing() { return new Bottle; }
};
class VegBurger : public Burger
{
public:
	float price() { return 25.0; }
	string name() { return string("VegBurger"); }
};
class ChickenBurger : public Burger
{
public:
	float price() { return 50.0; }
	string name() { return string("ChickenBurger"); }
};
class Coke :public ColdDrink
{
public:
	float price() { return 30.0; }
	string name() { return string("Coke"); }
};
class Pepsi :public ColdDrink
{
public:
	float price() { return 35.0; }
	string name() { return string("Pepsi"); }
};
class Meal
{
public:
	vector<Item*> items;
	void 	addItem(Item* i) { items.push_back(i); }
	float getCost()
	{
		float p = 0.0;
		for (int i = 0; i < items.size(); i++)
		{
			p += items[i]->price();
		}
		return p;
	}
	void showItem()
	{
		for (int i = 0; i < items.size(); i++)
		{
			cout << "Name :" << items[i]->name() << endl;
			cout << "Packing :" << items[i]->packing()->pack() << endl;
			cout << "Price : " << items[i]->price() << endl << endl;
		}
	}
};
class MealBuilder
{
public:
	Meal prepareVegMeal()
	{
		Meal m;
		VegBurger* vb = new VegBurger;
		m.addItem(vb);
		Coke* ck = new Coke;
		m.addItem(ck);
		return m;
	}
	Meal prepareNonVegMeal()
	{
		Meal m;
		ChickenBurger* cb = new ChickenBurger;
		m.addItem(cb);
		Pepsi* ps = new Pepsi;
		m.addItem(ps);
		return m;
	}
};
void BuilderDemo()
{
	MealBuilder mb;
	Meal vegmeal = mb.prepareVegMeal();
	vegmeal.showItem();
	Meal nonvegmeal = mb.prepareNonVegMeal();
	nonvegmeal.showItem();

}
#endif

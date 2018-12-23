// designPattern.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
#include<list>
using namespace std;
//Memento pattern is used to restore state of an object to a previous state. Memento
//pattern falls under behavioral pattern category.
class Memento
{
	string state;
public:
	Memento(string st) :state(st) {}
	string getState() { return state; }
};
class Originator
{
	string state;
public:
	Originator() {}
	string getState() { return state; }
	void setState(string s) { state = s; }
	Memento* saveStateToMemento() { return new Memento(state); }
	void getStateFromMemento(Memento * m) { state = m->getState(); }
};
class careTaker
{
	vector<Memento*> mlist;
public:
	void add(Memento *m) { mlist.push_back(m); }
	Memento* get(int i) { return mlist[i]; }
};
void Mementodemo()
{
	Originator *o = new Originator;
	careTaker *c = new careTaker;
	o->setState("State #1");
	o->setState("State #2");
	c->add(o->saveStateToMemento());
	o->setState("State #3");
	c->add(o->saveStateToMemento());
	o->setState("State #4");
	cout << "Current State " << o->getState()<<endl;
	o->getStateFromMemento(c->get(0));
	cout << "1st saved State " << o->getState()<<endl;
	o->getStateFromMemento(c->get(1));
	cout << "2nd saved State " << o->getState();

}
void SingletonDemo();
int main()
{
	SingletonDemo();
	//Mementodemo();
	system("pause");
	return 0;
}
	//interpretorDemo();
	//CommandDemo();
	//chainPatternDemo();
	//proxyDemo();
	//flyweightDemo();
	//facadeDemo();
	//decoratorDemo();
	//compositDemo();
	//criteriaDemo();
	//bridgeDemo();
	//creational pattern
	//FactoryDemo();
	//AbstractFactoryDemo();
	//BuilderDemo();
	//prototypedemo();
	//ObjectPoolDemo();
	//AdapterPatternDemo();

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class Order { public:	virtual void execute() = 0; };
class Stock
{
public:
	string name ;
	int qunatity ;
	Stock(string n,int q):name(n),qunatity(q){}
	void buy() 	{		cout << "Stock: Nmae " << name << " Quantity " << qunatity << " baught" << endl;	}
	void sell() 	{		cout << "Stock: Nmae " << name << " Quantity " << qunatity << " sold" << endl;	}
};
class BuyStock :public Order
{
	Stock abcstock;
public:
	BuyStock(Stock a):abcstock(a){}
	void execute() 	{		abcstock.buy();	}
};
class SellStock :public Order
{
	Stock abcstock;
public:
	SellStock(Stock a):abcstock(a){}
	void execute()	{		abcstock.sell();	}
};
class Broker
{
	vector<Order*> orderlist;
public:
	void takeOrder(Order * o) { orderlist.push_back(o); }
	void placeOrder() { for (int i = 0; i < orderlist.size(); i++) orderlist[i]->execute(); orderlist.clear(); }
};
void CommandDemo()
{
	Stock *abc = new Stock("MS",19);
	BuyStock* buyStockOrder = new BuyStock(*abc);
	SellStock *sellStockOrder = new SellStock(*abc);
	Broker * newBroker = new Broker;
	newBroker->takeOrder(buyStockOrder);
	newBroker->takeOrder(sellStockOrder);
	newBroker->placeOrder();
}

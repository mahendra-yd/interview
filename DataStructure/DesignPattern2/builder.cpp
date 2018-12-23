#include"stdafx.h"
#include"Design.h"
class Item
{
public:
    virtual float price()=0;
    virtual string name()=0;
    virtual string packing()=0;
};
class Packing
{
public:
    virtual string packing() = 0;
};
class wrapper :public Packing
{
public:
    string packing() final
    {
        return "wrapper";
    }
};
class bottle :public Packing
{
public:
    string packing() final
    {
        return "bottle";
    }
};
class Burger:public Item
{
public:
    string  packing()
    {
        return new wrapper;
   }
};
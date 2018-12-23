#include "stdafx.h"
#include<iostream>
#include<mutex>
#if 1
using namespace std;
class Singleton
{
	Singleton() = default;// :num(x) {}
	Singleton(const Singleton& s) = delete;// { num = s.num; }
	Singleton& operator=(const Singleton& s) = delete;// { if (this != &s) num = s.num; return *this; }
	static Singleton * instance;
	static std::mutex smutex;
	int num;
public:
	void setNum(int x) { num = x; }
	int getNum() { return num; }
	static	Singleton* getInstance()
	{
		if (instance == NULL)
		{
			smutex.lock();
			if(instance ==NULL)
			instance = new Singleton;
			smutex.unlock();
		}
		return instance;
	}
};
Singleton* Singleton::instance = NULL;
std::mutex Singleton::smutex;
void SingletonDemo()
{
	Singleton * s;
	s = Singleton::getInstance();
	s->setNum(5);
	cout << s->getNum();
	cout << Singleton::getInstance()->getNum();

}

#endif
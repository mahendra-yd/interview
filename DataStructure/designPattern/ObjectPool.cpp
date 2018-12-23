#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
using namespace std;
template <typename T>
class ObjectPool
{
private:
	long expirationTime;
	map<T, long> locked, unlocked;
public:
	static int count;
	ObjectPool() { expirationTime = 30000; }
	virtual T Create() = 0;
	virtual bool validate(T o) = 0;
	virtual void Expire(T o) = 0;
	T CheckOut()
	{
		long now = time(NULL);
		T t;
		if (unlocked.size() > 0)
		{
			map<T, long>::iterator it = unlocked.begin();
			while (it != unlocked.end())
			{
				if (time(NULL) - it->second > expirationTime)
				{
					// remove it from map
					unlocked.erase(it);
					Expire(it->first);
				}
				else
				{
					if (validate(it->first))
					{
						// add to lock
						// remove from unlock
						locked[it->first] = it->second;
						unlocked.erase(it);
						return it->first;
					}
					else
					{
						// remove from unlock
						unlocked.erase(it);
						Expire(it->first);
					}
				}
			}
		}
		// if no element is aviable 
		t = this->Create();
		locked[t] = time(NULL);
		return t;
	}
	void checkIn(T t)
	{
		locked.erase(t);
		unlocked[t]= time(NULL);
	}
};
int ObjectPool<string>::count = 0;

class  ConnectionPool : public ObjectPool<string>
{
private:
	string url, id, pwd;
public:
	string connection;
	ConnectionPool(const string _url,const string _id,const string _pwd) {
		url = _url;
		id = _id;
		pwd = _pwd;
		connection = "";
	}
	string	Create() { count++; connection = url + "/" + id + "/" + pwd + to_string(count);  return connection; }
	void Expire(string s) { s = ""; }
	bool validate(string s) { return s != ""; }

//	string CheckOut() { return NULL; }
};
void ObjectPoolDemo()
{
	ConnectionPool* pool = new ConnectionPool("www.abc.com", "root", "password");
	string s = pool->CheckOut();
	cout << s;
	string s2 = pool->CheckOut();
	cout << s2;
	pool->checkIn(s);
	pool->checkIn(s2);
}
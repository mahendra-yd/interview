#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class Image
{
public:
	virtual void display() {};
};
class RealImage : public Image
{
	string fileName;
public:
	RealImage(string fname) :fileName(fname) { loadFromDisk(fileName); }
	void display() { cout << "Displaying file =" << fileName<<endl; }
	void loadFromDisk(string fileName) { cout << "Loading from disk file " << fileName<<endl; }
};
class ProxyImage :public Image
{
	RealImage* ri;
	string file;
public:
	ProxyImage(string f):file(f),ri(NULL){}
	void display() 
	{
		if (ri == NULL) ri = new RealImage(file);
		ri->display();
	}
};
void proxyDemo()
{
	Image* im = new ProxyImage("file1.jpeg");
	// image will be loaded from disk
	im->display();
	// image will not be loaded
im->display();
}
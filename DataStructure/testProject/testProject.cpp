// testProject.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    int x;
    for (int i = 0; i<T; i++)
    {
        cin >> x;
        int j = 1, k = 0;
        for (; j<x; ++j)
        {
            cout << (j ^ x)<<" ";
            if ((j^x )> x)
                ++k;
        }
        cout << k << endl;
    }
    return 0;
}







#if 0
struct Point {	int x, y;	Point(int a = 0, int b = 0) :x(a), y(b) {}};
struct Line{	Point p, q;	Line(Point a = Point(), Point b = Point()) :p(a), q(b) {}};
struct Square{	Point p;	int r;};
inline int area(Point a, Point b, Point c){	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);}
inline bool left(Point a, Point b, Point c){	return area(a, b, c) > 0;}
inline bool right(Point a, Point b, Point c){	return area(a, b, c) < 0;}
inline bool linear(Point a, Point b, Point c){	return area(a, b, c) == 0;}
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
inline bool liesin(Point a, Point b, Point c)
{
	if (a.x == c.x)
	{
		int x = min(a.y, b.y);
		int y = max(a.y, b.y);
		return (x <= c.y) && (y >= c.y);
	}
	else if(a.y==c.y)
	{
		int x = min(a.x, b.x);
		int y = max(a.x, b.x);
		return (x <= c.x) && (y >= c.x);
	}
	return false;
}
inline bool intersecting(Line l, Line m)
{
	if (linear(l.p, l.q, m.p) && linear(l.p, l.q, m.q))
	{
		if (liesin(l.p, l.q, m.p) || liesin(l.p, l.q, m.q)) return true;
		return false;
	}
	bool x = left(l.p, l.q, m.p); bool y = left(l.p, l.q, m.q);
	if (!(x^y)) return false;
	x = left(m.p, m.q, l.p);  y = left(m.p, m.q, l.q);
	if (!(x^y)) return false;
	return true;
}
inline bool intersectSL(Square s, Line l)
{
	Point p1(s.p.x - s.r, s.p.y - s.r), p2(s.p.x + s.r, s.p.y - s.r), p3(s.p.x + s.r, s.p.y + s.r), p4(s.p.x - s.r, s.p.y + s.r);
	Line l1(p1, p2), l2(p2, p3), l3(p3, p4), l4(p4, p1);
	return intersecting(l1, l) || intersecting(l2, l) || intersecting(l3, l) || intersecting(l4, l);
}
int main()
{// n5000, m50000
	char buf[50];
	int m = 0, n = 0, i = 0, a, b, c, d;
	scanf("%d%d", &n, &m);
	Line l[5000];
	Square s[50000];
	for (i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		l[i].p.x = a; l[i].p.y = b; l[i].q.x = c; l[i].q.y = d;
	}
	for (i = 0; i < m; ++i)
	{
		//scanf("%s", buf); 
		scanf("%d%d%d", &a, &b, &c);
		s[i].p.x = a; s[i].p.y = b; s[i].r = c;
	}
	int j = 0;
	int cx = 0;
	for (i = 0; i<m;++i)
	{
		cx = 0;
		for (j = 0; j < n; ++j)
		{
			if (intersectSL(s[i], l[j]))
				cx++;
		}
		s[i+1].p.x ^= cx; s[i+1].p.y ^= cx;
	}
	std::cout << cx;
}
namespace test1
{
class Base
{
public:
virtual	void show() = 0;
};
class A :public Base
{
	int a;
	std::vector<int> v;
public:
	virtual void show() { std::cout << "valuse of A::a = " << a; }
	A(int x) :a(x) {}
	A(const A& x) { a = x.a; }
	A& operator=(const A& x) { if (this != &x) { a = x.a; }		return *this; }
	A& operator+=(const A& x) { a += x.a; return *this; }
	int operator[](int index) { return v[index]; }
	friend A operator+=(A& l, const A& r) { l += r; return lhs; }
	inline friend	bool operator==(const A& l, const A& r) { return l.a == r.a; }
	inline friend	bool operator!=(const A& l, const A& r) { return !(l == r); }
	inline friend	bool operator<(const A& l, const A& r) { return l.a < r.a; }
	inline friend	bool operator>=(const A& l, const A&r) { return !(l < r); }
	inline friend	bool operator>(const A& l, const A& r) { return r < l; }
	inline friend   bool operator<=(const A& l, const A& r) { return !(l > r); }
};
}
#endif
#include "stdafx.h"
#include <iostream>
using namespace std;
int UsageCounter = 0;
class Node1
{
	long long int  a[1024 * 1024];
public:
	Node1()
	{
		cout << UsageCounter++<<" ";
		Node1 *n1 = new Node1();
		//Node1* n2 = new Node1();
	}
};







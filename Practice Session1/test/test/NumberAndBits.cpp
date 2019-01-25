#include"stdafx.h"
#include<stack>
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
using namespace std;

bool isPalindrom(int num)
{
	stack<int> s;
	int temp = num;
	while (num)
	{
		s.push(num % 10);
		num = num / 10;
	}
	while (temp)
	{
		if (s.top() != temp % 10)
			return false;
		s.pop();
		temp= temp / 10;
	}
	return true;
}


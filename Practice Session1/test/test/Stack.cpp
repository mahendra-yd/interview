#include"stdafx.h"
#include<stack>
#include<iostream>

using namespace std;

void InsertAtBottom(stack<int>&s, int item)
{
	if (s.empty())
	{
		s.push(item);
	}
	else
	{
		int t = s.top(); s.pop();
		InsertAtBottom(s, item);
		s.push(t);
	}
}

void ReverseStack(stack<int>& s)
{
	if (!s.empty())
	{
		int t = s.top(); s.pop();
		ReverseStack(s);
		InsertAtBottom(s, t);
	}
}

void DemoReverseStack()
{
	stack<int> s;
	for (int i = 1; i < 9; i++)
		s.push(i);
	for (int i = 1; i < 9; i++)
	{
		cout << s.top()<<" "; s.pop();
	}
	cout  << endl;
	for (int i = 1; i < 9; i++)
		s.push(i);
	ReverseStack(s);
	for (int i = 1; i < 9; i++)
	{
		cout << s.top()<<" "; s.pop();
	}

}

int main2()
{
	DemoReverseStack();
	//for(int i=0;i<5;i++)
		cout << "\n Welcome Meenakshi"<<endl;
		return 0;
}


#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<stdlib.h>
using namespace std;
/*
http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
http://www.geeksforgeeks.org/the-stock-span-problem/
http://www.geeksforgeeks.org/next-greater-element/
*/
namespace Stack
{
	//http://www.geeksforgeeks.org/print-ancestors-of-a-given-binary-tree-node-without-recursion/
	//http://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
	//http://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
	//http://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
	//http://www.geeksforgeeks.org/iterative-tower-of-hanoi/
	//http://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
	//http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
	int precedence(char t){if (t == '+' || t == '-') return 1;else if (t == '*' || t == '/' || t == '%') return 2;else if (t == '^') return 3;return 0;}
	bool isOperand(char ch) 	{		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');	}
	void infixToPostfix(string &s)
	{
		stack<char>st;
		int i = 0;
		string post="";
		while (i < s.length())
		{
			if (isOperand(s[i])) post.push_back(s[i]); // if operand print
			else if (s[i] == '(')st.push(s[i]); // if ( then push in stack
			else if (s[i] == ')') // if ) pop until get ) and then pop)
			{
				while (!st.empty() && st.top() != '(') { post.push_back((st.top())); st.pop(); }
				if (!st.empty())st.pop();
			}
			else  // if operator check precedence in stack if higher or equel pop until empty or less found
			{
				if (st.empty()) st.push(s[i]);
				else
				{
					while (!st.empty() &&precedence(st.top()) >= precedence(s[i])) { post.push_back(st.top()); st.pop();}
					st.push(s[i]);
				}
			}
			i++;
		}
		// empty stack
		while (!st.empty())
		{
			post.push_back(st.top()); st.pop();
		}
		cout<<post;
	}
	bool isOperator(char t) { return (t == '+' || t == '-' || t == '*' || t == '/' || t == '^'); }
	int evaluatePostfix(char *a)
	{
		stack<int>s;
		int i = 0;
		while (a[i])
		{
			if (!isOperator(a[i]))
			{
				s.push(a[i]-'0');
			}
			else 
			{
				int x = s.top(); s.pop();
				int y = s.top(); s.pop();
				switch (a[i])
				{
				case '+':s.push(x + y); break;
				case '-':s.push(x - y); break;
				case '*':s.push(x * y); break;
				case '/':s.push(x / y); break;
				}

			}
			i++;
		}
		return s.top();
	}
	bool areParenthesisBalanced(char *a)
	{
		if (!a) return true;
		stack<char> s;
		int i = 0;
		while (a[i])
		{
			if (a[i] == '(' || a[i] == '{' || a[i] == '[')s.push(a[i]);
			else if (a[i] == ')') { if (s.top() != '(') return false; s.pop();}
			else if (a[i] == '}') { if (s.top() != '{') return false; s.pop();}
			else if (a[i] == ']') { if (s.top() != '[') return false; s.pop();}
			i++;
		}

		return s.empty();
	}
	void printStack(stack<int> s)
	{
		while (!s.empty()) { cout << s.top() << " "; s.pop(); }
		cout << endl;
	}
	void pushAtBottom(stack<int>& s, int x)
	{
		if (s.empty()) { s.push(x); return; }
		else
		{
			int y = s.top(); s.pop();
			pushAtBottom(s, x);
			s.push(y);
		}
	}
	void reverseStack(stack<int>& s)
	{
		if (!s.empty())
		{
			int a = s.top(); s.pop();
			reverseStack(s);
			pushAtBottom(s, a);
		}
	}
	void insertSorted(stack<int>& s, int x)
	{
		if (s.empty() || s.top() < x) { s.push(x); return;	}
		int y = s.top(); s.pop();
		insertSorted(s, x);
		s.push(y);
	}
	void sortStack(stack<int>& s)
	{
		if (!s.empty())
		{
			int x = s.top(); s.pop();
			sortStack(s);
			insertSorted(s, x);
		}
	}
	class QStack
	{/*implement stack using two queue*/
	public:
		queue<int> q1, q2;
		void push(int x)
		{
			if (q1.empty()) { q1.push(x); while (!q2.empty()) { q1.push(q2.front()); q2.pop(); } }
			else if (q2.empty()) { q2.push(x); while (!q1.empty()) { q2.push(q1.front()); q1.pop(); } }
		}
		void pop()
		{
			if (!q1.empty()) q1.pop();
			if (!q2.empty()) q2.pop();
			return;
		}
		int top()
		{
			if (!q1.empty()) { return q1.front();  }
			else if (!q2.empty()) { return q2.front(); }
		}
	};
	struct node { int data; struct node* next; struct node* prev; };
	node* newNode(int x) { node* t = new node; t->data = x; t->next = t->prev = NULL; return t; }
	class SStack
	{// implement mid in O(1) and all other too using link list
	public:
		node* top;
		node* middle;
		int size;
		SStack() { size = 0; top = NULL; middle = NULL; }
		void push(int x)
		{
			size++;
			node* t = newNode(x);
			t->next = top;
			if (size == 1)	middle = t;
			else
			{
				top->prev = t;
				if(size&1)
				middle = middle->prev;
			}
			top = t;
		}
		int Top()
		{
			if (size>0) 
				return top->data;
			return -1;
		}
		int pop()
		{
			if (size <= 0) return -1;
			size--;
			int x = top->data;
			top = top->next;
			top->prev = NULL;
			if (size & 1)middle = middle->next;
			return x;
		}
		int getMiddle()
		{
			if (middle)return middle->data;
		}
		void deleteMiddle()
		{
			middle->prev->next = middle->next;
			middle->next->prev = middle->prev;
		}
	};
	void towerHanoi(char a, char b, char c, int n)
	{
		if (n > 0)
		{
			towerHanoi(a,c,b,n-1);
			cout << "move  " << n << "disk from " << a << " to " << c << endl;
			towerHanoi(b,a,c,n-1);
		}
	}
}
/*
using namespace Stack;
int main()
{
	int n = 4;
	int id = findCelebrity(n);
	id == -1 ? cout << "No celebrity" :
		cout << "Celebrity ID " << id;
	system("pause");
}
*/
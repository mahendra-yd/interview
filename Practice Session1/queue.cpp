#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
using namespace std;
//http://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/
//http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
namespace Queue
{
	struct petrolPump
	{
		int petrol;
		int distance;
	};
	int printTour1(petrolPump a[], int n)
	{
		queue<petrolPump>q;
		int c = 0;
		int i = 0;
		int p = 0;
		petrolPump x;
		while (c != n )
		{
			q.push(a[i]);
			p += (a[i].petrol - a[i].distance);
			i = (i + 1) % n;
			c++;
			while (!q.empty() && p < 0) 
			{ 
				x = q.front(); q.pop(); 
				c--; 
				p = p -x.petrol + x.distance; 
			}
		}
		
		while (!q.empty())
		{
			x = q.front(); q.pop();
			cout << " [ " << x.petrol << "," << x.distance << " ]" << " ";
		}
		return i+1;
	}
	int printTour(struct petrolPump arr[], int n)
	{
		int start = 0;
		int end = 1;
		int curr_petrol = arr[start].petrol - arr[start].distance;
		while (end != start || curr_petrol < 0)
		{
			while (curr_petrol < 0 && start != end)
			{
				curr_petrol -= arr[start].petrol - arr[start].distance;
				start = (start + 1) % n;
					if (start == 0)
					return -1;
			}
			curr_petrol += arr[end].petrol - arr[end].distance;
			end = (end + 1) % n;
		} 
		return start;
	}
	void generatePrintBinary(int n)
	{
		if (n <= 0 )return;
		queue<string>q;
		q.push("1");
		for (int i = 0; i < n; i++)
		{
			string s = q.front(); q.pop();
			cout << s << endl;
			string s1 = s + "0";
			q.push(s1);
			s1 = s + "1";
			q.push(s1);
		}
	}
	int comp1(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }
	int comp2(const void* a, const void* b) { return (*(int*)b) - (*(int*)a); }

	int findMaxMultupleOf3(int a[], int n)
	{
		qsort(a, n-1, sizeof(int),comp1);
		queue<int>q0, q1, q2;
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			switch (a[i] % 3)
			{
			case 0:q0.push(a[i]); break;
			case 1:q1.push(a[i]); break;
			case 2:q2.push(a[i]); break;
			}
			s += a[i];
		}
		switch (s % 3)
		{
			case 0: break;
			case 1: {if (!q1.empty()) { q1.pop();  }
					else if (q2.size() >= 2) {  q2.pop(); q2.pop(); }
					else return -1;
		} break;
			case 2: {if (!q2.empty()) { q2.pop();  } else if (q2.size() >= 2) { q1.pop(); q1.pop(); } else return -1; } break;
		}
		int i = 0;
		while (!q0.empty()) { a[i++] = q0.front(); q0.pop();}
		while (!q1.empty()) { a[i++] = q1.front(); q1.pop(); }
		while (!q2.empty()) { a[i++] = q2.front(); q2.pop(); }
		n = i;
		qsort(a, n , sizeof(int), comp2);
		for (i = 0; i < n; i++)
			cout << a[i];
		cout << endl;
		return 1;
	}
	struct Node
	{
		int data;
		struct Node *prev, *next;
	};
	Node* newNode(int n)
	{
		Node  *t = new Node;
		t->prev = t->next = NULL;
		t->data = n;
		return t;
	}
	struct Queue
	{
		int size;
		int count;
		Node *front;
		Node *rear;
		bool isEmpty() { return count == 0; }
		bool isFull() { return size == count; }
		Queue(int n) { front = rear = NULL; count = 0; size = n; }
		void print()
		{
			Node *t = rear;
			for (int i = 0; i<count; i++) { cout << t->data << " "; t = t->next; }
			cout << endl;
		}
		Node* insert(int n)
		{
			Node *t;
			if (count == size) // queue is full need to remove last element and insert new
			{
				t = rear;
				rear = rear->next;
				rear->prev = NULL;
				t->data = n;
				t->prev = front;
				front->next = t;
				front = t;
			}
			else
			{
				t = newNode(n);
				t->prev = front;
				if (front != NULL)
					front->next = t;
				front = t;
				if (rear == NULL)
					rear = front;
				count++;
			}
			return t;
		}
		void update(Node *t)
		{
			if (t == front) return;
			else if (t == rear)
			{
				t = rear;
				rear = rear->next;
				rear->prev = NULL;
				t->prev = front;
				front->next = t;
				front = t;
			}
			else
			{
				t->prev->next = t->next;
				t->next->prev = t->prev;
				t->prev = front; front->next = t; front = t;
			}
		}
	};
	int refernce(map<int, Node*> &m, Queue &q, int page)
	{
		map<int, Node*>::iterator it;
		it = m.find(page);
		if (it == m.end()) { Node*t = q.insert(page); m[page] = t; return t->data; } // page was not in cache
		else
		{
			q.update(it->second);
			return it->second->data;
		}
	}

	void LRU()
	{
		Queue q(4);
		map<int, Node*>m;
		cout << refernce(m, q, 1) << " ";
		q.print();
		cout << refernce(m, q, 2) << " ";
		q.print();
		cout << refernce(m, q, 3) << " ";
		q.print();
		cout << refernce(m, q, 1) << " ";
		q.print();
		cout << refernce(m, q, 4) << " ";
		q.print();

		cout << refernce(m, q, 6) << " ";
		q.print();
		cout << refernce(m, q, 7) << " ";
		q.print();
	}

}
/*
using namespace Queue;

int main()
{
	int arr[] = { 8, 1, 7, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	if (findMaxMultupleOf3(arr, size) == 0)
		printf("Not Possible");

	system("pause");
}
*/
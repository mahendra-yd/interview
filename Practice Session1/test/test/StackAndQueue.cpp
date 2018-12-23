#include "stdafx.h"
#include<assert.h>
#include<iostream>
#include "Stack.h"
using namespace std;

template <class T>
class Stack
{
	struct Node
	{
		T data;
		struct Node * next;
		Node(T data)
		{
			this->data = data;
			this->next = NULL;
		}
	};
	Node *_top;

public:
	Stack()
	{
		_top = NULL;
	}
	void push(T data) { Node* t = new Node(data); t->next = _top; _top = t; }
	void pop() { _top = _top->next; }
	T top() { return _top->data; }
	bool isEmpty() { return _top == NULL; }
};

template <class T>
class Queue
{
	struct Node
	{
		T data;
		struct Node * next;
		Node(T data)
		{
			this->data = data;
			this->next = NULL;
		}
	};
	struct Node *head, *tail;
public:
	Queue()
	{
		head = tail = NULL;
	}
	void push(T data)
	{
		Node* t = new Node(data);
		if (tail) { tail->next = t; }
		else
			head = t;
		tail = t;
	}
	void pop() {
		assert(head != NULL);
		head = head->next;
		if (!head) 
			tail = NULL;
	}
	T front() { assert(head != NULL); return head->data; }
	bool isEmpty() { return head == NULL; }
};

void StackDemo()
{
	Stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	std::cout << s.top() << std::endl;
	std::cout << s.isEmpty() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	s.pop();
	std::cout << s.isEmpty() << std::endl;
	s.push(1);
	std::cout << s.top() << std::endl;
}


void DemoQueue()
{
	Queue<int> q;
	q.push(1);
	q.pop();
	std::cout << q.isEmpty() << std::endl;;
	q.push(2);
	q.push(3);
	std::cout << q.front() << std::endl;;
	q.push(4);
	std::cout << q.front() << std::endl;;
}


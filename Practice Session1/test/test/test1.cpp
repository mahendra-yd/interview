#include "stdafx.h"
#include "test1.h"
#include <iostream>
#include<vector>
#include <iomanip>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<assert.h>
#include<stack>
using namespace std;
int findMaxContainer(vector<int>&v)
{
	int m = 0, lmax;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			int min = v[i] < v[j] ? v[i] : v[j];
			if (m < min*(j - i))
				m = min * (j - i);
		}
	}
	return m;
}

int findMaxContainer1(vector<int>&v)
{
	int l = 0, r = v.size() - 1;
	int sum = 0;
	while (l < r)
	{
		sum = max(sum, min(v[l], v[r])*(r - l));
		if (v[l] < v[r])
			l++;
		else
			r--;
	}
	return sum;
}
bool strmatch(string s, string p)
{
	if (s.empty()) return  p.empty();
	if (s.empty())
	{
		for (auto a : p)
		{
			if (a != '*')
				return false;
		}
		return true;
	}

	if (p[0] == '?'||p[0] == s[0])
		return strmatch(s.substr(1), p.substr(1));
	else if (p[0] == '*')
		return strmatch(s, p.substr(1)) || strmatch(s.substr(1), p);
	else
		return false;
}
bool strmatchDP(string s, string p)
{
	
	int sl = s.length(), pl = p.length();
	if (sl == 0) return pl == 0;
	vector<vector<bool>> m(sl+1, vector<bool>(pl+1,false));
	m[0][0] = true;
	for (int i = 1; i <= sl; i++)
	{
		m[i][0] = false;
	}
	for (int i = 1; i <= pl; i++)
	{
		m[0][i] = m[0][i - 1] && p[i-1] == '*';
	}
	for (int i = 1; i <= sl; i++)
	{
		for (int j = 1; j <= pl; j++)
		{
			if (p[j] == '?' || p[j] == s[i])
				m[i][j] = m[i - 1][j - 1];
			else if (p[j] == '*')
				m[i][j] = m[i][j - 1] || m[i - 1][j];
		}
	}


	return m[sl][pl];
}

void Patternmatch()
{
	string str[] = { "baaabab" };
	string pattern[] = { "*****ba*****ab", "ba*****ab" ,"ba*ab" ,"a*ab","a*****ab","*a*****ab",
	"ba*ab****","****","*","aa?ab","b*b","a*a","baaabab","?baaabab","*baaaba*" };

		for (auto p : pattern)
		{
if (strmatch(str[0], p) && strmatchDP(str[0], p))
cout << str[0] << " match " << p << " Yes " << endl;
else
cout << str[0] << " match " << p << " No " << endl;
		}

}

char* convert(const char* input)
{
	if (NULL == input)
	{
		return NULL;
	}
	const char * ptr = input;
	int numberOfdots = 0;
	int len = 0;
	while (ptr[len] != '\0')
	{
		if (ptr[len] == '.')
			numberOfdots++;
		len++;
	}

	char * output = (char*)malloc(len + numberOfdots + 1);
	memset(output, 0, len + numberOfdots + 1);
	ptr = input;
	int counter = 0;
	int i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '.')
		{
			output[counter++] = ':';
			output[counter++] = ':';
			i++;
		}
		else
		{
			output[counter++] = input[i++];
		}
	}
	output[counter++] = '\0';
	return output;

}

void convertDemo()
{
	const char *input[] = { "a.b.c","a." ,".b" ,"." ,"a","abc","...." };
	const char *output[] = { "a::b::c", "a::" ,"::b" ,"::","a","abc" ,"::::::::" };
	int len = sizeof(input) / sizeof(input[0]);
	for (int i = 0; i < len; i++)
	{
		if (strcmp(convert(input[i]), output[i]) != 0) {
			cout << "Invalid result for " << input[i] << endl;
		}
	}
	cout << "Done" << endl;
}

typedef struct _node
{
	_node(int info)
	{
		this->info = info;
		this->next = NULL;
		this->left = NULL;
		this->right = NULL;
	}
	_node* operator++(int)
	{
		return this->next;
	}
	int info;
	struct _node *next;
	struct _node *left;
	struct _node *right;

}Node;


class List
{
	Node * root;
public:
	int size;
	List()
	{
		root = NULL;
		size = 0;
	}
	List(Node* l)
	{
		root = l;
		int count = 0;
		while (l) { count++; l = l->next; }
		size = count;
	}
	List(initializer_list<int> list)
	{
		root = NULL;
		for (auto item : list)
		{
			insert(item);
		}

	}
	List(const List& l)
	{
		root = NULL;
		Node* temp = l.root;
		while (temp)
		{
			insert(temp->info);
			temp = temp->next;
		}
	}
	void insert(int data)
	{
		size++;
		
		if (NULL == root)
			root= new Node(data);
		else
		{
			Node* temp = root;
			while (NULL != temp->next)
				temp = temp->next;
			temp->next = new Node(data);
		}
	}

	List& insertSorted(const List& l)
	{
		Node* temp = l.root;
		while (temp)
		{
			insertSorted(temp->info);
			temp = temp->next;
		}
		return *this;
	}

	List& insertSorted(int data)
	{
		size++;
		if (NULL == root)
			root = new Node(data);
		else
		{
			Node* temp = root;
			while (temp->info < data && NULL != temp->next )
				temp = temp->next;
			if (NULL == temp->next && temp->info < data)
			{
				temp->next = new Node(data);
			}
			else
			{
				Node* p = temp->next;
				int tempdata = temp->info;
				temp->info = data;
				temp->next = new Node(tempdata);
				temp->next->next = p;

			}
		}
		return *this;
	}

	void printList()
	{
		Node* temp = root;
		while (temp)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	Node* GetHead() { return root; }

	void Reverse()
	{
		Node* p, *q, *r;
		p = root;
		q = p->next;
		p->next = NULL;
		while (q)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		root = p;

	}

	bool operator==(List& l)
	{
		Node* h1 = this->root, *h2 = l.root;
		while (h1&&h2)
		{
			if (h1->info != h2->info)
				return false;
			h1 = h1->next;
			h2 = h2->next;
		}
		return h1 == NULL && h2 == NULL;
	}
	bool isPalindrome()
	{
		List l = *this;
		l.Reverse();
		return *this == l;
	}
};



void BstTOsortedList(Node* root, List& list)
{
	if (!root) return;
	BstTOsortedList(root->left, list);
	list.insert(root->info);
	BstTOsortedList(root->right, list);
}

Node* insertIntoBST(Node* root,int info)
{
	if (NULL == root)
		return new Node(info);
	else if (root->info > info)
		root->left = insertIntoBST(root->left, info);
	else
		root->right = insertIntoBST(root->right, info);
	return root;
}

/*

Simple merge 
1- create copy of first list
2- iterate through remaing list
3- inset each item of list into first list in sorted order 
## inserting in list in sorted order will be O(n2)

*/
List* merge(vector<List> lists)
{
	List* result = new List(lists[0]);
	for (int i = 1; i < lists.size(); i++)
	{
		result->insertSorted(lists[i]);
	}
	return result;

}

/*
Merge Using BST tree
1- cunstruct emptry BST
2- iterate to all list and insert items into BST
3- convert bst to list
4- return list
## inserting in list in sorted order will be O(nlogn)

*/
List merge2(vector<List> lists)
{
	List result;
	Node* root = NULL;

	for (auto item : lists)
	{
		Node* ptr = item.GetHead();
		while (ptr)
		{
			root = insertIntoBST(root,ptr->info);
			ptr = ptr->next;
		}
	}

	BstTOsortedList(root, result);
	return result;

}


void MergeListDemo()
{
	List l1 = { 11,55,90,111 };
	List l2 = { 1,3,7,50 };
	List l3 = { 6,8,35,455 };
	List l4 = { 61,67,135,235 };

	vector<List> lists = { l1,l2,l3,l4 };

	List* ll = merge(lists);
	ll->printList();
	List l = merge2(lists);
	l.printList();
}

void PrintStringPermutation(string s, string prefix="")
{
	int len = s.length();
	if (len == 0) cout << prefix << endl;
	for (int i = 0; i < len; i++)
	{
		string str = s.substr(0, i) + s.substr(i + 1, len);
		PrintStringPermutation(str, prefix + s[i]);
	}

}

void RotateMatrix(vector<vector<int>> & m)
{
	//vector<vector<int>> m = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = m.size();
	for (int layer = 0; layer < n / 2; layer++)
	{
		int first = layer, last = n - layer - 1;
		for (int i = first; i < last; ++i)
		{
			int temp = m[first][i];
			//m[first][i] = m[last - i][first];
			//m[last - i][first] = m[last][last - i];
			//m[last][last - i] = m[i][last];
			//m[i][last] = temp;

			m[first][i] = m[last-i][first];
			m[last-i][first] = m[last][last-i];
			m[last][last-i] = m[i][last];
			m[i][last] = temp;
		}
	}
}

void PrintMatrix(vector<vector<int>> & m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
			cout<<setw(3) << m[i][j];
		cout << endl;
	}

}
void SetZeroInMatrix(vector<vector<int>> & m)
{
	//vector<vector<int>> m = { {1,0,0,1},{0,0,1,0},{0,0,0,0}};

	map<int, bool> mapr;
	map<int, bool> mapc;
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
			if (m[i][j] == 1)
			{
				mapr[i] = mapc[j] = true;
			}
	}


	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
			if (mapr[i]|| mapc[j])
			{
				m[i][j] = 1;
			}
	}
}


void SetZeroInMatrixWithoutStorage(vector<vector<int>> & m)
{
	//vector<vector<int>> m = { { 0,1,1,0 },{ 1,1,0,1 },{ 1,1,1,1 } };
	
	bool fRowHasZero = false, fColHasZero = false;
	int row=m.size(), col= m[0].size();

	for (int i = 0; i < col; i++)
		if (m[0][i] == 0)
		{
			fRowHasZero = true;
			break;
		}
	for (int i = 0; i < row; i++)
		if (m[i][0] == 0)
		{
			fColHasZero = true;
			break;
		}
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (m[i][j] == 0)
			{
				m[i][0] = 0;
				m[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (m[i][0] == 0 || m[0][j]==0)
			{
				m[i][j] = 0;
			}
		}
	}

	if (fRowHasZero)
	{
		for (int i = 0; i < col; i++)
			m[0][i] = 0;
	}

	if (fColHasZero)
	{
		for (int i = 0; i < row; i++)
			m[i][0] = 0;
	}

}

void RemoveDuplicateFromList_N(Node* start)
{
	set<int> s;
	Node* p=NULL;
	while (start)
	{
		if (s.find(start->info) == s.end())
		{
			p = start;
			s.insert(start->info);
		}
		else
		{
			p->next = start->next;
		}
		start = start->next;
	}
}

void RemoveDuplicateFromList_N2(Node* start)
{
	Node* current = start;
	Node* runner = NULL;
	while (current)
	{
		runner = current->next;
		Node* prev=current;
		while (runner)
		{
			if (current->info == runner->info)
			{
				prev->next = runner->next;
			}
			else
			{
				prev = runner;
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

int PrintLastKthElemenet_R(Node* start, int k)
{
	int count = 0;
	if (start)
	{
		count = PrintLastKthElemenet_R(start->next, k)+1;
		if (count<=k) 
		{
			cout << start->info << " ";
		}
	}
	return count;

}

void PrintLastKthElemenet_I(Node* start, int k)
{
	Node* s=start, *p=start;
	for (int i = 0; i < k; i++)
		s = s->next;
	while (s)
	{
		p = p->next;
		s = s->next;
	}
	while (p)
	{
		cout << p->info << " ";
		p = p->next;
	}
}

bool DeleteNodeFromMiddle(Node *ptr)
{
	if (ptr == NULL || ptr->next == NULL)
		return false;
	Node* t = ptr->next;
	ptr->info = ptr->next->info;
	ptr->next = ptr->next->next;
	free(t);
}
//Stable Order is maintained
Node* PartitationList(Node* start, int n)
{
	Node* first = new Node(-1);
	Node*f = first;
	Node* last = new Node(-2);
	Node*l = last;
	while (start)
	{
		if (start->info < n)
		{
			first->next = start;
			first = start;
		}
		else
		{
			last->next = start;
			last = start;

		}
		start = start->next;
	}
	first->next = l->next;
	last->next = NULL;

	return f->next;
	
}

//Stable Order is maintained
Node* PartitationList2(Node* start, int n)
{
	Node* head=start, *tail=start;
	while (start)
	{
		Node* next = start->next;
		if (start->info < n)
		{
			start->next = head;
			head = start;
		}
		else
		{
			tail->next = start;
			tail = start;

		}
		start=next;
	}
	tail->next = NULL;
	return head;
}

Node* SumOfList(Node*l1, Node*l2)
{
	Node* l = NULL;
	Node*start=NULL;
	int sum = 0, carry = 0;
	while (l1&&l2)
	{
		sum = l1->info + l2->info+ carry;
		carry = sum / 10;
		sum = sum % 10;
		Node* p = new Node(sum);
		if (start == NULL)
			start = p;
		else
			l->next=p;
		l = p;
		l1 = l1->next; l2 = l2->next;
	}

	while (l1)
	{
		sum = l1->info +carry;
		carry = sum / 10;
		sum = sum % 10;
		Node* p = new Node(sum);
		if (start == NULL)
			start = p;
		else
			l->next = p;
		l = p;

		l1=l1->next;
	}

	while (l2)
	{
		sum = l2->info + carry;
		carry = sum / 10;
		sum = sum % 10;
		Node* p = new Node(sum);
		if (start == NULL)
			start = p;
		else
			l->next = p;
		l = p;

		l2 = l2->next;
	}

	return start;
}
void DemoQueue();
#pragma warning(disable : 4996).

#define MAXWORD 100
#define MAXSTRING 10000

void WordCount()
{
	/*Decalaration */
	char *wordArray[MAXWORD] = { 0 };
	int count[MAXWORD] = {0};
	char inputString[MAXSTRING];
	int wordCount=0;
	/*Reading data from input stream*/
	fgets(inputString, sizeof(inputString), stdin);
	/*Remove trailing new line char*/
	inputString[strlen(inputString) -1] = 0;

	/*Init string tokenizer*/
	char *wordPointer = strtok(inputString, " ");
	while (wordPointer)
	{
		int len = strlen(wordPointer);
		int found = 0;
		for (int i = 0; i < wordCount; i++)
		{
			/*check if word already processed then incrment word count*/
			if (strncmp(wordArray[i], wordPointer, len)==0)
			{
				count[i]++;
				found = 1;
				break;
			}

		}
		if (!found)
		{
			/*Allocate memory for string and copy for future comparision*/
			wordArray[wordCount] = (char*)malloc(len + 1);
			strncpy(wordArray[wordCount], wordPointer, len);
			wordArray[wordCount][len] = 0;
			count[wordCount]++;
			wordCount++;
		}
		wordPointer = strtok(NULL, " ");
	}

	/* print words and their frequency*/
	for (int i = 0; i < wordCount; i++)
	{
		printf("%s - %d \n", wordArray[i], count[i]);
	}
}

template <class T>
class MultipleStackinArray
{
	int stackCount, totalsize;
	T * data;
	int * next;
	int *top;
	int nextSlot = 0;
	int*prev;

public:
	MultipleStackinArray(int stackCount, int totalSize) :stackCount(stackCount), totalsize(totalSize)
	{
		data = new (nothrow)T[totalsize];
		next = new (nothrow)T[totalsize];
		prev = new (nothrow)T[totalsize];
		top = new (nothrow)int [stackCount] {0};
		int i = 0;
		for ( ; i < totalSize; i++)
		{
			data[i] = 0;
			next[i] = i + 1;
			prev[i] = i - 1;
		}
		next[i] = -1;
		prev[i] = i - 1;

		for (int i = 0; i < stackCount; i++)
		{
			top[i] = -1;
		}
	}

	void push(int s, T info){
		assert(nextSlot != -1);
		int loc = nextSlot;
		nextSlot = next[nextSlot];
		prev[loc] = top[s];
		top[s] = loc;
		data[loc] = info;
	}
	void pop(int s){
		assert(top[s] != -1);
		int loc = top[s];
		next[loc] = nextSlot;
		nextSlot = loc;
		top[s] = prev[loc];
	}
	T Top(int s) { assert(top[s] != -1); return data[top[s]]; }
	bool isEmpty(int s) { return top[s] == -1; }
};
void DemoMultipleStackinArray()
{
	MultipleStackinArray<int> a(3, 9);
	a.push(0, 0);
	a.push(1, 1);
	a.push(1, 2);

	a.push(1, 3);
	a.push(1, 4);
	a.push(1, 5);

	a.push(2, 6);
	a.push(2, 7);
	a.push(2, 8);

	a.pop(1);
	cout << a.Top(0) << endl;
	cout << a.Top(1) << endl;
	cout << a.Top(2) << endl;
	a.pop(0);
	a.pop(1);
	a.pop(2);

	//cout << a.Top(0) << endl;
	cout << a.Top(1) << endl;
	cout << a.Top(2) << endl;

	a.push(0, 9);
}

template <class T>
class Minstack1
{
public:
	stack<T> data;
	stack<T>min;
	int minvalue = INT16_MAX;
	void push(T info) {
		data.push(info); 
		if (min.empty()||info < min.top()) { min.push(info); }
	}
	void pop() { int d = data.top(); data.pop(); if(d==min.top()) min.pop(); }
		T top() { return data.top(); }
		T Min() { return min.top(); }
};

template <class T>
class MinStack
{
public:
	stack<T> data;
	int min=INT_MAX;
	void push(T info) { 
		if (data.empty() || info > min) {
			if(data.empty())
				min = info; 
			data.push(info);
		}
		else {
			data.push(2 * info - min); min = info;
		}
	}
	void pop() { 
		int info = data.top();
		data.pop();
		if (info < min) {
			min = 2 * min - info; 
		}  
	}
	T top() { if (data.top() > min) return data.top(); else return min; }
	T Min() { return min; }
	bool isEmpty() { return data.empty(); }
};

void SortStack(stack<int>&s)
{
	stack<int> temp;
	while (!s.empty())
	{
		int t = s.top(); s.pop();
		while (!temp.empty() && t < temp.top()) { s.push(temp.top()); temp.pop(); }
		temp.push(t);
	}
	while (!temp.empty())
	{
		s.push(temp.top()); temp.pop();
	}
}


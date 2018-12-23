#if 0
// DataStructure.cpp : Defines the entry point for the console application.
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "DataStructure.h"
#include<queue>
#include<deque>
#include<map>
#include<string>
#include<stack>
#include <iomanip>
using namespace std;
typedef struct node
{
	int info;
	char cinfo;
	string sinfo;
	int lis;
	struct node *left, *right, *parrent,*nextRight,*nextInOrder;
	bool isThreaded;
}Node;
Node* newNode(int x)
{
	Node* t = new Node;
	t->left = t->right = t->parrent = t->nextRight = t->nextInOrder= NULL;
	t->info = x;
	t->lis = 0;
	t->isThreaded = false;
	return t;
}
Node* newNode(string s)
{
	Node* t = new Node;
	t->left = t->right = t->parrent = t->nextRight = t->nextInOrder= NULL;
	t->lis = 0;
	t->sinfo = s;
	t->isThreaded = false;
	return t;
}
Node* newNode(char  x)
{
	Node* t = new Node;
	t->left = t->right = t->parrent = t->nextRight = t->nextInOrder= NULL;
	t->cinfo = x;
	t->lis = 0;
	t->isThreaded = false;
	return t;
}
void printPreOrder(Node* t)
{
	if (!t) return;
	cout << t->info<<" ";
	printPreOrder(t->left);
	printPreOrder(t->right);
}
void printInOrder(Node* t)
{
	if (!t) return;
	printInOrder(t->left);
	cout << t->info<<" ";
	printInOrder(t->right);
}
void printPrintTree(Node* t)
{
	if (!t) return;
	printPrintTree(t->left);
	printPrintTree(t->right);
	cout << t->info<<" ";
}
inline int MAX(int a, int b) { return a > b?a : b; }
int height(Node* t) { if (!t) return 0; return 1 + MAX(height(t->left), height(t->right)); }
void printNodesAtLevel(Node* t, int l)
{
	if (!t)return;
	if (l == 1) cout << t->info << " ";
	printNodesAtLevel(t->left, l - 1);
	printNodesAtLevel(t->right, l - 1);
}

void printLevelOrder(Node* t)
{
	if (!t)return;
	int h = height(t);
	for (int i = 1; i <= h; i++)
		printNodesAtLevel(t, i);
}
void printLevelOrderQ(Node* t)
{
	if (!t) return;
	queue<Node*> q;
	q.push(t);
	int h = 0;
	while (!q.empty())
	{
		int l = q.size();
		h++;
		while (l--)
		{
			t = q.front(); q.pop();
			cout << t->info << " ";
			if (t->left)q.push(t->left);
			if (t->right)q.push(t->right);
		}
		cout << endl;
	}
	cout << "Height of tree is " << h<<endl;
	//return h;
}
void Inorder(Node* t)
{
	if (!t) return;
	stack<Node*> s;
	label:	
	while(t){s.push(t); t = t->left;}
	while (!s.empty())
	{
		t = s.top(); s.pop();
		cout << t->info << " ";
		if (t->right) { t = t->right; goto label; }
	}
}
void Inorder1(Node* t)
{
	if (!t)return;
	stack<Node*> s;
	while (true)
	{
		if (t) { s.push(t); t = t->left; }
		else if (!s.empty()) { t = s.top(); s.pop(); cout << t->info << " "; if (t->right) t = t->right; else t = NULL; }
		else break;
	}
}
void PreOrder(Node* t)
{
	if (!t) return;
	stack<Node*> s;
	s.push(t);
	while (!s.empty())
	{
		t = s.top(); s.pop();
		cout << t->info << " ";
		if (t->right)s.push(t->right);
		if (t->left)s.push(t->left);
	}
}
void PrintPostOrder1(Node* t)
{
	if (!t) return;
	stack<Node*> s;
	// push right child and then parrent and move to left child untill left is null
label:	while (t) {if (t->right)s.push(t->right);  s.push(t); t = t->left; }
	while (!s.empty()) {
		// pop the item if its right child is stack top remove from stack push current in stack move t to right child
		t = s.top(); s.pop(); if (!s.empty() && t->right == s.top()) { s.pop(); s.push(t); t = t->right; goto label; }
		cout << t->info << " ";
	}
}
void PrintPostOrder(Node* t)
{
	if (!t) return;
	stack<Node*> s;
	while (true)
	{
		if (t) { if (t->right)s.push(t->right); s.push(t); t = t->left; }
		else if (!s.empty()) 
		{
			t = s.top(); s.pop();
			if (!s.empty() && t->right == s.top())
			{
				s.pop(); s.push(t);
				t = t->right;
			}
			else
			{
				cout << t->info << " ";
				t = NULL;
			}
		}
		else break;
	}
}
void PrintTree2(Node* t)
{
	if (!t)return;
	stack<Node*> s1, s2;
	s1.push(t);
	while (!s1.empty())
	{
		t = s1.top(); s1.pop();
		s2.push(t);
		if (t->right)s1.push(t->right);
		if (t->left)s1.push(t->left);
	}
	while (!s2.empty())
	{
		cout << s2.top()->info << " ";
		s2.pop();
	}
}
void MorrisPreOrder(Node* t)
{
	while (t)
	{
		if (t->left == NULL) { cout << t->info << " "; t = t->right; }
		else
		{
			Node* p = t->left; while (p->right && p->right!=t)p = p->right;
			if (p->right == NULL) { p->right = t; cout << t->info << " "; t = t->left; }
			else { p->right = NULL; t = t->right; }
		}
	}
}
void MorrisInOrder(Node* t)
{
	while (t)
	{
		if (t->left == NULL) { cout << t->info << " "; t = t->right; }
		else
		{
			Node* p = t->left; while (p->right && p->right!=t)p = p->right;
			if (p->right == NULL) { p->right = t; t = t->left; }
			else { p->right = NULL; cout << t->info<<" "; t = t->right; }
		}
	}
}
void ConvertToThreaded(Node* t)
{
	if (!t) return;
	if (t->left) 
	{
		Node* p = t->left;
		while (p->right) p = p->right;
		p->right = t;
		p->isThreaded = true;
	}
	ConvertToThreaded(t->left);
	if(!t->isThreaded)
	ConvertToThreaded(t->right);
}
Node* LeftMostNode(Node* t) { if (!t) return t; while (t->left) t = t->left; return t; }
void ConvertToThreaded2(Node* t)
{
	if (!t) return;
	while (t)
	{
		if(t->left)
		{
			Node* p = t->left;
			while (p->right) p = p->right;
			p->right = t;
			p->isThreaded = true;
			t = t->left;
		}
		else
		{
			if (t->isThreaded) { t = t->right->right; }
			else t = NULL;
		}
	}
}
void PrintThreadedInOrder(Node* t)
{
	if (!t) return;
	Node* p = LeftMostNode(t);
	while (p)
	{
		cout << p->info << " ";
		if (p->isThreaded)
			p = p->right;
		else
			p = LeftMostNode(p->right);
	}
}
bool isIdentical(Node* t1, Node* t2)
{
	if (t1 == t2) return true;
	if (!t1 || !t2) return false;
	return t1->info == t2->info && isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
}
void DeleteTree(Node* t)
{
	if (!t)return;
	DeleteTree(t->left);
	DeleteTree(t->right);
	free(t);
}
void ConvertToMirror(Node* t)
{
	if (!t) return;
	ConvertToMirror(t->left);
	ConvertToMirror(t->right);
	Node* p = t->left;
	t->left = t->right;
	t->right = p;
}
void printNodesAtLevelwd(Node* t,int l, int d, bool& f)
{
	if (!t)return;
	if (l == 1) { if (f) { d = d / 2; f = false; } cout << setw(d) << t->info; }
	printNodesAtLevelwd(t->left, l - 1, d / 2,f);
	printNodesAtLevelwd(t->right, l - 1, d / 2,f);
}
void PrintTree(Node* t, int indent = 0)
{
	int h = height(t);
	int n = pow(2, h+1);
	bool f = true;
	for (int i = 1; i <= h; i++) {	f = true;printNodesAtLevelwd(t, i, n, f); cout << endl << endl;	}
}
void PrintRootToLeafPathUtil(Node* t, int a[], int i)
{
	if (!t) return;
	a[i] = t->info;
	if (!t->left && !t->right) { for (int j = 0; j <= i; j++) cout << a[j] << " "; cout << endl; }
	PrintRootToLeafPathUtil(t->left, a, i + 1);
	PrintRootToLeafPathUtil(t->right, a, i + 1);
}
void PrintRootToLeafPath(Node* t){ 	int a[1000];PrintRootToLeafPathUtil(t, a, 0);}
void PrintLevelOrderSpiralUtil(Node* t, int l, bool f)
{
	if (!t)return;
	if (l == 1)cout << t->info << " ";
	if (f)
	{
		PrintLevelOrderSpiralUtil(t->left, l - 1, f);
		PrintLevelOrderSpiralUtil(t->right, l - 1, f);
	}
	else
	{
		PrintLevelOrderSpiralUtil(t->right, l - 1, f);
		PrintLevelOrderSpiralUtil(t->left, l - 1, f);
	}
}
void PrintLevelOrderSpiral1(Node* t)
{
	if (!t)return;
	int h = height(t);
	bool f = true;
	cout << t->info << " ";
	for (int i = 2; i <= h; i++,f=!f)
		PrintLevelOrderSpiralUtil(t, i, f);
}
void PrintLevelOrderSpiral2(Node* t)
{
	if (!t) return;
	deque<Node*> q;
	q.push_front(t);
	int h = 0;
	while (!q.empty())
	{
		int s = q.size();
		h++;
	//	if (h % 2)reverse(q.begin(),q.end());
		//either reverse dqueue or insret in specialnner as below
		while (s--) {
			if (h % 2)
				t = q.front(), q.pop_front();
			else
				t = q.back(), q.pop_back();
			cout << t->info << " ";
			if (h % 2)
			{
				if (t->left)q.push_back(t->left);
				if (t->right)q.push_back(t->right);
			}
			else
			{
				if (t->right)q.push_front(t->right);
				if (t->left)q.push_front(t->left);
			}
		}
	}
}
void PrintLevelOrderSpiral(Node* t)
{
	if (!t) return;
	stack<Node*>s1,s2;
	s1.push(t);
	int h = 0;
	while (!s1.empty()||!s2.empty())
	{
		while (!s1.empty()) 
		{
			t = s1.top(); s1.pop();
			cout << t->info << " ";
			if (t->left)s2.push(t->left);
			if (t->right)s2.push(t->right);
		}
		while (!s2.empty())
		{
			t = s2.top(); s2.pop();
			cout << t->info << " ";
			if (t->right)s1.push(t->right);
			if (t->left)s1.push(t->left);
		}
	}
}
bool isSumProperty(Node* t)
{
	if (!t || (!t->left && !t->right)) return true;
	int s = 0;
	if (t->left)s = t->left->info;
	if (t->right)s += t->right->info;
	return t->info == s&&isSumProperty(t->left) && isSumProperty(t->right);
}
void AddSumInLeft(Node* t, int s)
{
	while (t)
	{
		t->info += s;
		if (t->left) 
			t = t->left;
		else if (t->right) 
			t = t->right;
		else break;
	}
}
void ConvertToChildSumProperty(Node* t)
{
	if (!t || (!t->left&&!t->right))return;
	ConvertToChildSumProperty(t->left);
	ConvertToChildSumProperty(t->right);
	int s = 0;
	if (t->left) s = t->left->info;
	if (t->right)s += t->right->info;
	int diff = s - t->info;
	if (diff> 0)t->info += diff;
	else AddSumInLeft(t, -diff);
}
#define isLeaf(t) (t&&!t->left&&!t->right)
int DiameterOfTree1(Node* t)
{
	if (!t) return 0;
	if (isLeaf(t)) return 1;
	int hl = height(t->left);
	int hr = height(t->right);
	int dl = DiameterOfTree1(t->left);
	int dr = DiameterOfTree1(t->right);
	return max(hl + hr + 1, max(dl, dr));
}
int DiameterOfTreeUtil(Node* t, int& h)
{
	if (!t) { h = 0; return 0; }
	if (isLeaf(t)) {h = 1; return 1;}
	int hl = 0, hr = 0;
	int dl = DiameterOfTreeUtil(t->left, hl);
	int dr = DiameterOfTreeUtil(t->right, hr);
	h = 1 + max(hl, hr);
	return max(1 + hl + hr, max(dl, dr));
}
int DiameterOfTree(Node* t)
{
	int h = 0;
	return DiameterOfTreeUtil(t, h);
}
bool isBalanced(Node* t, int& h)
{
	if (!t) { h = 0; return true; }
	if (isLeaf(t)) { h = 1; return true; }
	int hl, hr;
	bool r = isBalanced(t->left, hl) && isBalanced(t->right, hr);
	h = 1 + max(hl, hr);
	return r&&abs(hl - hr) <= 1;
}
bool hasPathSum(Node* t, int s)
{
	if (!t) { return s == 0;}
	if (isLeaf(t) && t->info == s) return true;
	return hasPathSum(t->left, s - t->info) || hasPathSum(t->right, s - t->info);
}
Node* buildTreePreIn(int in[], int pre[], int l, int h)
{
	static int index = 0;
	if (l > h)return NULL;
	Node* t = newNode(pre[index++]);
	if (l == h)return t;
	int j = 0;
	for (j = l; j <= h; j++) if (in[j] == t->info) break;
	if (j > h) return t;
	t->left = buildTreePreIn(in, pre, l, j - 1);
	t->right = buildTreePreIn(in, pre, j + 1, h);
	return t;
}
void maxWidthTreeUtil(Node* t, int a[], int l)
{
	if (!t) return;
	a[l]++;
	maxWidthTreeUtil(t->left, a, l + 1);
	maxWidthTreeUtil(t->right, a, l + 1);
}
int maxWidthTree(Node* t)
{
	if (!t)return 0;
	int a[100] = { 0 };
	int m = 0;
	maxWidthTreeUtil(t, a, 1);
	for (int i = 1; i < 100; i++)
		if (m < a[i])m = a[i];
	return m;
}
void ConvertToDoubleTree(Node* t)
{
	if (!t)return;
	ConvertToDoubleTree(t->left);
	ConvertToDoubleTree(t->right);
	Node* p = t->left;
	t->left = newNode(t->info);
	t->left->left = p;
}
void printNodesAtKDistanceFromRoot(Node* t, int l)
{
	if (!t)return;
	if (l == 0)cout << t->info << " ";
	printNodesAtKDistanceFromRoot(t->left, l - 1);
	printNodesAtKDistanceFromRoot(t->right, l - 1);
}
int getLevelOfNode(Node* t, int x, int l = 1)
{
	int r = 0;
	if (!t) return 0;
	if (t->info == x) return l;
	if(r=getLevelOfNode(t->left, x, l + 1)) return r;
	return getLevelOfNode(t->right, x, l + 1);
}
bool printAncestor(Node* t, int x)
{
	if (!t)return false;
	if (t->info == x ||printAncestor(t->left, x) || printAncestor(t->right, x))
	{
		cout << t->info << " "; return true;
	}
}
bool isSumTree(Node* t)
{
	if (!t || isLeaf(t)) return true;
	if (isSumTree(t->left) && isSumTree(t->right)) {
		int s = 0;
		if (t->left) {
			if (isLeaf(t->left)) s = t->left->info;
			else s = 2 * t->left->info;
		}
		if (t->right) {
			if (isLeaf(t->right)) s += t->right->info;
			else s += 2 * t->right->info;
		}
		return t->info == s;
	}
	return false;
}
Node* findNodeInTree(Node* t, int x)
{
	if (!t) return t;
		if (t->info == x) return t;
		Node* p = findNodeInTree(t->left, x);
		if (p) return p;
		return findNodeInTree(t->right, x);
}
bool isSubTree(Node* t, Node* s)
{
	if (!s)return true;
	if (!t)return false;
	Node* p = findNodeInTree(t, s->info);
	return isIdentical(p, s);
}
Node* findNextRight(Node* t)
{
	Node* p = t->nextRight;
	while (p)
	{
		if (p->left) return p->left;
		else if (p->right) return p->right;
		p = p->nextRight;
	}
	return NULL;
}
void ConnectRight(Node* t)
{
	if (!t) return;
	if (t->nextRight) ConnectRight(t->nextRight);
	if (t->left)
	{
		if (t->right)
		{
			t->left->nextRight = t->right;
			t->right->nextRight = findNextRight(t);
		}
		else
			t->left->nextRight = findNextRight(t);
		ConnectRight(t->left);
	}
	else if (t->right) 
	{
		t->right->nextRight = findNextRight(t);
		ConnectRight(t->right);
	}
	else ConnectRight(findNextRight(t));
}
void LevelOrderRightConnected(Node* t)
{
	if (!t) return;
	Node* p = t;
	while (t) { cout << t->info<<" "; t = t->nextRight; }
	cout << endl;
	if (p->left) LevelOrderRightConnected(p->left);
	else if(p->right) LevelOrderRightConnected(p->right);
	else LevelOrderRightConnected(findNextRight(p));
}
void ConnectNextInOrder(Node* t, Node*& p)
{
	if (!t) return;
	ConnectNextInOrder(t->right,p);
	t->nextInOrder = p;
	p = t;
	ConnectNextInOrder(t->left,p);
}
void PrintConnectedNextInOrder(Node* t)
{
	if (!t) return;
	while (t->left)
		t = t->left;
	while (t) 
	{ cout << t->info << " "; t = t->nextInOrder; }
}
int toSumTree(Node* t)
{//this is tricky one 
	if (!t) return 0;
	int s = t->info;
	t->info = toSumTree(t->left) + toSumTree(t->right);
	return t->info + s;
}
void PrintVerticalSumUtil(Node* t, map<int, int>& m, int vd)
{
	if (!t)return;
	m[vd] += t->info;
	PrintVerticalSumUtil(t->left, m, vd - 1);
	PrintVerticalSumUtil(t->right, m, vd + 1);
}
void PrintVerticalSum(Node* t)
{
	if (!t) return;
	map<int,int> m ;
	PrintVerticalSumUtil(t, m, 0);
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
		cout<< it->first<< " -> "<<it->second<<endl;
}
void findRootToLeafMaxSum(Node* t,int sum,int& maxSum, Node*& p)
{
	if (!t)return;
	sum += t->info;
	if (isLeaf(t)) { if (maxSum < sum)maxSum = sum, p = t; }
	findRootToLeafMaxSum(t->left, sum, maxSum, p);
	findRootToLeafMaxSum(t->right, sum, maxSum, p);
}
void PrintLeafToRootMaxSumPath(Node* t)
{
	int sum = 0;
	Node *p = NULL;
	findRootToLeafMaxSum(t, 0, sum, p);
	cout << sum << endl;
	printAncestor(t, p->info);
}
Node* constructTreeSpecialPre(int pre[], char preLN[], int &index, int n)
{
	//int pre[] = { 10, 30, 20, 5, 15 };
	//char preLN[] = { 'N', 'N', 'L', 'L', 'L' };
	if (index == n) return NULL;
	Node* t = newNode(pre[index]);
	if (preLN[index++] == 'N')
	{
		t->left = constructTreeSpecialPre(pre, preLN, index, n);
		t->right = constructTreeSpecialPre(pre, preLN, index, n);
	}
	return t;
}
bool isCompleteBT(Node* t)
{
	if (!t || isLeaf(t)) return true;
	queue<Node*> q;
	q.push(t);
	bool flag = false;
	while (!q.empty())
	{
		t = q.front(); q.pop();
		if (t->left || flag) { 	q.push(t->left); if (flag) return !flag;}
		else flag = true;
		if (t->right || flag) { q.push(t->right); if (flag) return !flag;}
		else flag = true;
	}
	return true;
}
void printBoundryBTLeft(Node* t)
{
	if (!t || isLeaf(t))return;
	cout << t->info << " ";
	if (t->left)printBoundryBTLeft(t->left);
	else if (t->right) printBoundryBTLeft(t->right);
}
void printBoundryBTBottom(Node* t)
{
	if (!t)return;
	printBoundryBTBottom(t->left);
	if (isLeaf(t))cout << t->info << " ";
	printBoundryBTBottom(t->right);
}
void printBoundryBTRight(Node* t)
{
	if (!t || isLeaf(t)) return;
	cout << t->info << " ";
	if(t->right)
	printBoundryBTRight(t->right);
	else if (t->left)printBoundryBTRight(t->left);
	

}
void printBoundryBT(Node* t)
{
	if (!t)return;
	cout << t->info<<" ";
	printBoundryBTLeft(t->left);
	printBoundryBTBottom(t);
	printBoundryBTRight(t->right);
}
Node* constructTreePrePostFull(int pre[], int post[], int l, int h,int n)
{
	//int pre[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
	//int post[] = { 8, 9, 4, 5, 2, 6, 7, 3, 1 };
	//node *root = constructTreePrePostFull(pre, post,0, size-1,size);
	static int index = 0;
	if (l > h || index>n )return NULL;
	Node* t = newNode(pre[index]);
	if (index == n) return t;
	int i;
	index++;
	for ( i = l; i <= h; i++) if (pre[index] == post[i])break;
	if (i <= h) {
		t->left = constructTreePrePostFull(pre, post, l, i, n);
		t->right = constructTreePrePostFull(pre, post, i + 1, h, n);
	}
	return t;
}
void insertInCompleteBT(Node*& t, int x, queue<Node*>& q)
{
	Node* p = newNode(x);
	if (!t) t = p;
	if (!q.empty()) { Node* x = q.front(); if (!x->left) x->left = p; else if (!x->right) { x->right = p; q.pop(); }}
	q.push(p);
}
Node* constructCompleteBT(int a[], int n)
{
	//int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//Node* root = constructCompleteBT(a, sizeof(a) / sizeof(a[0]));
		queue<Node*> q;
	Node* t = NULL;
	for (int i = 0; i < n; i++)
		insertInCompleteBT(t, a[i], q);
	return t;
}
int LIS(Node* t)
{
	if (!t) return 0;
	if (isLeaf(t)) return 1;
	int ex = LIS(t->left) + LIS(t->right);
	int inc = 1;
	if (t->left) inc += LIS(t->left->left) + LIS(t->left->right);
	if (t->right) inc += LIS(t->right->left) + LIS(t->right->right);
	return max(ex, inc);
}
int LISDP(Node* t)
{
	if (!t) return 0;
	if (isLeaf(t)) return t->lis = 1;
	if (t->lis) return t->lis;
	int ex = LISDP(t->left) + LISDP(t->right);
	int inc = 1;
	if (t->left) inc += LISDP(t->left->left) + LISDP(t->left->right);
	if (t->right)inc += LISDP(t->right->left) + LISDP(t->right->right);
	return t->lis = max(inc, ex);
}
void printReverseLevelOrder(Node* t)
{
#define del -1
	if (!t) return;
	queue<Node*> q;
	stack<int> s;
	q.push(t);
	while (!q.empty())
	{
		int n = q.size();
		while (n--)
		{
			t = q.front(); q.pop();
			s.push(t->info);
			if (t->right)q.push(t->right);
			if (t->left)q.push(t->left);
		}
		s.push(del);
	}
	while (!s.empty())
	{
		int x = s.top(); s.pop();
		if (x == del) cout << endl;
		else cout << x << " ";
	}
}
void printList(Node* t) {	while (t) { cout << t->info << " "; t = t->right; } cout << endl;}
Node* convertToDLL(Node* t)
{
	// Do inorder traversal and update pointer o(n)
	if (!t)return NULL;
	static Node* p = NULL;
	static Node* r = NULL;
	convertToDLL(t->left);
	if (!r) r = t;
	if (p)
	{
		p->right = t;
		t->left = p;
	}
	p = t;
	convertToDLL(t->right);
	return r;
}
Node* convertToDLL1Util(Node* t)
{
	if (!t) return NULL;
	if (t->left)
	{
		node* p = convertToDLL1Util(t->left);
		for (; p->right; p = p->right);
		p->right = t;
		t->left = p;
	}
	if (t->right)
	{
		node* p = convertToDLL1Util(t->right);
		for (; p->left; p = p->left);
		t->right = p;
		p->left = t;
	}
	return t;
}
Node* convertToDLL1(Node* t)
{
	t = convertToDLL1Util(t);
	while (t->left)t = t->left;
	return t;
}
bool isIsomorphic(Node* t1, Node* t2)
{
	if (t1 == t2) return true;
	if (!t1 || !t2) return false;
	if (t1->info != t2->info)return false;
	return
		isIsomorphic(t1->left, t2->left) && isIsomorphic(t1->right, t2->right) ||
		isIsomorphic(t1->left, t2->right) && isIsomorphic(t1->right, t2->left);
}
string alphabet[] = { "", "a", "b", "c", "d", "e","f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r","s", "t", "u", "v", "w", "x", "v", "z" };
Node* printAllInterpretations(int a[], int n,string s="", int l=0)
{
	if (l > n) return NULL;
	Node* t = newNode(s);
	if (l == n) return t;
	string ls = s + alphabet[a[l]];
	t->left = printAllInterpretations(a, n, ls, l + 1);

	if (l + 1 < n && a[l] * 10 + a[l + 1] <= 26) {
		string rs = s + alphabet[a[l] * 10 + a[l + 1]];
		t->right = printAllInterpretations(a, n, rs, l + 2);
	}
	return t;
}
void printLeafString(Node* t)
{
	if (!t) return;
	if (isLeaf(t)) cout<<t->sinfo<<" ";
	printLeafString(t->left);
	printLeafString(t->right);
}
void findAllInterpretation()
{
	int arr[] = { 1, 1, 3, 4 };
	Node* t = printAllInterpretations(arr, sizeof(arr) / sizeof(arr[0]));
	printLeafString(t);
	// aaa(1,1,1) ak(1,11) ka(11,1)
	int arr2[] = { 1, 1, 1 };
	 printLeafString(printAllInterpretations(arr2, sizeof(arr2) / sizeof(arr2[0]) ));
	// bf(2,6) z(26)
	int arr3[] = { 2, 6 };
	 printLeafString(printAllInterpretations(arr3, sizeof(arr3) / sizeof(arr3[0]) ));
	// ab(1,2), l(12)  
	int arr4[] = { 1, 2 };
	 printLeafString(printAllInterpretations(arr4, sizeof(arr4) / sizeof(arr4[0]) ));
	// a(1,0} j(10)  
	int arr5[] = { 1, 0 };
	 printLeafString(printAllInterpretations(arr5, sizeof(arr5) / sizeof(arr5[0]) ));
	// abba abu ava lba lu
	int arr7[] = { 1, 2, 2, 1 };
	 printLeafString(printAllInterpretations(arr7, sizeof(arr7) / sizeof(arr7[0]) ));
}
void printAncestorIterative(Node* t,int k)
{
	if (!t)return;
	stack<Node*> s;
	while (true)
	{
		while (t && t->info != k) { s.push(t); t = t->left; }
		if (t&&t->info == k) break;
		if (s.top()->right == NULL)
		{
			t = s.top(); s.pop();
			while (!s.empty() && s.top()->right == t) { t = s.top(); s.pop(); }
		}
		t = s.empty() ? NULL : s.top()->right;
	}
	while (!s.empty())cout << s.top()->info << " ",s.pop();
}
int getLevelSumDiff(Node* t)
{
	if (!t) return 0;
	return t->info - getLevelSumDiff(t->left) - getLevelSumDiff(t->right);
}
void printLeftViewOfBTUtil(node* t, int l,int &m)
{
	if (!t)return;
	if (l > m)
	{
		m = l;
		cout << t->info<<" ";
	}
	printLeftViewOfBTUtil(t->right, l + 1, m);
	printLeftViewOfBTUtil(t->left, l + 1, m);
}
void printLeftViewOfBT(node* t)
{
	int max = 0;
	printLeftViewOfBTUtil(t, 1, max);
}
void printLeftViewOfBT1Util(Node* t, int a[], int l, int &m)
{
	if (!t) return;
	if (!a[l])a[l] = t->info;
	m = m < l ? l : m;
	printLeftViewOfBT1Util(t->right, a, l + 1, m);
	printLeftViewOfBT1Util(t->left, a, l + 1, m);
}
void printLeftViewOfBT1(Node* t)
{
	int a[100] = { 0 };
	int m = 0;
	printLeftViewOfBT1Util(t, a,1,m);
	for (int i = 1; i <= m; i++)
		cout << a[i] << " ";
}
Node* pruneUtilSum(Node* t, int s)
{
	if (!t) return t;
	t->left = pruneUtilSum(t->left, s - t->info);
	t->right =  pruneUtilSum(t->right, s - t->info);
	if (isLeaf(t) && t->info < s) return NULL;
	return t;
}
Node* exreactLeavesToDLL(Node* t, Node*& dl)
{
	if (!t) return t;
	static node* p = NULL;
	t->left = exreactLeavesToDLL(t->left, dl);
	if (isLeaf(t))
	{
		if (!dl)dl = t;
		if (p) { p->right = t; t->left = p; }
		p = t;
		return NULL;
	}
	t->right =exreactLeavesToDLL(t->right, dl);
	return t;
}
int treePathsSum(Node* t, int s=0)
{
	if (!t)return 0;
	s = s * 10 + t->info;
	if (isLeaf(t)) return s;
	return treePathsSum(t->left, s) + treePathsSum(t->right, s);
}
int search(int arr[], int x, int l,int n)
{
	for (int i = l; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}
void printPostOrderInPre(int in[], int pre[], int &index, int n, int l = 0)
{
	if (l > n || index>n)return;
	int i = search(in, pre[index], l, n);
	int x = pre[index];
	index++;
	if (i > 0)
		printPostOrderInPre(in, pre, index, i-1, l);
	if (i < n-1 )
		printPostOrderInPre(in, pre, index, n, i + 1);
	cout << x << " ";
}
Node* findLCAInBT(Node* t, int key1, int key2)
{
	if (!t) return t;
	if (t->info == key1 || t->info == key2) return t;
	Node* l = findLCAInBT(t->left, key1, key2);
	Node* r = findLCAInBT(t->right, key1, key2);
	if (l != NULL&&r != NULL) return t;
	return l ? l : r;
}
bool findAncestorStack(Node* t, int k, stack<int>& s)
{
	if (!t)return false;
	if (t->info == k) return true;
	if (findAncestorStack(t->left,k,s) || findAncestorStack(t->right,k,s)) {
		s.push(t->info);
		return true;
	}
if(!s.empty())	s.pop();
	return false;
}
int findLCAInBT2(node* t, int k1, int k2)
{
	stack<int> s1, s2;
	findAncestorStack(t, k1, s1);
	findAncestorStack(t, k2, s2);
	int x = -1;
	while (!s1.empty()&&!s2.empty())
	{
		
		if (s1.top() == s2.top()) { x = s1.top(); s1.pop(); s2.pop(); }
		else return x;
	}
	return x;
}
int findLevelOfNode(Node* t, int x, int l)
{
	if (!t)return 0;
	if (t->info == x) return l;
	int a = findLevelOfNode(t->left, x, l + 1);
	if (a) return a;
	return findLevelOfNode(t->right, x, l + 1);
}
int findDistanceBetweenTwoNodes(Node* t, int x, int y)
{
	Node* a = findLCAInBT(t, x, y);
	return  findLevelOfNode(a, x, 0) + findLevelOfNode(a, y, 0);
}

void printNodesAtKDistanceFromLeafUtil(Node* t, int a[], int k, int i)
{
	if (!t)return;
	a[i++] = t->info;
	if (isLeaf(t)) {
		if (i - k -1>= 0 && a[i - k-1]) cout << a[i - k-1] << " "; a[i - k-1] = 0;
	}
	printNodesAtKDistanceFromLeafUtil(t->left, a, k, i);
	printNodesAtKDistanceFromLeafUtil(t->right, a, k, i);
}
void printNodesAtKDistanceFromLeaf(Node* t, int k)
{
// maintain height of node in node structure as leaf node height is 1 and root height is max h
// traverse tree and check if a node is having height k print the node // solve this while doing avl tree
	int a[100] = { 0 };
	printNodesAtKDistanceFromLeafUtil(t, a, k, 0);
}
bool printNodesAtKDistanceUtil(Node* t, int k,int x, vector<Node*>& v)
{
	if (!t)return false;
	if (t->info == x) { printNodesAtKDistanceFromRoot(t, k);  return true; }
	if (printNodesAtKDistanceUtil(t->left, k,x, v) || printNodesAtKDistanceUtil(t->right, k,x, v))
	{
		v.push_back(t);
		return true;
	}
}
void printNodesAtKDistance(Node* t,int x, int k)
{
	vector<Node*> v;
	printNodesAtKDistanceUtil(t, k,x, v);
	while (!v.empty() && --k >= 0)
	{
		if (k == 0)
			cout << v.front()->info << " ";
		if ( k>0 && v.front()->left && v.front()->left->info == x)
		{
			if (v.front()->right) printNodesAtKDistanceFromRoot(v.front()->right, k - 1);
		}
		if (k>0&&v.front()->right && v.front()->right->info == x)
		{
			if (v.front()->left) printNodesAtKDistanceFromRoot(v.front()->left, k - 1);
		}
		t = v.front(); x = t->info; v.erase(v.begin());
	}
}
void printTreeVerticallyUtil1(Node* t, int& min, int& max, int d)
{
	if (!t)return;
	min = min > d ? d : min;
	max = max < d ? d : max;
	printTreeVerticallyUtil1(t->left, min, max, d - 1);
	printTreeVerticallyUtil1(t->right, min, max, d + 1);
}
void printNodesAtVerticalLevel(Node* t, int l, int d)
{
	if (!t) return;
	if (l == d) cout << t->info << " ";
	printNodesAtVerticalLevel(t->left, l, d - 1);
	printNodesAtVerticalLevel(t->right, l, d + 1);
}
void printTreeVertically(Node* t)
{
	int min = INT_MAX, max = INT_MIN;
	printTreeVerticallyUtil1(t, min, max, 0);
	for (int i = min; i <= max; i++)
		printNodesAtVerticalLevel(t, i, 0), cout << endl;
}
int findMinHeight(Node* t,int l=0)
{
	if (!t) return INT_MAX;
	if (isLeaf(t)) return 0;
	return 1 + min(findMinHeight(t->left, l + 1), findMinHeight(t->right, l + 1));
}
int printClosetLeafNodeUtil(Node* t, int x, vector<Node*> &v)
{
	if (!t) return 0;
	if (t->cinfo == x) { return findMinHeight(t); };
	int l = 0, r = 0;
	l = printClosetLeafNodeUtil(t->left, x, v);
	if (l > 0) { v.push_back(t); return l; }
	l = printClosetLeafNodeUtil(t->right, x, v);
	if (l > 0) { v.push_back(t); return l; }
	return l;
}
int printClosetLeafNode(Node* t, int x)
{
	vector<Node*> v;
	int d = printClosetLeafNodeUtil(t, x, v);
	for (int i = 0; i < v.size(); i++)
	{
		int m = findMinHeight(v[i]) + 1 + i;
		if (m < d) d = m;
	}
	return d;
}
typedef pair<Node*, int> P;
void TopViewBTUtil(Node* t, map<int, int> &m, int vd, bool top = true)
{
	if (!t)return;
	queue<P> q;
	q.push(P(t,0));
	while (!q.empty())
	{
	P p = q.front(); q.pop();
	if (top) { if (m.find(p.second) == m.end())m[p.second] = p.first->info; }
	else m[p.second] = p.first->info;
	if (p.first->left) q.push(P(p.first->left, p.second - 1));
	if (p.first->right)q.push(P(p.first->right, p.second + 1));
	}
}
void  TopViewBT(Node* t)
{
	map<int, int > m;
	TopViewBTUtil(t, m, 0);
	map<int, int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << it->second << " "; it++;
	}
}
void  BottomViewBT(Node* t)
{
	map<int, int > m;
	TopViewBTUtil(t, m, 0,false);
	map<int, int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << it->second << " "; it++;
	}
}
bool isFullBT(Node* t)
{
	if (!t || isLeaf(t)) return true;
	if (t->left&&t->right) {
		return  isFullBT(t->left) && isFullBT(t->right);
	}
	return false;
}
Node* removeHalfNodeBT(Node* t)
{
	if (!t || isLeaf(t)) return t;
	t->left = removeHalfNodeBT(t->left);
	t->right = removeHalfNodeBT(t->right);
	if (t->left&&t->right) return t;
	if (t->left) return t->left;
	if (t->right)  return t->right;
}
int leftLeaveSum(Node* t)
{
	if (!t) return 0;
	int s = 0;
	if (isLeaf(t->left))s = t->left->info;
	return s + leftLeaveSum(t->left) + leftLeaveSum(t->right);
}
Node* removeNodesLessDistanceK(Node* t, int k, int d=1)
{
	if (!t) return t;
	t->left = removeNodesLessDistanceK(t->left, k,d+1);
	t->right = removeNodesLessDistanceK(t->right, k,d+1);
	if (isLeaf(t) && d<k) return NULL;
	return t;
}
bool countSingleValuedTree(Node* t, int &count)
{
	if (!t) { return true; }
	if (isLeaf(t)) { count++; return true; }
	bool l = countSingleValuedTree(t->left, count);
	bool r = countSingleValuedTree(t->right, count);
	if (!l || !r) return false;
	if (t->left&&t->left->info != t->info) return false;
	if (t->right&&t->right->info != t->info) return false;
	count++; 
	return true;
}
int findMaxBT(Node* t)
{
	if (!t) return INT_MIN;
	int r = t->info;
	int l = findMaxBT(t->left);
	if (l > r)r = l;
	l = findMaxBT(t->right);
	if (l > r) r = l;
	return r;
}
int main()
{
	#define newnode newNode
	#define node Node
	Node *root = newNode(6);
	root->left = newNode(3);
	root->right = newNode(8);
	root->left->left = newNode(1);
	root->left->right = newNode(5);
	root->right->left = newNode(7);
	root->right->right = newNode(11);
	root->left->left->left = newNode(9);
	root->left->left->right = newNode(35); 
	TopViewBT(root);
	cout << endl;
	BottomViewBT(root);
	cout << endl;
	PrintTree(root);
	system("pause");
	return 0;
	/*
		6
	  /   \
	 3     8	
	/ \   / \
   1   5 7   11
  / \         
9	 35	   
	*/
}
/*
http://www.geeksforgeeks.org/expression-tree/
http://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
http://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/
http://quiz.geeksforgeeks.org/change-a-binary-tree-so-that-every-node-stores-sum-of-all-nodes-in-left-subtree/
http://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
http://quiz.geeksforgeeks.org/convert-left-right-representation-bianry-tree-right/
http://www.geeksforgeeks.org/minimum-iterations-pass-information-nodes-tree/
http://www.geeksforgeeks.org/clone-binary-tree-random-pointers/
http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
http://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
http://www.geeksforgeeks.org/succinct-encoding-of-binary-tree/
*/
#endif
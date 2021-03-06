// Tree.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>

/*
https://www.geeksforgeeks.org/find-all-possible-trees-with-given-inorder-traversal/
https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
https://www.geeksforgeeks.org/calculate-depth-full-binary-tree-preorder/
https://www.geeksforgeeks.org/number-of-binary-trees-for-given-preorder-sequence-length/
	  */
using namespace std;

struct Node
{
	int info;
	struct Node* next;
	struct Node* left;
	struct Node* right;
	struct Node* parrent;
	Node(int _info)
	{
		info = _info;
		next = left = right = NULL;
	}
};
Node* newNode(int t) { return new Node(t); }
#pragma region Traversal
void inorder(Node* root)
{
	if (NULL == root) return;
	inorder(root->left);
	cout << root->info << " ";
	inorder(root->right);
}
void Preorder(Node* root)
{
	if (NULL == root) return;
	cout << root->info << " ";
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(Node* root)
{
	if (NULL == root) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->info << " ";
}
void PreorderItr(Node* root)
{
	stack <Node*> s;
	if (!root) return;
	label:
	while (root)
	{
		cout << root->info << " ";
		if (root->right) s.push(root->right);
		root = root->left;
	}

	while (!s.empty())
	{
		root = s.top(); s.pop();
		goto label;
	}


}
void InorderItr(Node* root)
{
	stack <Node*> s;
	if (!root) return;
	label:
	while (root)
	{
		s.push(root);
		root = root->left;
	}
	while (!s.empty())
	{
		root = s.top(); s.pop();
		cout << root->info<<" ";
		if (root->right)
		{
			root = root->right;
			goto label;
		}
	}
}
void PostorderItr(Node* root)
{
	stack <Node*> s;
	if (!root) return;

	label:
	while (root)
	{
		if (root->right) s.push(root->right);
		s.push(root);
		root = root->left;
	}

	while (!s.empty())
	{
		root = s.top(); s.pop();
		if (!s.empty()&&root->right == s.top())
		{
			Node * temp = s.top(); s.pop();
			s.push(root);
			root = temp;
			goto label;
		}
		cout << root->info << " ";
	}
}
void PreorderItr1(Node* root)
{
	stack <Node*> s;
	if (!root) return;
	while (true)
	{
		if (root)
		{
			cout << root->info << " ";
			if (root->right) s.push(root->right);
			root = root->left;
		}

		else if (!s.empty())
		{
			root = s.top(); s.pop();

		}
		else
			break;
	}

}
void InorderItr1(Node* root)
{
	stack <Node*> s;
	if (!root) return;
	while (true)
		if (root)
		{
			s.push(root);
			root = root->left;
		}
		else if (!s.empty())
		{
			root = s.top(); s.pop();
			cout << root->info << " ";
			if (root->right)
			{
				root = root->right;
			}
			else
				root = NULL;
		}
		else
			break;
}
void PostorderItr1(Node* root)
{
	stack <Node*> s;
	if (!root) return;

	while (true)
	{
		if (root)
		{
			if (root->right) s.push(root->right);
			s.push(root);
			root = root->left;
		}

		else if (!s.empty())
		{
			root = s.top(); s.pop();
			if (!s.empty() && root->right == s.top())
			{
				Node * temp = s.top(); s.pop();
				s.push(root);
				root = temp;
			}
			else
			{
				cout << root->info << " ";
				root = NULL;
			}
		}
		else
			break;
	}
}
void MorrisInorder(Node* root)
{
	if (!root) return;
	while (root)
	{
		if (root->left == NULL)
		{
			cout << root->info<<" ";
			root = root->right;
		}
		else
		{
			
			Node* temp = root->left;
			while (temp->right != NULL && temp->right != root) temp = temp->right;
			if (temp->right == NULL) {
				temp->right = root;
				root = root->left;
			}
			else
			{
				temp->right = NULL;
				cout << root->info << " ";
				root = root->right;

			}
		}
	}
}
void MorrisPreorder(Node* root)
{

	if (!root) return;
	while (root)
	{
		if (!root->left )
		{
			cout << root->info<<" ";
			root = root->right;
		}
		else
		{
			Node* temp = root->left;
			while (temp->right != NULL && temp->right != root)	temp = temp->right;

			if (temp->right == NULL) {
				temp->right = root;
				cout << root->info << " ";
				root = root->left;
			}
			else
			{
				temp->right = NULL;
				root = root->right;
			}
		}
	}

}
int findLoc(int in[], int key,int l, int n)
{
	for (int i = l; i <= n; i++)
		if (in[i] == key)
			return i;
	return -1;
}
int findLocInPre(int pre[], int key, int l, int h)
{
	int i = 0;
	for ( i = l; i <= h; i++)
	{
		if (pre[i] > key) break;
	}
	return i <= h ? i : -1;

}
void PrintPostOfINandPre(int pre[], int in[], int low, int high, int& index)
{
	if (low > high) return;
	int t = pre[index++];
	int l = findLoc(in, t, low, high);
	
	if (l != -1)
	{
		PrintPostOfINandPre(pre, in, low, l - 1, index);

		PrintPostOfINandPre(pre, in, l + 1, high, index);

	}
	cout << t<<" ";
}
void PrintPostOrderOfBSTofPreOrder(int pre[], int low, int high) // o(n^2)
{
	if (low > high) return ;
	int l = findLocInPre(pre, pre[low], low + 1, high);
	int t = pre[low];
	if (l != -1)
	{
		PrintPostOrderOfBSTofPreOrder(pre, low + 1, l - 1);
		PrintPostOrderOfBSTofPreOrder(pre, l, high);
	}
	cout << t << " ";
}
void InOrderUpdate(vector<int>& temp, Node* root, int flag = false)
{
	static int i = 1;
	if (!root) return;
	InOrderUpdate(temp, root->left,flag);
	if (flag)
	{
		root->info = temp[i - 1] + temp[i + 1];
		i++;
	}
	else
	{
		temp.push_back(root->info);
	}
	InOrderUpdate(temp, root->right,flag);
}
void replaceNodeWithInOrderSuccPredSum(Node* root)
{
	//Replace each node in binary tree with the sum of its inorder predecessor and successor
	vector<int> temp;
	temp.push_back(0);
	InOrderUpdate(temp, root);
	temp.push_back(0);
	InOrderUpdate(temp, root,true);
}
void PopulateInorderSuccessor(Node* root, Node*& prev)
{
	// populate inorder successor in next field
	if (!root) return;
	PopulateInorderSuccessor(root->left, prev);
	if (prev) root->next = prev;
	prev = root;
	PopulateInorderSuccessor(root->right, prev);
}
Node* FindANodeInBT(Node* root, int key)
{
	if (!root) return NULL;
	if(root->info == key) return root;
	Node* t = FindANodeInBT(root->left, key);
	if (t) return t;
	return FindANodeInBT(root->right, key);
}
int height(Node* root)
{
	if (!root) return 0;
	return 1 + max(height(root->left), height(root->right));
}
void PrintNodesAtLevelK(Node* root, int l, bool flag=false)
{
	if (!root) return;
	if (l == 0) cout << root->info << " ";
	else if(l>0)
	{
		if (flag) {
			PrintNodesAtLevelK(root->left, l - 1, flag);
			PrintNodesAtLevelK(root->right, l - 1, flag);
		}
		else
		{
			PrintNodesAtLevelK(root->right, l - 1, flag);
			PrintNodesAtLevelK(root->left, l - 1, flag);
		}
	}
}
void LevelOrderTraversal(Node* root)
{
	int h = height(root);
	for (int i = 0; i < h; i++)
	{
		PrintNodesAtLevelK(root, i);
		cout << endl;
	}
}
void LevelOrderTraversalQ(Node* root)
{
	if (!root) return;
	queue<Node*> q;
	q.push(root);
	int w = 1;
	while (!q.empty())
	{
		root = q.front(); q.pop();
		cout << root->info <<" ";
		
		if (root->left) q.push(root->left);
		if (root->right) q.push(root->right);
		
		if (--w == 0)
		{
			w = q.size(); cout << endl;
		}
	}
}
void LevelOrderTraversalSpiral(Node* root)
{
	int h = height(root);
	bool flag = true;
	for (int i = 0; i < h; i++)
	{
		PrintNodesAtLevelK(root, i, flag = !flag);
	}
}
void LevelOrderTraversalSpiralStack(Node* root)
{
	if (!root) return;
	stack<Node*>s1, s2;
	s1.push(root);
	while (!s1.empty() || !s2.empty())
	{
		while (!s1.empty())
		{
			root = s1.top(); s1.pop();
			cout << root->info << " ";
			if (root->left) s2.push(root->left);
			if (root->right) s2.push(root->right);
		}
		cout << endl;
		while (!s2.empty())
		{
			root = s2.top(); s2.pop();
			cout << root->info << " ";
			if (root->right) s1.push(root->right);
			if (root->left) s1.push(root->left);
		}
		cout << endl;
	}
}
void PostOrderUsingTwoStack(Node* root)
{
	stack<Node*>s1, d2;
	s1.push(root);
	while (!s1.empty())
	{
		root = s1.top(); s1.pop();
		d2.push(root);
		if (root->left) s1.push(root->left);
		if (root->right) s1.push(root->right);
	}
	while (!d2.empty())
	{
		cout << d2.top()->info << " ";
		d2.pop();
	}
}
void PostOrderWithoutRecusrionAndStack(Node* root)
{//	Postorder traversal of Binary Tree without recursion and without stack

	if (!root) return;
	Node* t = root;
	unordered_set<Node *> s;
	int c = 0;
	while (root && s.find(root) == s.end() )
	{
		c++;
		if (root->left &&s.find(root->left) == s.end())
			root = root->left;
		else if (root->right && s.find(root->right) == s.end())
			root = root->right;
		else
		{
			cout << root->info << " ";
			s.insert(root);
			root = t;
		}

	}

}
void PrintDiagonalUtil(Node* root, map<int, vector<int>> &m, int d)
{
	if (!root) return;
	m[d].push_back(root->info);
	PrintDiagonalUtil(root->left, m, d + 1);
	PrintDiagonalUtil(root->right, m, d);
}
void PrintDiagonal(Node* root)
{
	if (!root) return;
	map<int, vector<int>> m;
	int d = 0;
	PrintDiagonalUtil(root, m, d);

	for (auto item : m)
	{
		for (auto num : item.second)
		{
			cout << num << " ";
		}
		cout << endl;
	}
}
void BoundaryTraversalLeftSide(Node* root)
{
	if (!root) return;
	if (root->left || root->right)
		cout << root->info << " ";
	if (root->left)
		BoundaryTraversalLeftSide(root->left);
	else
		BoundaryTraversalLeftSide(root->right);
}
void BoundaryTraversalRightSide(Node* root)
{
	if (!root) return;
	if (root->left || root->right)
		cout << root->info << " ";
	if (root->right)
		BoundaryTraversalRightSide(root->right);
	else
		BoundaryTraversalRightSide(root->left);
}
void BoundaryTraversalBottomUtil(Node* root)
{
	if (!root) return;
	if (root->left== NULL  && root->right==NULL)
		cout << root->info << " ";
	BoundaryTraversalBottomUtil(root->left);
	BoundaryTraversalBottomUtil(root->right);
}
void BoundaryTraversal(Node* root)
{
	if (!root) return;
	cout << root->info << " ";
	// print left view
	BoundaryTraversalLeftSide(root->left);
	// print right view
	BoundaryTraversalBottomUtil(root);
	//print bottom
	BoundaryTraversalRightSide(root->right);

}
#pragma endregion

#pragma region Construction
Node* constructBSTofPreOrder(int pre[], int low, int high)
{
	if (low > high) return NULL;
	int l = findLocInPre(pre, pre[low], low + 1, high);
	Node* root = new Node(pre[low]);
	if (l != -1)
	{
		root->left = constructBSTofPreOrder(pre, low + 1, l - 1);
		root->right = constructBSTofPreOrder(pre, l, high);
	}
	return root;
}
Node* constructBSTofPreOrderON(int pre[], int key, int &index, int min, int max, int n)// O(n)
{
	if (key > min&& key < max)
	{
		Node* t = new Node(key);
		if (index++ < n)
		{
			t->left = constructBSTofPreOrderON(pre, pre[index], index, min, t->info, n);
			t->right = constructBSTofPreOrderON(pre, pre[index], index, t->info, max, n);
		}
		return t;

	}
	else
	{
		return NULL;
	}

}
Node* constructTreeInAndPre(int pre[], int in[], int low, int high, int& preI)
{

	if (low > high) return NULL;
	Node* root = new Node(pre[preI++]);
	if (low == high) return root;

	int l = findLoc(in, root->info, low, high);
	if (l != -1)
	{
		root->left = constructTreeInAndPre(pre, in, low, l - 1, preI);
		root->right = constructTreeInAndPre(pre, in, l + 1, high, preI);
	}
	return root;

}
Node* constructTreeInAndPost(int post[], int in[], int low, int high, int& postI)
{

	if (low > high) return NULL;
	Node* root = new Node(post[postI--]);
	if (low == high) return root;

	int l = findLoc(in, root->info, low, high);
	if (l != -1)
	{
		root->right = constructTreeInAndPost(post, in, l + 1, high, postI);
		root->left = constructTreeInAndPost(post, in, low, l - 1, postI);
	}
	return root;

}
Node* constructTreeInAndLevel(int in[], int level[], int l,int h, int n)
{
	if (l > h) return NULL;

	Node* root = new Node(level[0]);
	int loc = findLoc(in, root->info, l, h);
	if (loc == -1) return root;
	unordered_set<int> s;
	for (int i = l; i < loc; i++)
		s.insert(in[i]);
	int* leftLevel = new int[s.size()];
	int* rightLevel = new int[n-s.size()-1];
	int j = 0, k = 0;
	for (int i = 1; i <n ; i++)
	{
		if (s.find(level[i]) == s.end())
		{
			rightLevel[j++] = level[i];
		}
		else
		{
			leftLevel[k++] = level[i];

		}
	}
		root->left = constructTreeInAndLevel(in, leftLevel, l, loc - 1, s.size());
		root->right= constructTreeInAndLevel(in, rightLevel, loc + 1,h, n - s.size() - 1);
	return root;

}
void constructTreeInAndLevelDemo() {
	int in[] = { 4, 8, 10, 12, 14, 20, 22 };
	int level[] = { 20, 8, 22, 4, 12, 10, 14 };
	int n = sizeof(in) / sizeof(in[0]);
	Node *root = constructTreeInAndLevel(in, level, 0, n - 1, n);
	cout << "Inorder traversal of the "
		"constructed tree is \n";
	inorder(root);
}
Node* ConstructCompleteBTFromList(Node* list)
{
	queue<Node*> q;
	if (!list) return NULL;
	q.push(list);
	Node* root=list;
	while (!q.empty() && list)
	{
		Node* t = q.front(); q.pop();
		
		t->left = list->next;
		list = list->next;
		
		if(list)
		t->right = list->next;
		list = list->next;
		
		if(t->left)
		q.push(t->left); 
		if(t->right)
		q.push(t->right);
	}
	return root;
}

Node* ArrayToBTInsertLevelOrder(int a[], int l, int h)
{
	if (l >= h) return NULL;
	Node* root = new Node(a[l]);
	root->left = ArrayToBTInsertLevelOrder(a, 2 * l + 1, h);
	root->right = ArrayToBTInsertLevelOrder(a, 2 * l + 2, h);
	return root;
}
Node* constructTreePreAndPost(int pre[], int post[], int& index, int l, int h)
{
	if (index > h || l > h) return NULL;
	Node* root = new Node(pre[index]);
	index++;
	if (l == h) return root;
	int i = findLoc(post, root->info, l, h);
	if (i != -1)
	{
		root->left = constructTreePreAndPost(pre, post, index, l, i);
		root->right = constructTreePreAndPost(pre, post, index,  i+1,h);
	}
	return root;
}
#pragma endregion

Node* insertAtFirstEmptyLevel(Node* root, int k)
{
	if (NULL == root) return new Node(k);
	Node* t = root;
	queue<Node*> q;
	q.push(root);

	while (q.empty() == false)
	{
		Node* root = q.front(); q.pop();
		if (root->left) q.push(root->left);
		else
		{
			root->left = new Node(k);
			return t;
		}
		if (root->right) q.push(root->right);
		else
		{
			root->right = new Node(k);
			return t;
		}
	}
}
void insertAtFirstEmptyLevelDemo()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder traversal before insertion:";
	inorder(root);

	int key = 12;
	insertAtFirstEmptyLevel(root, key);

	cout << endl;
	cout << "Inorder traversal after insertion:";
	inorder(root);
}
void DeleteLeafNode(Node* root, Node* leaf)
{
	if (NULL == root) return;
	if (root->left == leaf) root->left = NULL;
	if (root->right == leaf) root->right = NULL;
	DeleteLeafNode(root->left,leaf);
	DeleteLeafNode(root->right,leaf);
}
Node* shrinkTreeAfterDeletion(Node* root, int key)
{
	if (NULL == root )return NULL;
	Node* start = root;
	queue<Node*> q;
	q.push(root);
	Node* toBeDeleted = NULL;
	Node* ParrentOflastNode = NULL;
	while (q.empty() == false)
	{
		root = q.front(); q.pop();
		if (root->info == key)
			toBeDeleted = root;
		if (root->left) q.push(root->left);
		if (root->right)q.push(root->right);
	}
	int t = root->info;
	DeleteLeafNode(start, root);
	toBeDeleted->info =t;
}
void DeleteFromTreeAndShrinkDemo()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->left->right = newNode(12);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 11;
	shrinkTreeAfterDeletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);
}
Node* CreateMirror(Node* root)
{
	if (!root) return NULL;
	Node* t = new Node(root->info);
	t->left = CreateMirror(root->right);
	t->right= CreateMirror(root->left);
	return t;
}
bool IsMirror(Node* tree1, Node* tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	if (!tree1 || !tree2)
		return false;
	return tree1->info == tree2->info
		&& IsMirror(tree1->left, tree2->right)
		&& IsMirror(tree1->right, tree2->left);
}
bool IsIdentical(Node* tree1, Node* tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	if (!tree1 || !tree2)
		return false;
	return tree1->info == tree2->info
		&& IsIdentical(tree1->left, tree2->left)
		&& IsIdentical(tree1->right, tree2->right);
}
bool IsStructureMirror(Node* tree1, Node* tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	if (!tree1 || !tree2)
		return false;
	return IsStructureMirror(tree1->left, tree2->right)
		&& IsStructureMirror(tree1->right, tree2->left);
}
bool IsFoldable(Node* tree)
{
	if (!tree)
		return true;
	return IsStructureMirror(tree->left, tree->right);
}
bool isOperator(char t)
{
	return t == '+' || t == '-' || t == '*' || t == '/';
}
Node* constructExpressionTree(string expr)
{
	stack<Node*> s;
	int len = expr.length();
	int i = 0;
	while (i < len)
	{
		if (isOperator(expr[i]) == false)
			s.push(new Node(expr[i]));
		else
		{
			Node * t = new Node(expr[i]);
			t->right= s.top(); s.pop();
			t->left = s.top(); s.pop();
			s.push(t);
		}
		i++;
	}
	return s.top();
}
void ConstructPreFixTreeDemo()
{
	char postfix[] = "ab+ef*g*-";
	Node* r = constructExpressionTree(postfix);
	printf("infix expression is \n");
	inorder(r);
}
int evalute(int l, int r, int op)
{
	switch (op)
	{
	case '+': return l + r;
	case '-': return l - r;
	case '*': return l * r;
	case '/': return l / r;
	default:
		break;
	}
}
int EvaluteExpressionTree(Node* root)
{
	if (root)
	{
		if (!root->left && !root->right)
			return root->info;
		int l = EvaluteExpressionTree(root->left);
		int r = EvaluteExpressionTree(root->right);
		return evalute(l, r, root->info);
	}
}
Node* FindSuccessorInParrent(Node* root, int key, Node*& succ)
{
	static Node* t;
	if (!root) return NULL;
	if (root->info == key || (t=FindSuccessorInParrent(root->left, key, succ)) || (t=FindSuccessorInParrent(root->right, key, succ)))
	{
		if (t && root->left ==t )
		{
			succ = root;
		}
		return root;
	}
	return NULL;
}

Node* FindInOrderSuccesor(Node* root, int key)
{
	Node* temp = FindANodeInBT(root, key);
	if (!temp) return NULL;
	if (temp->right)
	{// successor lies in right child left most path
		Node* t = root->right;
		while (t->left) t = t->left;
		return t;
	}
	else
	{
		// is it right most Node then return null
		Node* t = root;
		/*while (t->right) t = t->right;
		if (t->info == key) return NULL;*/
		t = NULL;
		 FindSuccessorInParrent(root, key,t);
		 return t;
	}

}

void CreateBTFromInOrderAndLevel()
{
	int in[] = { 4, 8, 10, 12, 14, 20, 22 };
	int level[] = { 20, 8, 22, 4, 12, 10, 14 };
	int n = sizeof(in) / sizeof(in[0]);
	Node *root = constructTreeInAndLevel(in, level, 0, n - 1, n);
}
void ListToCompleteBTDemo()
{
	Node* list = newNode(10);
	list->next = newNode(12);
	list->next->next = newNode(15);
	list->next->next->next = newNode(25);
	list->next->next->next->next = newNode(30);
	list->next->next->next->next->next = newNode(36);
	Node* t = ConstructCompleteBTFromList(list);
	inorder(t);
}

void bintree2list(Node* root,Node*&head)
{
	if (!root) return;
	bintree2list(root->right,head);
	root->right = head;
	if (head) head->left = root;
	head = root;
	bintree2list(root->left,head);
}
void printList(Node* l)
{
	if (l)
	{
		cout << l->info<<" ";
		printList(l->right);
	}
}
int main()
{
	/*Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	inorder(root);
	cout << endl;*/
	

	// Let us create the tree shown in above diagram 
	Node *root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL 
	Node *head = NULL;
	bintree2list(root,head);

	// Print the converted list 
	printList(head);
	cout << endl;
}

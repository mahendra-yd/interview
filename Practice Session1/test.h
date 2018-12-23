#include<iostream>
#include<stack>
#include<queue>
#include<map>


using namespace std;
typedef struct node { bool isThreaded; struct node *left; struct node *next; struct node *right; struct node* nextRight; int data; }Node;
//http://www.geeksforgeeks.org/custom-tree-problem/
Node * newNode(int x);
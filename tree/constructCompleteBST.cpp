#include<iostream>
#include<list>
#include<queue>
using namespace std;
//http://www.geeksforgeeks.org/ternary-search-tree/
//http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
struct node
{
  int data;
  struct node* left;
  struct node* right;
  struct node* nextRight;// level order successor
  struct node* next;// inorder successor
};
struct node* newNode(int data)
{
  struct node* node = new struct node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;
  return(node);
}
void insert(node **t,int i,queue<node*> &q)
{
  node* p= newNode(i);
  if(*t==NULL)
    *t=p;
  else
  {
    node *r = q.front();
    if(r->left==NULL) r->left=p;
    else if(r->right==NULL) {r->right=p;q.pop();} 
  }
  q.push(p);
}
void levelOrder(node *t)
{
  queue<node *> q;
  q.push(t);
  while(!q.empty())
  {
    t=q.front();q.pop();
    cout<<t->data<<" ";
    if(t->left) q.push(t->left);
    if(t->right) q.push(t->right);
  }
}
int main()
{
     node* root = NULL;
    queue<node*> q;
    int i;
    for(i = 1; i <= 12; ++i)
        insert(&root, i, q);
    levelOrder(root);
    return 0;
}

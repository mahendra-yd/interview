#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
typedef struct node
{
  int data;
  int h;
  struct node *left,*right;
}Node;
Node * newNode(int n)
{
  Node *t= new Node;
  t->left=t->right=NULL;
  t->data=n;
  t->h=1;
}
int height(Node *t) { return t==NULL?0:t->h;}
int balance(Node *t) { return height(t->left)-height(t->right);}
void preOrder(struct node *root)
{
  if(root != NULL)
  {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
int max(int a,int b) { return a>b?a:b;}
Node * rotateRight(Node *t)
{
  Node * p = t->left;
  t->left = p->right;
  p->right = t;
  t->h = max(height(t->left),height(t->right))+1;
  p->h = max(height(p->left),height(p->right))+1;
  return p;
}
Node * rotateLeft(Node *t)
{
  Node * p = t->right;
  t->right = p->left;
  p->left = t;
  t->h = max(height(t->left),height(t->right))+1;
  p->h = max(height(p->left),height(p->right))+1;
  return p;
}

Node * insert(Node* t,int n)
{
  if(!t) return newNode(n);
  if(t->data > n)
    t->left =  insert(t->left,n);
  else 
    t->right =  insert(t->right,n);
  // completed BST insertaion now update height of curr node and do rotation if needed
  t->h = max(height(t->left),height(t->right)) +1;
  int b= balance(t);
  if(b>1&&t->left->data >n)
    t =    rotateRight(t);
  if(b>1&&t->left->data<n)
  {
    t->left= rotateLeft(t->left);
    t =    rotateRight(t);
  }
  if(b<-1 && t->right->data < n)
    t=   rotateLeft(t);
  if(b<-1&&t->right->data>n)
  {
    t->right = rotateRight(t->right);
    t =   rotateLeft(t);
  }
  return t;
}
Node * deleteTree(Node* t, int n)
{
  if(!t) return t;
  if(t->data > n) 
    t->left = deleteTree(t->left,n);
  else if(t->data < n) 
    t->right = deleteTree(t->right,n);
  else 
  {
    if(t->left ==NULL)
      return t->right;
    if(t->right == NULL)
      return t->left;
    // find inorder succ that lies in right sub tree
    Node *p = t->right;
    while(p->left!=NULL) p=p->left;
    t->data=p->data;
    t->right=deleteTree(t->right,p->data);
  }

  // completed BST deletion now update height of curr node and do rotation if
  t->h = max(height(t->left),height(t->right)) +1;
  int b= balance(t);
  if(b>1&&t->left->data >n)
    t =    rotateRight(t);
  if(b>1&&t->left->data<n)
  {
    t->left= rotateLeft(t->left);
    t =    rotateRight(t);
  }
  if(b<-1 && t->right->data < n)
    t=   rotateLeft(t);
  if(b<-1&&t->right->data>n)
  {
    t->right = rotateRight(t->right);
    t =   rotateLeft(t);
  }
  return t;
}
int main(int argc, char **argv)
{
  struct node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
     30
     /  \
     20   40
     /  \     \
     10  25    50
     */

  printf("Pre order traversal of the constructed AVL tree is \n");
root=   deleteTree(root,40);
  preOrder(root);

  return 0;
}

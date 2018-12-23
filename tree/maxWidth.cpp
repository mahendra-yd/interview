#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
struct Node
{
  int data;
  struct Node* left,*right;
};
Node* newNode(int n)
{
  Node * t= new Node;
  t->data = n;
  t->left= t->right =NULL;
  return t;
}
int height(Node *t)
{
  if (!t) return 0;
  return 1+ max(height(t->left),height(t->right));
}
int getCount(Node *t,int n)
{
  if(!t) return 0;
  if(n==0) return 1;
  return getCount(t->left,n-1) + getCount(t->right,n-1);
}
int getMaxWidth(Node *t)
{
  int h = height(t);
  int max=-999;
  for(int i=0;i<h;i++)
  {
    int l=getCount(t,i);
    if(l>max) max=l;
  }
  return max;
}
void util(Node *t,int *p, int l)
{
if(!t) return ;
p[l]++;
util(t->left,p,l+1);
util(t->right,p,l+1);
}
int getMaxWidth1(Node *t)
{
int h = height(t);
int *c = new int [h];
util(t,c,0);
int m=-9999;
for(int i=0;i<h;i++) 
if(c[i]>m) m=c[i];
return m;
}
int main(int argc, char **argv)
{
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);    
  root->right->right->left  = newNode(6);    
  root->right->right->right  = newNode(7);      

  /*
     Constructed bunary tree is:
     1
     /  \
     2    3
     /  \     \
     4   5     8 
     /  \
     6   7
     */ 
  printf("Maximum width is %d \n", getMaxWidth1(root));  

  return 0;
}

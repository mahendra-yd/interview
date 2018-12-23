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
  struct node* left;
  struct node* right;

}Node ;

struct node* newNode(int data) // new node
{
  struct node* node = new Node; 
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
int height(Node *t)
{
if(!t) return 0;
int h1 = height(t->left );
int h2 = height(t->right );
int h =  h1>h2?h1:h2  ;
return h+1;
}
// max of sum of heghit of left sub tree and right sub tree and diameter of left and right sub tree
int diameter(Node *t) // o(n^2)
{
if(!t) return 0;
int h1=height(t->left);
int h2=height(t->right);
int h = h1+h2+1;
int d1=diameter(t->left);
int d2=diameter(t->right);
int d=d1>d2?d1:d2;
return h>d?h:d;
}

int max(int a,int b){return a>b?a:b;}
int diameter1(Node *t, int& h)
{
if(!t) return 0;
int lh=0,rh=0;
int d1=diameter1(t->left,lh);
int d2=diameter1(t->right,rh);
h=lh>rh?lh:rh;
h++;
return max(lh+rh+1,max(d1,d2));
}
int main(int argc, char **argv)
{
  /* Constructed binary tree is 
     1
     /   \
     2      3
     /  \
     4     5
     /       \
     3         6
     \          \
     5          7
     */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->left->left  = newNode(3);
  root->left->left->left->right  = newNode(5);
  root->left->right = newNode(5);
  root->left->right->right = newNode(6);
  root->left->right->right->right = newNode(7);
  printf("Diameter of the given binary tree is %d\n", diameter(root));
  int h=0;
  printf("Diameter of the given binary tree is %d\n", diameter1(root,h));
  return 0;
}

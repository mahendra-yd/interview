#include<iostream>
#include<list>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}
int findIndex(char *in,int l,int h,char c)
{
  for(int i=l;i<=h;i++)
  {
    if(in[i]==c)
      return i;
  }
}
node * buildTree(char *in,char *pre,int l,int h,int *inindex)
{
  if(l>h) return NULL;
  node *t=newNode(pre[*inindex]);
  *inindex=(*inindex )+1;
  if(l==h) return t;
  int m=findIndex(in,l,h,t->data);
  t->left=buildTree(in,pre,l,m-1,inindex);
  t->right=buildTree(in,pre,m+1,h,inindex);
  return t;
}
node * constructTree(int* in,char* ln,int n,int& ref)
{
  if(ref==n) return NULL;
  node *root = newNode(in[ref]);
  int c= ref;
  ref++;
  if(ln[c]=='N')
  {
    root->left = constructTree(in,ln,n,ref); 
    root->right = constructTree(in,ln,n,ref); 
  }
  return root;
}
bool isCompleteBT(node * t)
{
  if(!t) return true;
  queue<node*> q;
  q.push(t);
  bool f=true;
  while(!q.empty())
  {   
    t=q.front();q.pop();
    if(t->left) { if(!f) return false; q.push(t->left);}else f=false;
    if(t->right){if(!f) return false;  q.push(t->right);} else f=false;
  }
  return true;
}
void printLeft(node *t)
{
  if(!t) return;
  if(t->left==NULL&& t->right==NULL) return; // do not print leaf node
  cout<<t->data<<" ";
  if(t->left) printLeft(t->left);
  else if(t->right) printLeft(t->right);
}
void printRight(node *t)
{
  if(!t) return;
  if(t->left==NULL&& t->right==NULL) return; // do not print leaf node
  cout<<t->data<<" ";
  if(t->right) printRight(t->right);
  else if(t->left) printRight(t->left);
}
void printBottom(node *t)
{
  if(!t) return;
  if(t->left==NULL&& t->right ==NULL)
    cout<<t->data<<" ";
  printBottom(t->left);
  printBottom(t->right); 
}
void printBoundary(node *t)
{
  if(!t) return ;
  cout<<t->data;
  printLeft(t->left);
  printBottom(t);
  printRight(t->right);
}
node *prePostUtil(int pre[],int post[],int n,int& ref,int l,int h)
{
  if( ref > n || l > h ) return NULL; 
  node *t = newNode(pre[ref]);
  ref++;
  if(l==h) return t;
  int i=0;
  for( i=l;i<=h;i++){if(pre[ref]==post[i]) break;}
  if(i<h)
  {
    t->left  =prePostUtil( pre,post,n,ref,l,i); 
    t->right = prePostUtil(pre,post,n,ref,i+1,h);
  }
  return t;
}
node * constructTreePrePost(int pre[],int post[],int n)
{
  int ref=0;
  return prePostUtil(pre,post,n,ref,0,n-1);
}
int main()
{
  /*
     char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
     char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
     int len = sizeof(in)/sizeof(in[0]);
     int inindex=0;
     int n = sizeof(pre)/sizeof(pre[0]);
     root = constructTree (pre, preLN, n);
     struct node *root = buildTree(in, pre, 0, len - 1,&inindex);
     printf("\n Inorder traversal of the constructed tree is \n");
     */
  /*
     int pre[] = {10, 30, 20, 5, 15};
     char preLN[] = {'N', 'N', 'L', 'L', 'L'};
     int ref=0;
     node* root = constructTree(pre,preLN,sizeof(pre)/sizeof(pre[0]),ref);
     printInorder(root);
     */
  /*
     struct node *root  = newNode(1);
     root->left         = newNode(2);
     root->right        = newNode(3);
     root->left->left   = newNode(4);
     root->left->right  = newNode(5);
     root->right->left = newNode(6);
     if ( isCompleteBT(root) == true )
     printf ("Complete Binary Tree");
     else
     printf ("NOT Complete Binary Tree");
     */
  int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
  int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
  int size = sizeof( pre ) / sizeof( pre[0] );
  struct node *root = constructTreePrePost(pre, post, size);
  printInorder(root);
  return 0;
}

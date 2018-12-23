#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
// construct binary tree given in order and post order.
struct Node 
{
  int data;
  struct Node * left,*right;
};

Node * newNode(int n) { Node *t = new Node; t->data=n;t->left=t->right=NULL; return t;}
int find (char* in,int l,int h,char c)
{
  for(int i=l;i<=h;i++)
    if(in[i]==c) return i;
  return -1;
}

Node *construct(char *in,char *post,int inl,int inh,int& postl)
{
  if(inl>inh) return NULL;
  Node *p = newNode(post[postl]);
  postl--;
  //  if(inl==inh) return p;
  int l = find(in,inl,inh,p->data);
  if(l<0) return NULL;
  p->right = construct(in,post,l+1,inh,postl);
  p->left = construct(in,post,inl,l-1,postl);
  return p;
}
void inr(Node *t)
{
  if(!t) return ;
  inr(t->left);
  printf("%c ",t->data);
  inr(t->right);
}
int main(int argc, char **argv)
{
  char in[] =   "dbeac";
  char post[] = "debca";
  int pi= sizeof(post)-1;
  Node * root = construct(in,post,0,sizeof(in)-1,pi);
  inr(root);
  return 0;
}

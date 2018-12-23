#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<map>
#include<list>
using namespace std;
struct Node
{
int data;
struct Node *left,*right;
};
Node * newNode(int n)
{
Node *t = new Node;
t->data=n;
t->left=t->right=NULL;
return t;
}

Node * insert(Node *root, int n)
{
  if(root==NULL) { root=newNode(n); return root;}
  if(root->data > n) root->left=insert(root->left,n);
  else root->right = insert(root->right,n);
  return root;
}

Node *insertI(Node *t, int n)
{
  if(t==NULL)return newNode(n);
  Node *p;
  while(t!=NULL)
  {
    p=t;
    if(t->data>n) t=t->left;
    else t=t->right;
  }
  if(p->data>n) p->left = newNode(n);
  else p->right=newNode(n);
  return t;
}  
Node * find(Node *t,int n,Node **p)
{
  while(t!=NULL && t->data !=n)
  {
    *p=t;
    if(t->data>n) t=t->left;
    else t=t->right;
  }
  if(t==NULL) return NULL;
  else return t;
}

bool Delete(Node *p, Node* par)
{
  if(p->left==NULL&&p->right==NULL){ if(par->left==p) par->left=NULL;else par->right=NULL; delete p;return true; }
  if(p->left==NULL) { if(par->left==p) par->left=p->right; else par->right=p->right;return true;}
  if(p->right==NULL) { if(par->left==p) par->left=p->left; else par->right=p->left;return true;}
 return false;
}

Node * deleteI(Node *t, int n)
{
  Node *par;
  Node *p = find(t,n,&par);
  if(p==NULL) return NULL;
  if(Delete(p,par)) return p;

  Node * tmp= p->right;
if(tmp->left==NULL) par=p;
else
  while(tmp->left!=NULL) {par=tmp;  tmp=tmp->left;}
  p->data=tmp->data;
  if(  Delete(tmp,par)) return tmp;
  return NULL;
}
void in(Node *t) { if(!t) return;  in(t->left); printf("%d ",t->data);in(t->right);}

void preI(Node *t)
{
  stack<Node *> s;
  s.push(t);
  while(!s.empty())
  {
    t=s.top();s.pop();
    cout<<t->data<<" ";
    if(t->right) s.push(t->right);
    if(t->left) s.push(t->left);
  }
}
void inI(Node * t)
{
  stack<Node*> s;
label:
  while(t!=NULL){ s.push(t); t=t->left;}
  while(!s.empty())
  {
    t=s.top();s.pop();
    cout<<t->data<<" ";
    if(t->right){ t=t->right; goto label;}
  }
}
void postI(Node* t)
{
  stack<Node*> s;
label:
  while(t!=NULL){ if(t->right) s.push(t->right);s.push(t);t=t->left;}
  while(!s.empty())
  {
    t=s.top();s.pop();
   
    if(!s.empty()&&  t->right==s.top()){ Node *p=s.top();s.pop();s.push(t); t=p;goto label;}
    cout<<t->data<<" ";
  }
}
void postII(Node* t)
{
  stack<long int> s;
long int i;
label:
  while(t!=NULL){ if(t->right) s.push(-(long int )t->right);s.push((long int)t);t=t->left;}
  while(!s.empty())
  {
    i=s.top();s.pop();
 if(i<0) { t=(Node*) -i; goto label;}
   t=(Node*) i;
    cout<<t->data<<" ";
  }
}

void printLeft(Node *t)
{
if(!t) return;
//if(t->left==NULL&&t->right==NULL) return;
cout<<t->data<<" ";
if(t->left){ printLeft(t->left);}
else 
if(t->right) {  printLeft(t->right);}
}
void printRight(Node *t)
{
if(!t) return;
if(t->left==NULL&&t->right==NULL) return;
if(t->right){ printLeft(t->right);}
else if(t->left) {  printLeft(t->left);}
cout<<t->data<<" ";
}
void printLeaf(Node *t)
{
if(!t) return;
if(t->left==NULL && t->right==NULL) cout<<t->data<<" ";
if(t->left) printLeaf(t->left);
if(t->right) printLeaf(t->right);
}
void boundry(Node* t)
{
if(!t) return ;
cout<<t->data<<" ";
printLeft(t->left);
printLeaf(t);
printRight(t->right);
}  
void topViewUtil(Node *t,int d,int& l,int& r)
{
if(d<l){ cout<<t->data<<" "; l=d;}
if(d>r){ cout<<t->data<<" "; r=d;}
if(t->left) topViewUtil(t->left,d-1,l,r);
if(t->right) topViewUtil(t->right,d+1,l,r);
}
void topView(Node *t)
{
if(!t) return;
int l=0,h=0;
cout<<t->data<<" ";
topViewUtil(t,0,l,h);

}
int arr[100]={0,};
//multimap<int ,int> M;
void bottomViewUtil(Node *t,int d,int& l,int& r)
{
  //M.insert(pair<int,int>(d,t->data));
  if(d<0) arr[d+50]=t->data;
  else arr[d]=t->data;
  cout<<d<<" "<<t->data<<endl;
  if(d>r){r=d;}
  if(d<l){l=d;}
  if(t->left) bottomViewUtil(t->left,d-1,l,r);
  if(t->right) bottomViewUtil(t->right,d+1,l,r);
}
void bottomView(Node* t)
{
  int l=0,h=0;
  int p=0;
  bottomViewUtil(t,0,l,h);
for(int i=0;i<100 ;i++)
  {
      if(arr[i]) 
    cout<<arr[i]<<" ";
  }

}
struct Node *pruneUtil(struct Node *root, int k, int *sum)
{
  if (root == NULL)  return NULL;
  int lsum = *sum + (root->data);
  int rsum = lsum;
  root->left = pruneUtil(root->left, k, &lsum);
  root->right = pruneUtil(root->right, k, &rsum);
  *sum = max(lsum, rsum);
  if (*sum < k)
  {
    free(root);
    root = NULL;
  }
  return root;
}
 
// A wrapper over pruneUtil()
struct Node *prune(struct Node *root, int k)
{
    int sum = 0;
    return pruneUtil(root, k, &sum);
}
int main(int argc, char **argv)
{
  Node *root=NULL;
  root=insert(root,10);
  root=insert(root,7);
  root=insert(root,9);
  root=insert(root,5);
  root=insert(root,3);
  root=insert(root,6);
  root=insert(root,15);
  root=insert(root,12);
  root=insert(root,16);
  bottomView(root);

  return 0;
}

#include<stdio.h>
#include<limits.h>
#define true 1;
#define false 0
struct _Node
{
  int data;
  struct _Node *left,*right;
};
typedef struct _Node Node;

Node * newNode(int n)
{
  Node *t =  (Node*)malloc(sizeof(Node));
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

int Delete(Node *p, Node* par)
{
  if(p->left==NULL&&p->right==NULL){ if(par->left==p) par->left=NULL;else par->right=NULL; return true; }
  if(p->left==NULL) { if(par->left==p) par->left=p->right; else par->right=p->right;return true;}
  if(p->right==NULL) { if(par->left==p) par->left=p->left; else par->right=p->left;return true;}
  return false;
}

int  deleteI(Node *t, int n)
{
  Node *par;
  Node *p = find(t,n,&par);
  if(p==NULL) return false;
  if(Delete(p,par)) return true;

  Node * tmp= p->right;
if(tmp->left==NULL) par=p;
else
  while(tmp->left!=NULL) {par=tmp;  tmp=tmp->left;}
  p->data=tmp->data;
  if(  Delete(tmp,par)) return true;
  return false;
}
void in(Node *t) { if(!t) return;  in(t->left); printf("%d ",t->data);in(t->right);}

void preI(Node *t)
{



}
int main(int argc, char **argv)
{
  Node *root=NULL;
  root=insert(root,10);
  root=insert(root,7);
  root=insert(root,9);
  root=insert(root,6);
  root=insert(root,5);
  root=insert(root,15);
  root=insert(root,12);
  root=insert(root,16);
  in(root);
deleteI(root,15);
printf("\n\n");
  in(root);

  return 0;
}

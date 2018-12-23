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
    struct node *left, *right;
}Node;
 struct node *newNode(int item)
{
    struct node *temp = new Node; 
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
Node * insert(Node *t,int data)
{
  if(!t) return newNode(data);
  if(t->data> data) 
    t->left = insert(t->left,data);
  else
    t->right = insert(t->right,data);
  return t;
}
Node * search(Node * t, int data)
{
  if(!t) return t;
  if(t->data == data) return t;
  if(t->data >data) return search(t->left,data);
  else return search(t->right,data);
}
Node * getMin(Node *t)
{
  while(t->left!=NULL) t=t->left;
  return t;
}
Node * deleteNode(Node * t, int data)
{
  if(!t) return t;
  if(t->data > data) t->left = deleteNode(t->left,data);
  else if( t->data < data) t->right = deleteNode(t->right,data);
  else // Node to be deleted
  {
    if(t->left==NULL) return t->right;
    else if(t->right==NULL) return t->left;
    Node *tmp = getMin(t->right);
    t->data = tmp->data;
    t->right = deleteNode(t->right,tmp->data);
  }
    return t;
}
// find inorder predesor and successor 
void findPreSuc(Node* t, Node*& pre, Node*& suc, int key)
{
  if(!t) return;
  if(t->data ==key)
  {
   if(t->left) { Node *p =t->left; while(p->right!=NULL) p=p->right; pre=p;}
   if(t->right) { Node *p =t->right; while(p->left!=NULL) p=p->left; suc=p;}
   return;
  }
  else if(t->data >key ) 
  {
    suc=t;
    findPreSuc(t->left,pre,suc,key);
  }
  else
  {
    pre=t;
    findPreSuc(t->right,pre,suc,key);
  }
}
bool isBSTutil(Node *t , int min, int max)
{
if(!t) return true;
if(t->data < min || t->data > max ) return false;
 return isBSTutil(t->left,min,t->data) && isBSTutil(t->right,t->data,max);
}
bool isBST(Node* t)
{
if(!t) return true;
return isBSTutil(t,INT_MIN,INT_MAX);
}
Node * LCA(Node *t,int a, int b)
{
if(t->data >a && t->data >b ) 
return LCA(t->left,a,b);
if(t->data <a && t->data <b ) 
return LCA(t->right,a,b);
return t;
}
Node *LCAI(Node *t,int a,int b) // iterative lowest common ancestor
{
  while(t!=NULL)
  {
    if(t->data >a && t->data >b )
      t=t->left;
    else if(t->data <a && t->data <b )
      t=t->right;
    else
      break;
  }
  return t;
}
Node * constructBSTutil(int pre[],int l,int h,int n)
{
  if(l>=n || l>h) return NULL;
  Node *t = newNode(pre[l]);
  int i=0;
  for(i=l;i<=h;i++) if(pre[l]<pre[i]) break; 
  //if(i==h) return t;
  t->left = constructBSTutil(pre,l+1,i-1,n);
  t->right = constructBSTutil(pre,i,h,n);
  return t;
}
Node * constructBSTutil1(int pre[],int& l,int min,int max,int n)
{
  if(l>=n) return NULL;
  Node *t = NULL;
  if(pre[l]>min && pre[l] <max)
  {
    t=newNode(pre[l++]);
    t->left= constructBSTutil1(pre,l,min,t->data,n);
    t->right= constructBSTutil1(pre,l,t->data,max,n);
  }
  return t;
}

Node * constructBST(int pre[],int n)
{
  int l=0;
  //return constructBSTutil(pre,0,n-1,n); // n2
  return constructBSTutil1(pre,l,INT_MIN,INT_MAX,n); // o(n)
}
int ceil(Node *t,int k)
{
  if(!t) return ;
  if(t->data == k) return k;
  if(t->data < k)
    return ceil(t->right,k);
  int c = ceil(t->left,k);
  return c==k?c:t->data;
}
int floor(Node *t,int k)
{
  if(!t) return -1;
  if(t->data ==k) return k;
  if(t->data > k) return floor(t->left,k);
  int f = floor(t->right,k);
  return f==c?f:t->data;
}
int main(int argc, char **argv)
{
  int pre[] = {10, 5, 1, 7, 40, 50};
  /* Let us create following BST
     50
     /     \
     30      70
     /  \    /  \
     20   40  60   80 */
  struct node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  root =  constructBST(pre,sizeof(pre)/sizeof(pre[0]));
  //    cout<<LCA(root,60,40)->data;
  inorder(root);
  return 0;
}

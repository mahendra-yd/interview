#include<iostream>
#include<list>
using namespace std;

struct Node
{
int data;
int count;
struct Node *left;
struct Node *right;
};

typedef pair<int,int> A;
Node * newNode(int v)
{
Node *tmp = new Node;
tmp->data=v;
tmp->count=1;
tmp->left=NULL;
tmp->right=NULL;
return tmp;
}
class BST
{
  public :
    Node * root;
    BST(){root=NULL;}

    void insert(int data)
    {
      if(root==NULL){
        root=newNode(data); return;}

      Node *tmp = root;
      Node *par = NULL;

      while(tmp!=NULL)
      {
        par =tmp;
        if(tmp->data==data) {tmp->count++; return;}
        else if(tmp->data < data){ tmp=tmp->right;}
        else tmp=tmp->left;
      }
      if(par->data > data) par->left = newNode(data);
      else par->right = newNode(data);
      return;
    }
    A max( Node *tmp )
    {
      static int count=0;
      static int data=0;
      if(tmp!=NULL)
      {
        max(tmp->left);
        max(tmp->right);
        if(tmp->count > count){ data = tmp->data;
          count = tmp->count;}
        return A(count,data);
      }
    }



};
A printMajority(int a[], int size)
{
  BST bst;
  for(int i=0;i<size;i++)
    bst.insert(a[i]);
   A b = bst.max(bst.root);
   if(b.first>=size/2)
   	return b;
   	return A(0,0);
}
A printMajority1(int a[], int size)
{
  int i=0,j=0;
  int count=1;

  for(i=1;i<size;i++)
  {
    if(a[i]==a[j])
      count++;
    else
      count--;
    if(count==0)
      j=i;
  }
  count=0;
  for(i=0;i<size;i++)
    if(a[i]==a[j])
      count++;

  if(count>=size/2)
  {
  cout<<a[j]<<endl;
    A b(a[j],j);
    return b;
  }
  return A (0,0);
}

int main()
{
  int a[] = {1, 5, 5, 5, 2};
  A b =   printMajority(a, 5);
  cout<<b.first<<b.second<<endl;
  return 0;
}


/* Program to print all nodes which are at distance k from a leaf */
#include <iostream>
using namespace std;
#define MAX_HEIGHT 10000
struct Node
{
  int key;
  Node *left, *right;
};

/* utility that allocates a new Node with the given key  */
Node* newNode(int key)
{
  Node* node = new Node;
  node->key = key;
  node->left = node->right = NULL;
  return (node);
}
void util(Node *t,int p[],bool v[],int i,int k)
{
  if(!t) return;
  p[i]=t->key;
  v[i]=false;

  if(t->left==NULL && t->right==NULL)
  {
    if(i-k>=0 && v[i-k]==false) { cout<<p[i-k];v[i-k]=true;}
  }
  i++;
  util(t->left,p,v,i,k);
  util(t->right,p,v,i,k);

}
void printKDistantfromLeaf(Node * t,int k)
{
  int path[MAX_HEIGHT];
  bool visited[MAX_HEIGHT]={false,};
  util(t,path,visited,0,k);
}
/* Driver program to test above functions*/
int main()
{
  // Let us create binary tree given in the above example
  Node * root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);

  cout << "Nodes at distance 2 are: ";
  printKDistantfromLeaf(root, 1);
  return 0;
}

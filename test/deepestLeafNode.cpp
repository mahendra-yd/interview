#include <stdio.h>
#include <iostream>
#include<limits.h>
using namespace std;
struct Node
{
    int val;
    struct Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}

void util(Node *t,Node **res,bool isLeft,int max,int level)
{
  if(!t) return;

  if(isLeft&&t->left==NULL&&t->right==NULL&&max<level)
  {
    *res=t;
    max=level;
    return;
  }
  util(t->left,res,false,max,level+1);
  util(t->right,res,true,max,level+1);

}
Node * deepestLeftLeaf(Node *t)
{
int max=INT_MIN;
Node * res;
util(t,&res,false,max,0);
return res;
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    Node *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->val;
    else
        cout << "There is no left leaf in the given tree";
 
    return 0;
}


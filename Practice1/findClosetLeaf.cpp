#include <iostream>
#include <limits.h>
using namespace std;
struct Node
{
    char key;
    struct Node* left, *right;
};
 
Node *newNode(char k)
{
    Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
int getMin(int x, int y)
{
    return (x < y)? x :y;
}
int  NLRoot(Node *t)
{
if(!t) return 0;
return 1+ getMin(NLRoot(t->left),NLRoot(t->right));
}
int util(Node *t,char k, Node* a[], int l)
{
  if(!t) return INT_MAX;
  if(t->key==k)
  {
    int h= NLRoot(t);
    for( int i=l;i>=0 && i<=h;i++)
      h = getMin(h,l-i+NLRoot(a[i]));
  }
  else {
    a[l]=t;
    return getMin(util(t->left,k,a,l+1),(util(t->left,k,a,l+1)));
  }
}
int  findClosest(Node *t, char k)
{
Node* a[100];
return util(t,k,a,0);
} 
int main()
{
    struct Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
 
    return 0;
}

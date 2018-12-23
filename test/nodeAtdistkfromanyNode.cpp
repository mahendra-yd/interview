#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
void printkdistanceNodeDown(node *root, int k)
{
    if (root == NULL || k < 0)  return;
    if (k==0)    {        cout << root->data << endl;        return;    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}
int printkdistanceNode(node* root, node* target , int k)
{
    if (root == NULL) return -1;
    if (root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }
    int dl = printkdistanceNode(root->left, target, k);
    if (dl != -1)
    {
         if (dl + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->right, k-dl-2);
         return 1 + dl;
    }
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }
    return -1;
}
 
// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}

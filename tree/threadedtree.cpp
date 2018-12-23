#include <iostream>
#include<iostream>
#include <queue>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    bool isThreaded;
};
 
void populateQueue(Node *root, std::queue <Node *> *q)
{
    if (root == NULL) return;
    if (root->left)
        populateQueue(root->left, q);
    q->push(root);
    if (root->right)
        populateQueue(root->right, q);
}
void createThreadedUtil(Node *root, std::queue <Node *> *q)
{
    if (root == NULL) return;
    if (root->left)
        createThreadedUtil(root->left, q);
    q->pop();
    if (root->right)
        createThreadedUtil(root->right, q);
    else
    {
        root->right = q->front();
        root->isThreaded = true;
    }
}
 
void createThreaded(Node *root)
{
    std::queue <Node *> q;
    populateQueue(root, &q);
    createThreadedUtil(root, &q);
}
Node *leftMost(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
void inOrder(Node *root)
{
    if (root == NULL) return;
    Node *cur = leftMost(root);
    while (cur != NULL)
    {
        cout << cur->key << " ";
        if (cur->isThreaded)
            cur = cur->right;
        else 
            cur = leftMost(cur->right);
    }
}
 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->key = key;
    return temp;
}
void createThreaded1(Node *t,Node *p)
{
  if(!t) return;
  createThreaded1(t->right,p);
  if(p==NULL) {p=t;}
  else if  (t->right==NULL) {t->right=p;t->isThreaded=1;}
  p=t;
  createThreaded1(t->left,p);
}

int main()
{
    /*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
  //  createThreaded(root);
    createThreaded2(root,NULL);
    cout << "Inorder traversal of creeated threaded tree is\n";
    inOrder(root);
    return 0;
}

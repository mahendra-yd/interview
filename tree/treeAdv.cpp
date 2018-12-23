#include<iostream>
#include<stdlib.h>
#include<list>
#include<limits.h>
#include<stdio.h>
using namespace std;
// 1-> take each elemnet of 1st tree and add to 2nd tree.
//2-> convert both tree in inorder array and then merge both array and then construct tree using merge tree
//3-> inplace merging of tree using doubly link list. convert both tree in dll adn then merge both dll and then construct tree.
/*
struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
  if (a == NULL) 
    return(b);
  else if (b==NULL) 
    return(a);
  if (a->data <= b->data) 
  {
    result = a;
    result->next = SortedMerge(a->next, b);
  }
  else
  {
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return(result);
}
*/

struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}
void printList(node *l)
{
  node *p=l;
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->right;
  }
  cout<<endl;
}

void BinaryTree2DoubleLinkedList(node *root, node **head)
{
  if (root == NULL) return;
  static node* prev = NULL;
  BinaryTree2DoubleLinkedList(root->left, head);
  if (prev == NULL)
    *head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  BinaryTree2DoubleLinkedList(root->right, head);
}


node *p=NULL;
void treeToList(node* t,node** l) //convert tree to doubly link list
{
  if(t==NULL) return;
  treeToList(t->left,l);
  if(p==NULL)
    *l=t;
  else
  {
    t->left=p;
    p->right=t;
  }
  p=t;
  treeToList(t->right,l);
}
node * mergeSortedList(node *l1,node*l2)
{
  node * l=NULL;
  node * p=NULL;
  while(l1!=NULL && l2!=NULL)
  {
    if(l1->data < l2->data) 
    { 
      if(NULL==p) 
      {
	l=l1;
	p=l1;
      }
      else
      {
	p->right=l1;
	l1->left=p;
	p=p->right;
      }
      l1=l1->right;
    }
    else
    {
      if(NULL==p)
      {
	l=l2;
	p=l2;
      }
      else{
	p->right=l2;
	l2->left=p;
	p=p->right;
      }
      l2=l2->right;
    }
  }
  if(l1!=NULL) {p->right=l1;l1->left=p;}
  if(l2!=NULL) {p->right=l2;l2->left=p;}
  return l;
}
int sizeOFList(node *l)
{
  int count=0;
  while(l!=NULL) {
    count++;
    l=l->right;
  }
  return count;
}
node* listToTree(node **l,int n)
{
  if(n<=0 ) return NULL;
  node *left,*right;
  left = listToTree(l,n/2);
  node * root= *l;
  (*l) = (*l)->right;
  root->left=left;
  right = listToTree(l,n-n/2-1);
  root->right=right;
  return root;
}
node * mergeTrees(node *t1, node* t2)
{
  node *l1,*l2,*l;
  p=NULL;
  treeToList(t1,&l1);
  printList(l1);
  p=NULL;
  treeToList(t2,&l2);
  printList(l2);
  l = mergeSortedList(l1,l2);
  printList(l);
  node *t= listToTree(&l,sizeOFList(l));
  return t;
  return NULL;
}

void storeInorder (struct node* node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;
    storeInorder (node->left, inorder, index_ptr);
    inorder[*index_ptr] = node->data;
    (*index_ptr)++;  // increase index for next entry
    storeInorder (node->right, inorder, index_ptr);
}
int countNodes (struct node* root)
{
    if (root == NULL)
     return 0;
    return countNodes (root->left) +
           countNodes (root->right) + 1;
}
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
void arrayToBST (int *arr, struct node* root, int *index_ptr)
{
    if (root == NULL)
      return;
 
    arrayToBST (arr, root->left, index_ptr);
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    arrayToBST (arr, root->right, index_ptr);
}
// first copy(inorder) data of treein arry and then sort array then again do inorder traverse and copy arry data in tree
void binaryTreeToBST (struct node *root) // convert any tree to BST having the same shape
{
    if(root == NULL)
       return;
    int n = countNodes (root);
    int *arr = new int[n];
    int i = 0;
    storeInorder (root, arr, &i);
    qsort (arr, n, sizeof(arr[0]), compare);
    i = 0;
    arrayToBST (arr, root, &i);
    delete [] arr;
}

int main()
{
  /* Create following tree as first balanced BST
     100
     /  \
     50    300
     / \
     20  70
     */
  struct node *root1  = newNode(100);
  root1->left         = newNode(50);
  root1->right        = newNode(300);
  root1->left->left   = newNode(20);
  root1->left->right  = newNode(70);

  /* Create following tree as second balanced BST
     80
     /  \
     40   120
     */
  struct node *root2  = newNode(80);
  root2->left         = newNode(40);
  root2->right        = newNode(120);
  struct node *mergedTree = mergeTrees(root1, root2);
  printf ("Following is Inorder traversal of the merged tree \n");
  printInorder(mergedTree);

  return 0;
}

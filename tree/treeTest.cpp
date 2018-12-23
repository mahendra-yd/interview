#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<map>
using namespace std;

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
}Node ;
struct node* newNode(int data)
{
  struct node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;
  return(node);
}
void connect(Node *t)
{
  queue<Node*> q;
  q.push(t);
  Node m;
  q.push(&m);
  Node *prev=NULL;
  while(!q.empty())
  {
   t=q.front();q.pop();
   if(t==&m) // new level is starting
   {
     if(q.empty()) break;
      prev=NULL; 
      q.push(t);
   }
    else 
   {
//      cout<<t->data;
      if(prev==NULL) prev=t;
      else { prev->nextRight=t; prev=t;}
      if(t->left) q.push(t->left);
      if(t->right) q.push(t->right);
   }
  }
} 
void vSumUtil(Node *t, map<int,int> &m, int h)
{
  if(!t) return;
  m[h]+=t->data;
  vSumUtil(t->left,m,h-1);
  vSumUtil(t->right,m,h+1);
}

int verticalSum(Node *t)
{
  map<int,int> m;
  vSumUtil(t,m,0);
  for(map<int,int>::iterator i =m.begin();i!=m.end();i++)
    printf("%d %d\n",i->first,i->second);
  return 0;
}
void maxSumUtil(Node *t,int & maxSum,int max,Node * & p)
{
  if(!t) return ;
  max+=t->data;
  maxSumUtil(t->left,maxSum,max,p);
  maxSumUtil(t->right,maxSum,max,p);
  if(t->left==NULL && t->right == NULL)
  {
   if(max>maxSum){ maxSum=max;  p=t;}
  }
}
bool printPath(Node *t , Node *p)
{
if(!t) return false;
if(t==p || printPath(t->left,p) || printPath(t->right,p)){ cout<<t->data; return true;}
}
int maxSum(Node * t)
{
if(!t) return 0;
Node *p;
int maxSum=-999;
maxSumUtil(t,maxSum,0,p);
printPath(t,p);
return maxSum;
}
void MorrisPre(node * root)
{
  if(!root) return ;
  while(root!=NULL)
  {
    if(root->left==NULL)
    {
      cout<<root->data<<" ";
      root=root->right;
    }
    else {
      // find inporder predessor
      Node *p=root->left;
      while(p->right!=NULL && p->right != root) p=p->right;
      if(p->right==NULL){
	cout<<root->data<<" ";
	p->right = root;
	root= root->left; }
      else {
	p->right =NULL;
	root=root->right; }
    }
  }
}

void MorrisIn(node * root)
{
  if(!root) return ;
  while(root!=NULL)
  {
    if(root->left==NULL)
    {
      cout<<root->data<<" ";
      root=root->right;
    }
    else  { // find inporder predessor
      Node *p=root->left;
      while(p->right!=NULL && p->right != root) p=p->right;
      if(p->right==NULL) {
	p->right = root;
	root= root->left; }
      else {
	cout<<root->data<<" ";
	p->right =NULL;
	root=root->right; }
    }
  }
}
void in(node *t)
{
if(!t) return; in(t->left);cout<<t->data<<" ";in(t->right);
}
void post2Stack(Node * t)
{
  stack<Node* >s1,s2;
  if(!t) return ;
  s1.push(t);
  while(!s1.empty())
  {
    t = s1.top();s1.pop();
    s2.push(t);
    if(t->left) s1.push(t->left);
    if(t->right) s1.push(t->right);
  }
 while(!s2.empty()){ cout<<s2.top()->data<<" ";s2.pop();}
}
Node * treeToDLL(Node *t)
{
  if(!t) return t;
  static node * prev=NULL;
  treeToDLL(t->left);
  if(prev==NULL) prev=t;
  else
  {
    prev->right=t;
    t->left=prev;
    prev=t;
  }
  treeToDLL(t->right);
  return t;
}
void leftViewUtil(Node *t,int level,int & max)
{
  if(!t) return ;
  if(level>max) { cout<<t->data<<" "; max=level;}
  leftViewUtil(t->left,level+1,max);
  leftViewUtil(t->right,level+1,max);
}
void  leftView(Node *t)
{
  int maxLevel=0;
  leftViewUtil(t,1,maxLevel);
}
void rightViewUtil(Node *t, int level,int& max)
{
  if(!t) return;
  if(level > max) { cout<<t->data<<" ";max=level;}
  rightViewUtil(t->right,level+1,max);
  rightViewUtil(t->left,level+1,max);
}
void rightView(Node* t)
{
  int max=0;
  rightViewUtil(t,1,max);
}
void topViewUtil(Node *t,int cur,int &l,int& r)
{
  if(!t) return ;
  if(cur<l) { cout<<t->data<<" "; l=cur;}
  if(cur>r) { cout<<t->data<<" "; r=cur;}
  topViewUtil(t->left,cur-1,l,r);
  topViewUtil(t->right,cur+1,l,r);
}
void topView(Node *t)
{
  int l=0,r=0;
  cout<<t->data<<" ";
  topViewUtil(t,0,l,r);
}
void bottomViewUtil(Node *t, map<int,int>& m,int l)
{
  if(!t) return;
  m[l]=t->data;
  bottomViewUtil(t->left,m,l-1);
  bottomViewUtil(t->right,m,l+1);
}
void bottomView(Node *t)
{
  map<int,int> m;
  bottomViewUtil(t,m,0);
  for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
   cout<<i->second<<" ";
}
Node* pruneUtil(Node *t,int k,int& sum)
{
  int lsum,rsum;
  if(!t) return t;
  lsum=rsum=sum+t->data;
  t->left =  pruneUtil(t->left,k,lsum);
  t->right = pruneUtil(t->right,k,rsum);
  int s = lsum>rsum?lsum:rsum;
  if(s<k) t=NULL;
  return t;
}
Node *prune(Node *t ,int k)
{
  if(!t) return t;
  int sum=0;
  return pruneUtil(t,k,sum);
}
Node *Prune(Node *t, int k)
{
  if(!t) return t;
  t->left = Prune(t->left,k-t->data);
  t->right = Prune(t->right,k-t->data);
  if(t->left==NULL && t->right ==NULL)
    if(t->data < k) t=NULL;
  return t;
}
void leftView1(Node *t)
{
  if(!t) return;
  if(t->left==NULL && t->right ==NULL) return;
  cout<<t->data<<" ";
  if(t->left) leftView1(t->left);
  else if(t->right) leftView1(t->right);
}
void rightView1(Node *t)
{
  if(!t) return;
  if(t->left==NULL && t->right ==NULL) return;
  cout<<t->data<<" ";
  if(t->right) rightView1(t->right);
  else if(t->left) rightView1(t->left);
}
void bottomView1(Node *t)
{
  if(!t) return;
  if(t->left==NULL && t->right == NULL)
    cout<<t->data<<" ";
  bottomView1(t->left);
  bottomView1(t->right);
}
void boundaryView(Node *t )
{
  if(!t) return ;
  cout<<t->data<<" ";
  leftView1(t->left);
  bottomView1(t);
  rightView(t->right);
}
Node * LeafDLL(Node *t,Node **L)
{
  if(!t) return t;
  static Node * prev=NULL;
  t->left = LeafDLL(t->left,L);
  if(t->left==NULL && t->right == NULL)
  {
    if(prev==NULL) { *L =t; prev= t;}
    else{ prev->right  =t ; t->left =prev; prev=t;}
    return NULL;
  }
  t->right = LeafDLL(t->right,L);
  return t;
}

void deepestLeftNodeUtil(Node *t,Node **p,int level, int& max,bool isLeft )
{
  if(!t) return;
  if(isLeft && t->left == NULL && t->right ==NULL && max<level)
  {
    max=level;*p=t;
  }
  deepestLeftNodeUtil(t->left,p,level+1,max,true);
  deepestLeftNodeUtil(t->right,p,level+1,max,false);
}
Node *deepestLeftNode(Node *t)
{
  int max=0;
  Node *p;
  deepestLeftNodeUtil(t,&p,1,max,false);
  return p;
}
/*
// A utility function to find minimum of x and y
int getMin(int x, int y)
{
    return (x < y)? x :y;
}
 
// A utility function to find distance of closest leaf of the tree
// rooted under given root
int closestDown(struct Node *root)
{
    // Base cases
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    // Return minimum of left and right, plus one
    return 1 + getMin(closestDown(root->left), closestDown(root->right));
}
 
// Returns distance of the cloest leaf to a given key 'k'.  The array
// ancestors is used to keep track of ancestors of current node and
// 'index' is used to keep track of curremt index in 'ancestors[]'
int findClosestUtil(struct Node *root, char k, struct Node *ancestors[],
                                               int index)
{
    // Base case
    if (root == NULL)
        return INT_MAX;
 
    // If key found
    if (root->key == k)
    {
        //  Find the cloest leaf under the subtree rooted with given key
        int res = closestDown(root);
 
        // Traverse all ancestors and update result if any parent node
        // gives smaller distance
        for (int i = index-1; i>=0; i--)
            res = getMin(res, index - i + closestDown(ancestors[i]));
        return res;
    }
 
    // If key node found, store current node and recur for left and
    // right childrens
    ancestors[index] = root;
    return getMin(findClosestUtil(root->left, k, ancestors, index+1),
                  findClosestUtil(root->right, k, ancestors, index+1));
 
}
 
// The main function that returns distance of the closest key to 'k'. It
// mainly uses recursive function findClosestUtil() to find the closes
// distance.
int findClosest(struct Node *root, char k)
{
    // Create an array to store ancestors
    // Assumptiom: Maximum height of tree is 100
    struct Node *ancestors[100];
 
    return findClosestUtil(root, k, ancestors, 0);
}
*/
int main()
{

  struct node *root = NULL;
  int x;
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
  Node * t=NULL;
  root =  LeafDLL(root,&t);
  in(root);
  cout<<endl;
  while(t) {cout<<t->data<<" "; t=t->right;}
  return 0;
}

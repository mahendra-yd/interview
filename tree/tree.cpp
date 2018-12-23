#include<iostream>
#include<list>
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node 
{
  int data;
  struct node* left;
  struct node* right;
  struct node* nextRight;// level order successor
  struct node* next;// inorder successor

};

struct node* newNode(int data) // new node
{
  struct node* node = (struct node*)
    malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;

  return(node);
}

bool isIsomorphic(node* n1, node *n2) //isomorphic tree
{
  if (n1 == NULL && n2 == NULL)
    return true;
  if (n1 == NULL || n2 == NULL)
    return false;
  if (n1->data != n2->data)
    return false;
  return
    (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
    (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
}

int size(struct node* node) 
{  
  if (node==NULL) 
    return 0;
  else    
    return(size(node->left) + 1 + size(node->right));  
}
bool identical(node * s1,node *s2) // two tree identical
{
  if(s1==NULL&&s2==NULL)
    return true;
  if(!s1||!s2)
    return false;
  return s1->data==s2->data&& identical(s1->left,s2->left )&& identical (s1->right,s2->right);

}
int height(node *p)
{
  if(!p)
    return 0;
  int h1=height(p->left);
  int h2=height(p->right);
  return 1+ (h1>h2?h1:h2);

}
void Delete(node *p)
{
  if(!p)return;
  Delete(p->left);
  Delete(p->right);
  cout<<p->data<<" ";
  free(p);
}
void mirror(node* p)
{
  if(!p)return;
  node *t=NULL;
  mirror(p->left);
  mirror(p->right);
  t=p->left;
  p->left=p->right;
  p->right=t;
}

node* lca(node *p,int n1,int n2) // lowest common ansestor of two nodes
{
  node *t=p;
  while(p)
  {
    t=p;
    if(p->data > n1 && p->data > n2) p=p->left;
    else if(p->data < n1 && p->data < n2) p=p->right;
    else break;
  }
  return t;
}
void LevelT(node* t,int l,int b=0)// print nodes at a level in zig zag order
{
  if(!t) return;
  if(l==0)
    cout<<t->data<<" ";
  if(b) {
    LevelT(t->left,l-1,b);
    LevelT(t->right,l-1,b);
  }
  else
  {
    LevelT(t->right,l-1);
    LevelT(t->left,l-1);
  }
}

void LevelOT(node *t) // level order traversal
{
  int h= height(t);
  for(int i=0;i<h;i++){
    LevelT(t,i);
    cout<<endl;
  }
}
void LevelOTS1(node *t) // level order traversal spiral or zig zag
{
  int h= height(t);
  int a=0;
  for(int i=0;i<h;i++){
    a=~a;
    LevelT(t,i,a);
    cout<<endl;
  }
}
void LevelOTS2(node *t) // Level order travser using two stack to print in spiral form
{
  stack<node*> t1,t2;
  t1.push(t);
  while(!t1.empty() || !t2.empty())
  {
    while(!t1.empty())
    {
      node *p = t1.top();t1.pop();
      cout<<p->data<<" ";
      if(p->left) t2.push(p->left);
      if(p->right) t2.push(p->right);
    }
    cout<<endl;
    while(!t2.empty())
    {
      node *p = t2.top();t2.pop();
      cout<<p->data<<" ";
      if(p->left) t1.push(p->right);
      if(p->right) t1.push(p->left);
    }
    cout<<endl;
  }
}
int LeafNode(node *p) // count leaf node 
{
  if(!p) return 0;
  if(!p->left&&!p->right)
    return 1;
  return LeafNode(p->left) + LeafNode(p->right);

}
bool isBST(node *p,int min,int max) // isbst
{
  if(!p) return true;
  if(p->data<min || p->data > max ) return false;
  return isBST(p->left,min,p->data)&& isBST(p->right,p->data,max);
}
bool isSumProperty(node *t)
{
  if(!t || (t->left==NULL && t->right==NULL) ) return true;
  int s=0;
  if(t->left!=NULL)
    s=t->left->data;
  if(t->right!=NULL)
    s+=t->right->data;
  return (t->data == s) && isSumProperty(t->left) && isSumProperty(t->right);
}
int diameter(node* t)// diamter of tree is max of heights sum left and right sub tree, and diameter of left and right
{
  if(!t) return 0;
  int h1= height(t->left);
  int h2= height(t->right);
  int d1= diameter(t->left);
  int d2= diameter(t->right);
  int d=d1>d2?d1:d2;
  int h= h1+h2+1;
  return h>d?h:d;
}
int diameter1(node* t, int *h)// diamter of tree is max of heights sum left and right sub tree, and diameter of left and right
{
  if(!t) return 0;
  int h1=0,h2=0;
  int d1= diameter1(t->left,&h1);
  int d2= diameter1(t->right,&h2);
  *h=h1>h2?h1:h2 +1;
  int d=d1>d2?d1:d2;
  return h1+h2+1>d?h1+h2+1:d;
}
void morrisTraversalPreorder(struct node* root) // preorder travsersal
{
  while (root)
  {
    // If left child is null, print the current node data. Move to
    // right child.
    if (root->left == NULL)
    {
      printf( "%d ", root->data );
      root = root->right;
    }
    else
    {
      // Find inorder predecessor
      struct node* current = root->left;
      while (current->right && current->right != root)
	current = current->right;

      // If the right child of inorder predecessor already points to
      // this node
      if (current->right == root)
      {
	current->right = NULL;
	root = root->right;
      }

      // If right child doesn't point to this node, then print this
      // node and make right child point to this node
      else
      {
	printf("%d ", root->data);
	current->right = root;
	root = root->left;
      }
    }
  }
}
void MorrisInoT(node * t) // iterative inorder withiut stack
{
  node *p;
  while(t!=NULL)
  {
    if(t->left==NULL)
    {	
      cout<<t->data<<" ";
      t=t->right;
    }
    else
    {
      p=t->left;
      while(p->right!=NULL&& p->right!=t) p=p->right;
      if(p->right==NULL)
      { p->right=t; t=t->left;}
      else
      {
	p->right=NULL; // reset the inorder successor pointer
	cout<<t->data<<" ";
	t=t->right;
      }
    }
  }// end of while t!=NULL
}
void StackPreOT(node *t) // preorder travseral using stack
{
  stack<node *> s;
  s.push(t);
  node * p=NULL;
  while(!s.empty())
  {
    if(p==NULL){
      p=s.top();s.pop();}
    cout<<p->data<<" ";
    if(p->right)
      s.push(p->right);
    p=p->left;
  }
}
void StackInorderT(node *t) // inorder traversal
{
  stack<node*>s;
  bool done=true;
  while(done)
  {
    if(t!=NULL) // push all left node to stack
    {
      while(t!=NULL) {s.push(t); t=t->left;}
    }
    else
    {
      if(!s.empty())
      {	
	t=s.top();s.pop();
	cout<<t->data<<" ";
	t=t->right;
      }
      else 
	done=false;
    }
  }
}
bool PathSum(node *t , int sum)
{
  if(t!=NULL)
  {
    if(sum==t->data && t->left==NULL && t->right==NULL) return true;
    return   PathSum(t->left,sum - t->data) ||   PathSum(t->right,sum - t->data);
  }
}

bool PathSum1(node *t , int sum)
{
  static bool res=false;
  if(t!=NULL)
  {
    if(t->left==NULL&&t->right==NULL&&t->data==sum) res=true;
    PathSum1(t->left,sum - t->data); 
    PathSum1(t->right,sum - t->data);
  }
  return res;
}

int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
void in(node *r)
{
  if(r)
  {
    in(r->left);
    printf("%c ",r->data);
    in(r->right);
  }
}
struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{/*
    char in1[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in1)/sizeof(in1[0]);
    struct node *root = buildTree(in1, pre, 0, len - 1);
    */

  static int preIndex = 0;
  if(inStrt > inEnd)
    return NULL;
  struct node *tNode = newNode(pre[preIndex++]);
  if(inStrt == inEnd)
    return tNode;
  int inIndex = search(in, inStrt, inEnd, tNode->data);
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
  return tNode;
}
void print(int *p,int len) { for(int i=0;i<len;i++)cout<<p[i]<<" ";cout<<endl;}
void NodeToLeafPath(node *t,int *buf,int len)
{
  if(t!=NULL)
  {
    buf[len++]=t->data;
    if(t->left==NULL&&t->right==NULL)
      print(buf,len);
    else 
    {
      NodeToLeafPath(t->left,buf,len);
      NodeToLeafPath(t->right,buf,len);
    }
  }
}
void doubleTree(struct node* node) 
{
  struct node* oldLeft;
  if (node==NULL) return;
  doubleTree(node->left);
  doubleTree(node->right);
  oldLeft = node->left;
  node->left = newNode(node->data);
  node->left->left = oldLeft;
}
void getMaxWidthRecur(struct node *root, int count[], int level) //o(n) complexity
{
  if(root)
  {
    count[level]++;
    getMaxWidthRecur(root->left, count, level+1);
    getMaxWidthRecur(root->right, count, level+1);
  }
}
int getMax(int a,int b)
{
  return a>b?a:b;
}
int getMaxWidth(struct node* root)// otgher way is to count nodes at each level.
{
  int width;
  int h = height(root);
  int *count = (int *)calloc(sizeof(int), h);
  int level = 0;
  getMaxWidthRecur(root, count, level);
  return getMax(*count, h);
}
bool FoldableUtil(node *a, node *b)
{
  if(a==NULL && b==NULL)
    return true;
  if(a==NULL || b==NULL)
    return false;
  return FoldableUtil(a->left,b->right)&&FoldableUtil(a->right,b->left);
}
bool isFoldable1(node *t)// both sub tree have  mirror image  structure
{
  if(!t) return true;
  return  FoldableUtil(t->left,t->right);

}
bool isStructleIdentical(node *a,node *b)
{
  if(a==NULL&&b==NULL) return true;
  if(a==NULL || b==NULL) return false;
  return isStructleIdentical(a->left,b->right)&&isStructleIdentical(a->right,b->left);

}
bool isFoldable(node *t)
{
  if(!t) return true;
  mirror(t->left);
  bool ret= isStructleIdentical(t->left,t->right);
  mirror(t->left);
  return ret;
}
node * findNode(node *t ,int x)
{
  if(!t) return NULL;
  while(t!=NULL)
  {
    if(t->data==x ) return t;
    else if(t->data > x) t=t->left;
    else t=t->right;
  }
  return NULL;
}
int minTree(node *p)
{
  while(p->left!=NULL) p=p->left;
  return p->data;
}
int InOrder(node * t, int data)
{
  node *p = findNode(t,data);
  if(p!=NULL&&p->right!=NULL) return minTree(p->right);
  node *s;
  while(t)
  {
    if(data < t->data)
    {
      s=t;
      t=t->left;

    }
    else if(data > t->data)
      t=t->right;
    else
      break;
  }
  return s->data;
}
int kthSmallest(node *t,int *k)//run iterative inorder traversal and count for kth element
{
  static  int res=0;
  if(t!=NULL&&k!=0)
  {
    kthSmallest(t->left,k);
    *k=*k-1;
    if(*k==0)
      res=t->data;
    kthSmallest(t->right,k);
    return res;
  }
}
int LevelOfNode(node *t, int n,int k) // to get level of a node
{
  if(t==NULL) {return 0;}
  if(t->data==n){  return k ;}
  int x;
  x = LevelOfNode(t->left,n,k+1);
  if(x!=0)
    return x;
  x = LevelOfNode(t->right,n,k+1);
  return x;
}
void printAncestors(node *t , int data) // Ancestor of BST
{
  if(!t) return ;
  if(t->data==data) return;
  while(t!=NULL&&t->data!=data)
  {
    cout<<t->data<<" ";
    if(t->data<data) t=t->right;
    else t=t->left;
  }
  cout<<endl;
}
bool printAncestors1(struct node *root, int target) // print  Ancestor of BT
{
  if (root == NULL)
    return false;
  if (root->data == target)
    return true;
  if ( printAncestors1(root->left, target) ||
      printAncestors1(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
  return false;
}
void Print(node *t, int x,int y) // print nodes between a range in BST
{
  if(!t) return ;
  if(t->data >x) Print(t->left,x,y);
  if(t->data>x && t->data <y) cout<<t->data<<" ";
  if(t->data < y) Print(t->right,x,y);
}
void LevelOTConnect_node(node *t) // Level order travser using two stack to print in spiral form
{
  // complete it
  stack<node*> t1,t2;
  t1.push(t);
  node * prev=NULL;
  while(!t1.empty() || !t2.empty())
  {
    while(!t1.empty())
    {
      node *p = t1.top();t1.pop();
      cout<<p->data<<" ";
      if(p->left) t2.push(p->left);
      if(p->right) t2.push(p->right);
    }
    cout<<endl;
    while(!t2.empty())
    {
      node *p = t2.top();t2.pop();
      cout<<p->data<<" ";
      if(p->left) t1.push(p->right);
      if(p->right) t1.push(p->left);
    }
    cout<<endl;
  }
}
node * SortedArrayToBST(int arr[],int l, int r)// convert sorted array in balance BST o(n)
{
  if(r<l) return NULL;
  int m=(l+r)/2;
  node *t = newNode(arr[m]);
  t->left = SortedArrayToBST(arr,l,m-1); 
  t->right = SortedArrayToBST(arr,m+1,r); 
  return t;
}
void PopulateInorderSuccesor(node *t) // populate inorder succesor
{
  static node *prev=NULL;
  if(!t) return;
  PopulateInorderSuccesor(t->right);
  t->next=prev;
  prev=t;
  PopulateInorderSuccesor(t->left);
}
void PopulateInorderSuccesor1(node *t,node **p) // populate inorder succesor
{
  if(!t) return;
  PopulateInorderSuccesor1(t->right,p);
  t->next=*p;
  *p=t;
  PopulateInorderSuccesor1(t->left,p);
}
int VTSumUtil(node *ptr,int hd,map<int,int>& sum) //vertical sum of tree
{
  if(ptr!=NULL)
  {
    VTSumUtil(ptr->left,hd-1,sum);
    sum[hd]+=ptr->data;
    VTSumUtil(ptr->right,hd+1,sum);
  }
}
int VTSum(node * t)
{
  map<int,int>sum;
  VTSumUtil(t,0,sum);
  for (std::map<int,int>::iterator it=sum.begin(); it!=sum.end(); ++it)
  {      std::cout << it->first << " => " << it->second << '\n';
    sum.erase( it->first);
  }
  sum.clear();
}
void findLeafMaxSum(node *t,int* msum,int sum,node **p)
{
  if(!t) return ;
  sum+=t->data;
  if(t->left==NULL&&t->right==NULL)
  {
    if(*msum<sum)
    {
      *msum=sum;
      *p=t;
    }
  }
  findLeafMaxSum(t->left,msum,sum,p);
  findLeafMaxSum(t->right,msum,sum,p);
}
bool printPath(node* t,node *p)
{
  if(!t) return false;
  //  cout<<t->data<<" ";// print path from root to leaf
  if(t==p||printPath(t->right,p)||printPath(t->left,p))
  {
    cout<<t->data<<" "; // print path from leaft to root
    return true;
  }
  return false;

}
void maxSumPath(node *t)
{
  int maxsum=-9999;
  node *p ;
  findLeafMaxSum(t,&maxsum,0,&p);
  printPath(t,p);
}
void preIT(node *t)
{
  stack<node *> s;
  if(NULL==t) return;
  s.push(t);
  while(!s.empty())

  {
    t=s.top();s.pop();
    if(t!=NULL){
      cout<<t->data<<" ";
      s.push(t->right);
      s.push(t->left);
    }
  }
  cout<<endl;
}
void inIT(node *t)
{
  if(!t) return;
  stack<node*> s;
label:
  while(t){ s.push(t); t=t->left;}
  while(!s.empty()){
    t=s.top();s.pop();
    if(t!=NULL) {
      cout<<t->data<<" ";
      if(t->right){ t=t->right; goto label;}
    }
  }
  cout<<endl;
}
void postOrdert1(node* t) // postorder travsersal using single stack
{
  stack<node*> s;
  if(!t) return ;
  bool done=true;
  while(done)
  {
    if(t!=NULL) //travser left path and push node and right in tree
    {
      while(t!=NULL) { if(t->right) s.push(t->right); s.push(t);t=t->left; }
    }
    else // pop element from stack and if it is right node continue else print item
    {
      if(!s.empty()) 
      {
	t=s.top();s.pop();
	if(s.size()&& t->right ==s.top()){s.pop();s.push(t);t=t->right;}
	else
	{
	  cout<<t->data<<" ";fflush(stdout);
	  t=NULL;
	}
      }
      else // if stack is empty exit loop
	done=false;
    }
  }
}
void postOrderT(node* t)// postorder travsersal using two stack;
{
  if(!t) return;
  stack<node*>s1;
  stack<node*>s2;
  s1.push(t);
  while(!s1.empty())
  {
    t=s1.top();s1.pop();
    s2.push(t);
    if(t->left) s1.push(t->left);
    if(t->right) s1.push(t->right);
  }
  while(!s2.empty()) { t=s2.top();s2.pop();cout<<t->data<<" ";}
}
void printLeft(node *t)
{
  if(t!=NULL)
  {
    if(!(t->left==NULL && t->right==NULL))  cout<<t->data<<" ";
    if(t->left) {printLeft(t->left);}
    else if( t->right){ printLeft(t->right);} 
  }
}
void printLeaf(node *t )
{
  if(t!=NULL)
  {
    printLeaf(t->left);
    if(t->left==NULL && t->right==NULL)
      cout<<t->data<<" ";
    printLeaf(t->right);
  }
}
void printRight(node *t)
{
  if(t!=NULL)
  {
    if(t->right){ printRight(t->right); cout<<t->data<<" "; }
    else if(t->left) { printRight(t->left);  cout<<t->data<<" ";}
  }
}
void boundryT(node* t)
{
  if(!t) return;
  cout<<t->data<<" ";
  // print left path top to bottom
  printLeft(t->left);
  // print leaf nodes
  printLeaf(t);
  // print right path ottom to top
  printRight(t->right);
}

int treeHeight(node *root) // Iterative method to find height of Bianry Tree
{
  if (root == NULL)
    return 0;
  queue<node *> q;
  q.push(root);
  int height = 0;
  while (1)
  {
    int nodeCount = q.size();
    if (nodeCount == 0)
      return height;
    height++;
    while (nodeCount > 0)
    {
      node *node = q.front();
      q.pop();
      if (node->left != NULL)
	q.push(node->left);
      if (node->right != NULL)
	q.push(node->right);
      nodeCount--;
    }
  }
}
int getLevelDiff(struct node *root)
{
  if (root == NULL)
    return 0;
  return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
}
/*
   void printPostOrder(int in[], int pre[], int n)
   {
   int root = search(in, pre[0], n);
   if (root != 0)
   printPostOrder(in, pre+1, root);
   if (root != n-1)
   printPostOrder(in+root+1, pre+root+1, n-root-1);
   cout << pre[0] << " ";
   }*/
// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node *root, int level, int *max_level)
{
  if (root==NULL)  return;
  if (*max_level < level)
  {
    printf("%d\t", root->data);
    *max_level = level;
  }
  leftViewUtil(root->left, level+1, max_level);
  leftViewUtil(root->right, level+1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
  int max_level = 0;
  leftViewUtil(root, 1, &max_level);
}
void deepestLeafNode(node* t, int h,int *maxh) // deepest leaf node
{
  if(!t) return;
  if(t->left==NULL &&t->right==NULL) {
    if(h>*maxh) 
      *maxh=h;
  }
  deepestLeafNode(t->left,h+1,maxh);
  deepestLeafNode(t->right,h+1,maxh);

}
void ConvertLeafNodeList(node *t,node**head) // convert leaf node in dll
{
  if(!t) return;
  ConvertLeafNodeList(t->right,head);
  ConvertLeafNodeList(t->left,head);
  if(t->left==NULL&&t->right==NULL)
  {
    t->right=*head;
    if(*head) (*head)->left=t;
    *head=t;
  }
}

bool findPath(node *root, vector<int> &path, int k)
{
  if (root == NULL) return false;
  path.push_back(root->data);
  if (root->data == k)
    return true;
  if ( (root->left && findPath(root->left, path, k)) ||
      (root->right && findPath(root->right, path, k)) )
    return true;
  path.pop_back();
  return false;
}
int findLCA(node *root, int n1, int n2)
{
  vector<int> path1, path2;
  if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
    return -1;
  int i;
  for (i = 0; i < path1.size() && i < path2.size() ; i++)
    if (path1[i] != path2[i])
      break;
  return path1[i-1];
}
void kDistantFromLeafUtil(node* node, int path[], bool visited[], int pathLen, int k)
{
  if (node==NULL) return;
  path[pathLen] = node->data;
  visited[pathLen] = false;
  pathLen++;
  if (node->left == NULL && node->right == NULL &&
      pathLen-k-1 >= 0 && visited[pathLen-k-1] == false)
  {
    cout << path[pathLen-k-1] << " ";
    visited[pathLen-k-1] = true;
    return;
  }
  kDistantFromLeafUtil(node->left, path, visited, pathLen, k);
  kDistantFromLeafUtil(node->right, path, visited, pathLen, k);
}

#define MAX_HEIGHT 10
void printKDistantfromLeaf(node* node, int k)
{
  int path[MAX_HEIGHT];
  bool visited[MAX_HEIGHT] = {false};
  kDistantFromLeafUtil(node, path, visited, 0, k);
}
void findwidthofTree(node *t,int d, int *l,int*r) // find horizantal with of tree from root
{
  if(t!=NULL) {
    if(d>*r) *r=d;
    if(d<*l) *l=d;
    findwidthofTree(t->left,d-1,l,r);
    findwidthofTree(t->right,d+1,l,r);
  }
}
void printVAtLine(node *t,int line,int d)
{
  if(t!=NULL)
  {
    if(line==d) cout<<t->data<<" ";
    printVAtLine(t->left,line,d-1);
    printVAtLine(t->right,line,d+1);
  }
}
void printVerticallytree(node* t) //print-binary-tree-vertical-order
  // one can do using 2d array with inorder travserasal and store node at particaular dist
  // and later print 2d array
{
  int l=0,r=0;
  findwidthofTree(t,0,&l,&r);
  for(int i=l;i<=r;i++)
  {
    printVAtLine(t,i,0);
    cout<<endl;
  }
}

void rightViewUtil(node *root, int level, int *max_level)
{
  if (root==NULL)  return;
  if (*max_level < level)
  {
    printf("%c\t", root->data);
    *max_level = level;
  }
  rightViewUtil(root->right, level+1, max_level);
  rightViewUtil(root->left, level+1, max_level);
}
void rightView(node *root)
{
  int max_level = 0;
  rightViewUtil(root, 1, &max_level);
}

/* Given a binary tree, print nodes from level number 'low' to level
   number 'high'*/
void printLevels(node* root, int low, int high)
{
  queue <node *> Q;
  node *marker = new node; // Marker node to indicate end of level
  int level = 1;   // Initialize level number
  Q.push(root);
  Q.push(marker);
  while (Q.empty() == false)
  {
    node *n = Q.front();
    Q.pop();
    if (n == marker)
    {
      cout << endl;
      level++;
      if (Q.empty() == true || level > high) break;
      Q.push(marker);
      continue;
    }
    if (level >= low)
      cout << n->data << " ";
    if (n->left != NULL)  Q.push(n->left);
    if (n->right != NULL) Q.push(n->right);
  }
  return;
}


struct node* constructTree (int pre[], int* preIndex, int low, int high, int size) // construct BST from preorder o(n2)
{
  if (*preIndex >= size || low > high)
    return NULL;
  struct node* root = newNode ( pre[*preIndex] );
  *preIndex = *preIndex + 1;
  if (low == high)
    return root;
  int i;
  for ( i = low; i <= high; ++i )
    if ( pre[ i ] > root->data )
      break;
  root->left = constructTree ( pre, preIndex, *preIndex, i - 1, size );
  root->right = constructTree ( pre, preIndex, i, high, size );
  return root;
}
struct node* constructTree1( int pre[], int* preIndex, int key/* First will be pre[0]*/,int min, int max, int size )
  // construct BST from preorder
{
  if( *preIndex >= size )
    return NULL;
  struct node* root = NULL;
  if( key > min && key < max )
  {
    root = newNode ( key );
    *preIndex = *preIndex + 1;
    if (*preIndex < size)
    {
      root->left = constructTree1( pre, preIndex, pre[*preIndex], min, key, size );
      root->right = constructTree1( pre, preIndex, pre[*preIndex], key, max, size );
    }
  }
  return root;
}
void topView(node* t,int d,int *h,int *l)
{
  if(!t) return;
  if(d>*h) { cout<<t->data<<" ";*h=d;}
  if(d<*l) { cout<<t->data<<" ";*l=d;}
  topView(t->right,d+1,h,l);
  topView(t->left,d-1,h,l);
} 

void topView1(node* t)
{
typedef pair<int ,node*> P;
  queue<P> q;
  map <int,int> A;
  P p;
  p.first=0;
  p.second=t;
  q.push(p);
  while(!q.empty())
  {
    p=q.front();q.pop();
    if(A[p.first]==0) { cout<<p.second->data<<" ";A[p.first]=1;}
    if(p.second->left){ P a; a.first=p.first-1;a.second=p.second->left; q.push(a);};
    if(p.second->right){ P a; a.first=p.first+1;a.second=p.second->right; q.push(a);};
  }
}
void bottomView(node* t)
{
typedef pair<int ,node*> P;
  queue<P> q;
  map <int,node*> A;
  P p;
  p.first=0;
  p.second=t;
  q.push(p);
  while(!q.empty())
  {
    p=q.front();q.pop();
    A[p.first]=p.second;
    if(p.second->left){ P a; a.first=p.first-1;a.second=p.second->left; q.push(a);};
    if(p.second->right){ P a; a.first=p.first+1;a.second=p.second->right; q.push(a);};
  }
  for(map<int,node*>::iterator i=A.begin();i!=A.end();++i)
      cout<<i->second->data<<" ";
}
#if 0
void  digonalSum(node* t)
{
  /*
  1. Add root with vertical distance as 0 to the queue.
  2. Process the sum of all right child and right of right child and so on.
  3. Add left child current node into the queue for later processing. The vertical distance of left child is vertical distance of current node plus 1.
  4. Keep doing 2nd, 3rd and 4th step till the queue is empty.*/
  int sum=0;
  typedef pair<int ,node*> P;
  queue<P> q;
  map <int,int> A;
  P p;
  p.first=0;
  p.second=t;
  q.push(p);
  while(!q.empty())
  {
    p=q.front();q.pop();
    node *r=p.second;
    int k=0;
    while(r!=NULL)
    {
      A[p.first]=A[p.first]+p.second->data;
	k=
      if(r->left){ P a; a.first=p.first+1;a.second=r->left; q.push(a);};
      r=r->right;
      // if(p.second->right){ P a; a.first=p.first+1;a.second=p.second->right; q.push(a);};
    }
  }
  for(map<int,int>::iterator i=A.begin();i!=A.end();++i)
    cout<<i->second<<" ";
}
// delete path from tree id its path sum is less than number k
/* Main function which truncates the binary tree. */
struct Node *pruneUtil(struct Node *root, int k, int *sum)
{
    // Base Case
    if (root == NULL)  return NULL;
 
    // Initialize left and right sums as sum from root to
    // this node (including this node)
    int lsum = *sum + (root->data);
    int rsum = lsum;
 
    // Recursively prune left and right subtrees
    root->left = pruneUtil(root->left, k, &lsum);
    root->right = pruneUtil(root->right, k, &rsum);
 
    // Get the maximum of left and right sums
    *sum = max(lsum, rsum);
 
    // If maximum is smaller than k, then this node
    // must be deleted
    if (*sum < k)
    {
        free(root);
        root = NULL;
    }
 
    return root;
}

 
// A wrapper over pruneUtil()
struct Node *prune(struct Node *root, int k)
{
    int sum = 0;
    return pruneUtil(root, k, &sum);
}
 
#endif
bool printAncestor(node *t, int n)
{
  if(!t) return false;
  if(t->data == n) return true;
  if(printAncestor(t->left,n) || printAncestor(t->right,n))
  {
    cout<<t->data;
    return true;
  }
}
int heightIterative(node* t)
{
  if(!t) return 0;
  queue<node*>q;
  int h=0;
  q.push(t);
  while(1)
  {
    int c= q.size();
    if(c==0) return h;
      h++;
    while(c--)
    {
      t=q.front();q.pop();
      if(t->left) q.push(t->left);
      if(t->right) q.push(t->right);
    }
  }
  return h;
}
// Iterative Function to print all ancestors of a given key
void printAncestors(struct Node *root, int key)
{
    if (root == NULL) return;
 
    // Create a stack to hold ancestors
     stack<Node *> s;
    // Traverse the complete tree in postorder way till we find the key
    while (1)
    {
        // Traverse the left side. While traversing, push the nodes into
        // the stack so that their right subtrees can be traversed later
        while (root && root->data != key)
        {
            s.push.(root);   // push current node
            root = root->left;  // move to next node
        }
 
        // If the node whose ancestors are to be printed is found,
        // then break the while loop.
        if (root && root->data == key)
            break;
 
        // Check if right sub-tree exists for the node at top
        // If not then pop that node because we don't need this
        // node any more.
        if (peek(stack)->right == NULL)
        {
            root = pop(stack);
 
            // If the popped node is right child of top, then remove the top
            // as well. Left child of the top must have processed before.
            // Consider the following tree for example and key = 3.  If we
            // remove the following loop, the program will go in an
            // infinite loop after reaching 5.
            //          1
            //        /   \
            //       2     3
            //         \
            //           4
            //             \
            //              5
            while (!isEmpty(stack) && peek(stack)->right == root)
               root = pop(stack);
        }
 
        // if stack is not empty then simply set the root as right child
        // of top and start traversing right sub-tree.
        root = isEmpty(stack)? NULL: peek(stack)->right;
    }
 
    // If stack is not empty, print contents of stack
    // Here assumption is that the key is there in tree
    while (!isEmpty(stack))
        printf("%d ", pop(stack)->data);
}
int main()
{
  int buf[1000]={0,};
/*  struct node *root  = newNode(10);
  root->right        = newNode(12);
  root->left         = newNode(4);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(14); */
  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left  = newNode(9);
  root->left->right  = newNode(6);
  root->right->left = newNode(4);
  root->right->right = newNode(5);
  root->right->left->left = newNode(12);
  root->right->left->right = newNode(7);
  root->left->right->left = newNode(11);
  root->left->left->right = newNode(10);
cout<<heightIterative(root);
  return 0;
}

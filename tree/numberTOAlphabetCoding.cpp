#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<string>
using namespace std;
struct Node
{
  string s;
  struct Node *left,*right;
};
Node * newNode(string s)
{
  Node *t = new Node;
  t->left=t->right=NULL;
  t->s=s;
  return t;
}
string w = "abcdefghijklmnopqrstuvwxyz";
Node* util(int a[],int i,int n,string s)
{
  if(i>n) return NULL;
  Node *t = newNode(s);
  string l,r;
  l = s + w[a[i]-1];
  t->left  = util(a,i+1,n,l);
 if(i+1>=n) return t;
  int k=a[i]*10+a[i+1];
  if(k<26)
    t->right = util(a,i+2,n,s+w[k-1]);
  return t;
}
void printLeaf(Node *t)
{
 if(!t) return;
  printLeaf(t->left);
  printLeaf(t->right);
  if(t->left==NULL&&t->right==NULL)
    cout<<t->s<<" leaf"<<endl;
    //cout<<t->s<<endl;
}
void printAllInterpretations(int a[],int n)
{

  Node *t = util(a,0,n,"");
  printLeaf(t);
}
int main(int argc, char **argv)
{

  // aacd(1,1,3,4) amd(1,13,4) kcd(11,3,4)
  // Note : 1,1,34 is not valid as we don't have values corresponding
  // to 34 in alphabet
  int arr[]  = {1, 1, 3, 4};
  printAllInterpretations(arr,sizeof(arr)/sizeof(arr[0]));
  // aaa(1,1,1) ak(1,11) ka(11,1)
  int arr2[]  = {1, 1, 1};

  printAllInterpretations(arr2,sizeof(arr2)/sizeof(arr2[0]));
  // bf(2,6) z(26)
  int arr3[] = {2, 6};

  printAllInterpretations(arr3,sizeof(arr3)/sizeof(arr3[0]));
  // ab(1,2), l(12)  
  int arr4[]  = {1, 2};

  printAllInterpretations(arr4,sizeof(arr4)/sizeof(arr4[0]));
  // a(1,0} j(10)  
  int arr5[]  = {1, 0};
return 0;
printAllInterpretations(arr5,sizeof(arr5)/sizeof(arr5[0]));
// "" empty string output as array is empty
int arr6[]  = {};

printAllInterpretations(arr6,sizeof(arr6)/sizeof(arr6[0]));
// abba abu ava lba lu
int arr7[]  = {1, 2, 2, 1};

printAllInterpretations(arr7,sizeof(arr7)/sizeof(arr7[0]));
return 0;
}

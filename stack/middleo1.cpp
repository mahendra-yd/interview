#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
struct Node
{
  int data;
  struct Node * next;
  struct Node * prev;
};
Node * newNode(int n)
{
  Node *t =new Node;
  t->data=n;
  return t;
}


struct Stack
{
  int count;
  Node * top;
  Node *mid;
  Stack() { top=NULL;mid=NULL;count=0;}
  int size() { return count;}
  bool isEmpty() { return count ==0;}
  void push(int n )
  {
    Node *t = newNode(n);
    t->next=top;
    if(top) top->prev= t;
    top =t ;
   if(mid==NULL) mid=top;
   if(count&1) mid = mid->prev;
    count++;
  }
  int  pop()
  {
  if(count==0) 
  return -1;
  Node *t = top;
  top= top->next;
  count--;
  if(count&1) mid=mid->next;
  return t->data;
  }
  int middle()
  {
   if(count>0)
   return mid->data;
   return -1;
  }
};

int main(int argc, char **argv)
{
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
//s.push(6);
s.push(7);
 
cout<<s.pop();
cout<<s.pop();
cout<<s.pop();
cout<<s.middle();
  return 0;
}

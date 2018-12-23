#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<map>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
  struct Node* rand;
};
Node * newNode(int data)
{
  Node *t=new Node;
  t->data=data;
  t->next=NULL;
  t->rand =  (t+2);
}
Node * append(Node *s ,Node *t)
{
  if(s==NULL) return t;
  Node * start=s;
  while(start->next!=NULL) start=start->next;
  start->next=t;
  return s;
}

void display(Node* p)
{
int count=0;
while(p && count++ <20){cout<<p->data<<" "<<p->rand<<" ";p=p->next;}
}
Node * clone(Node * l)
{
  map<Node*,Node*> m;
  Node *p=l;
  while(p!=NULL) { m[p] = newNode(p->data);p=p->next;}
  p=l;
  while(p!=NULL) { m[p]->next = m[p->next]; m[p]->rand = p->rand+2; p=p->next; }
  return m[l];
}
int main(int argc, char **argv)
{
  Node* head = NULL;
Node *p=NULL;
  head=append(head,newNode(1));
  head=append(head,newNode(2));
  head=append(head,newNode(3));
  //  head=append(head,newNode(3));
  head=append(head,newNode(4));
  head=append(head,newNode(5));
  head=append(head,newNode(6));
  head=append(head,newNode(7));
  head=append(head,newNode(8));
  head=append(head,newNode(9));
  display(head);
  head = clone(head);
  cout<<endl;
  display(head);
  return 0; }



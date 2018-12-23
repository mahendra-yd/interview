#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<map>
using namespace std;
// store all pages in dll and use a hashmap to map page and address of node in list
struct Node
{
  int data;
  struct Node *prev,*next;
};
Node* newNode(int n)
{
  Node  *t = new Node;
  t->prev=t->next=NULL;
  t->data=n;
  return t;
}
struct Queue
{
  int size;
  int count;
  Node *front;
  Node *rear;
  bool isEmpty() { return count==0;}
  bool isFull() { return size==count;}
  Queue(int n) { front=rear=NULL; count =0; size=n;}
  void print()
  {
   Node *t =rear;
   for(int i=0;i<count;i++){ cout<<t->data<<" "; t=t->next;}
   cout<<endl;
 }
  Node* insert(int n)
  {
    Node *t;
    if(count==size) // queue is full need to remove last element and insert new
    {
      t=rear;
      rear=rear->next;
      rear->prev=NULL;
      t->data =n;
      t->prev=front;
      front->next =t;
      front =t;
    }
    else
    { 
      t =newNode(n);
      t->prev=front;
      if(front!=NULL)
      front->next =t; 
      front =t; 
      if(rear==NULL) 
	rear=front;
      count++;
    }
    return t;
  }
  void update(Node *t)
  {
    if(t==front) return;
    else if(t==rear)
    {
      t=rear;
      rear=rear->next;
      rear->prev=NULL;
      t->prev=front;
      front->next =t;
      front =t;
    }
    else
    {
      t->prev->next = t->next;
      t->next->prev = t->prev;
      t->prev=front;front->next =t; front =t;
    }
  }
};
int refernce(map<int,Node*> &m, Queue &q,int page)
{
  map<int,Node*>::iterator it;
  it=m.find(page);
  if(it==m.end()) {Node*t= q.insert(page);m[page]=t; return t->data;} // page was not in cache
  else 
  {
    q.update(it->second);
    return it->second->data;
  }
}

int main(int argc, char **argv)
{
  Queue q(4);
  map<int,Node*>m;
  cout<<refernce(m,q,1)<<" ";
  q.print();
  cout<<refernce(m,q,2)<<" ";
  q.print();
  cout<<refernce(m,q,3)<<" ";
  q.print();
  cout<<refernce(m,q,1)<<" ";
  q.print();
  cout<<refernce(m,q,4)<<" ";
  q.print();

  cout<<refernce(m,q,6)<<" ";
  q.print();
  cout<<refernce(m,q,7)<<" ";
  q.print();
  return 0;
}

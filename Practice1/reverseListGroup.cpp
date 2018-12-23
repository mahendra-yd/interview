#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
struct Node
{
int data;
struct Node * next;
};
Node * newNode(int n){ Node *t = new Node; t->next=NULL; t->data=n; return t;}
Node * appent(Node *t,int  n)
{
  if(!t) return newNode(n);
  Node *p = newNode(n);
  p->next=t;
  return p;
}
Node * reverse(Node *h, Node *e)
{
  if(h==e) return h;// zero node
  if(h->next==e) return h;//one ndoe
  if(h->next->next==e) {Node *t=h->next; h->next->next=h; h->next=e;return t;} //2 node
  Node *p,*q,*r;
  p=h;
  q=h->next;
  h->next=e;
  while(q!=e)
  {
    r=q->next;
    q->next=p;
    p=q;
    q=r;
  }
return p;
}
void display(Node *t){ while(t){cout<<t->data<<" ";t=t->next;}cout<<endl;}
Node * groupReverse(Node *t, int n)
{
  Node *p,*q,*e;
  Node *r;
  Node *head=NULL;
  p=q=t;
  while(q!=NULL)
  {
    for( int i=0;i<n && p!=NULL;i++)
      p=p->next;
    r = reverse(q,p);
    if(head==NULL) head=r;
    else t->next=r;
    t=q;
    q=p;
  }
  return head;
}
int main(int argc, char **argv)
{
Node *head=NULL;
head=appent(head,1);
head=appent(head,2);
head=appent(head,3);
head=appent(head,4);
head=appent(head,5);
head=appent(head,6);
head=appent(head,7);
head=appent(head,8);
head=appent(head,9);
head=appent(head,10);
head=appent(head,11);
head=appent(head,12);

head=reverse(head,NULL);
display(head);
head = groupReverse(head,14);
display(head);
return 0;
}

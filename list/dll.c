#include<stdio.h>
#include<limits.h>
typedef struct Node
{
  int data;
  unsigned int next;
}Node ;
Node * newNode(int data)
{
  Node *t= (Node*)malloc(sizeof( Node));
  t->data=data;
  t->next = NULL;
}

Node * append(Node *s ,Node *t)
{
  if(s==NULL) { return t;}
  t->next = 0^ (unsigned int)s;

  Node *next = (unsigned int )(s->next) ^ 0;
  s->next = (unsigned int)(t)^(unsigned int)(next);
  return t;
}
/*
int getCount(Node *h)
{
  if(h==NULL) return 0;
  return 1+ getCount(h->next);
}

int search(Node *h,int n)
{
  static int s=0;
  if(h==NULL) return -1;
  if(h->data==n) return s+1;
  s++;
  return search(h->next,n);
}
*/
void display(Node* p)
{
int count=0;
Node *prev = NULL,*curr;

while(p && count++ <20){printf("%d ",p->data);curr=p; p=(unsigned int)(p->next)^(unsigned int)(prev); prev=curr;}
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
printf("\n");
  display(head);
  return 0; }



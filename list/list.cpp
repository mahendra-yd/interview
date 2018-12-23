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
  struct Node* next;
  struct Node* prev;
};
Node * newNode(int data)
{
  Node *t=new Node;
  t->data=data;
  t->next=NULL;
  t->prev=NULL;
}
Node * append(Node *s ,Node *t)
{
  if(s==NULL) return t;
  Node * start=s;
  while(start->next!=NULL) start=start->next;
  start->next=t;
  return s;
}
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
Node * med(Node* h)
{
  Node * s=h,*f=h;
  Node *prev;
  while(f!=NULL&&f->next!=NULL)
  {
    prev=s;
    f = f->next->next;
    s=s->next;
  }
  return prev;
//return s;
}
Node* nthNodeLast(Node *h,int n)
{
  int i;
  if(h==NULL) return h;
  Node *t=h,*p=h;
  for(i=0;i<n&&t!=NULL;i++)
    t=t->next;
  if(i<n && t==NULL ) return NULL;
  while(t!=NULL){ p=p->next;t=t->next;}
  return p;
}
Node * Delete(Node *h)
{
  Node *p=NULL;
  while(h!=NULL)
  {
    p=h;
    h=h->next;
    delete p;
  }
  return NULL;
}
bool palindromeStack(Node * h)
{
stack<Node*>s;
Node *p=h;
while(p!=NULL){ s.push(p);p=p->next;}
while(h!=NULL){ if(h->data!=s.top()->data) return false; h=h->next; s.pop();}
return true;
}
bool palindromeUtil(Node **l,Node *r)
{
  if(r==NULL) return true;
  bool t = palindromeUtil(l,r->next);
    if( t==false || (*l)->data!=r->data) t= false;
  *l=(*l)->next;
    return t;
}
bool palindromeRec(Node *h)
{
return palindromeUtil(&h,h);

}
Node * reverseList(Node *h)
{
  Node *p,*q,*r;
  if(h==NULL|| h->next==NULL) return h;
  p=h;
  q=p->next;
  p->next=NULL;
  while(q!=NULL) { r=q->next; q->next =p; p=q;q=r;}
 return p;
}
bool isSame(Node*p,Node* q)
{
while(p&&q) { if(p->data!=q->data) return false; p=p->next;q=q->next; }
if(p==q) return true;
return false;
}
bool palindrome(Node *h)
{
  Node *pmed=med(h);
  Node *second=reverseList(pmed->next);
  pmed->next=NULL;
  if(isSame(h,second)) cout<<"Both are palindrome\n";
  else cout<<"Not palindrome\n";
  pmed->next=reverseList(second);
return true;
}
void display(Node* p)
{
int count=0;
while(p && count++ <20){cout<<p->data<<" ";p=p->next;}
}
void printr(Node *p)
{
  if(p!=NULL) 
  {
    cout<<p->data<<" ";
    printr(p->next);
  }
}
void rprintr(Node *p)
{
  if(p!=NULL) 
  {
    rprintr(p->next);
    cout<<p->data;
  }
}
void swap(int *a,int *b) { int *p=a;a=b;b=p;}
void pairSwapd(Node *p)//pair wise swap data
{
  while(p!=NULL && p->next!=NULL)
  {
    swap(p->data,p->next->data);
    p=p->next->next;
  }
}
void pairSwapr(Node *p)
{
  if(p!=NULL&&p->next!=NULL)
  {
    swap(p->data,p->next->data);
    pairSwapr(p->next->next);
  }
}


Node * segregateEvenOdd(Node * h)
{
  if(h==NULL|| h->next == NULL) return h;
  Node *p=h,*q=h,*r=NULL;
  while(p->next!=NULL) p=p->next; // get last node
  r=p;
  while(q->data%2==1 && q->next!=r) { p->next=q; q=q->next;p=p->next;p->next=NULL;} // move all odd node to end of list before first even node
  if(q->data%2==0)
  {
    Node *prev=q;
    h=q;
    while(q!=r) {
      if(q->data%2==0) { prev=q;q=q->next; }
      else { prev->next=q->next;p->next=q;p=p->next;p->next=NULL;q=prev->next;}
    }
  }
  return h;
}

Node * segregateEvenOdd1(Node *h) // split list in two and then add and return;
{
  Node *le=NULL,*lo=NULL;
  Node *e,*o;
  while(h!=NULL)
  {
    if(h->data%2==0) { if(!le) { le=h;e=h; }else{  le->next=h;le=le->next;}}
    else { if(!lo) { lo=h;o=h; } else {lo->next=h;lo=lo->next;}}
    h=h->next;
  }
  le->next=o;
  lo->next=NULL;
  return e;
}
/*
Node * findLoop(Node *h)
{
  Node *s=h,*f=h;
  while(s!=NULL && f!=NULL ) { s=s->next;f= f->next? f->next->next: f->next; if(s==f) break;} 
  return f;
}
bool detectandRemoveCycle(Node *h)
{
  Node *l=findLoop(h)
    Node *s=l;
  if(l==NULL) return false;
  while(1) { while(l->next!=h && l!=s) l=l->next; if(l->next ==h ) break; h=h->next;}
  l->next=NULL;
}
*/

Node * pairSwap1(Node *l)
{
  if(l==NULL || l->next==NULL) return l;
  Node *t,*p,*q;
  p=l;
  q=l->next;
  t=p;
  Node *head=q;
  p->next = q->next;
  q->next = p;
  while(p->next)
  {
    p=p->next;
    q=p->next;
    if(q==NULL) break;

    p->next = q->next;
    q->next = p;

    t->next = q;
    t=p;
  }
  return head;
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
  cout<<endl;
  head = pairSwap(head);
  display(head);
  return 0; }



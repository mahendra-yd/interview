#include<iostream>
using namespace std;
#include<stack>
#include<map>
namespace list
{
	//http://www.geeksforgeeks.org/point-to-next-higher-value-node-in-a-linked-list-with-an-arbitrary-pointer/
	//http://www.geeksforgeeks.org/flattening-a-linked-list/
	//http://www.geeksforgeeks.org/maximum-sum-linked-list-two-sorted-linked-lists-common-nodes/
	//http://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/
	//http://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/
	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
		struct node* rand;
	};

	node* newNode(int x)
	{
		node* l = new node;
		l->rand=l->next = l->prev = NULL; l->data = x; return l;
	}
	void printList(node* l) {
		while (l) { cout << l->data << " "; l = l->next; }cout << endl;
	}
	node* insert(node* l, int x)
	{
		node* t = newNode(x);
		if (l)
			t->next = l;
			return t;
	}
	node* append(node* l, int x)
	{
		node * t = newNode(x);
		if (!l) return t;
		node* p = l;
		while (l->next)l = l->next;
		l->next = t;
		return p;
	}
	node* findNode(node* l, int s)
	{
		while (l&&l->data != s) l = l->next;
		return l?l : NULL;
	}
	void  insertAfter(node*l, int s, int x)
	{
		node* p = findNode(l, s);
		if (p) {
			node* t = p->next;
			p->next = newNode(x);
			p->next->next = t;
			return;
		}
		cout << "Node not found" << endl;
	}
	void findNode(node* l, node* &p, node* &c, int x)
	{
		while (l && l->data != x) { p = l; l = l->next; }
		if (l)c = l;
		else p = NULL;
	}
	node* deleteNode(node* l, int x)
	{
		node*p=NULL, *c=NULL;
		if (!l)return l;
		findNode(l, p, c, x);
		if ( c == l) return l->next;
		p->next = c->next;
	}
	int sizeList(node* l)
	{
		int c = 0;
		while (l) { l = l->next; c++; }
		return c;
	}
	int sizeListR(node* l)
	{
		if (!l) return 0;
		return 1 + sizeListR(l->next);
	}
	node* swapNodes(node* l, int a, int b)
	{
		node*pa = NULL, *qa = NULL,*s=l;
		node* pb = NULL, *qb = NULL;
		node* t = NULL;
		if (a == b)return l;
		findNode(l, pa, qa, a);
		findNode(l, pb, qb, b);
		if (!(qa&&qb))return l;
	 	if (pa&&pb) {
			pa->next = qb;
			pb->next = qa;
			t = qa->next;
			qa->next = qb->next;
			qb->next = t;
		}
		if (pa == NULL) {
			pb->next = qa;
			t = qb->next;
			qb->next = qa->next;
				qa->next = t;
				s = qb;
		}
		if (pb == NULL) {
			pa->next = qb;
			t = qa->next;
			qa->next = qb->next;
			qb->next = t;
			s = qa;
		}
		return s;
	}
	int GetNth(node* l, int n)
	{
		while (l&&--n) { l = l->next;  }
		return l ? l->data : 0;
	}
	node* printMiddle1(node* l)
	{
		node*s = l;
		while (l&&l->next) {
			s = s->next;
			l = l->next->next ;
		}
		//cout << s->data;
		return s;
	}
	node* printMiddle(node* l)
	{
		int c = 0;
		node*s = l;
		while (l) {
			if (c++ & 1)s = s->next;
			l = l->next; 
		}
		cout << s->data;
		return s;
	}
	void printNthFromLast(node* l, int n)
	{
		node*s = l;
		while (l&&n--)
			l = l->next;
		while (l) {
			s = s->next;
			l = l->next;
		}
		if (n > 0)return;
		cout << s->data;
	}
	node* reverseList(node* l,node* del=NULL)
	{
		node*p, *q, *r;
		if (l==del || l->next==del)return l;
		if (l->next!=del&&l->next->next == del) { l->next->next = l; p = l->next; l->next = del; return p; }
		p = l; q = p->next;
		p->next = del;
		while (q!=del)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		return p;
	}

	node* reverseListR(node* l)
	{
		if (!l || !l->next) return l;
		node* p = reverseListR(l->next);
		l->next->next = l;
		l->next = NULL;
		return p;
	}
	node* detectloop(node* l)
	{
		if (!l || !l->next)return l;
		node*s=l, *f=l;
		node* p=NULL;
		while (s && f && f->next)
		{
			p = s;
			s = s->next;
			f = f->next->next;
			if (f == s) { cout << "loop found at " << s->data; return p; }
		}
		cout << "nop loop in the list\n"; 
		return NULL;
	}
	node* SortedMerge(node* a, node* b)
	{
		if (!a) return b;
		if (!b) return a;
		node*l = NULL;
		node* p = NULL;
		while (a&&b)
		{
			if (a->data < b->data)
			{
				if (!l) {
					l = a; p = a;
				}
				else
					p->next = a;
				p = a;
				a = a->next;
			}
			else
			{
				if (!l) { l = b; p = b; }
				else
					p->next = b;
				p = b;
				b = b->next;
			}
		}
		if (a) { p->next = a; }
		if (b) { p->next = b; }
		return l;
	}
	node* insertSorted(node* l, int x)
	{
		node* p = l;
		node* t = NULL;
		if (!l)return newNode(x);//1st node
		if (l->data > x) { p = newNode(x); p->next = l; return p; }// insert smaller node
		while (p && p->data < x) { t = p; p = p->next; }
		if (!p) { t->next = newNode(x); return l; }// if last node add at end
		t->next = newNode(x);// in middle 
		t->next->next = p;
		return l;
	}
	bool isPalindrome1(node* l)
	{// using stack check for palindrome
		stack<node*> s;
		node* p = l;
		while (p) { s.push(p); p = p->next; }
		while (!s.empty())
		{
			if (l->data != s.top()->data) return false;
			l = l->next;
			s.pop();
		}
		return true;
	}
	bool isPalindrome(node* l)
	{
		if (!l) return true;// null node
		if (!l->next) return false;// single node
		if (!l->next->next) return l->data == l->next->data?true:false;// only two nodes
		node*r = printMiddle1(l);
		node* p = reverseList(r->next);
		node* t1 = l, *t2 = p;
		bool f = true;
		while (t2 != NULL)
		{
			if (t1->data != t2->data) { f = false; break; }
			t1 = t1->next;
			t2 = t2->next;
		}
		r->next = reverseList(p);
		return f;
	}
	void printReverseR(node* l)
	{
		if (!l)return;
		printReverseR(l->next);
		cout << l->data << " ";
	}
	bool isIntersecting(node* a, node* b)
	{
		while (a->next)a = a->next;
		while (b->next)b = b->next;
		return a == b;
	}
	node* getIntesectionNode(node* a, node* b)
	{
		if (!isIntersecting(a, b))return NULL;
		int l1 = sizeList(a);
		int l2 = sizeList(b);
		if (l1 < l2) {int t = l1; l1 = l2; l2 = t; node* p = a; a = b; b = p;}
		int l = l1 - l2;
		while (l--)a = a->next;
		while (a&&b&&a != b) { a = a->next; b = b->next; }
		if (a&&b) return a;
		return NULL;
	}
	void deleteAlternate(node* l)
	{
		if (!l || !l->next)  return;
		while (l && l->next) {
			l->next = l->next->next; l = l->next;
		}
	}
	void deleteAlternateR(node* l)
	{
		if (!l || !l->next)  return;
		l->next = l->next->next;
		deleteAlternateR(l->next);
	}
	void alternateSplit(node* l, node* &aa, node* &bb)
	{
		int x = 1;
		node* a=NULL, *b=NULL;
		if(l) a = l;// initilize a and b
		l = l->next;
		if (l) b = l;
		l = l->next;
		aa = a; bb = b;
		while (l)// loop for rest of element and split
		{
			if (x & 1) {
				a->next = l; a = a->next;
			}
			else {
				b->next = l; b = b->next;
			}
			l = l->next;
			x++;
		}
		a->next = b->next = NULL;
	}
	node* delLesserNodes(node* l)
	{
		l = reverseList(l);
		node* t = l;
		node* p;
		while (l)
		{
			p = l;
			l = l->next;
			while (l&& (l->data < p->data))l = l->next;
			p->next = l;
		}
		return reverseList(t);
	}
	node* segregateEvenOdd(node* p)
	{
		if(!p || !p->next) return p;
		
		node* even=NULL, *odd=NULL;
		node*e = NULL, *o = NULL;
		while (p)
		{
			if (p->data % 2 == 0)
			{
				if (!even) { even = e = p; }
				else { e->next = p; e = e->next; }

			}
			else
			{
				if (!odd) { odd = o = p; }
				else
				{
					o->next = p; o = o->next;
				}
			}
			p = p->next;
		}
		if (o)o->next = NULL;
		if (even)e->next = odd;
		else return odd;
		return even;
	}
	void detectAndRemoveLoop1(node* l)
	{ 
		if (!l || !l->next) return;
		if (l == l->next) { l->next = NULL; return; }
		node *s = detectloop(l);//detect loop
		if (!s) return;// if no loop return
		node* p = l;
		node *t = s;
		while (1)// find loop begining point
		{
			while (p == t->next &&t != s)t = t->next;
			if (p == t->next) break;
			p = p->next;
		}
		if (p == t->next)// find last node and set next of this nod eto null
		p->next = NULL;
	}
	void detectAndRemoveLoop(node* l)
	{
		if (!l || !l->next) return;
		if (l == l->next) { l->next = NULL; return; }
		node* s = l, *f = l->next;
		while (f&&f->next)
		{
			if (s == f) break;
			s = s->next;
			f = f->next->next;
		}
		if (s == f)
		{
			s = l;
			while (s != f->next) { f = f->next; s = s->next; }
			f->next = NULL;
		}
	}
	void removeDuplicates(node* l)
	{
		if (!l || !l->next) return;
		node* p = l;
		while (l)
		{
			if (p->data != l->data) { p->next = l; p = l;}
			l = l->next;
		}
		p->next = NULL;
	}
	void pairWiseSwap1(node* l)
	{
		while (l && l->next)
		{
			swap(l->data, l->next->data);
			l = l->next->next;
		}
	}
	void pairWiseSwap(node* l)
	{
		if (l&&l->next)
		{
			swap(l->data, l->next->data);
			pairWiseSwap(l->next->next);
		}
	}
	
	node* reverseGroup(node* l, int x)
	{
		if (!l || !l->next)return l;
		node* h = NULL;
		node* t = l;
		node* p = NULL;
		node* q = NULL;
		int i = 0;
		while (t)
		{
			i = 0;
			t = l;
			while (t && i++ < x)t = t->next;
			p = reverseList(l, t);
			if (!h) { h = p; }
			if (!q)q = l;
			else { q->next = p; q = l; }
			l = t;
		}
		return h;
	}
	node* kAltReverse(node*l, int x)
	{
		if (!l || !l->next)return l;
		node* h = NULL;
		node* t = l;
		node* p = NULL;
		node* q = NULL;
		int i = 0;
		while (t)
		{
			i = 0;
			t = l;
			while (t && i++ < x)t = t->next;
			p = reverseList(l, t);
			if (!h) { h = p; }
			if (q)q->next = p;
			l->next = t;
			i = 0;
			while (t && i++ < x) {	q = t; t = t->next;}
			l = t;
		}
		return h;

	}
	node* mergeAlternate1(node* a, node* b)
	{
		if (!a) return b;
		if (!b) return a;
		node* h = a;
		node* t = a;
		a = a->next;
		int c = 1;
		while (a&&b)
		{
			if (c & 1)
			{
				t->next = b;
				b = b->next;
			}
			else
			{
				t->next = a;
				a = a->next;
			}
			t = t->next;
			c++;
		}
		if (a)t->next = a;
		if (b)t->next = b;
		return h;
	}
	node* mergeAlternate(node* a, node* b)
	{

		if (!a) return b;
		if (!b) return a;
		node* h = a;
		node* an=a->next, *bn=b->next;
		while (an&&bn)
		{
			a->next = b;
			b->next = an;
			a = an;
			b = bn;
			bn = bn->next;
			an = a->next;
		}
		if (an)a->next = an;
		if (bn)a->next = bn;
		return h;
	}
	node* pairWiseSwap2(node* l)
	{
		if (!l || !l->next)return l;
		node* n = NULL;
		node* h = l->next;
		while (l&&l->next)
		{
			n = l->next->next;
			l->next->next = l;
			l->next =n? n->next:n;
			if (!n->next)l->next = n;
			l = n;
		}
		return h;		                                                                                                                              
	}
	node* pairWiseSwap2R(node* l)
	{
		if (!l || !l->next)return l;
		node* h = l->next;
		l->next = pairWiseSwap2R(l->next->next);
		h->next = l;
		return h;
	}
	node* cloneList(node* l)
	{
		// using map
		map<node*,node*> m;
		node* h = l;
		node* x = NULL;
		while (l) 
		{
			m[l] = newNode(l->data);
			l = l->next;
		}
		l = h;
		h = m[l];
		x = h;
		while (l)
		{
			x->next = m[l->next];
			x->rand = m[l->rand];
			x = x->next;
			l = l->next;
		}
		return h;
	}
	void printListRandom(node* l)
	{
		while (l)
		{
			cout << l->data << " -> " << l->rand->data << endl;
			l = l->next;
		}

	}
	node* cloneList1(node* l)
	{
		if (!l)return l;
		node* p;
		node* h = l;
		while (l)
		{
			p = newNode(l->data);
			p->next = l->next;
			l->next = p;
			l = l->next->next;
		}
		l = h;
		while (l)
		{
			l->next->rand = l->rand->next;
			l = l->next->next;
		}
		l = h;
		p = l->next;
		h = p;
		while (true)
		{
			l->next = p->next;
			l = l->next;
			if (!l) break;
			p->next = l->next;
			p = p->next;
		}
		return h;
	}
}

/*
using namespace list;
int main(int argc, char* argv[])
{
	node* l = NULL;
	l = append(l, 1);
	l = append(l, 2);
	l = append(l, 3);
	l = append(l, 4);
	l = append(l, 5);
//	l = append(l, 6);
	node* ll = NULL;
	ll = append(ll, 7);
    ll = append(ll, 8);
	ll = append(ll, 9);
	//printList(l);
	l->rand = l->next->next;
	l->next->next->rand = l->next->next->next->next;
	l->next->next->next->next->rand = l->next;
	l->next->next->next->rand = l->next->next;
	l->next->rand = l;
	printListRandom(l);
	ll = cloneList1(l);
	printListRandom(ll);
	system("pause");
} */    
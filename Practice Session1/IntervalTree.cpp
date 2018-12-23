#include"test.h"
struct interval
{
	int l, h;
};
struct inode
{
	interval *i;
	struct inode *left;
	struct inode *right;
};

inode* newInode(interval i)
{
	inode *t = new inode;
	t->i = new interval;
	t->left = t->right = NULL;
	t->i->h = i.h;
	t->i->l = i.l;
	return t;
}
inode* insertI(inode * t,interval i)
{
	if (!t) return newInode(i); 
	if (t->i->l > i.l)
		t->left = insertI(t->left, i);
	else t->right = insertI(t->right, i);
	return t;
}
bool overlap(interval* i1, interval* i2)
{
	if (i1->l<i2->h&& i1->h>i2->l)
		return true;
	return false;
}

inode* searchTree(inode* t, interval i)
{
	if (!t)return t;
	if (overlap(t->i, &i)) return t;
	if(t->i->l > i.l)
	return searchTree(t->left, i);
	return searchTree(t->right, i);
}
void printOverlap(inode* t, interval i)
{
cout << "Interval [" << i.l << "," << i.h << "] overlaps with [" << t->i->l << "," << t->i->h << "] " << endl;
}
void printConflicting(interval a[], int n)
{
	inode* t = NULL;
	t = insertI(t, a[0]);
	for (int i = 1; i < n; i++)
	{
		inode * p = searchTree(t, a[i]);
		if (p) { printOverlap(p, a[i]); }
		t = insertI(t, a[i]);
	}
}
#if 0
// Driver program to test above functions
int main()
{
	// Let us create interval tree shown in above figure
	interval appt[] = { { 1, 5 },{ 3, 7 },{ 2, 6 },{ 10, 15 },
	{ 5, 6 },{ 4, 100 } };
	int n = sizeof(appt) / sizeof(appt[0]);
	cout << "Following are conflicting intervals\n";
	printConflicting(appt, n);
	system("pause");
	return 0;
}
#endif
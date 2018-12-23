#include "test.h"

	//http://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/
	//http://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/
	//http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/
	//http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
	//http://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/
	//http://www.geeksforgeeks.org/count-bst-subtrees-that-lie-in-given-range/
	//http://www.geeksforgeeks.org/construct-all-possible-bsts-for-keys-1-to-n/
	//http://www.geeksforgeeks.org/print-common-nodes-in-two-binary-search-trees/
	//http://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/
	//http://www.geeksforgeeks.org/data-structure-for-future-reservations-for-a-single-resource/
	Node* insertBST(Node* t, int x)
	{
		if (!t) return  newNode(x);
		if (t->data > x) { t->left = insertBST(t->left, x); }
		else { t->right = insertBST(t->right, x); }
		return t;
	}
	int minValue(Node* t)
	{
		if (!t)return 0;
		while (t->left != NULL)t = t->left;
		return t->data;
	}
	Node*  minValueNode(Node* t)
	{
		if (!t)return 0;
		while (t->left != NULL)t = t->left;
		return t;
	}
	bool isBST1(Node* t)
	{
		if (!t || !t->left && !t->right)return true;
		static int x = 0;
		bool l = isBST1(t->left);
		if (l == false) return l;
		if (x == 0)x = t->data;
		if (x > t->data) return false;
		x = t->data;
		bool r = isBST1(t->right);
		return r;
	}
	bool isBSTUtil(Node* t, int min, int  max)
	{
		if (!t || !t->left && !t->right)return true;
		if (t->data<min || t->data>max) return false;
		return isBSTUtil(t->left, min, t->data - 1) && isBSTUtil(t->right, t->data + 1, max);
	}

	bool isBST(Node* t)
	{
		return isBSTUtil(t, INT_MIN, INT_MAX);
	}

	void printSorted(int a[], int l, int h)
	{
		if (l > h) return;
		printSorted(a, 2 * l + 1, h);
		cout << a[l] << " ";
		printSorted(a, 2 * l + 2, h);
	}
	Node* inOrderSuccessor1(Node* t, Node* s)
	{
		if (!t)return t;
		static bool p = false;
		Node* n = inOrderSuccessor1(t->left, s);
		if (n)return n;
		if (t == s)p = true;
		if (p)return t;
		return inOrderSuccessor1(t->right, s);
	}
	Node* inOrderSuccessor(Node* t, Node* s)
	{
		if (s->right != NULL) return minValueNode(t->right);
		Node* succ = NULL;
		while (t != NULL)
		{
			if (t->data > s->data) {
				succ = t;
				t = t->left;
			}
			else if (t->data < s->data)
				t = t->right;
			else break;
		}
		return succ;
	}
	Node* k_smallest_element_inorder(Node* t, int& k)
	{
		if (!t)return t;
		Node* l = k_smallest_element_inorder(t->left, k);
		if (l)return l;
		k--;
		if (k == 0)return t;
		return k_smallest_element_inorder(t->right, k);
	}

	Node* k_largest_element_inorder(Node* t, int& k)
	{
		if (!t)return t;

		Node* r = k_largest_element_inorder(t->right, k);
		if (r)return r;
		k--;
		if (k == 0)return t;
		return k_largest_element_inorder(t->left, k);
	}
	void printRangeBST(Node* t, int l, int r)
	{
		if (!t) return;
		if (t->data > l) printRangeBST(t->left, l, r);
		if (t->data >= l && t->data <= r) cout << t->data << " ";
		if (t->data < r)	printRangeBST(t->right, l, r);
	}
	void push(Node** t, int n)
	{
		if (*t == NULL) { *t = newNode(n); return; }
		Node*p = *t;
		while (p->right)p = p->right;
		p->right = newNode(n);
	}
	void printList(Node* t);// {	while (t != NULL) { cout << t->data << " "; t = t->right; }}
	void inOrderR(Node*t);

	Node*sortedListToBSTUtil(Node* &t, int n)
	{
		if (n <= 0)return NULL;
		Node* l = NULL;
		Node* r = NULL;
		l = sortedListToBSTUtil(t, n / 2);
		Node* tree = newNode(t->data);
		t = t->right;
		tree->left = l;
		tree->right = sortedListToBSTUtil(t, (n - n / 2) - 1);
		return tree;
	}

	Node* sortedListToBST(Node* t)
	{
		int s = 0;
		Node* p = t;
		while (p != NULL) { p = p->right; s++; }
		return sortedListToBSTUtil(t, s);
	}
	void preOrder(Node* t);
	Node* sortedArrayToBST(int a[], int l, int h)
	{
		if (l > h)return NULL;
		int m = (l + h) / 2;
		Node* t = newNode(a[m]);
		if (l == h)return t;
		t->left = sortedArrayToBST(a, l, m - 1);
		t->right = sortedArrayToBST(a, m + 1, h);
		return t;
	}
	int size(Node*);
	int largestBST1(Node* t)
	{
		if (isBST(t)) return size(t);
		return max(largestBST1(t->left), largestBST1(t->right));
	}
	int largestBSTutil(Node* t, int& minref, int& maxref, int& maxlenref, bool& fref)
	{
		// TODO
		if (!t) { fref = true; return 0; }
		if (!t->left && !t->right) { fref = true; return 1; }
		bool lf = false, rf = false;
		int min = INT_MIN, max = INT_MAX, maxlen = INT_MIN;
		int ll = largestBSTutil(t->left, min, max, maxlen, lf);
		int rr = largestBSTutil(t->right, min, max, maxlen, rf);

	}
	int largestBST(Node* t)
	{
		int min = INT_MIN, max = INT_MAX, maxref = INT_MIN;
		bool bst = false;
		return largestBSTutil(t, min, max, maxref, bst);
	}
	Node* removeOutsideRange(Node* t, int min, int max)
	{
		if (!t)return t;
		if (t->data < min) return t->right;
		if (t->data > max) return t->left;
		t->left = removeOutsideRange(t->left, min, max);
		t->right = removeOutsideRange(t->right, min, max);
		return t;
	}
	void findPreSuc1(Node* t, Node* &p, Node* & s, int k)
	{ // if element is present in tree.
		if (!t) return;
		static Node* q = NULL;
		if (p&&s) return;
		findPreSuc1(t->left, p, s, k);
		if (!q) q = t;
		if (p)s = t;
		if (t->data == k)
			p = q;
		q = t;
		findPreSuc1(t->right, p, s, k);
	}
	void findPreSuc(Node* t, Node* &p, Node* &s, int k)
	{
		if (!t) return;
		if (t->data == k)
		{
			if (t->left) {
				Node* n = t->left;
				while (n->right)n = n->right;
				s = n;
			}
			if (t->right) {
				Node* n = t->right;
				while (n->left)n = n->left;
				p = n;
			}
		}
		if (t->data > k)
		{
			s = t;
			findPreSuc(t->left, p, s, k);
		}
		else
		{
			p = t;
			findPreSuc(t->right, p, s, k);
		}
	}
	int getCountRangeBST(Node* t, int l, int h)
	{
		if (!t)return 0;
		if (t->data == l || t->data == h) return 1;
		if (t->data > l&&t->data < h)
			return 1 + getCountRangeBST(t->left, l, h) + getCountRangeBST(t->right, l, h);
		else if (t->data > l)
			return getCountRangeBST(t->left, l, h);
		else return getCountRangeBST(t->right, l, h);
	}

#if 0
#define insert insertBST
int main(int argc, wchar_t *argv)
{
	
	// Let us construct the BST shown in the above figure
	node *root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(50);
	root->left->left = newNode(1);
	root->right->left = newNode(40);
	root->right->right = newNode(100);
	/* Let us constructed BST shown in above example
	10
	/    \
	5       50
	/       /  \
	1       40   100   */
	int l = 5;
	int h = 45;
	cout << "Count of nodes between [" << l << ", " << h
		<< "] is " << getCountRangeBST(root, l, h);
system("pause");
}
#endif
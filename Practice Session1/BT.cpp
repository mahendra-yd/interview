#include "test.h"

//http://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
//http://www.geeksforgeeks.org/construct-tree-inorder-level-order-traversals/
//http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
//http://www.geeksforgeeks.org/minimum-iterations-pass-information-nodes-tree/
//****http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
//http://www.geeksforgeeks.org/check-given-binary-tree-follows-height-property-red-black-tree/
//http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
//http://www.geeksforgeeks.org/construct-ancestor-matrix-from-a-given-binary-tree/
//http://www.geeksforgeeks.org/construct-tree-from-ancestor-matrix/
/*
http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/
http://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
http://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/
http://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
http://www.geeksforgeeks.org/serialize-deserialize-n-ary-tree/
http://www.geeksforgeeks.org/find-closest-leaf-binary-tree/
http://www.geeksforgeeks.org/construct-ancestor-matrix-from-a-given-binary-tree/
http://www.geeksforgeeks.org/closest-leaf-to-a-given-node-in-binary-tree/
http://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/
http://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
http://www.geeksforgeeks.org/find-all-possible-trees-with-given-inorder-traversal/
http://www.geeksforgeeks.org/find-lca-in-binary-tree-using-rmq/
http://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
http://www.geeksforgeeks.org/succinct-encoding-of-binary-tree/
*/


Node * newNode(int x) { Node *t = new Node; t->next = t->nextRight = t->left = t->right = NULL; t->data = x; t->isThreaded = false; return t; }
int size(Node *tree) { if (tree == NULL) return 0; return 1 + size(tree->left) + size(tree->right); }
bool identicalTrees(Node* t1, Node* t2) { if (t1 == NULL&&t2 == NULL) return true; return t1 &&t2 && t1->data == t2->data &&  identicalTrees(t1->left, t2->left) && identicalTrees(t1->right, t2->right); }
bool identicalTrees1(Node* t1, Node* t2) { if (t1 == NULL&&t2 == NULL) return true; return t1 &&t2 &&  identicalTrees1(t1->left, t2->left) && identicalTrees1(t1->right, t2->right); }
int height(Node* t) { if (t == NULL) return 0; return 1 + max(height(t->left), height(t->right)); }
void deleteTree(Node* t) { if (t == NULL) return;	deleteTree(t->left);	deleteTree(t->right);	cout << "Deleting node " << t->data;	delete t; }
void inOrderR(Node *t) { if (t == NULL) return; inOrderR(t->left); cout << t->data << " "; inOrderR(t->right); }
void mirror(Node *t) { if (t == NULL) return; mirror(t->left); mirror(t->right); Node *p = t->left; t->left = t->right; t->right = p; }
void printPathUtil(Node* t, Node* p[], int i) { if (t == NULL) return; p[i++] = t; if (t->left == NULL && t->right == NULL) { cout << "\nPath " << i << "is \n"; for (int j = 0; j<i; j++)cout << " " << p[j]->data; }	printPathUtil(t->left, p, i); printPathUtil(t->right, p, i); }
void printPath(Node* t) { Node* p[100]; int i = 0; if (t != NULL) printPathUtil(t, p, i); }
Node* lcaBST(Node* t, int a, int b) { if (t == NULL) return NULL; if (t->data< a && t->data<b)return lcaBST(t->right, a, b); else if (t->data>a && t->data>b)return lcaBST(t->left, a, b); else return t; }
void printNodeAtLevel(Node* t, int l) { if (t == NULL) return; if (l == 0) cout << t->data << " "; printNodeAtLevel(t->left, l - 1); printNodeAtLevel(t->right, l - 1); }
void printLevelOrder(Node* t) { int h = height(t); for (int i = 0; i < h; i++) { printNodeAtLevel(t, i); cout << endl; } }
int getLeafCount(Node* t) { if (t == NULL) return 0; if (t->left == NULL && t->right == NULL) return 1; return getLeafCount(t->left) + getLeafCount(t->right); }
void printNodeAtLevelS(Node* t, int i, bool f) { if (t == NULL) return; if (i == 0) cout << t->data << " "; else if (i>0) { if (f == true) { printNodeAtLevelS(t->left, i - 1, f); printNodeAtLevelS(t->right, i - 1, f); } else { printNodeAtLevelS(t->right, i - 1, f); printNodeAtLevelS(t->left, i - 1, f); } } }
void printSpiralR(Node* t) { bool f = false; int h = height(t); for (int i = 0; i<h; i++, f = !f) { printNodeAtLevelS(t, i, f); } }
void printSpiral(Node* t) { stack<Node*> s1, s2; s1.push(t); while (!s1.empty() || !s2.empty()) { while (!s1.empty()) { t = s1.top(); s1.pop(); cout << t->data << " "; if (t->right) s2.push(t->right); if (t->left) s2.push(t->left); }while (!s2.empty()) { t = s2.top(); s2.pop(); cout << t->data << " "; if (t->left) s1.push(t->left);		if (t->right) s1.push(t->right); } } }
bool isSumProperty(Node* t) { if (t == NULL || t->right == NULL && t->left == NULL) return true;	bool b1 = isSumProperty(t->left); bool b2 = isSumProperty(t->right); int x = 0; if (t->left) x += t->left->data; if (t->right)x += t->right->data; return  t->data == x && b1 && b2; }
void printInorder(Node *t) { if (t == NULL) return; printInorder(t->left); cout << t->data << " "; printInorder(t->right); }
void addDiff(Node* t, int d) { if (t->left != NULL) { t->left->data += d; addDiff(t->left, d); } else if (t->right != NULL) { t->right->data += d; addDiff(t->right, d); } }
void convertTreeChildSumProperty(Node* t) { if (t == NULL || t->left == NULL &&& t->right == NULL) return; convertTreeChildSumProperty(t->left); convertTreeChildSumProperty(t->right); int x = 0, d = 0; if (t->left) x = t->left->data; if (t->right)x += t->right->data; d = x - t->data; if (d>0) t->data += d; else addDiff(t, -d); }
int diameter(Node* t) { if (t == NULL) return 0; int dl = diameter(t->left); int dr = diameter(t->right); int lh = height(t->left); int rh = height(t->right); int d = lh + rh + 1; return max(max(dl, dr), d); }
int diameterOptUtil(Node* t, int& h) { if (t == NULL) { h = 0; return 0; }int lh = 0, rh = 0; int dl = diameterOptUtil(t->left, lh); int dr = diameterOptUtil(t->right, rh); h = 1 + max(lh, rh); return max(max(dr, dl), lh + rh + 1); }
int diameterOpt(Node *t) { int h = 0; if (t == NULL) return 0; return diameterOptUtil(t, h); }
bool isBalanced(Node* t) { if (t == NULL) return true; int lh = height(t->left); int rh = height(t->right); return isBalanced(t->left) && isBalanced(t->right) && abs(lh - rh) <= 1; }
bool isBalancedOpt(Node* t, int& h) { if (t == NULL) { h = 0; return true; }int lh = 0, rh = 0; int lb = isBalancedOpt(t->left, lh); int rb = isBalancedOpt(t->right, rh); h = 1 + max(lh, rh); return lb&&rb&&abs(lh - rh) <= 1; }
void preOrder(Node* t) { if (t == NULL) return; stack<Node*> s; s.push(t); while (!s.empty()) { t = s.top(); s.pop(); cout << t->data<<" "; if (t->right)s.push(t->right); if (t->left)s.push(t->left); } }
void inOrder(Node* t) { if (t == NULL) return; stack<Node* > s; label:while (t != NULL) { s.push(t); t = t->left; }while (!s.empty()) { t = s.top(); s.pop(); cout << t->data << " "; if (t->right) { t = t->right; goto label; } } }
void postOrder(Node*t) { if (t == NULL) return; stack<Node*>s; label:while (t != NULL) { if (t->right) s.push(t->right); s.push(t); t = t->left; }while (!s.empty()) { t = s.top(); s.pop(); if (!s.empty() && t->right == s.top()) { s.pop(); s.push(t); t = t->right; goto label; } else cout << t->data << " "; } }
void InMorrisTraversal(Node* t) { if (!t) return; while (t) { if (!t->left) { cout << t->data << " "; t = t->right; } else { Node* p  = t->left; while (p->right != NULL && p != t)p = p->right; if (p->right == t) { p->right = NULL; cout << t->data << " "; t = t->left; } else { p->right = t; t = t->right; } } } }
void PreMorrisTraversal(Node*t) { if (!t) return; while (t) { if (!t->left) { cout << t->data << " "; t = t->right; } else { Node* p = t->left; while (p->right != NULL && p != t)p = p->right; if (p->right == t) { p->right = NULL; t = t->left; } else { p->right = t; cout << t->data << " "; t = t->right; } } } }
bool hasPathSum(Node* t, int x) { if (t == NULL && x == 0) return true; else if (t == NULL && x != 0) return false; else return hasPathSum(t->left, x - t->data) || hasPathSum(t->right, x - t->data); }
int findPre(char in[], char c, int i, int n) { for (int j = i; j <= n; j++) { if (c == in[j]) return j; } }
Node* buildTree(char in[], char pre[], int& index, int low, int n) { if (low>n)  return NULL; Node *t = newNode(pre[index++]); if (low == n) return t; int l = findPre(in, t->data, low, n); t->left = buildTree(in, pre, index, low, l - 1); t->right = buildTree(in, pre, index, l + 1, n); return t; }
void print(int a[], int i) { for (int j = 0; j<i; j++) cout << a[j] << " "; cout << endl; }
void printPaths(Node* t, int a[], int i) { if (t == NULL) return; a[i++] = t->data; if (t->left == NULL && t->right == NULL) print(a, i); printPaths(t->left, a, i); printPaths(t->right, a, i); }
//count nodes at level
int getMaxWidthUtil1(Node* t, int l) { if (t == NULL) return 0; if (l == 0) return 1; return 	getMaxWidthUtil1(t->left, l - 1) + getMaxWidthUtil1(t->right, l - 1); }
int getMaxWidth1(Node* t) {/*count node at each level*/int maxWidth = 0, w = 0, l = height(t); for (int i = 0; i<l; i++) { w = getMaxWidthUtil1(t, i); if (w>maxWidth) maxWidth = w; }return maxWidth; }
void getMaxWidth2(Node* t, int a[], int l) {/*do a pre order traversal increment array of each level*/if (t == NULL) return; a[l]++; getMaxWidth2(t->left, a, l + 1); getMaxWidth2(t->right, a, l + 1); }
int getMaxWidth3(Node* t) { if (t == NULL) return 0; queue<Node*>q; q.push(t); int m = 0; while (!q.empty()) { int i = q.size(); if (i>m)m = i; while (i--) { t = q.front(); q.pop(); cout << t->data << " "; if (t->left) q.push(t->left); if (t->right)q.push(t->right); }cout << endl; }return m; }
void getMaxWidthUtil(Node* t, int l, int& ll, int& rr, int w) { if (t == NULL) return; if (l == 0) { if (w>0 && rr<w) rr = w; if (w<0 && w<ll)ll = w; }getMaxWidthUtil(t->left, l - 1, ll, rr, w - 1); getMaxWidthUtil(t->right, l - 1, ll, rr, w + 1); }
int getMaxWidth(Node* t) { int l = 0, r = 0, w = 0; int h = height(t); for (int i = 0; i<h; i++) { getMaxWidthUtil(t, i, l, r, 0); if (r - l - 1>w)w = r - l - 1; r = 0, l = 0; }return w; }
bool isFoldable(Node* t) { if (t == NULL) return true; if (t->left != NULL)mirror(t->left); return identicalTrees1(t->left, t->right); }
void printKDistantFromRoot(Node* t, int l) { if (t == NULL) return; if (l == 0)cout << t->data << " "; printKDistantFromRoot(t->left, l - 1); printKDistantFromRoot(t->right, l - 1); }
int getLevel(Node* t, int x, int l) { if (t == NULL) return 0; if (x == t->data) return l; return getLevel(t->left, x, l + 1) + getLevel(t->right, x, l + 1); }
void printAncestors1(Node* t, int x, int a[], int i) { if (t == NULL) return; if (x == t->data) { for (int j = i - 1; j >= 0; j--)cout << a[j] << " "; return; }a[i++] = t->data;	printAncestors1(t->left, x, a, i); printAncestors1(t->right, x, a, i); }
bool printAncestors(Node* t, int x) { if (t == NULL) return false; if (t->data == x) return true; if (printAncestors(t->left, x) || printAncestors(t->right, x))cout << " " << t->data; }
bool isSumTree(Node* t, int& s) { if (t == NULL) { return true; }int s1 = 0, s2 = 0; if (t->left == NULL&&t->right == NULL) { s = t->data; return true; }return isSumTree(t->left, s1) && isSumTree(t->right, s2) && s1 + s2 == t->data && (s = 2 * t->data); }
bool isSubtree(/*Do inorder and pre order of both tree and check wheather one sub array of other or not*/Node* t, Node* s) { if (s == NULL) return true; if (t == NULL) return false; if (t->data == s->data && identicalTrees(t, s)) return true; return isSubtree(t->left, s) || isSubtree(t->right, s); }
void connectNextRight1(Node* t) { if (t == NULL) return; queue<Node*> q; q.push(t); while (!q.empty()) { int s = q.size(); Node* p = NULL; while (s--) { t = q.front(); q.pop(); t->nextRight = p; p = t; if (t->right) q.push(t->right); if (t->left)  q.push(t->left); } } }
Node* findNextRight(Node* t) { Node* p = t->nextRight; while (p) { if (p->left) return p->left; if (p->right) return p->right; p = p->nextRight; }return NULL; }
void connectNextRightR(Node* t) {/*Recursive*/if (!t) return; if (t->nextRight) { connectNextRightR(t->nextRight); }if (t->left) { if (t->right) { t->left->nextRight = t->right; t->right->nextRight = findNextRight(t); } else t->left->nextRight = findNextRight(t); connectNextRightR(t->left); } else if (t->right) { t->right->nextRight = findNextRight(t); connectNextRightR(t->right); } else connectNextRightR(findNextRight(t)); }
void connectNextRight(Node * t) {/*Iterative*/if (!t) return; while (t != NULL) { Node* p = t; while (p != NULL) { if (p->left) { if (p->right)p->left->nextRight = p->right; else p->left->nextRight = findNextRight(p); }if (p->right)p->right->nextRight = findNextRight(p); p = p->nextRight; }if (t->left)t = t->left; else if (t->right) t = t->right; else t = findNextRight(t); } }
void populateInOrderSucc(Node* t) { if (!t) return; static Node * p = NULL; populateInOrderSucc(t->right); t->next = p; p = t; populateInOrderSucc(t->left); }
int toSumTree(Node* t) { if (t == NULL) return 0; int old = t->data; t->data = toSumTree(t->left) + toSumTree(t->right); return t->data + old; }
int maxSumPath(Node* t, int s, int& m, Node* & p) { if (!t) return 0; s += t->data; if (t->left == NULL&&t->right == NULL) { if (m<s) { m = s; p = t; } }maxSumPath(t->left, s, m, p); maxSumPath(t->right, s, m, p); }
bool isCompleteBT(Node* t) { if (!t) return true; bool f = false; queue<Node*>q; q.push(t); while (!q.empty()) { int s = q.size(); while (s--) { t = q.front(); q.pop(); cout << t->data; if (t->left) { if (f) return false; q.push(t->left); } else f = true; if (t->right) { if (f) return false; q.push(t->right); } else f = true; } }return true; }
Node* constructTree(int pre[], char preLn[], int& index, int n) { if (index >= n) return NULL; Node* t = newNode(pre[index]); if (preLn[index++] == 'N') { t->left = constructTree(pre, preLn, index, n); t->right = constructTree(pre, preLn, index, n); }return t; }

void VerticalSumUtil(Node* t, map<int, int>& m, int d) { if (!t) return; m[d] += t->data; VerticalSumUtil(t->left, m, d - 1); VerticalSumUtil(t->right, m, d + 1); }
void VerticalSum(Node* t) { map<int, int>m; VerticalSumUtil(t, m, 0); for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)cout << i->first << " sum = " << i->second << endl; }
int findPre(int a[], int x, int l, int h) { for (int i = l; i <= h; i++) if (a[i] == x) return i; }
Node* constructTreePrePost(int pre[], int post[], int& preIndex, int l, int h, int n) { if (l>h || preIndex >= n) return NULL; Node* t = newNode(pre[preIndex++]); if (l == h) return t; int i = findPre(post, pre[preIndex], l, h); if (i <= h) { t->left = constructTreePrePost(pre, post, preIndex, l, i, n); t->right = constructTreePrePost(pre, post, preIndex, i + 1, h, n); }return t; }
void ConstructCompleteBT(Node*& t, int i, queue<Node*>& q) { Node* p = newNode(i); if (!t) t = p; else { Node* m = q.front(); if (!m->left) m->left = p; else if (!m->right)m->right = p; if ((q.front()->left == NULL) && (q.front()->right == NULL))q.pop(); }	q.push(p); }
void levelOrder(Node* t) { if (!t) return; queue<Node*>q; q.push(t); while (!q.empty()) { int s = q.size(); while (s--) { t = q.front(); q.pop(); cout << t->data; if (t->left)	q.push(t->left); if (t->right)q.push(t->right); } } }


/*  Node* t=newNode(1);
t->left=newNode(2);
t->left->left=newNode(9);
t->left->left->right=newNode(10);
t->left->right=newNode(6);
t->left->right->left=newNode(11);
t->right=newNode(3);
t->right->right=newNode(5);
t->right->left=newNode(4);
t->right->left->left=newNode(12);
t->right->left->right=newNode(7);
*/
int findPreIn(int in[], int x, int n)
{
	for (int i = 0; i<n; i++) if (x == in[i]) return i;
	return -1;
}
// given pre and in orde rprint post order
void printPostOrderInPre(int in[], int pre[], int n)
{
	if (n<0) return;
	int i = findPreIn(in, pre[0], n);
	if (i != 0) printPostOrderInPre(in, pre + 1, i);
	if (i != n - 1) printPostOrderInPre(in + i + 1, pre + i + 1, n - i - 1);
	cout << pre[0];
}



int treePathsSum(Node* t, int s)
{
	if (!t) return 0;
	s = (s * 10 + t->data);
	if (!t->left && !t->right) return s;
	return treePathsSum(t->left, s) + treePathsSum(t->right, s);
}
void printSingles(Node* t)
{
	if (!t) return;
	if (t->left&&t->right) { printSingles(t->left); printSingles(t->right); }
	else if (t->right) { cout << t->right->data << " "; printSingles(t->right); }
	else if (t->left) { cout << t->left->data << " "; printSingles(t->left); }
}

Node* findLCA(Node* t, int a, int b)
{
	if (!t) return t;
	if (t->data == a || t->data == b) return t;
	Node* l = findLCA(t->left, a, b);
	Node* r = findLCA(t->right, a, b);
	if (l&&r) return t;
	return l ? l : r;

}

void verticalOrder1(Node* t, map<int, vector<int>>& m, int d)
{
	/*map<int,vector<int>> m;
	verticalOrder(root,m,0);
	for(map<int,vector<int>>::iterator i=m.begin();i!=m.end();i++)
	{
	for(vector<int>::iterator j=i->second.begin();j!=i->second.end();j++)
	cout<<*j<<" ";
	cout<<endl;
	}*/
	if (!t) return;
	m[d].push_back(t->data);
	verticalOrder1(t->left, m, d - 1);
	verticalOrder1(t->right, m, d + 1);
}


void findMinMaxVd(Node* t, int& min, int& max, int d)
{
	if (!t) return;
	if (min>d)min = d;
	if (max<d) max = d;
	findMinMaxVd(t->left, min, max, d - 1);
	findMinMaxVd(t->right, min, max, d + 1);
}
void printNodeAtDist(Node* t, int i, int d)
{
	if (!t) return;
	if (i == d) cout << t->data << " ";
	printNodeAtDist(t->left, i, d - 1);
	printNodeAtDist(t->right, i, d + 1);
}
void verticalOrder(Node*t)
{
	int min = INT_MAX, max = INT_MIN;
	findMinMaxVd(t, min, max, 0);
	for (int i = min; i <= max; i++) { printNodeAtDist(t, i, 0); cout << endl; }
}
bool isSibling(Node* t, Node* a, Node* b)
{
	if (!t) return false;
	return t->left == a && t->right == b || t->left == b && t->right == a || isSibling(t->left, a, b) || isSibling(t->right, a, b);
}
int  getLevel(Node*, int, int);
bool isCousin(Node* t, Node* a, Node* b)
{
	if (!t) return false;
	return !isSibling(t, a, b) && getLevel(t, a->data, 0) == getLevel(t, b->data, 0);

}
void fillDepth(int p[], int i, int d[])
{
	if (d[i]) return;
	if (p[i] == -1) { d[i] = 1; return; }
	if (d[p[i]] == 0)
		fillDepth(p, p[i], d);
	d[i] = d[p[i]] + 1;
}
int findHeight(int p[], int n)
{
	int d[100] = { 0 };
	for (int i = 0; i<n; i++)
		fillDepth(p, i, d);
	int m = 0;
	for (int i = 0; i<n; i++)
		if (m<d[i])m = d[i];
	return m;
}
void printNodeRangeLevels(Node* t, int h, int l, int d)
{
	if (!t) return;
	if (d >= h && d <= l) cout << t->data << " ";
	printNodeRangeLevels(t->left, h, l, d + 1);
	printNodeRangeLevels(t->right, h, l, d + 1);
}


void createThreaded(Node* t)
{
	if (!t)
		return;
	static Node* p = NULL;
	createThreaded(t->right);
	if (p == NULL) p = t;
	else if (t->right == NULL)
	{
		t->right = p;
		t->isThreaded = true;
	}
	p = t;
	createThreaded(t->left);
}
Node* leftMost(Node* t) { while (t && t->left != NULL) t = t->left; return t; }
void inOrderThreaded(Node* t)
{
	Node* p = leftMost(t);
	while (p)
	{
		cout << p->data << " ";
		if (p->isThreaded)p = p->right;
		else p = leftMost(p->right);
	}
}

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
		cout << i->second << " ";
}
void TopViewBT(Node* t)
{
	typedef pair<Node*, int> P;
	if (!t) return;
	queue<P>q;
	map<int, int>m;
	q.push(P(t, 0));
	while (!q.empty())
	{
		P p = q.front();
		q.pop();
		if (m.find(p.second) == m.end())
			m[p.second] = p.first->data;
		if (p.first->left)q.push(P(p.first->left, p.second - 1));
		if (p.first->right)q.push(P(p.first->right, p.second + 1));
	}
	printMap(m);

}
void BottomViewBT(Node* t)
{
	typedef pair<Node*, int> P;
	if (!t) return;
	queue<P>q;
	map<int, int>m;
	q.push(P(t, 0));
	while (!q.empty())
	{
		P p = q.front();
		q.pop();
		m[p.second] = p.first->data;
		if (p.first->left)q.push(P(p.first->left, p.second - 1));
		if (p.first->right)q.push(P(p.first->right, p.second + 1));
	}
	printMap(m);
}

void leftViewBT(Node* t, int l, int& h)
{
	if (!t) return;
	if (h<l) { cout << t->data << " "; h = l; }
	leftViewBT(t->left, l + 1, h);
	leftViewBT(t->right, l + 1, h);
}
void rightViewBT(Node* t, int l, int& h)
{
	if (!t) return;
	if (h<l) { cout << t->data << " "; h = l; }
	rightViewBT(t->right, l + 1, h);
	rightViewBT(t->left, l + 1, h);
}
void printLeftBoundry(Node* t) { if (!t) return; if (t->left == NULL&&t->right == NULL) return; cout << t->data << " "; if (t->left) printLeftBoundry(t->left); else printLeftBoundry(t->right); }
void printBottomBoundry(Node* t) { if (!t) return; if (t->left == NULL&&t->right == NULL)cout << t->data << " "; printBottomBoundry(t->left); printBottomBoundry(t->right); }
void printRightBoundry(Node* t) { if (!t) return; if (t->left == NULL&&t->right == NULL) return; cout << t->data << " "; if (t->right) printRightBoundry(t->right); else printRightBoundry(t->left); }
void printBoundary(Node*t) { if (!t) return; cout << t->data << " "; printLeftBoundry(t->left); printBottomBoundry(t); printRightBoundry(t->right); }
void printSpecificLevelOrder(Node* t)
{/*full binary tree print alternate 1234756......*/
	if (!t) return;
	cout << t->data << " ";
	if (!t->left) return;
	cout << t->left->data << " " << t->right->data << " ";
	if (!t->left->left) return;
	queue<Node*> q;
	Node* f1 = NULL;
	Node* f2 = NULL;
	q.push(t->left);
	q.push(t->right);
	while (!q.empty())
	{
		f1 = q.front(); q.pop();
		f2 = q.front(); q.pop();
		cout << f1->left->data << " " << f2->right->data << " ";
		cout << f1->right->data << " " << f2->left->data << " ";
		if (f1->left->left)
		{
			q.push(f1->left);
			q.push(f2->right);
			q.push(f1->right);
			q.push(f2->left);
		}
	}
}

node* RemoveHalfNodes(Node* t)
{
	if (!t) return t;

	t->left = RemoveHalfNodes(t->left);
	t->right = RemoveHalfNodes(t->right);
	if (!t->left && !t->right) return t;
	if (t->left == NULL) return t->right;
	if (t->right == NULL) return t->left;
	return t;
}

bool isOperator(char c) { if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true; return false; }
Node* constructTree(char p[])
{
	/*char postfix[] = "ab+ef*g*-";*/
	stack<Node*> s;
	Node* l = NULL, *r = NULL;
	for (int i = 0; i<strlen(p); ++i)
	{
		if (!isOperator(p[i])) { Node* t = newNode(p[i]); s.push(t); }
		else
		{
			r = s.top(); s.pop();
			l = s.top(); s.pop();
			Node* t = newNode(p[i]);
			t->left = l;
			t->right = r;
			s.push(t);
		}
	}	return s.top();
}





void postOrderIterative2Stack(Node* t)
{
	if (!t) return;
	stack<Node*>s1, s2;
	s1.push(t);
	while (!s1.empty())
	{
		t = s1.top(); s1.pop();
		s2.push(t);
		if (t->left)s1.push(t->left);
		if (t->right) s1.push(t->right);
	}
	while (!s2.empty()) {
		t = s2.top(); s2.pop(); cout << t->data << " ";
	}
}
void bintree2list(Node* t, Node*& head)
{
	if (!t) return;
	static Node* ptr = NULL;
	bintree2list(t->left, head);
	if (head == NULL) { ptr = t; head = t; }
	else { ptr->right = t; t->left = ptr; ptr = t; }
	bintree2list(t->right, head);
}
void printList(Node* t) { while (t) { cout << t->data << " "; t = t->right; } }

bool isIsomorphic(Node* t1, Node* t2)
{
	if (!t1 && !t2) return true;
	if (!t1 || !t2) return false;
	return t1->data == t2->data && (isIsomorphic(t1->left, t2->left) && isIsomorphic(t1->right, t2->right) || isIsomorphic(t1->left, t2->right) && isIsomorphic(t1->right, t2->left));
}
int getLevelDiff(Node* t)
{
	if (!t) return 0;
	return t->data - (getLevelDiff(t->left) + getLevelDiff(t->right));

}
int depthOfOddLeaf(Node *t, int l, int& h)
{
	if (!t) return 0;
	if (!t->left && !t->right && l & 1) { if (l>h) h = l; }
	depthOfOddLeaf(t->left, l + 1, h);
	depthOfOddLeaf(t->right, l + 1, h);
	return h;
}
bool checkAllLeavesAtSameLevel(Node* t, int l, int& h)
{
	if (!t) return true;
	if (!t->left && !t->right) { if (h == 0) { h = l; return true; }if (l != h) return l == h; }
	return checkAllLeavesAtSameLevel(t->left, l + 1, h) && checkAllLeavesAtSameLevel(t->right, l + 1, h);
}

Node* prune(Node* t, int s, int k)
{
	if (!t) return NULL;
	s += t->data;
	t->left = prune(t->left, s, k);
	t->right = prune(t->right, s, k);
	if (!t->left && !t->right && s<k) return NULL;
	return t;
}

Node* extractLeafList(Node* t, Node* & h)
{
	static Node* p = NULL;
	if (!t) return NULL;
	if (!t->left && !t->right) { if (h == NULL) { h = t; p = t; } else { p->right = t; t->left = p; p = t; } return NULL; }
	t->left = extractLeafList(t->left, h);
	t->right = extractLeafList(t->right, h);
	return t;
}
Node* deepestLeftLeaf(Node* t, int l, int& h, bool isleft)
{
	static Node* p = NULL;
	if (!t) return NULL;
	if (isleft && !t->left && !t->right) { if (h<l) h = l; p = t; }
	deepestLeftLeaf(t->left, l + 1, h, true);
	deepestLeftLeaf(t->right, l + 1, h, false);
	return p;
}

Node* nextRightBT(Node* t, int k)
{
	if (!t) return t;
	queue<Node*>q;
	q.push(t);
	while (!q.empty())
	{
		int s = q.size();
		while (s--)
		{
			t = q.front(); q.pop();
			if (t->data == k) { if (!s) return NULL; return q.front(); }
			if (t->left)q.push(t->left);
			if (t->right)q.push(t->right);
		}
	}
}
Node* findLCA(Node* t, int a, int b);
int findDistance(Node* t, int a, int b)
{
	Node* p = findLCA(t, a, b);
	return getLevel(p, a, 0) + getLevel(p, b, 0);
}
void printKDistantfromLeaf(Node* t, int d, int a[], int i, bool v[])
{
	if (!t) return;
	a[i] = t->data;
	v[i] = false;
	if (!t->left && !t->right && !v[i - d] && i - d >= 0) { cout << a[i - d] << " "; v[i - d] = true; }
	i++;
	printKDistantfromLeaf(t->left, d, a, i, v);
	printKDistantfromLeaf(t->right, d, a, i, v);
}

void BottomViewBT(Node* t);
void printMap(map<int, int>& m);
void TopViewBT(Node* t);
void digonalSumBT(Node* t)
{
	/*http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/DiagonalSum.jpg*/
	queue<Node*>q;
	if (!t)return;
	q.push(t);
	while (!q.empty())
	{
		int sum = 0;
		int l = q.size();
		while (l--)
		{
			t = q.front(); q.pop();
			while (t) { sum += t->data; if (t->left)q.push(t->left); t = t->right; }
		}
		cout << sum << " ";
		sum = 0;
	}
}

Node* removeShortPathNodes(Node* t, int l, int k)
{
	if (!t) return t;
	t->left = removeShortPathNodes(t->left, l + 1, k);
	t->right = removeShortPathNodes(t->right, l + 1, k);
	if (!t->left && !t->right&&l<k)return NULL;
	return t;
}
int leftLeavesSum(Node* t, bool f = false)
{
	if (!t) return 0;
	if (!t->left && !t->right&&f) return t->data;
	return leftLeavesSum(t->left, true) + leftLeavesSum(t->right, false);
}
bool isFullTree(Node* t)
{/*full tree no node have single child all node have 2child or zero chiuld*/
	if (!t) return true;
	if (!t->left && !t->right) return true;
	else if (!t->left || !t->right) return false;
	else return isFullTree(t->left) && isFullTree(t->right);
}
bool isCompleteBT(Node* t, int i, int n)
{/****complete bt is except last level all are full and after one null child no next child*/
	if (!t) return true;
	if (i >= n) return false;
	return isCompleteBT(t->left, 2 * i + 1, n) && isCompleteBT(t->right, 2 * i + 2, n);
}
int countNodes(Node* t) { if (!t) return 0; return 1 + countNodes(t->left) + countNodes(t->right); }
int minDepth(Node* t)
{
	if (t == 0) return 0;
	if (!t->left && !t->right) return 1;
	return 1 + min(minDepth(t->left), minDepth(t->right));
}
bool isMirror(Node* t1, Node* t2)
{
	if (!t1 && !t2) return true;
	return t1&&t2&&t1->data == t2->data&&isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool isSymmetric(Node* t)
{
	if (!t) return true;
	return isMirror(t, t);
}
void printPath(map<Node*,Node* >&m,Node* t)
{
	stack<Node*>s;
	while (t!=NULL)
	{
		s.push(t);
		t = m[t];
	}
	while (!s.empty())
	{
		t = s.top(); s.pop();
		cout << t->data << " ";
	}
	cout << endl;
}
void printRootToLeaf(Node* t)
{
	if (!t)return;
	stack<Node*> s;
	s.push(t);
	map<Node*, Node*> m;
	m[t] = NULL;
	while (!s.empty())
	{
		t = s.top(); s.pop();
		if (!t->left && !t->right) printPath(m,t);
		if (t->left) {	m[t->left] = t; s.push(t->left);}
		if (t->right) {	m[t->right] = t; s.push(t->right);}
	}
}
int heightAndSize(Node* t, int& s)
{
	if (!t)return 0;
	s++;
	return 1 + max(heightAndSize(t->left,s), heightAndSize(t->right,s));
}
float density(Node* t)
{
	if (!t)return 0;
	int s = 0;
	int h=heightAndSize(t, s);
	return (float) s / h;
}
void sinkOddNodes(Node* t)
{
	if (!t || !t->left && !t->right) return;
	if (t->data & 1 && !(t->left->data & 1))
		swap(t->data, t->left->data);
	if (t->data & 1 && !(t->right->data&1))
		swap(t->data, t->right->data);
	if (t->left) {
		sinkOddNodes(t->left);
	}
	if (t->right) {
		sinkOddNodes(t->right);
	}
}
void printCousinsUtil(Node* t, Node* s, int h, int l)
{
	if (!t)return;
	printCousinsUtil(t->left, s, h, l + 1);
	printCousinsUtil(t->right, s, h, l + 1);
	if (l + 1 == h) {
		if (t->left == s || t->right == s) return;
		if (t->left)cout << t->left->data << " ";
		if (t->right)cout << t->right->data << " ";
	}
}
void printCousins(Node* t, Node* s)
{
	int h=getLevel(t, s->data,0);
	printCousinsUtil(t, s, h,0);
}
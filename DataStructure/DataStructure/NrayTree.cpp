#if 0
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node
{
	int info;
	vector<Node*> child;
};
Node* newNode(int x)
{
	Node* t = new Node;
	t->info = x;
	return t;
}
void printNodeLevelWise(Node* t){
	if (!t) return;
	queue<Node *> q;
	q.push(t);
	while (!q.empty())
	{
		t = q.front(); q.pop();
		cout << t->info << " ";
		for (int i = 0; i < t->child.size(); i++)
			q.push(t->child[i]);
	}
}
void mirror(Node* t)
{
	if (!t) return;
	if (t->child.size() < 2) return;
	for (int i = 0; i < t->child.size(); i++)
		mirror(t->child[i]);
	reverse(t->child.begin(), t->child.end());
}
int main()
{
	/*   Let us create below tree
	*              10
	*        /   /    \   \
	*        2  34    56   100
	*                 |   /  | \
	*                 1   7  8  9
	*/
	Node* t = NULL;
	Node* root = newNode(10);
	root->child.push_back(newNode(2));
	(root->child).push_back(newNode(34));
	(root->child).push_back(newNode(56));
	(root->child).push_back(newNode(100));
	(root->child[2]->child).push_back(newNode(1));
	(root->child[3]->child).push_back(newNode(7));
	(root->child[3]->child).push_back(newNode(8));
	(root->child[3]->child).push_back(newNode(9));

	cout << "Level order traversal Before Mirroring\n";
	printNodeLevelWise(root);

	mirror(root);

	cout << "\nLevel order traversal After Mirroring\n";
	printNodeLevelWise(root);
	system("pause");
}
#endif
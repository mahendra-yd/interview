#if 0
//ternary is used for next word in dict,  near search and spell correct
// find all phone number starting from 0921
#include<iostream>
using namespace std;
typedef struct node
{
	int info;
	bool endOfWord;
	struct node *left, *equal, *right;
}Node;
Node* newNode(char c)
{
	Node* t = new Node;
	t->info = c;
	t->endOfWord = false;
	t->left = t->equal = t->right = NULL;
	return t;
}
void insert(node*& t, char* s)
{
	if (!*s) return;
	if (!t)t = newNode(*s);
	if (*s < t->info)insert(t->left, s);
	else if (*s > t->info)insert(t->right, s);
	else
	{
		if (*(s + 1)) insert(t->equal, s + 1);
		else t->endOfWord = true;
	}
}
void traverseTST(Node* t,char buf[],int i=0)
{
	if (!t)return;
	traverseTST(t->left, buf,i);
	buf[i] = t->info;
	if (t->endOfWord) { buf[i+1] = '\0'; cout << buf<<endl; }
	traverseTST(t->equal, buf,i+1);
	traverseTST(t->right, buf,i);
}
bool searchTST(Node* t, char* s)
{
	if (!t)return false;
	if (*s < t->info)return searchTST(t->left, s);
	else if (*s > t->info)return searchTST(t->right, s);
	else // mean t->info is equal to *s
	{
		if (*(s + 1) == '\0') return t->endOfWord;
		else searchTST(t->equal, s + 1);
	}
}
int main(int argc, char* argv[])
{
	 Node *root = NULL;
	insert(root, "cat");
	insert(root, "cats");
	insert(root, "up");
	insert(root, "bug");

	printf("Following is traversal of ternary search tree\n");
	char buf[100] = { 0 };
	traverseTST(root,buf);

	printf("\nFollowing are search results for cats, bu and cat respectively\n");
	searchTST(root, "cats") ? printf("Found\n") : printf("Not Found\n");
	searchTST(root, "bu") ? printf("Found\n") : printf("Not Found\n");
	searchTST(root, "cat") ? printf("Found\n") : printf("Not Found\n");
	system("pause");
	return 0;
}
#endif 
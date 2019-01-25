#include "stdafx.h"
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parrent;
	int height;
	Node(int info, Node *parrent = NULL)
	{
		this->data = info;
		this->left = this->right = NULL;
		this->parrent = parrent;
		this->height = 1;
	}
};
Node* insertIntoBinaryTree(Node*root, int item)
{
	if (!root) return new Node(item);
	if (root->data > item)
		root->left = insertIntoBinaryTree(root->left, item);
	else
		root->right = insertIntoBinaryTree(root->right, item);
	return root;
}
void InorderRec(Node* root)
{
	if (!root) return;
	InorderRec(root->left);
	cout << root->data << " ";
	InorderRec(root->right);
}
void PreorderRec(Node* root)
{
	if (root)
	{
		cout << root->data << " ";
		PreorderRec(root->left);
		PreorderRec(root->right);
	}

}
void PostorderRec(Node* root)
{
	if (root)
	{
		PostorderRec(root->left);
		PostorderRec(root->right);
		cout << root->data << " ";
	}

}
int height(Node* root)
{
	if (!root) return 0;
	return 1 + max(height(root->left), height(root->right));

}
void printBT(const std::string& prefix, const Node* node, bool isLeft=false)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "|__");

		// print the value of the node
		std::cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}
Node* InorderSuccessor(Node* root)
{
	if (!root) return root;
	if (root->right)
	{
		Node* t = root->right;
		while (t->left)
			t = t->left;
		return t;
	}
}
Node* deleteFromTree(Node*root, int item)
{
	if (!root) return NULL;
	if (root->data < item)
		root->right = deleteFromTree(root->right, item);
	else if (root->data > item)
		root->left = deleteFromTree(root->left, item);
	else
	{
		// case 1 node has no child
		//case 2 node has 1 child
		if ( !root->left || !root->right)
		{
			Node * temp = root->left ? root->left : root->right;
			free(root);
			return temp;
		}
		//case 3 node has 2 child
		// find inorder successor replace it with current node and then call delete in order successor

		else
		{
			Node* temp = InorderSuccessor(root);
			root->data =temp->data;
			root->right = deleteFromTree(root->right, temp->data);
		}
	}
	return root;
}
void DemodeleteFromBT()
{
	Node*root = NULL;
	root = insertIntoBinaryTree(root, 10);
	root = insertIntoBinaryTree(root, 5);
	root = insertIntoBinaryTree(root, 15);
	root = insertIntoBinaryTree(root, 2);
	root = insertIntoBinaryTree(root, 6);
	root = insertIntoBinaryTree(root, 13);
	root = insertIntoBinaryTree(root, 18);
	root = insertIntoBinaryTree(root, 19);
	string s;
	printBT(s, root);
	root = deleteFromTree(root, 15);
	printBT(s, root);
	InorderRec(root);
}
Node* getTree()
{
	Node*root = NULL;
	/*root = insertIntoBinaryTree(root, 10);
	root = insertIntoBinaryTree(root, 5);
	root = insertIntoBinaryTree(root, 15);
	root = insertIntoBinaryTree(root, 2);
	root = insertIntoBinaryTree(root, 6);
	root = insertIntoBinaryTree(root, 13);
	root = insertIntoBinaryTree(root, 18);
	root = insertIntoBinaryTree(root, 19);*/
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right= new Node(5);
	root->right->left= new Node(6);
	root->right->right= new Node(7);
	root->left->right->left = new Node(8);
	root->right->left->right = new Node(9);
	root->right->right->left = new Node(10);

	return root;
}

void PreOrderIterative(Node* root)
{
	stack<Node*> s;
	if (!root) return;
	while (root)
	{
		if (root->right) s.push(root->right);
		cout << root->data << " ";
		if (root->left)
			root = root->left;
		else if (!s.empty())
		{
			root = s.top(); s.pop();
		}
		else
			root = NULL;
	}


}
void InOrderIterative(Node* root)
{
	stack<Node*> s;
	if (!root) return;
	
	while (true)
	{
		if (root)
		{
			s.push(root);
			root = root->left;
		}
		else if (!s.empty())
		{
			root = s.top(); s.pop();
			cout << root->data << " ";
			if (root->right)
			{
				root = root->right;
			}
			else
				root = NULL;
		}
		else
			break;
	}
}
void PostOrderIterative(Node* root)
{
	stack<Node*>s;
	if (!root) return;
	while (true)
	{
		if (root)
		{
			if (root->right)
				s.push(root->right);
			s.push(root);
			root = root->left;
		}
		else if (!s.empty())
		{
			root = s.top(); s.pop();
			if (!s.empty() && root->right == s.top())// if right child
			{
				Node* temp = s.top(); s.pop();
				s.push(root);
				root = temp;
			}
			else
			{
				cout << root->data << " ";
				root = NULL;
			}

		}
		else
			break;
	}
}

int Hight(Node* root)
{
	if (!root) return 0;
	return root->height;
}
int BalanceFactor(Node* root)
{
	return Hight(root->left) - Hight(root->right);
}
Node* RotateRight(Node* root)
{
	Node * y = root->left;
	root->left = y->right;
	y->right = root;

	root->height = 1 + max(Hight(root->left), Hight(root->right));
	y->height = 1 + max(Hight(y->left), Hight(y->right));

	return y;

}
Node* RotateLeft(Node* root)
{
	Node * y = root->right;
	root->right = y->left;
	y->left = root;

	root->height = 1 + max(Hight(root->left), Hight(root->right));
	y->height = 1 + max(Hight(y->left), Hight(y->right));

	return y;

}
Node* BalanceTree(Node* root)
{
	if (BalanceFactor(root) > 1 && BalanceFactor(root->left) > 0) //left left case
	{
		return RotateRight(root);
	}
	else if (BalanceFactor(root) < 1 && BalanceFactor(root->right) < 0)//right right case
	{
		return RotateLeft(root);
	}
	else if (BalanceFactor(root) > 1 && BalanceFactor(root->right) < 0)//right right case
	{
		root->left = RotateLeft(root->left);
		return RotateRight(root);
	}
	else if (BalanceFactor(root) < 1 && BalanceFactor(root->right) > 0)//right right case
	{
		root->right = RotateRight(root->right);
		return RotateLeft(root);

	}
	return root;
}
Node* InsertIntoAVLTree(Node*root, int item)
{
	if (root == NULL)
		return new Node(item);
	else if (root->data > item)
	{
		root->left = InsertIntoAVLTree(root->left, item);
	}
	else
	{
		root->right = InsertIntoAVLTree(root->right, item);
	}
	root->height = max(Hight(root->left),Hight(root->right))+1;
	return BalanceTree(root);
}
Node* DeleteFromAVLTree(Node*root, int item)
{
	if (!root) return NULL;
	if (root->data < item)
		root->right = deleteFromTree(root->right, item);
	else if (root->data > item)
		root->left = deleteFromTree(root->left, item);
	else
	{
		// case 1 node has no child
		//case 2 node has 1 child
		if (!root->left || !root->right)
		{
			Node * temp = root->left ? root->left : root->right;
			free(root);
			return temp;
		}
		//case 3 node has 2 child
		// find inorder successor replace it with current node and then call delete in order successor

		else
		{
			Node* temp = InorderSuccessor(root);
			root->data = temp->data;
			root->right = deleteFromTree(root->right, temp->data);
		}
	}
	root->height = max(Hight(root->left) , Hight(root->right)) + 1;
	return BalanceTree( root);
}
void DemoAVLTree()
{
	Node*root = NULL;
	for (int i = 1; i < 15; i++)
	{
		root = InsertIntoAVLTree(root, i);
	}
	string s;
	printBT(s, root);
	root = DeleteFromAVLTree(root, 12);
	root = DeleteFromAVLTree(root, 9);
	s.clear();
	printBT(s, root);
	InOrderIterative(root);
}

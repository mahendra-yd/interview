
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct LNode
{
    int data;
    struct LNode* next;
};
 
/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};
 
struct TNode* newNode(int data);
int countLNodes(struct LNode *head);
struct TNode* sortedListToBSTRecur(struct LNode **head_ref, int n);

int countLNodes(struct LNode *head)
{
    int count = 0;
    struct LNode *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
 
void push(struct LNode** head_ref, int new_data)
{
    struct LNode* new_node =
        (struct LNode*) malloc(sizeof(struct LNode));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct LNode *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
LNode * mid(LNode *L,LNode *e)
{
  if(L==e || L->next==e) return L;
  LNode *s=L,*f=L;
  while(s!=e && f!=e &&f->next!=e)
  {
    s=s->next;
    f=f->next->next;
  }
  return s;
}
TNode * sortedListToBST(LNode *l,LNode *e)
{
  if(!l) return NULL;
  LNode *p = mid(l,e);
  if(p==e) return NULL;
  TNode *t = newNode(p->data);
  t->left = sortedListToBST(l,p);
  t->right = sortedListToBST(p->next,e);
 return t;
}
TNode * util(LNode **l, int c)
{
  if(!l || c<=0) return NULL;
  TNode *t ,*left,*right;
  left = util(l,c/2);
  t = newNode((*l)->data);
  *l=(*l)->next;
  right = util(l,c-c/2-1);
  t->left =left;
  t->right = right;
  return t;
}
	
TNode * sortedListToBST(LNode *l)
{
int c = countLNodes(l);
return util(&l,c);
}
int main()
{
    struct LNode* head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("\n Given Linked List ");
    printList(head);
    /* Convert List to BST */
    struct TNode *root = sortedListToBST(head,NULL);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
    return 0;
}

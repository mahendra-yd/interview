#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct node
{
    int val;
    struct node *left, *right;
};
 
bool isPairPresent(struct node *root, int target)
{
  stack<node *> s1,s2;
  node *r1=root,*r2=root;
  bool done1=false,done2=false;
  while(1)
  {
    while(done1==false)
    {
      if(r1!=NULL){ s1.push(r1); r1=r1->left;}
      else { if(s1.empty()) done1=true;
	else { r1=s1.top(); s1.pop(); v1=r1->data;r1=r1->right;done1=true; }
      }
    }
    while(done2==false)
    {
      if(r2!=NULL){ s2.push(r2); r2=r2->right;}
      else { if(s2.empty()) done2=true;
	else { r2=s2.top(); s2.pop(); v2=r2->data;r2=r2->left;done2=true; }
      }
    }
    if(v1!=v2 && v1+v2=target ) return true;
    else if( v1+v2<target)  done1=false;
    else done2=false;
    if(v1>v2) return false;
  }
}
 
struct node * NewNode(int val)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->right = tmp->left =NULL;
    return tmp;
}
int main()
{
    /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    struct node *root =  NewNode(15);
    root->left = NewNode(10);
    root->right = NewNode(20);
    root->left->left = NewNode(8);
    root->left->right = NewNode(12);
    root->right->left = NewNode(16);
    root->right->right = NewNode(25);
    int target = 33;
    if (isPairPresent(root, target) == false)
        printf("\n No such values are found\n");
    getchar();
    return 0;
}

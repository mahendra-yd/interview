#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trie_node {
  int value;
  trie_node * child[26];
};
struct trie
{ 
  int count;  
  trie_node *root;
};
trie_node * newNode()
{  
  trie_node * t = new trie_node;  
  t->value=0;
  for(int i=0;i<26;i++) 
    t->child[i]=NULL; 
  return t;
}
void initialize(trie *t)
{
  t->root = newNode();
  t->count=0;
}
void insert(trie * t,char *s)
{
  int index=0;
  int len = strlen(s);
  trie_node *p =t->root;
  t->count++;
  for(int i=0;i<len;i++)
  {
    index=s[i]-'a';
    if(!p->child[i])
      p->child[i]=newNode();
    p=p->child[i];
  }
  p->value=t->count;
}
int search(trie *t,char s[])
{
  int index=0;
  int len=strlen(s);
  trie_node *p = t->root;
  for(int i=0;i<len;i++)
  {
    index=s[i]-'a';
    if(!p->child[i])
      return 0;
    p=p->child[i];
  }
  return p!=NULL&&p->value!=0 ;
}
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
#define ALPHABET_SIZE 26
int isItFreeNode(trie_node_t *pNode)
{
  int i;
  for(i = 0; i < ALPHABET_SIZE; i++)
  {
    if( pNode->children[i] )
      return 0;
  }

  return 1;
}

bool deleteHelper(trie_node_t *pNode, char key[], int level, int len)
{
  if( pNode )
  {
    if( level == len )  {
      if( pNode->value )  {
	pNode->value = 0;
	if( isItFreeNode(pNode) )
	  return true;
	return false;   }  }
    else     {
      int index = INDEX(key[level]);
      if( deleteHelper(pNode->children[index], key, level+1, len) )
      {
	FREE(pNode->children[index]);
	return ( !leafNode(pNode) && isItFreeNode(pNode) );
      }
    }   }
    return false;
}

int main()
{
  char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  trie trie;
  char output[][32] = {"Not present in trie", "Present in trie"};
  initialize(&trie);
  for(int i = 0; i < ARRAY_SIZE(keys); i++)
  {
    insert(&trie, keys[i]);
  }
  printf("%s --- %s\n", "the", output[search(&trie, "the")] );
  printf("%s --- %s\n", "these", output[search(&trie, "these")] );
  printf("%s --- %s\n", "their", output[search(&trie, "their")] );
  printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
  return 0;
}

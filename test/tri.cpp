#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<string.h>
using namespace std;
struct triNode
{
  int value;
  struct triNode *next[26];
};
struct Tri
{
  int count;
  triNode * start;
};
triNode * newNode()
{
  triNode * p = new triNode;
  p->value=0;
  for(int i=0;i<26;i++)
    p->next[i]=NULL;
  return p;
}
Tri * initTri()
{
  Tri * t = new Tri;
  t->count=0;
  t->start=newNode();
  return t;
}
void insert(Tri *t, char *s)
{
  int n=strlen(s);
  t->count++;
  triNode * p=t->start;
  for(int i=0;i<n;i++,s++)
  {
    if(!p->next[*s-'a'])
    {
      p->next[*s-'a'] = newNode();
    }
    p=p->next[*s-'a'];
  }
  p->value=t->count;
}
bool search(Tri *t , char *s)
{ 
  int n=strlen(s);
  triNode * p=t->start;
  for(int i=0;i<n;i++,s++)
  {
    if(!p->next[*s-'a']) return false;
    p=p->next[*s-'a'];
  }
  return p!=NULL && p->value !=0;
}
// Driver
int main()
{
  // Input keys (use only 'a' through 'z' and lower case)
  char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  Tri* trie;
  char output[][32] = {"Not present in trie", "Present in trie"};
  trie =  initTri();
  // Construct trie
  for(int i = 0; i < 8; i++)
  {
    insert(trie, keys[i]);
  }
  // Search for different keys
  printf("%s --- %s\n", "the", output[search(trie, "the")] );
  printf("%s --- %s\n", "these", output[search(trie, "these")] );
  printf("%s --- %s\n", "their", output[search(trie, "their")] );
  printf("%s --- %s\n", "thaw", output[search(trie, "thaw")] );
  return 0;
}

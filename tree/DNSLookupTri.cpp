#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<string.h>
#include<queue>
#include<list>
#define NO_OF_CHAR 11
using namespace std;
int getIndex(char c) { return c=='.'?10:c-'0';}
char getChar(int n){ return n==10?'.':'0'+n;}
struct triNode
{
  bool isLeaf;
  struct triNode *child[NO_OF_CHAR];
  char * url;
};
triNode* newNode()
{
  triNode * p = new triNode;
  p->isLeaf=false;
  p->url=NULL;
  for(int i=0;i<NO_OF_CHAR;i++)
    p->child[i]=NULL;
  return p;
}
void insert(triNode *t,char *ip,char *url)
{
int l=strlen(ip);
for(int i=0;i<l;i++)
{
if(!t->child[getIndex(ip[i])])
t->child[getIndex(ip[i])] =newNode();
t=t->child[getIndex(ip[i])];
}
t->isLeaf=true;
l =strlen(url);
t->url=new char [l+1];
memcpy(t->url,url,l+1);
}
char * searchDNSCache(triNode *t, char *ip)
{
int l = strlen(ip);
for(int i=0;i<l;i++)
{
if(!t->child[getIndex(ip[i])])
return NULL;;
t=t->child[getIndex(ip[i])];
}
if(t!=NULL && t->isLeaf)
return t->url;
return NULL;
}
#define MAX 17
int main(int argc, char **argv)
{
  /* Change third ipAddress for validation */
  char ipAdd[][MAX] = {"107.108.11.123", "107.109.123.255",
    "74.125.200.106"};
  char URL[][50] = {"www.samsung.com", "www.samsung.net",
    "www.google.in"};
  int n = sizeof(ipAdd)/sizeof(ipAdd[0]);
  struct triNode *root = newNode();

  // Inserts all the ip address and their corresponding
  // domain name after ip address validation.
  for (int i=0; i<n; i++)
    insert(root,ipAdd[i],URL[i]);

  // If reverse DNS look up succeeds print the domain
  // name along with DNS resolved.
  char ip[] = "107.108.11.123";
  char *res_url = searchDNSCache(root, ip);
  if (res_url != NULL)
    printf("Reverse DNS look up resolved in cache:\n%s --> %s",
	ip, res_url);
  else
    printf("Reverse DNS look up not resolved in cache ");
  return 0;

  return 0;
}

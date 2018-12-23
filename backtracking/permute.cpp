#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<string.h>
using namespace std;
/* Driver program to test above functions */
void swap(char *p,char *q) { char r=*p; *p=*q;*q=r;}
void permute( char *s,int l,int r)
{
  if(l==r)
    printf(" %s\n",s);
  for(int i=l;i<=r;i++)
  {
    swap(&s[l],&s[i]);
    permute(s,l+1,r);
    swap(&s[l],&s[i]);
  }

}
int main()
{
  char str[] = "ABC";
  int n = strlen(str);
  permute(str, 0, n-1);
  return 0;
}

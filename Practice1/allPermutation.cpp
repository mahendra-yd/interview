#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
void swap(char *a,char *b) {char t=*a;*a=*b;*b=t;}
int count;
void permute( char *s, int l , int h)
{
count++;
  if(l==h) printf("%s\n",s);
else {
  for( int i=l;i<=h;i++)
  {
    swap(&s[l],&s[i]);
    permute(s,l+1,h);
    swap(&s[l],&s[i]);
  }
}
}
int main(int argc, char **argv)
{

  char str[] = "ABC";
  int n = strlen(str);
  permute(str, 0, n-1);
cout<<count;
  return 0;
}

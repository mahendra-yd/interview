#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
void swap(char *a, char*b) { char t=*a;*a=*b;*b=t;}
int findRight(char *s, int n) // find rightmost cahr which is smaller than its right side char
{
  n--;
  while(n>0 && s[n-1]<s[n]) n--;
  if(n>0) return n-1;
  return -1;
}
int findCeil1(char *s, char a,int i, int n)
{
  int min=i+1;
int j=min;
while(j<n&& s[j]<a && s[j]<s[min]) min=j; 
  return j;
}
int findCeil (char str[], char first, int l, int h)
{
    int ceilIndex = l;
 
    for (int i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}
int comp(char a, char b) { return a<b;}
void sortedPermutations(char *s)
{
  int n= strlen(s);
  sort(s,s+n,comp);
  while(1==1)
  {
    cout<<s;
//    int i = findRight(s,n);
    int i;
        for ( i = n - 2; i >= 0; --i )
           if (s[i] < s[i+1])
              break;

    if(i==-1) break;
    int j= findCeil(s,s[i],i+1,n-1);
    swap(&s[i],&s[j]);
    sort(s+i,s+n-i,comp);

  }
}
int main(int argc, char **argv)
{
 char str[] = "ABCD";
    sortedPermutations( str );

return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
bool isPalindrome(char *s, int l, int h){ while(l<=h) if( s[l++]!=s[h--]) return false; return true;}
int minPalPartion(char *s, int l, int h)
{
  if(h-l<=1) return 0;
  if(isPalindrome(s,l,h)) return 0;
  int min=INT_MAX;
  int r;
  for( int i=l;i<h;i++)
  {
    r= minPalPartion(s,l,i)+ minPalPartion(s,i+1,h)+1;
    if(min>r) min=r;
  }
  return min;
}
int main(int argc, char **argv)
{

 char str[] = "ababbbabbababa";
   printf("Min cuts needed for Palindrome Partitioning is %d", minPalPartion(str,0,strlen(str)-1));

return 0;
}

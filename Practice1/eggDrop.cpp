#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int max(int a, int b){ return a>b?a:b;}
int eggDrop(int e, int f)
{
  if( f==0 || f==1) return f;
  if(e==1) return f;
  int res,min=INT_MAX;
  for( int i=1;i<=f;i++)
  {
    res=max(eggDrop(e-1,f-1),eggDrop(e,f-i));
    if(min>res) min=res;
  }
  return min+1;
}
int main(int argc, char **argv)
{
  int n = 2, k = 10;
  printf ("\nMinimum number of trials in worst case with %d eggs and %d floors is %d \n", n, k, eggDrop(n, k));

  return 0;
}

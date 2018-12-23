#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int max( int a, int b) { return a>b?a:b;}
int knapSack(int W,int wt[],int val[], int n)
{
  if(W==0 || n==0) return 0;
  if(W<wt[n-1]) return knapSack(W, wt, val, n-1);
  else 
    return max( knapSack(W, wt, val, n-1) , knapSack(W-wt[n-1], wt, val, n-1) + val[n-1]);
}
int knapSackDP(int W,int wt[],int val[], int n)
{
  int M[W+1][n+1];
  for( int i=0;i<=W;i++)
    for( int j=0;j<=n;j++)
    {
      if(i==0 || j==0) M[i][j]=0;
      else if(i < wt[j]) M[i][j]=M[i][j-1];
      else
	M[i][j] = max(M[i][j-1], val[j]+ M[i-wt[j]][j-1]);
    }
  return M[W][n];
}
int main(int argc, char **argv)

{
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int  W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  printf("%d", knapSack(W, wt, val, n));
  printf("%d", knapSackDP(W, wt, val, n));

  return 0;
}

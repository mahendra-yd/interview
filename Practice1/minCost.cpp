#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int Min(int a, int b, int c) { return a<b?a<c?a:c:b<c?b:c;}
#define R 3
#define C 3
int minCost(int c[R][C], int m, int n)
{
  if(m<0||n<0) return 99999;
  else if(m==0&&n==0) return c[0][0];
  else
    return Min(minCost(c,m-1,n), minCost(c,m,n-1),minCost(c,m-1,n-1)) + c[m][n];
}

int minCostDP(int c[R][C], int m, int n)
{
  int cm[R][C];
  cm[0][0]=c[0][0];
  for(int i=1;i<=n;i++) cm[0][i]=cm[0][i-1]+c[0][i];
  for(int i=1;i<=m;i++) cm[i][0]=cm[i-1][0]+c[i][0];
  for(int i=1;i<=m;i++)
    for( int j=1;j<=n;j++)
      cm[i][j]=Min(cm[i-1][j],cm[i][j-1],cm[i-1][j-1])+c[i][j];
  return cm[m][n];
}
int main(int argc, char **argv)
{
  int cost[R][C] = { 
    {1, 2, 3},
    {4, 8, 2},
    {1, 5, 3} };
  printf(" %d ", minCost(cost, 2, 2));
  printf(" %d ", minCostDP(cost, 2, 2));

  return 0;
}

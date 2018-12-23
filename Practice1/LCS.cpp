#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
int max( int a, int b) {return a>b?a:b;}

int lcs(char *x,char *y, int m, int n)
{
  if(m==0|| n==0) return 0;
  if(x[m-1]==y[n-1] ) return 1+ lcs(x,y,m-1,n-1);
  else return max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
}
int lcsDP(char *x, char*y,int m, int n)
{
  if(m==0|| n==0) return 0;
  int l[m+1][n+1];
  for( int i=0;i<=m;i++){
    for( int j=0;j<=n;j++)
    {
      if(i==0|| j==0) l[i][j]=0;
      else if(x[i-1]==y[j-1]) l[i][j]=l[i-1][j-1]+1;
      else l[i][j]=max(l[i][j-1] ,l[i-1][j]);
    }
  }
  return l[m][n];
}

int main(int argc, char **argv)
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
  printf("Length of LCS is %d\n", lcsDP( X, Y, m, n ) );
  return 0;
}

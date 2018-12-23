#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int MIN(int a, int b){ return a<b?a:b;}
int binomialCoeff( int n, int k)
{
if(k==0|| n==k) return 1;
return binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k);
}

int binomialCoeffDP( int n, int k)
{
  int M[n+1][k+1];
  for( int i=0;i<=n;i++)
    for( int j=0;j<=MIN(i,k);j++)
    {
      if(j==0|| i==j) M[i][j]=1;
      else
	M[i][j]=M[i-1][j-1]+M[i-1][j];
    }
  return M[n][k];
}
int main(int argc, char **argv)
{

int n = 5, k = 2;
    printf("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k));
    printf("Value of C(%d, %d) is %d ", n, k, binomialCoeffDP(n, k));
return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int MatrixChainOrder(int a[], int l, int h)
{
  if(l==h) return 0;
  int min =INT_MAX,r;
  for( int i=l;i<h;i++)
  {
    r=MatrixChainOrder(a,l,i) + 
      MatrixChainOrder(a,i+1,h) +
      a[i] * a[l-1] * a[h] ;
    if(r<min) min =r;
  }
return min;
}
int MCMDP(int a[],int n)
{
  int M[n][n];
  for( int i=1;i<=n;i++) M[i][i]=0; // single matrix cost will be zero

  for(int l=2;l<n;l++) //from length 2 to n-1
  {
    for( int i=1;i<=n-l+1;i++)
    {
      int j=i+l-1;
      M[i][j]=INT_MAX;
      for( int k =i;k<j;k++)
      {
	int r = M[i][k] + M[k+1][j] + a[i-1]*a[k]*a[j];
	if(r<M[i][j]) M[i][j] =r;
      }
    }	
  }
return M[1][n-1];
}
int main(int argc, char **argv)
{
  int arr[] = {1, 2, 3, 4, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, 1, n-1));
  printf("Minimum number of multiplications is %d ", MCMDP(arr,n));
  return 0;
}


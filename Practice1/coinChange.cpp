#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int count(int a[],int n, int sum)
{
  if( sum ==0) return 1;
  if(sum<0) return 0;
  if(n<=0&&sum>0) return 0;
  return count(a,n-1,sum)+count( a,n,sum-a[n-1]);
}
int countDP(int a[],int n, int sum)
{
  int l[sum+1][n];
  for( int i=-0;i<n;i++) //if sum ==0 set that row as 1;
  l[0][i]=1;
  int x,y;
  for( int i=1;i<=sum;i++)
  {
    for( int j=0;j<n;j++)
    {
      // if(a[j] is included
      x = (i-a[j])>=0 ? l[i-a[j]][j] : 0;
      // do not include 
      y = j>=1? l[i][j-1] :0;
      l[i][j]=x+y;

    }
  }
return l[sum][n-1];
}
int main(int argc, char **argv)
{
  int i, j;
  int arr[] = {1, 2, 3};
  int m = sizeof(arr)/sizeof(arr[0]);
  printf("%d ", count(arr, m, 4));
  printf("%d ", countDP(arr, m, 4));
  return 0;

  return 0;
}

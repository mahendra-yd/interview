#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

bool util( int a[],int n , int s)
{
  if(s==0) return true;
  if(n==0&&s!=0) return false;
  if(a[n-1]>s) return util(a,n-1,s);
  else return  util(a,n-1,s) || util(a,n-1,s-a[n-1]);
}
bool utilDP(int a[],int n , int s)
{
  int p[s+1][n+1];
  for(int i=0;i<=n;i++) p[0][i]=true;
  for( int i=1;i<=s;i++) p[i][0]=false;
  for( int i=1;i<=s;i++)
  {
    for( int j=1;j<=n;j++)
      if(i<a[j]) p[i][j] = p[i][j-1];
      else p[i][j]= p[i][j-1] ||p[i-a[j]][j-1];
  }
  return p[s][n];
}
bool findPartiion(int a[], int n)
{
  int sum=0;
  for( int i=0;i<n;i++) sum+=a[i];
  if(sum%2) return false;
  return utilDP(a,n,sum/2);
}
int main(int argc, char **argv)
{
  int arr[] = {4, 2, 5, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n) == true)
    printf("Can be divided into two subsets of equal sum");
  else
    printf("Can not be divided into two subsets of equal sum");

  return 0;
}

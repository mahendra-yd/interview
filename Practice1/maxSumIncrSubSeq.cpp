#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
int lisDP(int a[], int n)
{
  if(n==1) return 1; 
  int *l = new int [n+1];
  for( int i=0;i<n;i++) l[i]=a[i];

  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
      if(a[j]<a[i] && l[i]<l[j]+a[i])
	l[i]=l[j]+a[i];
  int m=1;
  for( int i=0;i<n;i++)
    if(m<l[i]) m=l[i];
  return m;
}
int main(int argc, char **argv)
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
 //int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n",  lisDP( arr, n ));
return 0;
}

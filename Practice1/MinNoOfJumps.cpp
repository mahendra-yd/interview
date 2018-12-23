#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
// minimum no of jumps top reach at end of arrya 
int  minJumps(int a[], int l, int h)
{
  if(l==h) return 0;
  if(a[l]==0) return INT_MAX;
  int r=0;
  int min=INT_MAX;
  for( int i=l+1;i<=h && i<=l+a[l];i++)
  {
    r= minJumps(a,i,h);
    if(r!=INT_MAX && min>r+1 ) 
      min =r+1; 
  }
  return min;
}

int main(int argc, char **argv)
{
  int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d ", minJumps(arr, 0, n-1));
  return 0;
}

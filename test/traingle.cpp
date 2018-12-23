#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<stdlib.h>
using namespace std;

int findNumberOfTriangles(int a[],int n)
{
  int c=0;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      for(int k=j+1;k<n;k++)
	if(a[i]+a[j]>a[k])c++;
  return c;
}

int comp(const void *a, const void *b)
{
  return *(int*)a > *(int*)b;
}
int findNumberOfTrianglesDP(int a[],int n)
{
  int c=0;
int m=0;
  qsort(a,n,4,comp);
  for(int i=0;i<n-2;i++)
  {
    int k=i+2;
    for(int j=i+1;j<n;j++)
    {
      while(k<n && a[i]+a[j]>a[k]) { k++; m++;}
      c+=(k-j-1);
    }
  }
cout<<m<<" "<<c <<"done";
  return c;
}
int main()
{
  int arr[] =   {10, 21, 22, 100, 101, 200, 300};
  int size = sizeof( arr ) / sizeof( arr[0] );

  printf("Total number of triangles possible is %d ",
      findNumberOfTrianglesDP( arr, size ) );

  return 0;
}

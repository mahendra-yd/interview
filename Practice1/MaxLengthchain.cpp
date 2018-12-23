#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct Pair
{
  int a;
  int b;
};
int comp(const Pair a ,const Pair b)
{
  return a.a < b.a;
}
// SAME AS lis
int maxChainLength(Pair a[], int n)
{
  sort(a,a+n-1,comp);
  if(n==1) return 1;
  int *l = new int [n+1];
  for( int i=0;i<n;i++) l[i]=1;
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
      if(a[j].b<a[i].a && l[i]<l[j]+1)
	l[i]=l[j]+1;
  int m=1;
  for( int i=0;i<n;i++)
    if(m<l[i]) m=l[i];
  return m;
}

int main(int argc, char **argv)
{
  struct Pair arr[] = { {5, 24}, {15, 25},
    {27, 40}, {50, 60} };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of maximum size chain is %d\n",
      maxChainLength( arr, n ));

  return 0;
}

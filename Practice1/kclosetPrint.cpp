#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int findLoc(int a[],int l, int h, int x)
{
  if(l<h)
  {
    if(a[l]> x) return l;
    if(a[h]< x) return h;
    int m=(l+h)/2;
    if(a[m]<=x && a[m+1] > x)
      return m;
    else if(a[m]<x)
      return findLoc(a,m+1,h,x);
    else
      return findLoc(a,l,m-1,x);
  }
}
void printKclosest(int a[],int x, int c,int n)
{
  int l=findLoc(a,0,n-1,x);
  int h=l+1;
  if(a[l]==x) l--;
  int k=0;
  while(l>=0 && h < n && k<c)
  {
    if(x - a[l]> a[h]-x )
      cout<<a[h++]<<" ";
    else
      cout<<a[l--]<<" ";
    k++;
  }

  while(h<n && k<c) {cout<<a[h++]<<" ";k++;}
  while(l>=0 && k<c) {cout<<a[l--]<<" ";k++;}
}
int main(int argc, char **argv)
{
   int arr[] ={12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 35, k = 4;
   printKclosest(arr, x, 4, n);

return 0;
}

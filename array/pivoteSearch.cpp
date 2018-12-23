#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
int findPivote(int a[], int n)
{
  int l=0; int h=n-1;
  if(a[l]<a[h]) return -1;
  while(l<=h)
  {
    int m=(l+h)/2;
    if(m<h&&a[m]>a[m+1]) return m+1;
    if(m>l&& a[m]<a[m-1]) return m;
    if(a[l]<a[m])
      l=m+1;
    else
	h=m-1;
  }
  return -1;
}
int binarySearch(int a[],int l,int h,int s)
{
  while(l<=h)
  {
    int m=l+(h-l)/2;
    if(a[m]==s) return s;
    else if(a[m]<s) l=m+1;
    else h=m-1;
  }
  return -1;
}
int pivotedBinarySearch(int a[],int n,int s)
{
  int p =findPivote(a,n);
  if(p==-1) return binarySearch(a,0,n-1,s);
  if(a[p]==s) return p;
  if(a[0]>s)
    return binarySearch(a,p+1,n-1,s);
  else return binarySearch(a,0,p-1,s);
}
int main()
{
  // Let us search 3 in below array
  int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
  int arr_size = sizeof(arr1)/sizeof(arr1[0]);
  int no = 3;
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr1, arr_size, no));

  // Let us search 3 in below array
  int arr2[] = {3, 4, 5, 1, 2};
  arr_size = sizeof(arr2)/sizeof(arr2[0]);
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));

  // Let us search for 4 in above array
  no = 4;
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));

  // Let us search 0 in below array
  int arr3[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
  no = 0;
  arr_size = sizeof(arr3)/sizeof(arr3[0]);
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr3, arr_size, no));

  // Let us search 3 in below array
  int arr4[] = {2, 3, 0, 2, 2, 2, 2, 2, 2, 2};
  no = 3;
  arr_size = sizeof(arr4)/sizeof(arr4[0]);
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));

  // Let us search 2 in above array
  no = 2;
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));

  // Let us search 3 in below array
  int arr5[] = {1, 2, 3, 4};
  no = 3;
  arr_size = sizeof(arr5)/sizeof(arr5[0]);
  printf("Index of the element is %d\n",  pivotedBinarySearch(arr5, arr_size, no));

  return 0;
}

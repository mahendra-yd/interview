#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
/* Driver program to check above functions */
int findPivot(int a[],int size)
{
  int l=0,h=size-1;
  int m=0;
  if(a[l]<a[h])
    return -1;
  while(l<=h)
  {
    m=(l+h)/2;
    if(m<h&&a[m]>a[m+1])
      return m;
    if(m>l&&a[m]<a[m-1])
      return m-1;
    if(a[h]<a[m])
      l=m+1;
    else
      h=m-1;
  }
  return -1;
}
int BinarySearch(int a[],int l,int h,int no)
{
  int m=0;
  while(l<=h)
  {
    m=(l+h)/2;
    if(a[m]==no)
      return m;
    else if(a[m]<no)
      l=m+1;
    else
      h=m-1;
  }
  return -1;
}
int pivotedBinarySearch(int arr[], int size, int no)
{
  int pivot = findPivot(arr,size);
  if(pivot ==-1) 
    return BinarySearch(arr,0,size-1,no);
  if(arr[pivot]==no)
    return pivot;
  if(arr[0]<=no)
    return BinarySearch(arr,0,pivot-1,no);
  else
    return BinarySearch(arr,pivot+1,size-1,no);
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

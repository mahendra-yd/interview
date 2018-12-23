#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
void swap(int *a, int *b)
{
  int t= *a;
  *a=*b;
  *b=t;
}
void heapify(int a[], int i, int n)
{
  int l=2*i+1;
  int r = l+1;
  
  while(r<=n) 
  {
    if(a[l]>a[r]) r=l;
    if(a[i] < a[r])
    { 
      swap(&a[i],&a[r]);
      i=r;
      l=2*i+1;
      r=l+1;
    }
    else  break;
  }
  if(r>n && a[i]>a[l])
   swap(&a[i],&a[l]);
}

void heapSort(int a[], int n)
{
n--;
  for(int i=(n-2)/2;i>=0;i--)
    heapify(a,i,n);
  for(int i=0;i<=n;i++)
  {
    swap(&a[0],&a[n-i]);
    heapify(a,0,n-i-1);
  }
}
// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
  int i;
  for (i = 0; i < size; ++i)
    printf("%d ", arr[i]);
}
/* Driver program to test above functions */
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Given array is \n");
  printArray(arr, size);

  heapSort(arr, size);

  printf("\nSorted array is \n");
  printArray(arr, size);
  return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;

void heapify(int *a,int i,int n)
{
  int l,r;
  l=2*i+1;
  r=l+1;
  while(r<=n)
  {
    if(a[l]<a[r]) r=l;
    if(a[i]>a[r]) { int t=a[i];a[i]=a[r];a[r]=t;}
    i=r;
  l=2*i+1;
  r=l+1;
 
  }
}
void buildHeap(int *arr,int n)
{
  int l,r;
  for(int i=n/2-1;i>=0;i--)
    heapify(arr,i,n);
}
void kthLargest(int k)
{
  int count = 0, x;  // x is for new element
  int *arr = new int[k];
  while (1)
  {
    cout << "Enter next element of stream ";
    cin >> x;
    if (count < k-1){ arr[count] = x;count++;}
    else
    {
      if (count == k-1)
      {
	arr[count] = x;
	buildHeap(arr,k);
       count++;
      }
      else
      {
	if (x > arr[0])
	{
	  arr[0]=x;
	heapify(arr,0,k);
        }
      }
    }
    cout << "K'th largest element is " << arr[0] << endl;
  }
  cout << "K'th largest element is " << arr[0] << endl;
}
int main()
{
    int k = 3;
    cout << "K is " << k << endl;
    kthLargest(k);
    return 0;
}

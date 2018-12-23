#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
void swap(int *a,int *b) { int t=*a;*a=*b;*b=t;}
void sortInWave1(int a[], int n)
{
  sort(&a[0],&a[n]);
  for(int i=0;i<n-1;i+=2)
  {
    swap(&a[i],&a[i+1]);
  }
}

void sortInWave(int a[], int n)
{
  for( int i=0;i<n-1;i+=2)
  {
    if(i>0&& a[i]<a[i-1]) swap(&a[i],&a[i-1]);
    if(i<n-1&& a[i+1]>a[i]) swap(&a[i+1],&a[i]);
  }
}
int main(int argc, char **argv)
{
    int arr[] = {90, 10, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    cout << "Sorted array \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";

return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<list>
using namespace std;
int c=0;
void swap(int*a,int *b)
{
int t=*a;*a=*b;*b=t;
c++;
}
void selectionSort(int a[],int n)
{
  c=0;
  for(int i=0;i<n;i++)
  {
    int min=i;
    for(int j=i+1;j<n;j++)
      if(a[j]<a[min]) min=j;
    if(i==min) break;
    swap(&a[i],&a[min]);
  }
  cout<<"Total no of swap"<<c;
}
void insertionSort(int a[],int n)
{
  for(int i=1;i<n;i++)
  {
    int t=a[i];
    int j=i-1;
    while(j >= 0 && a[j] > t) a[j+1]=a[j--];
    a[j+1]=t;
  }
}
/* Function to print an array */
template<typename T>
void printArray(T arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<< arr[i]<<" ";
    printf("\n");
}
int partitation(int a[], int l, int h)
{
  int m=(l+h)/2;
  while(l<h)
  {
    while(l<h && a[l]<a[m])l++;
    while(l<h && a[h]>a[m])h--;
    if(l<h) { swap(&a[l],&a[h]); l++;h--;}
  }
  return m;
}
void quickSort(int a[],int l, int h)
{
  if(l<h){
    int p = partitation(a,l,h);
    quickSort(a,l,p-1);
    quickSort(a,p+1,h);
  }
}
void bucketSort(float a[], int n)
{
  vector<float> v[n];
  for(int i=0;i<n;i++)
  {
    int l = n*a[i];
    v[l].push_back(a[i]);
  }
  for(int i=0;i<n;i++)
    sort(v[i].begin(),v[i].end()); // sort using insertion sort avg o(n)
  int k=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0; j<v[i].size();j++)
    {
      a[k]=v[i][j];k++;
    }
  }
}
int main(int argc, char **argv)
{
    int arr[] = {64, 25, 12, 22, 11};
    float arr1[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    selectionSort(arr, n);
//      insertionSort(arr,n);
     // quickSort(arr,0,n);
    bucketSort(arr1,n1);
     
    printf("Sorted array: \n");
    printArray(arr1, n);

return 0;
}

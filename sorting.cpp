#include <stdio.h>
void swap(int *xp, int *yp)
{
  static int count=0;
  printf("count = %d ",count++);
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void selectionSort1(int arr[], int n)// this gaurantee that max swap is n
{
  int i, j, min_idx;
  for (i = 0; i < n-1; i++)
  {
    min_idx = i;
    for (j = i+1; j < n; j++)
      if (arr[j] < arr[min_idx])
	min_idx = j;
    swap(&arr[min_idx], &arr[i]);
  }
}
void selectionSort(int arr[], int n) // this does not gaurantee max sum n
{
  int i, j, min_idx;
  for (i = 0; i < n-1; i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
	swap(&arr[i],&arr[j]);
    }
  }
}
void bubbleSort(int arr[], int n)
{
  int i, j, min_idx;
  bool b=false;
  for (i = 0; i < n-1; i++)
  {
    b=false;
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1]){ b=true;
	swap(&arr[j],&arr[j+1]);}
    }
    if(b==false) break;
  }
}
void insertionSort(int arr[], int n)
{
  int i,j,t;
  for(i=1;i<n;i++)
  {
    t=i-1;
    j=arr[i];
    while(t>=0&& arr[t]>j)
    {
      arr[t+1]=arr[t];
      t=t-1;
    }
    arr[t+1]=j;
  }
}

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;
 
    int mid = (low + high)/2;
 
    if(item == a[mid])
        return mid+1;
 
    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
void insertionSort1(int a[], int n)
{
    int i, loc, j, k, selected;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}
void mergeArray(int a[],int l, int m,int h)
{
  int i=l,j=m+1;
  int k=l;
  int tmp[100]={0};
  while(i<=m&&j<=h)
  { 
    if(a[i]<=a[j])
      tmp[k++]=a[i++];
    else
      tmp[k++]=a[j++];
  }
  while(i<=m)
    tmp[k++]=a[i++];
  while(j<=h)
    tmp[k++]=a[j++];
  for(i=l;i<=h;i++)
    a[i]=tmp[i];
} 
void mergeSort(int arr[], int l,int h)
{
  if(l<h)
  {
    //int mid=(l+(h-l)/2);
    int mid=(l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    mergeArray(arr,l,mid,h);
  }
}

void heapify(int a[],int i,int n)
{
  int l=2*i+1;
  int r=l+1;
  int t;
  while(r<=n)
  { 
    t =a[i];
    if(a[r]<a[l]) r=l; // get max child in r
    if(a[r]>t)
    {
      a[i]=a[r];
      a[r]=t;
      i=r;
      l=2*i+1; r = l+1;
    }
    else
      break;
  }
}
void heapSort(int a[],int n)
{
  for(int i=(n-1)/2;i>=0;i--)
    heapify(a,i,n);
  for(int i=0;i<=n;i++)
  {
    swap(&a[0],&a[n-i]);
    heapify(a,0,n-i-1); 
  }
}
int pivote(int a[],int l,int h)
{
  int m=(l+h)/2;
  int t=a[m];
  int i=l,j=h;
  while(l<h)
  {
    while(a[l]<t) l++;
    while(a[h]>t) h--;
    if(l<h) swap(&a[l],&a[h]);
    l++;h--;
  }
  return m; 
}
void quickSort(int a[],int l,int h)
{
  if(l<h)
  {
    int p= pivote(a,l,h);
    quickSort(a,l,p);
    quickSort(a,p+1,h);
  }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// sort 0 1 2  dutch national flag sorting 
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    while (mid <= hi)
    {
        switch (a[mid])
        {
        case 0:
            swap(&a[lo++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}
// Driver program to test above functions
int main()
{
//  int arr[] = {64, 22, 12, 25, 11};
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
//  quickSort(arr,0,n-1);
  heapSort(arr,n-1);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}

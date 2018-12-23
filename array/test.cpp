#include <stdio.h>
void swap(int *a, int *b);
 void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%4d ", arr[i]);
 printf("\n");
}
void rearrange(int arr[], int n)
{
int i=0,j=n-1;
while(i<j)
{
while(i<j && arr[i]<0)i++;
while(i<j && arr[j]>0)j--;
swap(&arr[i],&arr[j]);
i++;j--;
}
     printArray(arr, n);
j=j+2; //first +ve no.
i=1;
while(i<n&& arr[i]<0)
{
swap(&arr[i],&arr[j]);
i+=2;
j+=2;
}
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}

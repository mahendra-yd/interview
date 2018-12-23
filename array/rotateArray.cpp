#include<stdio.h>
/* function to print an array */
void printArray(int arr[], int size){for(int i = 0; i < size; i++)	printf("%d ", arr[i]);}

int gcd(int a, int b)
{
if(b==0) return a;
return gcd(b,a%b);
}
void leftRotate(int a[],int d, int n)
{
  int g = gcd(n,d);
  for(int i=0;i<g;i++)
  {
    int tmp =a[i];
    int j=i;
    int k;
    while(1)
    {
      k =j + d;
      if(k>=n) k = k-n;
      if(k==i)  break;
      a[j]=a[k];
      j=k;
    }
    a[j]=tmp;
  }

}
int main()
{
int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
leftRotate(arr, 2, 8);
printArray(arr, t);
getchar();
return 0;
}


#include<iostream> 
 #include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) {return a>b?a:b;}
int cutRod(int a[],int n)
{
  if(n<=0) return 0;
  int m=INT_MIN;
  for(int i=0;i<n;i++)
  {
    m= max(m,a[i]+cutRod(a,n-i-1));
  }
  return m;
}
int cutRodDP(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
 
   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }
 
   return val[n];
}
int main(int argc, char **argv)
{
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
  printf("Maximum Obtainable Value is %d\n", cutRodDP(arr, size));
  return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int util(int a[], int n, int& m)
{
if(n==1) return 1;
int res , max=1;
for(int i=1; i<n;i++)
{
res= util(a,i,m);
if(max<res+1 && a[i-1]<a[n-1])
max =res+1;
}
if(m<max) m=max;
return max;
}
int lis(int a[], int n)
{
int m=0;
util(a,n,m);
return m;

}
int lisDP(int a[], int n)
{
if(n==1) return 1; 
int *l = new int [n+1];
for( int i=0;i<n;i++) l[i]=1;
for(int i=1;i<n;i++)
for(int j=0;j<i;j++)
if(a[j]<a[i] && l[i]<l[j]+1)
l[i]=l[j]+1;
int m=1;
for( int i=0;i<n;i++)
if(m<l[i]) m=l[i];
return m;
}
int main(int argc, char **argv)
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n",  lis( arr, n ));
    printf("Length of LIS is %d\n",  lisDP( arr, n ));
return 0;
}

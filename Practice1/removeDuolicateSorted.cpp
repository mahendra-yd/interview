#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
int removeDup(int a[], int n)
{
int i=0, j=0;
while(j<n)
{
while(j<n-1&& a[j]!=a[j+1])  a[i++]=a[j++];
a[i]=a[j];
while(j<n-1&& a[j]==a[j+1]) j++;
j++;
i++;
a[i]=a[j];
}
return i;
}

int main(int argc, char **argv)
{
//int a[]= { 1,2,3,4,4,4,4,5,5,5,5,6,7,8,9,9,9,9};
//int a[]= { 1,2,3,4,4,4,4,5,5,5,5,6,7,8,9,};
int a[]= { 1,1,1,1,1,1,1,1,1,};
int k =removeDup(a,sizeof(a)/sizeof(a[0]));
for( int i=0;i<k;i++)
cout<<a[i]<<" ";
cout<<endl;
return 0;
}

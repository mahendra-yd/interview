#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
void print(int b[],int r) { for(int i=0;i<r;i++)cout<<b[i];cout<<endl;}
void util(int a[],int n,int r,int b[], int i, int j)
{
  if(i==r){ print(b,r);return ;}
  if(j>=n) return;
  b[i]=a[j]; 
  util(a,n,r,b,i+1,j+1); // include jth element in sol
  util(a,n,r,b,i,j+1); //do not include jth element in solution undo 
}
void printCombination(int a[],int n,int r)
{
int b[r];
 util(a,n,r,b,0,0);

}
int main(int argc, char **argv)
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);

return 0;
}

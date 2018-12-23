#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

int compinc(int a, int b){ return a<b;}
int compdec(int a, int b){ return a>b;}
int findMaxMultupleOf3(int a[], int n)
{
  sort(a,a+n,compinc);
  cout<<a[0]<<a[1]<<endl;
  queue<int> q0,q1,q2;
  int sum=0;
  for( int i=0;i<n;i++)
  {
    sum+=a[i];
    if(a[i]%3==0) 
      q0.push(a[i]);
    else if(a[i]%3==1) 
      q1.push(a[i]);
    else if (a[i]%3==2) 
      q2.push(a[i]);
  }
  if(sum%3==1)
  {
    if(!q1.empty()) q1.pop();
    else{  q2.pop();  q2.pop();}
  }
  else if(sum%3==2)
  {
    if(!q2.empty()) q2.pop();
    else{  q1.pop();  q1.pop();}
  }
  else { sort(a,a+n,compdec); for(int i=0;i<n;i++) cout<<a[i];cout<<endl; return 1;}
  int aux[n];
  int i=0;
  while(!q0.empty())
  {
    aux[i++]=q0.front();q0.pop();
  }
  while(!q1.empty())
  {
    aux[i++]=q1.front();q1.pop();
  }
  while(!q2.empty())
  {
    aux[i++]=q2.front();q2.pop();
  }

  sort(aux,aux+i,compdec);
  for(int j=0;j<i;j++) cout<<aux[j];cout<<endl; return 1;
}
int main(int argc, char **argv)
{
  int arr[] = {8, 1, 7, 5, 0};
  int size = sizeof(arr)/sizeof(arr[0]);

  if (findMaxMultupleOf3( arr, size ) == 0)
    printf( "Not Possible" );

      return 0;
}

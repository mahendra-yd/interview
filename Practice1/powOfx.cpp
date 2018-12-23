#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

float pow( int x, int n)
{
  float res=1;
  int t=n;
  if(n==0) return res;
  if(n<0)t=-n; 
  for( int i=0;i<t;i++)
  {
   if(n>0) res=res*x;
    else res= res/x;
   }
    return res;
}

float pow1(int x, int n)
{
  if(n==0) return 1;
  else if(n%2==0)
    return pow1(x,n/2)*pow1(x,n/2);
  else
  return   x*pow1(x,n/2)*pow1(x,n/2);
}
float pow2(int x, int n)
{
  if(n==0) return 1;
  float res= pow2(x,n/2);
  if(n%2==0)
    return res*res;
  else { 
    if(n>0)   return   x*res*res;
    else return (res*res)/x;
  }
}

int main(int argc, char **argv)
{

float i = pow2(2,-3);
cout<<i;
return 0;
}

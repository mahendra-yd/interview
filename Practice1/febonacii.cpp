#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int febonacci(int n)
{
  if(n==0|| n==1) return n;
  else return febonacci(n-1) + febonacci(n-2);
}
int l[1000]={0,};

int febo(int n)
{
  if(l[n]==0)
  {
    if(n<=1) l[n]=n;
    else
      l[n] = febo(n-1)+febo(n-2);
  }
  return l[n];
}
int feb(int n)
{
  int x=0,y=1;
  if(n<=1) return n;
  for( int i=2;i<=n;i++)
  {
    y=x+y;
    x=y-x;
  }
  return y;
}
int fe(int n)
{
  int l[10000]={0,};
  l[0]=0;l[1]=1;
  for( int i=2;i<=n;i++)
    l[i]=l[i-1]+l[i-2];
  return l[n];
}

void multiply(int M[2][2],int F[2][2])
{
int a,b,c,d;
a = F[0][0]*M[0][0] + F[0][1]*M[1][0];
b = F[0][0]*M[0][1] + F[0][1]*M[1][1];
c = F[1][0]*M[0][0] + F[1][1]*M[1][0];
c = F[1][0]*M[0][1] + F[1][1]*M[1][1];
M[0][0]=a;
M[0][1]=b;
M[1][0]=c;
M[1][1]=d;
}
int power(int M[2][2], int n)
{
int F[2][2]={ {1,1},{1,0}}; 
for( int i=0;i<=n;i++)
multiply(M,F);
}
int FibonacciM( int n)
{
if(n<=1) return n;
int M[2][2]={ {1,1},{1,0}};
power(M,n-1);
return M[0][0];
}
int main(int argc, char **argv)
{
  //cout<<febonacci(56);
  cout<<feb(6)<<endl;
 cout<<FibonacciM(6);
  return 0;
}

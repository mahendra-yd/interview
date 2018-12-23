#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
void pascal(int n)
{
  int a[n][n];
for( int i=0;i<n;i++)
    for(int j=0;j<n;j++)
   a[i][j]=0;

  for( int i=0;i<n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      //printf(" %2d",a[i][j]);
      if(j==0 || j==i) a[i][j]=1;
      else a[i][j]=a[i-1][j-1]+a[i-1][j];
      printf(" %2d",a[i][j]);
    }
    cout<<endl;
  }
}
void pascal1(int n)
{
  for( int line=1;line<n;line++)
  {
    int c=1;
    int k=0;
  while(k++<n-line) cout<<"  ";
    for(int i=1;i<=line;i++)
    {
      printf(" %2d ",c);
      c=c*(line-i)/i;
    }
    cout<<endl;
  }
}
int main(int argc, char **argv)
{
  pascal1(9);
  return 0;
}

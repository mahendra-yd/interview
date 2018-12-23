#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

void draw( int r)
{
  int N=2*r+1;
  int x=0, y=0;

  for( int i=0;i<N;i++)
  { 
    for( int j=0;j<N;j++)
    {
      x=i-r;
      y=j-r;
      if(x*x+y*y <r*r) printf(".");
      else cout<<" ";
      cout<<" ";
    }
    cout<<endl;
  }
}
int main(int argc, char **argv)
{
draw(8);

return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
#define N 8

bool isSafe(int b[N][N],int r, int c)
{
  // check row 
  for( int i=0;i<c;i++) 
    if(b[r][i]) return false;
  // check column
  for( int i=0;i<N;i++) 
    if(b[i][c]) return false;
  // check diagonal in both direction up direction left and right
  int i,j;
  i=r;j=c;
  while(i<N&&j>=0) { if(b[i][j]) return false; i++;j--;}
  i=r;j=c;
  while(i>=0&&j>=0) { if(b[i][j]) return false; i--;j--;}
  return true;
}

bool nQueenUtil(int b[N][N], int c)
{
  if(c==N) return true;

  for( int i=0;i<N;i++)
  {
    if(isSafe(b,i,c))
    {
      b[i][c]=1;
      if(nQueenUtil(b,c+1)) return true;
      b[i][c]=0;
    }
  }
  return false;
}
void solveNQueen()
{
  int b[N][N]={0,};
  if(!nQueenUtil(b,0))
    cout<<"No solution exist\n";
  for(int i=0;i<N;i++)
  {
    for( int j=0;j<N;j++)
      cout<<" "<<b[i][j];
    cout<<endl;   
  }
}
int main(int argc, char **argv)
{
solveNQueen();

return 0;
}

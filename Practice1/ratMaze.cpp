#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#define N 4
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
struct Pair{ int x,y;};
int X[]={0,1,-1,0};
int Y[]={1,0,0,-1};
bool isSafe(int x, int y,int m[4][4])
{
  if(x>=0&&x<4 &&y>=0&&y<4 && m[x][y]==1) return true;
  return false;
}
void solveMaze1(int m[4][4])
{
  stack<Pair>s;
  Pair a;
  a.x=a.y=0;
  s.push(a);
  int i;
  while(!s.empty())
  {
    a=s.top();
    if(a.x==3&&a.y==3)break;
    for( i=0;i<4;i++)
    {
      int x=a.x+X[i];
      int y=a.y+Y[i];
      if(isSafe(x,y,m))
      {
	a.x=x;
	a.y=y;
	s.push(a);
	break;
      }
    }
    if(i==4){a=s.top();s.pop(); m[a.x][a.y]=0;}
  }
  int S[N][N]={0,};

  while(!s.empty())
  {
    a=s.top();s.pop();
    S[a.x][a.y]=1;
  }
  for( int i=0;i<N;i++)
  {for( int j=0;j<N;j++)
    cout<<S[i][j]<<" ";
    cout<<endl;
  }
} 
bool  mazeUtil(int m[N][N], int a, int b, int s[N][N])
{
  if(a==N-1&& b==N-1) { s[N-1][N-1]=1; return true;;}
  for( int i=0;i<4;i++)
  {
    int x=a+X[i];
    int y=b+Y[i];
    if(isSafe(x,y,m))
    {
      s[x][y]=1;
      if(mazeUtil(m,x,y,s)) return true;
      else s[x][y]=0;
    }
  }
  return false;
}
void  solveMaze(int m[N][N])
{
 int s[N][N]={0};
s[0][0]=1;
  mazeUtil(m,0,0,s);
for( int i=0;i<N;i++){ 
for(int j=0;j<N;j++)
cout<<s[i][j]<<" ";cout<<endl;
}
}

int main(int argc, char **argv)
{
  int maze[N][N]  =  {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
  };

  solveMaze(maze);

  return 0;
}

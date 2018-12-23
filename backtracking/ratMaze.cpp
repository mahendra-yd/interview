#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define N 4
void print(int sol[N][N]){    for (int i = 0; i < N; i++)    {        for (int j = 0; j < N; j++)            printf(" %d ", sol[i][j]);        printf("\n");    }}
bool isSafe(int maze[N][N], int x, int y) {    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)        return true;    return false;}
bool mutil(int m[][N],int s[][N],int x,int y)
{
  if(x==N-1&&y==N-1){ s[x][y]=1; return true;}
  if(isSafe(m,x,y))
  {
    s[x][y]=1;
    if(mutil(m,s,x,y+1)) return true;
    if(mutil(m,s,x+1,y)) return true;
    s[x][y]=0;
  } 
  return false;
}
void solveMaze(int m[][N])
{
  int sol[N][N];
  for(int i=0;i<N;i++){for(int j=0;j<N;j++) sol[i][j]=0;}
  if(mutil(m,sol,0,0))
    print(sol);
  else
    cout<<"No solution exist\n";
}
int main()
{
  int maze[N][N]  = { 
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
  };

  solveMaze(maze);
  getchar();
  return 0;
}

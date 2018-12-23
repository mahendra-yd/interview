#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define N 9
void printGrid(int grid[N][N])
{
  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
      printf("%2d", grid[row][col]);
    printf("\n");
  }
}
bool getEmpty(int g[][N],int &r,int &c)
{
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(g[i][j]==0) {r=i;c=j; return true;}
  return false;
}
bool isSafeRow(int g[][N], int r,int n)
{
  for(int i=0;i<N;i++)
    if(g[r][i]==n) return false;
  return true;
}
bool isSafeColumn(int g[][N], int c,int n)
{
  for(int i=0;i<N;i++)
    if(g[i][c]==n) return false;
  return true;
}

bool isSafeGrid(int g[][N],int r,int c,int n)
{
  for(int i=r;i<r+3;i++)
    for(int j=c;j<c+3;j++)
      if(g[i][j]==n) return false;
  return true;
}
bool isSafe(int g[][N],int r, int c, int n)
{
  return isSafeRow(g,r,n) && isSafeColumn(g,c,n) && isSafeGrid(g,r-r%3,c-c%3,n);

}
bool SolveSudoku(int g[][N]) 
{
  int r,c;
  if(!getEmpty(g,r,c)) return true;
  for(int i=1;i<=N;i++)
  {
    if(isSafe(g,r,c,i))
    {
      g[r][c]=i;
      if(SolveSudoku(g)) return true;
      g[r][c]=0;
    }
  }
return false;
}
int main()
{
  int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  if (SolveSudoku(grid) == true)
    printGrid(grid);
  else
    printf("No solution exists");

  return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
#define N 9
bool findVacent(int g[N][N],int& x, int& y)
{
for( int i=0;i<N;i++)
for( int j=0;j<N;j++)
if(g[i][j]==0) { x=i;y=j; return true;}
return false;
}
bool isSafe(int g[N][N],int x, int y, int n)
{
// check row
for( int i=0;i<N;i++) if(g[x][i]==n) return false;
// check column

for( int i=0;i<N;i++) if(g[i][y]==n) return false;
// check square
x=x-x%3;
y=y-y%3;
for( int i=x;i<x+3;i++)
for( int j=y;j<y+3;j++)
if(g[i][j]==n) return false;
return true;
}
bool SolveSudoku(int g[N][N])
{
  int x,y;
  if(!findVacent(g,x,y)) return true;
  for( int i=0;i<N;i++)
  {
    if(isSafe(g,x,y,i+1))
    {
      g[x][y]=i+1;
      if(SolveSudoku(g)) return true;
      else g[x][y]=0;
    }

  }
  return false;
}
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}
int main(int argc, char **argv)
{
 int grid[N][N] = {   {3, 0, 6, 5, 0, 8, 4, 0, 0},
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

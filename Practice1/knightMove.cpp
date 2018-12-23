#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

//int X[]={1,-1,2,2,-2,-2,1,-1};
//int Y[]={2,2,-1,1,1,-1,-2,-2};
int X[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int Y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
struct Pair{int x,y;};
bool isSafe(int x, int y,int c[8][8]) { if(x>=0&&x<8&&y>=0&&y<8 && c[x][y]==-1) return true; return false;}
bool  knightMoveUtil(int c[8][8], int a, int b,int move)
{
  if(move==64) { return true;}
  else {
    for( int i=0;i<8;i++)
    {
      int x = a + X[i];
      int y = b + Y[i];
      if(isSafe(x,y,c))
      {
	c[x][y]=move;
	if(knightMoveUtil(c,x,y,move+1)) return true;
	else
	  c[x][y]=-1;
      }
    }
    return false;
  }
}
void knightMove()
{
int c[8][8]; for( int i=0;i<8;i++) for( int j=0;j<8;j++) c[i][j]=-1;
c[0][0]=0;
if(knightMoveUtil(c,0,0,1))
{for( int i=0;i<8;i++){ for( int j=0;j<8;j++) printf(" %2d",c[i][j]);cout<<endl;}}
else 
cout<<"No solution exist\n";
}
int main(int argc, char **argv)
{
knightMove();

return 0;
}

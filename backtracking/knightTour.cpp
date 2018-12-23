#include<iostream>
#include<stdio.h>
using namespace std;
#define N 8
bool isSafe(int x,int y,int S[][N]){if( x>=0 && x<N && y>=0 && y<N && S[x][y]==-1) return true;return false;}
bool ktu(int S[][N],int m,int xm[],int ym[],int x,int y)
{
  if(m==N*N) return true;
  for(int i=0;i<8;i++) {
    int _x=x+xm[i];
    int _y=y+ym[i];
    if(isSafe(_x,_y,S))  {
      S[_x][_y]=m;
      if(ktu(S,m+1,xm,ym,_x,_y)) return true;
      else
	S[_x][_y]=-1;
    }
  }
return false;
}
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N]){for (int x = 0; x < N; x++) { for (int y = 0; y < N; y++) printf(" %2d ", sol[x][y]); printf("\n"); }}
void KT()
{
  int S[N][N];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      S[i][j]=-1;
  S[0][0]=0;
  int xm[]={2,2,-2,-2,1,1,-1,-1};
  int ym[]={1,-1,1,-1,-2,2,-2,2};
 // int xm[]={2,1,-1,-2,-2,-1,1,2};
 // int ym[]={1,2, 2, 1,-1,-2,-2,-1};
  if(!ktu(S,1,xm,ym,0,0))
    cout<<"No Solution exist"<<endl;
  else
    printSolution(S);
}
int main(int argc, char **argv)
{
  KT();
  return 0;
}

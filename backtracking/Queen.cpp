#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define N 32
void print(int s[][N])
{
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++) 
      printf(" %2d",s[i][j]);
    cout<<endl;
  }

}
bool isSafe(int s[][N],int r, int c)
{
  for(int i=0;i<c;i++) if(s[r][i]) return false;
  for(int i=r,j=c;i>=0&&j>=0;i--,j--) if(s[i][j]) return false;
  for(int i=r,j=c;i<N&&j>=0;i++,j--) if(s[i][j]) return false;
  return true;
}
bool qutil(int s[][N],int c)
{
if(c==N)
return true;
  for(int i=0;i<N;i++)
  {
    if(isSafe(s,i,c))
    {
      s[i][c]=1;
      if(qutil(s,c+1)) return true;
      else
      s[i][c]=0;
    }
  }
  return false;
}
void Queen()
{
  int s[N][N]={0,};
  if(qutil(s,0))print(s);
  else cout<<"No solution\n";
}

int main(int argc, char **argv)
{

  Queen();

  return 0;
}

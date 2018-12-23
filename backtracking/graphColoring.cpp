#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define V 4
bool isSafe(int g[][V],int c[],int color,int v)
{
  for(int i=0;i<V;i++) {
    if(g[v][i]&&c[i]==color) 
      return false; }
  return true; 
}
bool gcutil(int g[][V],int c[],int m,int v)
{
  if(v==V) return true;
  for(int i=1;i<=m;i++)
  {
    if(isSafe(g,c,i,v))
    {
      c[v]=i;
      if(gcutil(g,c,m,v+1)) return true;
      else c[v]=0;
    }
  }
 return false;
}
void graphColoring(int g[][V],int m)
{
int c[V]={0,};
if(gcutil(g,c,m,0)) { for(int i=0;i<V;i++)cout<<i<<" "<<c[i]<<endl;}
else cout<<"m coloring not possible\n";
}
int main(int argc, char **argv)
{
/* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    int graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    graphColoring (graph, m);

return 0;
}

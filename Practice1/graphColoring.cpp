#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
#define V 4
bool isSafe(int g[V][V],int * color,int c, int v)
{
  for(int i=0;i<V;i++)
  {
    if(g[v][i] && color[i]==c) return false;
  }
  return true;
} 

bool colorUtil(int g[V][V],int m, int* color,int v)
{
  if(v==V) return true;
  for(int i=1;i<=m;i++)
  {
    if (isSafe(g,color,i,v))
    {
      color[v]=i;
      if(colorUtil(g,m,color,v+1)) return true;
      color[v]=0;
    }
  }
  return false;
}
void printSolution(int *c, int v)
{
for( int i=0;i<v;i++)
printf("color of verted[%d] is [%d]\n",i,c[i]);
}
void graphColoring(int g[V][V], int m)
{
int* color = new int[V];
if(colorUtil(g,m,color,0))
printSolution(color,V);
else
cout<<"coloring not possible";
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
  int  graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0},
  };
  int m = 2; // Number of colors
  graphColoring (graph, m);
  return 0;
}

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
struct Edge {int src,dest,weight;};
int comp(const void *a_,const void* b_)
{
  Edge *a=(Edge*)a_,*b=(Edge*)b_;
  if(a->weight > b->weight) return 1;
  else return -1;
}
int find ( int p[], int i)
{
  if(p[i]==-1) return i;
  return find(p,p[i]);
}
void Union(int p[],int i,int j)
{
 int x=find(p,i);
 int y=find(p,j);
  p[x]=y;
}
Edge sol[100];
struct graph
{
  int V,E;
  Edge *edge;
  int *p;
  graph(int v,int e) { V=v;E=e; p=new int [V]; edge = new Edge[E]; for(int i=0;i<V;i++) p[i]=-1;}
  void krushkal()
  {
  int k=0;
    //   sort(edge,edge+E,comp);
    qsort(edge,E,sizeof(Edge),comp);
    for(int i=0;i<E;i++)
    {
     int x = find(p,edge[i].src);
     int y = find(p,edge[i].dest);
    if(x!=y)
    { 
     sol[k++]=edge[i];
    Union(p,x,y);
    }
    } 
for( int i=0;i<k;i++) printf("src= %d dst= %d, weight =%d\n",sol[i].src,sol[i].dest,sol[i].weight);
  }
};
int main(int argc, char **argv)
{

  /* Let us create following weighted graph
     10
     0--------1
     |  \     |
     6|   5\   |15
     |      \ |
     2--------3
     4       */
  int V = 4;  // Number of vertices in graph
  int E = 5;  // Number of edges in graph
  graph g(V, E);


  // add edge 0-1
  g.edge[0].src = 0;
  g.edge[0].dest = 1;
  g.edge[0].weight = 10;

  // add edge 0-2
  g.edge[1].src = 0;
  g.edge[1].dest = 2;
  g.edge[1].weight = 6;

  // add edge 0-3
  g.edge[2].src = 0;
  g.edge[2].dest = 3;
  g.edge[2].weight = 5;

  // add edge 1-3
  g.edge[3].src = 1;
  g.edge[3].dest = 3;
  g.edge[3].weight = 15;

  // add edge 2-3
  g.edge[4].src = 2;
  g.edge[4].dest = 3;
  g.edge[4].weight = 4;

  g.krushkal();

  return 0;
}

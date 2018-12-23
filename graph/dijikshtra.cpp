#include<iostream>
#include<list>
#include<limits.h>
#include<stdio.h>
using namespace std;
#define V 9

int minw(bool spt[],int w[])
{
int min=INT_MAX,j=0;
  for(int i=0;i<V;i++)
	if(spt[i]==false&&min>w[i]) { min=w[i];j=i;}
return j;
}
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
 
void dijkstra(int g[V][V],int s)
{
  int w[V];
  bool spt[V];
  int p[V];
  int u=0;
  for(int i=0;i<V;i++){w[i]=INT_MAX;spt[i]=false; }
  w[s]=0;

  for(int i=0;i<V;i++)
  {
	u= minw(spt,w);
	spt[u]=true;
	for(int v=0;v<V;v++)
	{
		if(g[u][v]&&spt[v]==false&& w[u] + g[u][v] < w[v])
			w[v]=w[u] + g[u][v]; 
		p[v]=u;
	}
  }

printSolution(w,V);
}
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
 
    return 0;
}

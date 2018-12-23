/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : mst.cpp

 * Purpose : General programming practice

 * Creation Date : 10-04-2015

 * Last Modified : Fri 10 Apr 2015 08:25:19 PM IST

 * Created By :  Mahendra

 _._._._._._._._._._._._._._._._._._._._._.*/
//http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/
#include<iostream>
#include <cstdlib>
#include <list>
#include<string>
#include<limits.h>
#include<string.h>
using namespace std;
struct Edge
{
  int src;
  int dest;
  int weight;
};
class Graph
{
  public :

    int V,E;
    struct Edge * edge;
    int count;
    Graph(int v,int e)
    {
      V=v;
      E=e;
      count =0;
      //edge= (struct Edge*)malloc(sizeof(struct Edge)*E);
      edge = new struct Edge [E];
    }
    bool addEdge(int i,int j,int k)
    { 
      if(count>=E)
        return false;
      edge[count].src=i;
      edge[count].dest=j;
      edge[count].weight=k;
      count++;
      return true;
    }
    void    print()
    {
      for(int i=0;i<E;i++)
      {
        cout<<"Edge "<<i<<" src = "<< edge[i].src<<" dst = "<< edge[i].dest<<" weight = "<<edge[i].weight<<endl;

      }
    }
    void   KruskalMST();
    void   PrimsMST();
};

//struct Edge* comp(struct Edge *a,struct Edge *b)
int  comp(const void *a_,const void  *b_)
{
  struct Edge *a=(struct Edge * )a_;
  struct Edge *b=(struct Edge *)b_;
  if(a->weight> b->weight)
    return 1;
  else
    return -1;

}

int find( int*p, int x)
{
  if(p[x]==-1)
    return x;
  return find(p,p[x]);
}

void Union(int*p, int x,int y)
{
  int xx,yy;
  xx = find(p,x);
  yy=find(p,y);
    p[xx]=yy;
}
int minw(int *w,bool *m,int V)
{
	int min=INT_MAX;
	int v=-1;
	for(int i=0;i<V;i++)
  {
    if(w[i]<min && !m[i])
    	min =w[i],v=i;
  }
  return v;
}
int min(int i, int j)
{
return i<j?i:j;
}
void update(int u, struct Edge* e ,int n,int * weight)
{
	for(int i=0;i<n;i++)
		if(e[i].src==u)
			weight[e[i].dest]= min(e[i].weight,weight[e[i].dest]);
}
void sol( list<struct Edge> &g,int u, struct Edge *e,int n,bool *m)
{
	for(int i=0;i<n;i++)
		if(e[i].dest==u && m[e[i].src])
		{	g.push_back(e[i]);return;}
}
void Graph::PrimsMST()
{
  bool mst[V];
  int weight[V];
  list<struct Edge> g; 
  for(int i=0;i<V;i++)
    mst[i]=false,weight[i]=INT_MAX;
  weight[0]=0;
  int u=0; 
  mst[u]=true;
  for(int i=0;i<V;i++)
  {
  	update(u,edge,E,weight);
  	u= minw(weight,mst,V);
  	sol(g,u,edge,E,mst);
  	mst[u]=true;
  }

  struct Edge e;
  int i=0;
  cout<<"MST of above graph using prims is \n\n";
  while(!g.empty())
  {

    e=g.front();
    g.pop_front();
    cout<<"Edge "<<i<<" src = "<< e.src<<" dst = "<< e.dest<<" weight = "<<e.weight<<endl;
    i++;
  }


}
void Graph::KruskalMST()
{
  list<struct Edge> g; 
  int u[V];
  print();
  qsort(edge,E,sizeof(struct Edge),comp);
  int count =1;
  struct Edge e;
  for(int i=0;i<V;i++)
  	u[i]=-1;
  e=edge[0];
  g.push_back(e);
  Union(u,e.src,e.dest);

  for(int i=1;i<E && count<V-1;i++)
  {
    e=edge[i];
    int x = find(u,e.src);
    int y = find(u,e.dest);
    if(x !=y)
    {
      g.push_back(e);
      Union(u,e.src,e.dest);
      count++;
    }
  }
  int i=0;

  cout<<"MST of above graph using krushkal is \n\n";
  while(!g.empty())
  {

    e=g.front();
    g.pop_front();
    cout<<"Edge "<<i<<" src = "<< e.src<<" dst = "<< e.dest<<" weight = "<<e.weight<<endl;
    i++;
  }
  return;
}
// Driver program to test above functions
int main()
{
  /* Let us create following weighted graph
     10
     0--------1
     |  \     |
     6|   5\   |15
     |      \ |
     2--------3
     4       */
  int V = 9 ;  // Number of vertices in graph
  int E = 14 ;  // Number of edges in graph
  Graph graph(V,E);
/*  cin>>E>>V;
  int x,y,z;
  for(int i=0;i<E;i++)
  {
  	cin>>x>>y>>z;
  graph.addEdge(y,z,x);
  }
  */
    graph.addEdge( 0, 1, 4);
    graph.addEdge( 0, 7, 8);
    graph.addEdge( 1, 2, 8);
    graph.addEdge( 1, 7, 11);
    graph.addEdge( 2, 3, 7);
    graph.addEdge( 2, 8, 2);
    graph.addEdge( 2, 5, 4);
    graph.addEdge( 3, 4, 9);
    graph.addEdge( 3, 5, 14);
    graph.addEdge( 4, 5, 10);
    graph.addEdge( 5, 6, 2);
    graph.addEdge( 6, 7, 1);
    graph.addEdge( 6, 8, 6);
    graph.addEdge( 7, 8, 7);


 graph.PrimsMST();
 graph.KruskalMST();
  return 0;
}



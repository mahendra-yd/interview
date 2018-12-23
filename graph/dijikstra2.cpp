#include<iostream>
#include<list>
using namespace std;
int V = 9;
class Graph
{
  public:
  int V;
  list<int,int> *adj;
  Graph(int v)
  {
    V=v;
    adj=new list<int> [V]; 
  }
  void addEdge(int v,int u,int w)
  {
    adj[v].push_back(<u,w>);
  }
  void   dijkstra(int i);
};
void Graph::dijkstra(int u)
{
  bool spt[V];
  int w[V];
  for(int i=0;i<V;i++){ spt[i]=false;w[i]=INT_MAX;}
  w[u]=0;
  for(int i=0;i<V;i++)
  {
    u = getmin(spt,w);
	spt[u]=true;
    for(list<int>::iterator i=adj[u].begin();i!=adj[u].end() && spt[i->first]==false && w[u]+i->second < w[i->first];++i)
    {
       w[i->first] =  w[u]+i->second;
    }
  }
}

int main()
{
    // create the graph given in above fugure
     Graph g(V);
    g.addEdge( 0, 1, 4);
    g.addEdge( 0, 7, 8);
    g.addEdge( 1, 2, 8);
    g.addEdge( 1, 7, 11);
    g.addEdge( 2, 3, 7);
    g.addEdge( 2, 8, 2);
    g.addEdge( 2, 5, 4);
    g.addEdge( 3, 4, 9);
    g.addEdge( 3, 5, 14);
    g.addEdge( 4, 5, 10);
    g.addEdge( 5, 6, 2);
    g.addEdge( 6, 7, 1);
    g.addEdge( 6, 8, 6);
    g.addEdge( 7, 8, 7);
    g.dijkstra(0);
    return 0;
}


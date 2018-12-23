#include<iostream>
#include<stack>
#include <list>
using namespace std;
class Graph
{
  int V;    // No. of vertices
  list<int> *adj;    // Pointer to an array containing adjacency lists
  void DFSUtil(int v, bool visited[]);  // A function used by DFS
  public:
  Graph(int V);   // Constructor
  void addEdge(int v, int w);   // function to add an edge to graph
  void DFS(int v);    // DFS traversal of the vertices reachable from v
  void topologicalSort();
  void util(int a,bool visited[],stack<int> &s);
};
Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w); // Add w to v.s list.
}
void Graph::DFSUtil(int v, bool visited[])
{
  visited[v]=true;
  cout<<v<<" ";
  for(list<int>::iterator i=adj[v].begin();i!=adj[v].end();i++)
    if(!visited[*i]) DFSUtil(*i,visited);

}
void Graph::DFS(int v)
{
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;
  DFSUtil(v, visited);
}
void Graph::util(int u,bool visited[],stack<int>& s)
{
  visited[u]=true;
  for(list<int>::iterator i=adj[u].begin();i!=adj[u].end();i++)
    if(!visited[*i]) util(*i,visited,s);
  s.push(u);
}
void Graph::topologicalSort()
{
  bool visited[V];for(int i=0;i<V;i++) visited[i]=false;
  stack<int > s;
  for(int i=0;i<V ;i++)
  if( visited[i]==false) 
    util(i,visited,s);
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }

}
int main()
{
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  cout << "Following is a Topological Sort of the given graph \n";
   g.topologicalSort();
  return 0;

}

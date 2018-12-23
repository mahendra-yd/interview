#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;
class Graph
{
  int V;
  list<int> *adj;
  public:
  Graph(int v)
  {
    V=v;
    adj=new list<int> [V]; 
  }
  void DFS(int v);
  void BFS(int v);
  bool isCycle();
  bool isCycleUtil(int v, bool visited[],bool isRec[]);
  bool isReachable(int,int);
  void addEdge(int v,int u)
  {
    adj[v].push_back(u);
  }
};
void Graph::DFS(int v)
{
  stack<int> s;
  bool visited[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  s.push(v);
  visited[v]=true;
  while(!s.empty())
  {
    v=s.top();s.pop();
    cout<<v<<" ";
    for(list<int>::iterator i=adj[v].begin();i!=adj[v].end();++i)
    {
      if(!visited[*i])
      {
      	visited[*i]=true;
      	s.push(*i);
      }
    }
  }
}
void Graph::BFS(int v)
{
  queue<int> q;
  bool visited[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  q.push(v);
  visited[v]=true;
  while(!q.empty())
  {
    v=q.front();q.pop();
    cout<<v<<" ";
    for(list<int>::iterator i=adj[v].begin();i!=adj[v].end();++i)
    {
      if(!visited[*i])
      {
      	visited[*i]=true;
      	q.push(*i);
      }
    }
  }
}
bool Graph::isCycleUtil( int i,bool v[],bool r[])
{
  if(!v[i])
  {
    v[i]=true;
    r[i]=true;
    for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++)
    {
      if(!v[*it]) return isCycleUtil(*it,v,r);
      else if(r[*it]) return true;
    }
  }
  r[i]=false;
  return false;

}
bool Graph::isCycle()
{
  bool visited[V],rec[V];
  for(int i=0;i<V;i++){ visited[i]=false;rec[i]=false;} 
  for(int i=0;i<V && !visited[i];i++)
  {
    if(isCycleUtil(i,visited,rec))
      return true;
  }
  return false;
}
bool Graph::isReachable(int v,int u)
{
 stack<int> s;
  bool visited[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  s.push(v);
  visited[v]=true;
  while(!s.empty())
  {
    v=s.top();s.pop();
//    cout<<v<<" ";
    if(v==u) return true;
    for(list<int>::iterator i=adj[v].begin();i!=adj[v].end();++i)
    {
      if(!visited[*i])
      {
      	visited[*i]=true;
      	s.push(*i);
      }
    }
  }

return false;
}
int main()
{
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
 // g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
//  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal (starting from vertex 2) \n";
 
 // g.DFS(2);
//  g.BFS(2);
//cout<< g.Cycle()<<endl;
cout<< g.isCycle();

  return 0;
}

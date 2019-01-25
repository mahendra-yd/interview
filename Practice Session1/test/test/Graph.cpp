#include "stdafx.h"
#include<list>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	enum COLOR { RED, BLUE };

	COLOR * color = new COLOR[V];
public:
	Graph( int vertex)
	{
		V = vertex;
		adj = new list<int>[V];
	}

	void addEdge(int u, int v, bool isdirected=false)
	{
		adj[u].push_back(v);
		if(!isdirected)
			adj[v].push_back(u);

	}
	void BFS(int start) {
		bool * visited = new bool[V] {false};
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			start = q.front(); q.pop();
			visited[start] = true;
			cout << start << " ";
			for (auto i : adj[start])
			{
				if (!visited[i])
				{
					q.push(i);
				}
			}
		}
	}

	bool isBipartiteOrTwoColoring()
	{
		queue<int > q;
		bool *visited = new bool[V] {false};
		for (int i = 0; i < V && !visited[i]; i++)
		{
			int t = adj[i].front();
			q.push(t);
			visited[t] = true;
			color[t] = COLOR::RED;
			while (!q.empty())
			{
				int t = q.front(); q.pop();
				for (auto v : adj[t])
				{
					if (!visited[v])
					{
						visited[v] = true;
						q.push(v);
						color[v] = color[t] == COLOR::BLUE ? COLOR::RED : COLOR :: BLUE;
					}
					else
					{
						if (color[v] == color[t])
							return false;
					}
				}
			}
		}
		for (int i = 0; i < V; i++)
		{
			cout <<endl<< " " << i << " -> " << (color[i] == COLOR::BLUE) ? " BLUE " : " RED " ;
		}
		return true;
	}


	int BFSCountIsland() {
		bool * visited = new bool[V] {false};
		int islandcount = 0;
		queue<int> q;
		for (int start = 0; start < V && !visited[start]; start++) {
			islandcount++;
			int t = adj[start].front();
			q.push(t);
			while (!q.empty())
			{
				t = q.front(); q.pop();
				visited[t] = true;
				
				for (auto i : adj[t])
				{
					if (!visited[i])
					{
						q.push(i);
					}
				}
			}
		}
		return islandcount;
	}
	void DSFUtil(int start, bool* visited,bool print=true){

		visited[start] = true;
		print&&cout << start << " ";
		for (auto i : adj[start])
		{
			if (!visited[i])
				DSFUtil(i, visited,print);
		}
	}
	void DFS() {
		bool *visited = new bool[V] {false};
		DSFUtil(adj[0].front(), visited);
	}
	void DFSIterative() {
		bool *visited = new bool[V] {false};
		int start = adj[0].front();
		stack<int> s;
		s.push(start);
		while (!s.empty())
		{
			start = s.top(); s.pop();
			cout << start << " ";
			visited[start] = true;
			for (auto i : adj[start])
			{
				if (!visited[i])
				{
					s.push(i);
				}
			}
		}
	}
bool isCyclicUtil(int s, bool *visited, bool *recpath)
	{
		if (!visited[s])
		{
			visited[s] = true;
			recpath[s] = true;
			for (auto i : adj[s])
			{
				if (!visited[i] && isCyclicUtil(i, visited, recpath))
					return true;
				else if (recpath[i])
					return true;
			}
		}
		recpath[s] = false;
		return false;

	}
	bool isCyclic()
	{
		bool *visited = new bool[V] {false};
		bool *recpath = new bool[V] {false};
		for (int i = 0; i < V; i++)
		{
			if (isCyclicUtil(adj[i].front(), visited, recpath))
				return true;
		}
		return false;
	}
	void topologicalSortUtil(int s, bool * visited, stack<int> & st)
	{
		visited[s] = true;
		for (auto i : adj[s])
		{
			if (!visited[i])
				topologicalSortUtil(i, visited, st);
		}

		st.push(s);
	}
	void topologicalSort()
	{
		bool *visited = new bool[V] {false};
		stack<int> s;
		for (int i = 0; i < V; i++)
		{
			if (!visited[i])
				topologicalSortUtil(adj[i].front(), visited, s);
		}
		while (!s.empty())
		{
			cout << s.top(); s.pop();
		}
	}
	int hasMotherVertex()
	{
		bool *visited = new bool[V] {false};
		int motherVertex = -1;// mother vertex is the last vertex that would be visited in DFS
		for (int i = 0; i < V; i++)
		{
			if (!visited[i]) {
				DSFUtil(i, visited, false);
				motherVertex = i;
			}
		}
		// test is mother vertex
		memset(visited, 0, sizeof(bool)*V);
		DSFUtil(motherVertex, visited,false);
		for (int i = 0; i < V; i++)
		{
			if (!visited[i]) return -1;
		}

		return motherVertex;
	}

};

void DemoGraph()
{
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

	cout << "A mother vertex is " << g.isBipartiteOrTwoColoring();
}

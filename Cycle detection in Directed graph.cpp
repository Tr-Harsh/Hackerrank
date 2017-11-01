#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	bool iscyclicUtil(int v, vector<bool> &visited, vector<bool> &recstack);
	public:
		Graph(int v);
		void addedge(int v, int u);
		bool iscyclic();
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addedge(int v, int u)
{
	adj[v].push_back(u);
}

bool Graph::iscyclicUtil(int v,vector<bool> &visited, vector<bool> &recstack)
{
	if(!visited[v])
	{
		visited[v] = true;
		recstack[v]  = true;
		list<int>::iterator i;
		
		for(i=adj[v].begin();i!= adj[v].end();++i)
		{
			if(!visited[*i])
				if( iscyclicUtil(*i,visited,recstack))
					return true;
			else if(recstack[*i])
				return true;
		}
	}
	recstack[v]= false;
	return false;
}
bool Graph::iscyclic()
{
	vector<bool> visited(v,false);
	vector<bool> recstack(v,false);
	
	for(int i=0;i<v;i++)
	{
		if(iscyclicUtil(i,visited,recstack))
			return true;
	}
	return false;
}

int main()
{
    Graph g(7);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(1, 3);
	g.addedge(4, 1);
	g.addedge(6, 4);
	g.addedge(5, 6);
	g.addedge(5, 2);
	g.addedge(6, 0);

    if(g.iscyclic())
    cout<<"Graph is Cyclic";
    
    else
    cout<<"Graph is Acyclic";
    return 0;
}

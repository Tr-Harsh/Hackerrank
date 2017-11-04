#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addedge(int v,int u);
		bool iscyclicUtil(int v,vector<bool> &visited, int parent);
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
	adj[u].push_back(v);
}

bool Graph::iscyclicUtil(int v,vector<bool> &visited, int parent)
{
	visited[v] = true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			if(iscyclicUtil(*i,visited,v))
				return true;
		}
		else if(*i!= parent)
		{
			return true;
		}
	}
	return false;
}

bool Graph::iscyclic()
{	
	vector<bool> visited(v,false);
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
			if(iscyclicUtil(i,visited,-1))
				return true;
	}
	return false;
}

int main()
{
    Graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 0);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    g1.iscyclic()? cout << "Graph g1 contains cycle\n":
				   cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    g2.iscyclic()? cout << "Graph g2 contains cycle\n":
				   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}

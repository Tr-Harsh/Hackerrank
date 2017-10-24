#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addedge(int v,int u);
		void iterativeDFSutil(int s, vector<bool> &visited);
		void iterativeDFS();
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

void Graph::iterativeDFSutil(int s, vector<bool> &visited)
{
	stack<int> stack;
	stack.push(s);
	
	while(!stack.empty())
	{
		s = stack.top();
		stack.pop();
		
		if(!visited[s]){
			cout<<s<<" ";
			visited[s] = true;
		}	
		list<int>::iterator i;
		for(i=adj[s].begin();i!=adj[s].end();++i)
		{
			if(!visited[*i])
			{
				stack.push(*i);
			}
		}
	}	
}

void Graph::iterativeDFS()
{
	vector<bool> visited(v,false);
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			iterativeDFSutil(i,visited);
		}
	}
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

    cout << "Following is iterative Depth First Traversal\n";
    g.iterativeDFS();
 
    return 0;
}

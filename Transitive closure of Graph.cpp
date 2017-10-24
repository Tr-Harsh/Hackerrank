#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	bool **trancol;
	list<int> *adj;
	void DFSutil(int v,int u);
	public:
		Graph(int v);
		void addedge(int v,int u);
		void transitiveclosure();
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<int>[v];
	trancol = new bool *[v];
	for(int i=0;i<v;i++)
	{
		trancol[i] = new bool[v];
		memset(trancol[i], false, v*sizeof(bool));
	}	
}

void Graph::addedge(int v,int u){
	adj[v].push_back(u);
}

void Graph::DFSutil(int v,int u){
	trancol[v][u] =true;
	
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();++i){
		if(!trancol[v][*i]){
			DFSutil(v,*i);
		}
	}
}

void Graph::transitiveclosure(){
	for(int i=0;i<v;i++){
		DFSutil(i, i);
	}
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<trancol[i][j]<<" ";	
		}
		cout<<endl;
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

    cout << "Transitive closure matrix is \n";
    g.transitiveclosure();
 
    return 0;
}

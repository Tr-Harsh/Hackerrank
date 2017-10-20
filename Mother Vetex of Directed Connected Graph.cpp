#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addedge(int x,int y);
		int motherVertex();
		void DFSutil(int v,vector<bool> &visited);
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}

void Graph::DFSutil(int v,vector<bool> &visited){
	visited[v] = true;
	
	list<int>::iterator p;
	for(p=adj[v].begin();p!=adj[v].end();++p){
		if(!visited[*p])
		{
			DFSutil(*p,visited);
		}
	}	
}

void Graph::addedge(int x, int y){
	adj[x].push_back(y);
}

int Graph::motherVertex(){
	vector<bool> visited(v,false);
	int mothervertex = 0;
	
	for(int i=0;i<v;i++)
	{
		if(visited[i] == false)
		{
			DFSutil(i,visited);
			mothervertex = i;
		}
	}
	
	fill(visited.begin(), visited.end(), false);
	DFSutil(mothervertex, visited);

	for(int i=0;i<v;i++){
		if(visited[i] == false)
			return -1;
			
	return mothervertex;
}
}
int main(){
    Graph g(7);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(1, 3);
	g.addedge(4, 1);
	g.addedge(6, 4);
	g.addedge(5, 6);
	g.addedge(5, 2);
	g.addedge(6, 0);

	cout << "Mother Vertex of the following graph is:\n"<<g.motherVertex();
    return 0;
}

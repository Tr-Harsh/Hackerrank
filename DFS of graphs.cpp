#include<iostream>
#include<list>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addedge(int v,int u);
		void DFSutil(int v,bool visited[]);
		void DFS(int s);
};
Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addedge(int v, int u){
	adj[v].push_back(u);
}

void Graph::DFSutil(int v,bool visited[]){
	visited[v] = true;
	cout<<v<<" ";
	
	list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();++i){
			if(!visited[*i]){
				DFSutil(*i,visited);
		}
	}
}

void Graph::DFS(int v){
	bool *visited;
	visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}	
	DFSutil(v,visited);
}

int main(){
	Graph g(4);
	g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS(2);
 
    return 0;
}

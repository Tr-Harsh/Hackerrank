#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;
	list<int>*adj;
	public:
		Graph(int v);
		void addedge(int v,int u);
		void BFS(int s);
};
Graph::Graph(int v){
	this->v=v;
	adj = new list<int>[v];
}

void Graph::addedge(int v,int u){
	adj[v].push_back(u);
}

void Graph::BFS(int s){
	list<int>::iterator i;
	bool *visited;
	visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}
	
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	while(!queue.empty()){
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		} 
	}
}

int main(){
	Graph g(4);
	g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    cout<<"The BFS of the graph is: \n";
    g.BFS(2);
    return 0;
}

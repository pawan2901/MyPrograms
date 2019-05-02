#include<iostream>
#include<list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    public:
    Graph(int V);

    void addEdge(int v, int u);
    void BFS(int s);
};

Graph::Graph(int V) 
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int u) 
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::BFS(int s)
{
    list<int> queue;
    bool *visited = new bool[V];
    queue.push_back(s);
    visited[s] = true;

    list<int>::iterator i;
    while(queue.size() != 0) {
	s = queue.front();
	cout << " " << s;
	queue.pop_front();
	for( i = adj[s].begin(); i != adj[s].end(); i++) {
	    if( !visited[*i]) {
		visited[*i] = true;
		queue.push_back(*i);
	    }
	}
    }
    cout << endl;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    return 0;
}

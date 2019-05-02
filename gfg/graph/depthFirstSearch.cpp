#include<iostream>
#include<list>
#include<stack>
#include<vector>

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
    vector<int> visited(V, false);
    stack<int> stack;
    stack.push(s);

    list<int>::iterator i;
    while(stack.size() != 0) {
	s = stack.top();
	stack.pop();
	if(!visited[s]) {
	    cout << " " << s;
	    visited[s] = true;
	}
	for( i = adj[s].begin(); i != adj[s].end(); i++) {
	    if( !visited[*i]) {
		stack.push(*i);
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

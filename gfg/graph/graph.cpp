#include<iostream>

using namespace std;

struct adjNode {
    int data;
    adjNode *next;
};

struct adjList {
    adjNode *head;
};

struct Graph{
    int v;
    adjList *array;
};

adjNode *newAdjNodeCreate(int dest) {
    adjNode *tmp = new adjNode;
    tmp->data = dest;
    tmp->next = NULL;
    return tmp;
}

Graph *createGraph(int v) {
    Graph *graph = new Graph;
    graph->v = v;
    graph->array = new adjList[v];
    for(int i=0; i<v; i++) {
	graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dst) {
    adjNode *newNode = newAdjNodeCreate(dst);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;


    newNode = newAdjNodeCreate(src);
    newNode->next = graph->array[dst].head;
    graph->array[dst].head = newNode;
}

void printGraph(Graph *graph) {
    for(int i=0; i<graph->v; i++) {
	adjNode *crawl = graph->array[i].head;
	cout << " node id " << i << "->";
	while(crawl) {
	    cout << crawl->data <<" ";
	    crawl=crawl->next;
	}
    cout << endl;
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    addEdge(graph,3,4);
    printGraph(graph);
    return 0;
}


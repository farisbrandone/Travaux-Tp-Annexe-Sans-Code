#ifndef GRAPH_H
#define GRAPH_H

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct {
    int numVertices;
    GraphNode** adjLists;
    int* visited;
} Graph;

Graph* createGraph(int vertices);
void destroyGraph(Graph* graph);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void BFS(Graph* graph, int startVertex);
void DFS(Graph* graph, int startVertex);

#endif
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

static GraphNode* createGraphNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (GraphNode**)malloc(vertices * sizeof(GraphNode*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void destroyGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* current = graph->adjLists[i];
        while (current != NULL) {
            GraphNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

void addEdge(Graph* graph, int src, int dest) {
    // Ajouter de src à dest
    GraphNode* newNode = createGraphNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Ajouter de dest à src (graphe non orienté)
    newNode = createGraphNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void removeEdge(Graph* graph, int src, int dest) {
    // Supprimer de src à dest
    GraphNode** current = &graph->adjLists[src];
    while (*current != NULL) {
        if ((*current)->vertex == dest) {
            GraphNode* temp = *current;
            *current = (*current)->next;
            free(temp);
            break;
        }
        current = &(*current)->next;
    }
    
    // Supprimer de dest à src (graphe non orienté)
    current = &graph->adjLists[dest];
    while (*current != NULL) {
        if ((*current)->vertex == src) {
            GraphNode* temp = *current;
            *current = (*current)->next;
            free(temp);
            break;
        }
        current = &(*current)->next;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* current = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void BFS(Graph* graph, int startVertex) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
    
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;
    
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS from %d: ", startVertex);
    
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        
        GraphNode* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(queue);
}

static void DFSUtil(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    
    GraphNode* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFSUtil(graph, adjVertex);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
    
    printf("DFS from %d: ", startVertex);
    DFSUtil(graph, startVertex);
    printf("\n");
}
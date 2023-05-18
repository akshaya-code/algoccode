#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Adjacency List Node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Adjacency List
typedef struct List {
    Node* head;
} List;

// Graph
typedef struct Graph {
    int numNodes;
    List* adjListArray;
} Graph;

// Create a new node
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with given number of nodes
Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjListArray = (List*)malloc(numNodes * sizeof(List));
    for (int i = 0; i < numNodes; ++i)
        graph->adjListArray[i].head = NULL;
    return graph;
}

// Add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjListArray[src].head;
    graph->adjListArray[src].head = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjListArray[dest].head;
    graph->adjListArray[dest].head = newNode;
}

// Depth First Search
void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    Node* temp = graph->adjListArray[vertex].head;
    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex])
            DFS(graph, adjVertex, visited);
        temp = temp->next;
    }
}

int main() {
    int numNodes = 6;
    Graph* graph = createGraph(numNodes);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    bool visited[MAX_NODES] = { false };

    printf("Depth First Traversal (starting from vertex 0): ");
    DFS(graph, 0, visited);

    return 0;
}

/*

This code represents a simple undirected graph with six nodes. You can modify the numNodes variable and the addEdge function calls to create a different graph. The DFS algorithm starts from a given vertex (in this case, vertex 0) and recursively explores all the connected vertices. The visited array is used to keep track of visited vertices to avoid revisiting them. The code prints the vertices in the order they are visited during the DFS traversal.

*/
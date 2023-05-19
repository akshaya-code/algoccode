
/*
DP programming to get single source shortest path
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Structure to represent a graph
struct Graph {
    int vertices, edges;
    struct Edge* edge;
};

// Function to create a graph with 'V' vertices and 'E' edges
struct Graph* createGraph(int vertices, int edges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (struct Edge*)malloc(edges * sizeof(struct Edge));
    return graph;
}

// Function to print the distance array
void printDistance(int distance[], int n) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t%d\n", i, distance[i]);
}

// Function to find the shortest path using Bellman-Ford algorithm
void bellmanFord(struct Graph* graph, int source) {
    int V = graph->vertices;
    int E = graph->edges;
    int distance[V];

    // Initialize distance array
    for (int i = 0; i < V; ++i)
        distance[i] = INT_MAX;
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print the distance array
    printDistance(distance, V);
}

int main() {
    int V, E, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; ++i)
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, source);

    return 0;
}

/*

In this code, you need to input the number of vertices, the number of edges, and the details of each edge (source, destination, and weight) to create the graph. After that, you provide the source vertex, and the code will compute the shortest path using the Bellman-Ford algorithm and print the distance from the source to each vertex.

Please note that this code assumes the graph has no negative-weight cycles. If a negative-weight cycle exists, the algorithm will detect it and print a corresponding message.



*/

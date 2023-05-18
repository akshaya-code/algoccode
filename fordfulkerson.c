#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define V 6 // Number of vertices in the graph

bool bfs(int rGraph[V][V], int source, int sink, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    visited[source] = true;
    parent[source] = -1;

    // Create a queue, enqueue source vertex and mark it as visited
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = source;

    while (front != rear) {
        int u = queue[front++];
        
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached the sink vertex, then there is a path from source to sink
    return visited[sink];
}

int fordFulkerson(int graph[V][V], int source, int sink) {
    int rGraph[V][V]; // Residual graph
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V]; // Array to store the path

    int maxFlow = 0; // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, source, sink, parent)) {
        // Find the minimum residual capacity of the edges along the path
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = pathFlow < rGraph[u][v] ? pathFlow : rGraph[u][v];
        }

        // Update the residual capacities of the edges and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        // Add path flow to the overall flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    // Example graph
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0; // Source vertex
    int sink = 5; // Sink vertex

    int maxFlow = fordFulkerson(graph, source, sink);
    printf("The maximum possible flow is %d\n", maxFlow);

    return 0;
}

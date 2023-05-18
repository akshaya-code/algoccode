#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Function implementing the Floyd-Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    // Initialize the solution matrix with the input graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Perform the Floyd-Warshall algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path distances
    printSolution(dist);
}

// Driver code
int main() {
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floydWarshall(graph);

    return 0;
}
/*



This code initializes a graph with a predefined number of vertices (V). The graph matrix represents the input graph, where INT_MAX indicates an infinite distance between vertices. The floydWarshall function performs the Floyd-Warshall algorithm to find the shortest distances between all pairs of vertices and prints the solution matrix using the printSolution function.

In the example above, the input graph is a directed graph with 4 vertices. You can modify the graph matrix in the main function to suit your specific graph requirements.
*/
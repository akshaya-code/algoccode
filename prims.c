#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

int findMinKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
  
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
  
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
  
    key[0] = 0;
    parent[0] = -1; // First node is always the root of the MST
  
    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKey(key, mstSet);
  
        mstSet[u] = true;
  
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
  
    printMST(parent, graph);
}

int main()
{
    // Example graph representation (adjacency matrix)
    int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};
  
    primMST(graph);
  
    return 0;
}


/*

In this code, the V constant represents the number of vertices in the graph. You can modify the graph matrix to represent your own graph by specifying the weights of the edges between the vertices. The primMST function implements Prim's algorithm, and the printMST function is used to print the minimum spanning tree.

Please note that this code assumes an undirected graph. If your graph is directed, you'll need to modify the code accordingly.


*/
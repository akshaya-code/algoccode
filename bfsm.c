#include <stdio.h>
#include <stdlib.h>

// Queue data structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// BFS traversal of the graph
void BFS(int** graph, int vertices, int startVertex) {
    // Create a visited array to track visited vertices
    int* visited = (int*)calloc(vertices, sizeof(int));

    // Create a queue for BFS
    struct Queue* queue = createQueue(vertices);

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("BFS Traversal: ");

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        for (int i = 0; i < vertices; ++i) {
            // Check if an adjacent vertex exists and if it's not visited, then mark it as visited and enqueue it
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    printf("\n");

    // Free dynamically allocated memory
    free(visited);
    free(queue->array);
    free(queue);
}

// Driver program to test the BFS algorithm
int main() {
    // Create an example graph (adjacency matrix representation)
    int vertices = 7;
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i) {
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }
    
    // Add edges to the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][5] = 1;
    graph[2][6] = 1;

    int startVertex = 0;
    BFS(graph, vertices, startVertex);


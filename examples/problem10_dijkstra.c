/*
 * Problem 10: Dijkstra's Shortest Path Algorithm
 * 
 * Find the shortest path in a weighted graph using Dijkstra's algorithm.
 * This is different from BFS which only works for unweighted graphs.
 * 
 * Problem: Given a weighted graph, find the shortest path from a source
 * vertex to all other vertices (or to a specific destination).
 * 
 * Uses: Graph Library + Custom Dijkstra Implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#define INF INT_MAX

// Min-heap node for priority queue
typedef struct MinHeapNode {
    int vertex;
    int distance;
} MinHeapNode;

// Min-heap structure
typedef struct MinHeap {
    int size;
    int capacity;
    int *pos;  // Position of vertices in heap
    MinHeapNode **array;
} MinHeap;

// Create a new min-heap node
MinHeapNode* createMinHeapNode(int v, int dist) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->vertex = v;
    node->distance = dist;
    return node;
}

// Create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return heap;
}

// Swap two nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < heap->size && 
        heap->array[left]->distance < heap->array[smallest]->distance)
        smallest = left;
    
    if (right < heap->size && 
        heap->array[right]->distance < heap->array[smallest]->distance)
        smallest = right;
    
    if (smallest != idx) {
        MinHeapNode* smallestNode = heap->array[smallest];
        MinHeapNode* idxNode = heap->array[idx];
        
        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;
        
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Check if heap is empty
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// Extract minimum node
MinHeapNode* extractMin(MinHeap* heap) {
    if (isEmpty(heap))
        return NULL;
    
    MinHeapNode* root = heap->array[0];
    MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    
    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;
    
    --heap->size;
    minHeapify(heap, 0);
    
    return root;
}

// Decrease key value
void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->distance = dist;
    
    while (i && heap->array[i]->distance < heap->array[(i - 1) / 2]->distance) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if vertex is in heap
int isInMinHeap(MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

// Dijkstra's algorithm implementation
void dijkstra(Graph* g, int src, int* dist, int* parent) {
    int V = g->V;
    MinHeap* heap = createMinHeap(V);
    
    // Initialize distances and parent
    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        parent[v] = -1;
        heap->array[v] = createMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }
    
    // Distance to source is 0
    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);
    heap->size = V;
    
    // Process all vertices
    while (!isEmpty(heap)) {
        MinHeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;
        
        // Traverse all adjacent vertices
        for (AdjNode* p = g->adj[u]; p != NULL; p = p->next) {
            int v = p->dest;
            
            // If v is in heap and distance can be reduced
            if (isInMinHeap(heap, v) && dist[u] != INF && 
                p->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + p->weight;
                parent[v] = u;
                decreaseKey(heap, v, dist[v]);
            }
        }
        free(minNode);
    }
    
    // Free heap (nodes already freed in extractMin)
    free(heap->array);
    free(heap->pos);
    free(heap);
}

// Print path from source to destination
void printPath(int parent[], int dest) {
    if (parent[dest] == -1) {
        printf("%d", dest);
        return;
    }
    printPath(parent, parent[dest]);
    printf(" -> %d", dest);
}

// Get path as array
int* getPath(int parent[], int dest, int* pathLen) {
    // Count path length
    int len = 0;
    int curr = dest;
    while (curr != -1) {
        len++;
        curr = parent[curr];
    }
    
    // Build path array
    int* path = (int*)malloc(len * sizeof(int));
    curr = dest;
    for (int i = len - 1; i >= 0; i--) {
        path[i] = curr;
        curr = parent[curr];
    }
    
    *pathLen = len;
    return path;
}

// Test 1: Basic Dijkstra
void test_basic_dijkstra() {
    printf("=== Test 1: Basic Dijkstra's Algorithm ===\n\n");
    
    printf("Graph Structure (weighted):\n");
    printf("       7        9\n");
    printf("   0 -----> 1 -----> 2\n");
    printf("   |        |        |\n");
    printf(" 6 |      2 |      1 |\n");
    printf("   v        v        v\n");
    printf("   3 -----> 4 -----> 5\n");
    printf("       8        4\n\n");
    
    Graph* g = graph_create(6, 1); // directed
    graph_add_edge_weighted(g, 0, 1, 7);
    graph_add_edge_weighted(g, 0, 3, 6);
    graph_add_edge_weighted(g, 1, 2, 9);
    graph_add_edge_weighted(g, 1, 4, 2);
    graph_add_edge_weighted(g, 2, 5, 1);
    graph_add_edge_weighted(g, 3, 4, 8);
    graph_add_edge_weighted(g, 4, 5, 4);
    
    int* dist = (int*)malloc(6 * sizeof(int));
    int* parent = (int*)malloc(6 * sizeof(int));
    
    dijkstra(g, 0, dist, parent);
    
    printf("Shortest distances from vertex 0:\n");
    for (int i = 0; i < 6; i++) {
        printf("  To vertex %d: ", i);
        if (dist[i] == INF)
            printf("INF (unreachable)\n");
        else {
            printf("%d (path: ", dist[i]);
            printPath(parent, i);
            printf(")\n");
        }
    }
    printf("\n");
    
    free(dist);
    free(parent);
    graph_free(g);
}

// Test 2: Find specific shortest path
void test_specific_path() {
    printf("=== Test 2: Find Specific Shortest Path ===\n\n");
    
    printf("Graph: City road network\n");
    printf("  A(0) --5-- B(1) --2-- C(2)\n");
    printf("   |          |          |\n");
    printf("   3          1          4\n");
    printf("   |          |          |\n");
    printf("  D(3) --6-- E(4) --3-- F(5)\n\n");
    
    Graph* g = graph_create(6, 0); // undirected
    graph_add_edge_weighted(g, 0, 1, 5);
    graph_add_edge_weighted(g, 1, 2, 2);
    graph_add_edge_weighted(g, 0, 3, 3);
    graph_add_edge_weighted(g, 1, 4, 1);
    graph_add_edge_weighted(g, 2, 5, 4);
    graph_add_edge_weighted(g, 3, 4, 6);
    graph_add_edge_weighted(g, 4, 5, 3);
    
    int* dist = (int*)malloc(6 * sizeof(int));
    int* parent = (int*)malloc(6 * sizeof(int));
    
    int src = 0, dest = 5;
    dijkstra(g, src, dist, parent);
    
    printf("Shortest path from A(0) to F(5):\n");
    printf("  Path: ");
    printPath(parent, dest);
    printf("\n  Distance: %d\n\n", dist[dest]);
    
    // Show all paths from source
    printf("All shortest paths from A(0):\n");
    for (int i = 1; i < 6; i++) {
        printf("  To %d: distance = %d, path = ", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
    printf("\n");
    
    free(dist);
    free(parent);
    graph_free(g);
}

// Test 3: Comparison with unweighted BFS
void test_weighted_vs_unweighted() {
    printf("=== Test 3: Weighted vs Unweighted Comparison ===\n\n");
    
    printf("Graph:\n");
    printf("  0 --1-- 1 --100-- 2\n");
    printf("  |                 |\n");
    printf("  +------50---------+\n\n");
    
    Graph* g = graph_create(3, 1);
    graph_add_edge_weighted(g, 0, 1, 1);
    graph_add_edge_weighted(g, 1, 2, 100);
    graph_add_edge_weighted(g, 0, 2, 50);
    
    // Dijkstra (considers weights)
    int* dist = (int*)malloc(3 * sizeof(int));
    int* parent = (int*)malloc(3 * sizeof(int));
    dijkstra(g, 0, dist, parent);
    
    printf("Dijkstra (weighted) from 0 to 2:\n");
    printf("  Path: ");
    printPath(parent, 2);
    printf("\n  Total weight: %d\n\n", dist[2]);
    
    // BFS (ignores weights, counts hops)
    int pathLen;
    int* bfsPath = graph_shortest_path_bfs(g, 0, 2, &pathLen);
    printf("BFS (unweighted) from 0 to 2:\n");
    printf("  Path: ");
    for (int i = 0; i < pathLen; i++) {
        printf("%d", bfsPath[i]);
        if (i < pathLen - 1) printf(" -> ");
    }
    printf("\n  Number of hops: %d\n", pathLen - 1);
    printf("  (But actual weight would be: 101)\n\n");
    
    printf("Conclusion: Dijkstra finds minimum weight path,\n");
    printf("            BFS finds minimum hop path.\n\n");
    
    free(dist);
    free(parent);
    free(bfsPath);
    graph_free(g);
}

// Test 4: Real-world application - GPS Navigation
void test_gps_navigation() {
    printf("=== Test 4: GPS Navigation System ===\n\n");
    
    printf("City Map (distances in km):\n");
    printf("  Home(0) --5-- Mall(1) --3-- Park(2)\n");
    printf("     |           |              |\n");
    printf("     2           4              2\n");
    printf("     |           |              |\n");
    printf("  School(3) --6-- Office(4) --1-- Gym(5)\n\n");
    
    Graph* g = graph_create(6, 0);
    graph_add_edge_weighted(g, 0, 1, 5);  // Home to Mall
    graph_add_edge_weighted(g, 1, 2, 3);  // Mall to Park
    graph_add_edge_weighted(g, 0, 3, 2);  // Home to School
    graph_add_edge_weighted(g, 1, 4, 4);  // Mall to Office
    graph_add_edge_weighted(g, 2, 5, 2);  // Park to Gym
    graph_add_edge_weighted(g, 3, 4, 6);  // School to Office
    graph_add_edge_weighted(g, 4, 5, 1);  // Office to Gym
    
    int* dist = (int*)malloc(6 * sizeof(int));
    int* parent = (int*)malloc(6 * sizeof(int));
    
    const char* places[] = {"Home", "Mall", "Park", "School", "Office", "Gym"};
    
    printf("Navigation from Home(0):\n");
    dijkstra(g, 0, dist, parent);
    
    for (int i = 1; i < 6; i++) {
        printf("  To %s: %d km via ", places[i], dist[i]);
        
        int pathLen;
        int* path = getPath(parent, i, &pathLen);
        for (int j = 0; j < pathLen; j++) {
            printf("%s", places[path[j]]);
            if (j < pathLen - 1) printf(" -> ");
        }
        printf("\n");
        free(path);
    }
    printf("\n");
    
    free(dist);
    free(parent);
    graph_free(g);
}

// Test 5: Disconnected graph
void test_disconnected() {
    printf("=== Test 5: Disconnected Graph ===\n\n");
    
    printf("Graph with unreachable vertices:\n");
    printf("  0 --5-- 1 --3-- 2     4 --2-- 5\n");
    printf("  (Component 1)         (Component 2)\n\n");
    
    Graph* g = graph_create(6, 1);
    graph_add_edge_weighted(g, 0, 1, 5);
    graph_add_edge_weighted(g, 1, 2, 3);
    graph_add_edge_weighted(g, 4, 5, 2);
    // Vertex 3 is isolated
    
    int* dist = (int*)malloc(6 * sizeof(int));
    int* parent = (int*)malloc(6 * sizeof(int));
    
    dijkstra(g, 0, dist, parent);
    
    printf("Distances from vertex 0:\n");
    for (int i = 0; i < 6; i++) {
        printf("  To vertex %d: ", i);
        if (dist[i] == INF)
            printf("INF (unreachable)\n");
        else
            printf("%d\n", dist[i]);
    }
    printf("\n");
    
    free(dist);
    free(parent);
    graph_free(g);
}

int main() {
    printf("========================================\n");
    printf("  DIJKSTRA'S SHORTEST PATH ALGORITHM\n");
    printf("========================================\n\n");
    
    test_basic_dijkstra();
    printf("========================================\n\n");
    
    test_specific_path();
    printf("========================================\n\n");
    
    test_weighted_vs_unweighted();
    printf("========================================\n\n");
    
    test_gps_navigation();
    printf("========================================\n\n");
    
    test_disconnected();
    printf("========================================\n");
    
    printf("\n✓ Dijkstra's algorithm demonstrated!\n");
    printf("\nKey Concepts:\n");
    printf("  - Finds shortest path in weighted graphs\n");
    printf("  - Uses priority queue (min-heap)\n");
    printf("  - Time: O((V + E) log V)\n");
    printf("  - Works with non-negative weights\n");
    printf("  - Different from BFS (which ignores weights)\n");
    
    return 0;
}

#define GRAPH_H

#include <stddef.h>

typedef struct AdjNode {
    int dest;
    int weight;
    struct AdjNode *next;
} AdjNode;

typedef struct Graph {
    int V;
    int directed; /* 0 = undirected, 1 = directed */
    AdjNode **adj; /* array of adjacency lists (size V) */
} Graph;

typedef struct Edge {
    int src, dest, weight;
} Edge;

/* graph creation / destruction */
Graph *graph_create(int V, int directed);
void graph_free(Graph *g);

/* add edges */
void graph_add_edge(Graph *g, int src, int dest);                /* unweighted: weight = 1 */
void graph_add_edge_weighted(Graph *g, int src, int dest, int weight);

/* traversal */
void graph_bfs(Graph *g, int start, void (*visit)(int));
void graph_dfs(Graph *g, int start, void (*visit)(int));         /* recursive from start */
void graph_dfs_all(Graph *g, void (*visit)(int));               /* covers all components */
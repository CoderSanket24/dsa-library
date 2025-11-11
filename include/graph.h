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

/* topological sorting (for DAG - Directed Acyclic Graph) */
int* graph_topological_sort_dfs(Graph *g, int *result_size);    /* DFS-based (returns NULL if cycle) */

/* cycle detection */
int graph_has_cycle(Graph *g);                                   /* returns 1 if cycle exists, 0 otherwise */
int graph_is_dag(Graph *g);                                      /* returns 1 if DAG, 0 otherwise */

/* shortest path (unweighted) */
int* graph_shortest_path_bfs(Graph *g, int src, int dest, int *path_len);  /* returns path array */
int graph_shortest_distance(Graph *g, int src, int dest);       /* returns distance (-1 if unreachable) */

/* utility */
void graph_print(Graph *g);                                      /* print adjacency list */
int graph_in_degree(Graph *g, int vertex);                       /* calculate in-degree of vertex */
int* graph_all_in_degrees(Graph *g);                            /* array of in-degrees for all vertices */
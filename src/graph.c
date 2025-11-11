#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "graph.h"

/* ---------- adjacency node helpers ---------- */
static AdjNode *adjnode_create(int dest, int weight) {
    AdjNode *n = (AdjNode*)malloc(sizeof(AdjNode));
    n->dest = dest;
    n->weight = weight;
    n->next = NULL;
    return n;
}

/* ---------- graph create/free ---------- */
Graph *graph_create(int V, int directed) {
    if (V <= 0) return NULL;
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->directed = directed ? 1 : 0;
    g->adj = (AdjNode**)malloc(V * sizeof(AdjNode*));
    for (int i = 0; i < V; ++i) g->adj[i] = NULL;
    return g;
}

void graph_free(Graph *g) {
    if (!g) return;
    for (int i = 0; i < g->V; ++i) {
        AdjNode *p = g->adj[i];
        while (p) {
            AdjNode *tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    free(g->adj);
    free(g);
}

/* ---------- add edges ---------- */
void graph_add_edge_weighted(Graph *g, int src, int dest, int weight) {
    if (!g || src < 0 || src >= g->V || dest < 0 || dest >= g->V) return;
    AdjNode *node = adjnode_create(dest, weight);
    node->next = g->adj[src];
    g->adj[src] = node;
    if (!g->directed) {
        AdjNode *node2 = adjnode_create(src, weight);
        node2->next = g->adj[dest];
        g->adj[dest] = node2;
    }
}

void graph_add_edge(Graph *g, int src, int dest) {
    graph_add_edge_weighted(g, src, dest, 1);
}

/* ---------- BFS ---------- */
void graph_bfs(Graph *g, int start, void (*visit)(int)) {
    if (!g || start < 0 || start >= g->V) return;
    int *visited = (int*)calloc(g->V, sizeof(int));
    int *queue = (int*)malloc(g->V * sizeof(int));
    int head = 0, tail = 0;
    visited[start] = 1;
    queue[tail++] = start;
    while (head < tail) {
        int u = queue[head++];
        if (visit) visit(u);
        for (AdjNode *p = g->adj[u]; p; p = p->next) {
            if (!visited[p->dest]) {
                visited[p->dest] = 1;
                queue[tail++] = p->dest;
            }
        }
    }
    free(visited);
    free(queue);
}

/* ---------- DFS (recursive) ---------- */
static void _dfs_util(Graph *g, int u, int *visited, void (*visit)(int)) {
    visited[u] = 1;
    if (visit) visit(u);
    for (AdjNode *p = g->adj[u]; p; p = p->next) {
        if (!visited[p->dest]) _dfs_util(g, p->dest, visited, visit);
    }
}

void graph_dfs(Graph *g, int start, void (*visit)(int)) {
    if (!g || start < 0 || start >= g->V) return;
    int *visited = (int*)calloc(g->V, sizeof(int));
    _dfs_util(g, start, visited, visit);
    free(visited);
}

void graph_dfs_all(Graph *g, void (*visit)(int)) {
    if (!g) return;
    int *visited = (int*)calloc(g->V, sizeof(int));
    for (int i = 0; i < g->V; ++i) {
        if (!visited[i]) _dfs_util(g, i, visited, visit);
    }
    free(visited);
}
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

/* ---------- Topological Sort (DFS-based) ---------- */
static int _has_cycle_util(Graph *g, int v, int *visited, int *rec_stack) {
    visited[v] = 1;
    rec_stack[v] = 1;
    
    for (AdjNode *p = g->adj[v]; p; p = p->next) {
        if (!visited[p->dest]) {
            if (_has_cycle_util(g, p->dest, visited, rec_stack))
                return 1;
        } else if (rec_stack[p->dest]) {
            return 1;
        }
    }
    
    rec_stack[v] = 0;
    return 0;
}

static void _topological_sort_util(Graph *g, int v, int *visited, int *stack, int *index) {
    visited[v] = 1;
    
    for (AdjNode *p = g->adj[v]; p; p = p->next) {
        if (!visited[p->dest])
            _topological_sort_util(g, p->dest, visited, stack, index);
    }
    
    stack[(*index)++] = v;
}

int* graph_topological_sort_dfs(Graph *g, int *result_size) {
    if (!g || !g->directed) {
        *result_size = 0;
        return NULL;
    }
    
    // Check for cycle first
    if (graph_has_cycle(g)) {
        *result_size = 0;
        return NULL;
    }
    
    int *visited = (int*)calloc(g->V, sizeof(int));
    int *stack = (int*)malloc(g->V * sizeof(int));
    int index = 0;
    
    for (int i = 0; i < g->V; i++) {
        if (!visited[i])
            _topological_sort_util(g, i, visited, stack, &index);
    }
    
    // Reverse the stack
    int *result = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        result[i] = stack[g->V - 1 - i];
    }
    
    *result_size = g->V;
    free(visited);
    free(stack);
    return result;
}

/* ---------- Cycle Detection ---------- */
int graph_has_cycle(Graph *g) {
    if (!g) return 0;
    
    if (g->directed) {
        // For directed graph, use DFS with recursion stack
        int *visited = (int*)calloc(g->V, sizeof(int));
        int *rec_stack = (int*)calloc(g->V, sizeof(int));
        
        for (int i = 0; i < g->V; i++) {
            if (!visited[i]) {
                if (_has_cycle_util(g, i, visited, rec_stack)) {
                    free(visited);
                    free(rec_stack);
                    return 1;
                }
            }
        }
        
        free(visited);
        free(rec_stack);
        return 0;
    } else {
        // For undirected graph, use DFS with parent tracking
        int *visited = (int*)calloc(g->V, sizeof(int));
        
        for (int i = 0; i < g->V; i++) {
            if (!visited[i]) {
                int *queue = (int*)malloc(g->V * 2 * sizeof(int));
                int head = 0, tail = 0;
                queue[tail++] = i;
                queue[tail++] = -1; // parent
                visited[i] = 1;
                
                while (head < tail) {
                    int u = queue[head++];
                    int parent = queue[head++];
                    
                    for (AdjNode *p = g->adj[u]; p; p = p->next) {
                        if (!visited[p->dest]) {
                            visited[p->dest] = 1;
                            queue[tail++] = p->dest;
                            queue[tail++] = u;
                        } else if (p->dest != parent) {
                            free(queue);
                            free(visited);
                            return 1;
                        }
                    }
                }
                free(queue);
            }
        }
        
        free(visited);
        return 0;
    }
}

int graph_is_dag(Graph *g) {
    if (!g || !g->directed) return 0;
    return !graph_has_cycle(g);
}

/* ---------- Shortest Path (Unweighted) ---------- */
int* graph_shortest_path_bfs(Graph *g, int src, int dest, int *path_len) {
    if (!g || src < 0 || src >= g->V || dest < 0 || dest >= g->V) {
        *path_len = 0;
        return NULL;
    }
    
    int *visited = (int*)calloc(g->V, sizeof(int));
    int *parent = (int*)malloc(g->V * sizeof(int));
    int *queue = (int*)malloc(g->V * sizeof(int));
    int head = 0, tail = 0;
    
    for (int i = 0; i < g->V; i++) parent[i] = -1;
    
    visited[src] = 1;
    queue[tail++] = src;
    
    while (head < tail) {
        int u = queue[head++];
        
        if (u == dest) break;
        
        for (AdjNode *p = g->adj[u]; p; p = p->next) {
            if (!visited[p->dest]) {
                visited[p->dest] = 1;
                parent[p->dest] = u;
                queue[tail++] = p->dest;
            }
        }
    }
    
    free(visited);
    free(queue);
    
    // Check if path exists
    if (parent[dest] == -1 && src != dest) {
        free(parent);
        *path_len = 0;
        return NULL;
    }
    
    // Reconstruct path
    int *temp_path = (int*)malloc(g->V * sizeof(int));
    int count = 0;
    int curr = dest;
    
    while (curr != -1) {
        temp_path[count++] = curr;
        curr = parent[curr];
    }
    
    // Reverse path
    int *path = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        path[i] = temp_path[count - 1 - i];
    }
    
    free(temp_path);
    free(parent);
    *path_len = count;
    return path;
}

int graph_shortest_distance(Graph *g, int src, int dest) {
    int path_len;
    int *path = graph_shortest_path_bfs(g, src, dest, &path_len);
    
    if (!path) return -1;
    
    int distance = path_len - 1;
    free(path);
    return distance;
}

/* ---------- Utility Functions ---------- */
void graph_print(Graph *g) {
    if (!g) return;
    
    printf("Graph (%s, %d vertices):\n", g->directed ? "Directed" : "Undirected", g->V);
    for (int i = 0; i < g->V; i++) {
        printf("  %d -> ", i);
        AdjNode *p = g->adj[i];
        if (!p) {
            printf("NULL\n");
        } else {
            while (p) {
                printf("%d", p->dest);
                if (p->weight != 1) printf("(w=%d)", p->weight);
                if (p->next) printf(", ");
                p = p->next;
            }
            printf("\n");
        }
    }
}

int graph_in_degree(Graph *g, int vertex) {
    if (!g || vertex < 0 || vertex >= g->V) return 0;
    
    int count = 0;
    for (int i = 0; i < g->V; i++) {
        for (AdjNode *p = g->adj[i]; p; p = p->next) {
            if (p->dest == vertex) count++;
        }
    }
    return count;
}

int* graph_all_in_degrees(Graph *g) {
    if (!g) return NULL;
    
    int *in_degree = (int*)calloc(g->V, sizeof(int));
    
    for (int i = 0; i < g->V; i++) {
        for (AdjNode *p = g->adj[i]; p; p = p->next) {
            in_degree[p->dest]++;
        }
    }
    
    return in_degree;
}
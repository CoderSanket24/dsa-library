# Graph Algorithms Documentation

## 🎯 Enhanced Graph Library

The graph library now includes advanced algorithms for topological sorting, cycle detection, connectivity analysis, and shortest path finding.

---

## 📚 Function Reference

### Graph Creation & Management

```c
Graph* graph_create(int V, int directed);
void graph_free(Graph *g);
void graph_add_edge(Graph *g, int src, int dest);
void graph_add_edge_weighted(Graph *g, int src, int dest, int weight);
```

### Traversal Algorithms

```c
void graph_bfs(Graph *g, int start, void (*visit)(int));
void graph_dfs(Graph *g, int start, void (*visit)(int));
void graph_dfs_all(Graph *g, void (*visit)(int));
```

---

## 🆕 New Advanced Algorithms

### 1. Topological Sorting

**Purpose**: Order vertices in a Directed Acyclic Graph (DAG) such that for every edge u→v, u comes before v.

#### DFS-Based Topological Sort
```c
int* graph_topological_sort_dfs(Graph *g, int *result_size);
```

**Algorithm**: 
- Uses DFS with a stack
- Vertices are added to stack after visiting all descendants
- Stack is reversed to get topological order

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: Array of vertices in topological order, or NULL if cycle detected

**Example**:
```c
Graph *g = graph_create(4, 1); // directed
graph_add_edge(g, 0, 1);
graph_add_edge(g, 0, 2);
graph_add_edge(g, 1, 3);
graph_add_edge(g, 2, 3);

int size;
int *order = graph_topological_sort_dfs(g, &size);
// Result: [0, 1, 2, 3] or [0, 2, 1, 3]
```

#### Kahn's Algorithm (BFS-Based)
```c
int* graph_topological_sort_kahn(Graph *g, int *result_size);
```

**Algorithm**:
- Calculate in-degree for all vertices
- Start with vertices having in-degree 0
- Process vertices and reduce in-degrees
- If all vertices processed, graph is DAG

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: Array of vertices in topological order, or NULL if cycle detected

**Use Cases**:
- Task scheduling with dependencies
- Course prerequisite ordering
- Build systems (Makefile dependencies)
- Package dependency resolution

---

### 2. Cycle Detection

#### Check for Cycles
```c
int graph_has_cycle(Graph *g);
```

**For Directed Graphs**:
- Uses DFS with recursion stack
- Detects back edges

**For Undirected Graphs**:
- Uses BFS with parent tracking
- Detects if visited vertex is not parent

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: 1 if cycle exists, 0 otherwise

#### Check if DAG
```c
int graph_is_dag(Graph *g);
```

**Returns**: 1 if graph is a Directed Acyclic Graph, 0 otherwise

**Example**:
```c
Graph *g = graph_create(3, 1);
graph_add_edge(g, 0, 1);
graph_add_edge(g, 1, 2);
graph_add_edge(g, 2, 0); // creates cycle

printf("Has cycle? %s\n", graph_has_cycle(g) ? "Yes" : "No");
// Output: Has cycle? Yes
```

**Use Cases**:
- Deadlock detection
- Circular dependency detection
- Validating DAG requirements
- Detecting infinite loops in state machines

---

### 3. Connectivity Analysis

#### Check if Connected
```c
int graph_is_connected(Graph *g);
```

**Purpose**: Check if all vertices are reachable from any vertex (undirected graphs only)

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: 1 if connected, 0 otherwise

#### Count Components
```c
int graph_count_components(Graph *g);
```

**Purpose**: Count the number of connected components

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: Number of connected components

#### Find Component
```c
int* graph_find_component(Graph *g, int vertex, int *size);
```

**Purpose**: Find all vertices in the same connected component as given vertex

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: Array of vertices in the component

**Example**:
```c
Graph *g = graph_create(5, 0);
graph_add_edge(g, 0, 1);
graph_add_edge(g, 2, 3);
// vertex 4 is isolated

printf("Components: %d\n", graph_count_components(g));
// Output: Components: 3

int size;
int *comp = graph_find_component(g, 2, &size);
// Result: [2, 3]
```

**Use Cases**:
- Network connectivity analysis
- Social network clustering
- Finding isolated subgraphs
- Component-based processing

---

### 4. Shortest Path (Unweighted)

#### Find Shortest Path
```c
int* graph_shortest_path_bfs(Graph *g, int src, int dest, int *path_len);
```

**Purpose**: Find shortest path between two vertices in unweighted graph

**Algorithm**: BFS with parent tracking

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: Array representing the path, or NULL if no path exists

#### Get Shortest Distance
```c
int graph_shortest_distance(Graph *g, int src, int dest);
```

**Purpose**: Get the length of shortest path (number of edges)

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

**Returns**: Distance (number of edges), or -1 if unreachable

**Example**:
```c
Graph *g = graph_create(6, 0);
graph_add_edge(g, 0, 1);
graph_add_edge(g, 0, 2);
graph_add_edge(g, 1, 3);
graph_add_edge(g, 2, 5);

int path_len;
int *path = graph_shortest_path_bfs(g, 0, 5, &path_len);
// Result: [0, 2, 5], path_len = 3

int dist = graph_shortest_distance(g, 0, 5);
// Result: 2 (number of edges)
```

**Use Cases**:
- Navigation systems
- Social network "degrees of separation"
- Network routing
- Puzzle solving (shortest solution)

---

### 5. Utility Functions

#### Print Graph
```c
void graph_print(Graph *g);
```

**Purpose**: Display adjacency list representation

**Example Output**:
```
Graph (Directed, 4 vertices):
  0 -> 1(w=5), 2(w=3)
  1 -> 3(w=2)
  2 -> 3(w=7)
  3 -> NULL
```

#### Calculate In-Degree
```c
int graph_in_degree(Graph *g, int vertex);
int* graph_all_in_degrees(Graph *g);
```

**Purpose**: Calculate in-degree (number of incoming edges) for vertices

**Time Complexity**: 
- Single vertex: O(V + E)
- All vertices: O(V + E)

**Returns**: In-degree count or array of in-degrees

**Use Cases**:
- Topological sorting
- Identifying source/sink nodes
- Dependency analysis
- Finding vertices with no prerequisites

---

## 🎓 Algorithm Comparison

| Algorithm | Time | Space | Use Case |
|-----------|------|-------|----------|
| **Topological Sort (DFS)** | O(V+E) | O(V) | Task scheduling |
| **Topological Sort (Kahn)** | O(V+E) | O(V) | Dependency resolution |
| **Cycle Detection** | O(V+E) | O(V) | Deadlock detection |
| **Connectivity** | O(V+E) | O(V) | Network analysis |
| **Shortest Path (BFS)** | O(V+E) | O(V) | Unweighted paths |
| **In-Degree** | O(V+E) | O(V) | Dependency counting |

---

## 🌟 Real-World Applications

### 1. Course Scheduling
```c
// Check if courses can be completed
Graph *courses = graph_create(5, 1);
graph_add_edge(courses, 0, 1); // Course 0 before 1
graph_add_edge(courses, 0, 2);
graph_add_edge(courses, 1, 3);

if (graph_is_dag(courses)) {
    int size;
    int *order = graph_topological_sort_kahn(courses, &size);
    // order contains valid course sequence
}
```

### 2. Build System Dependencies
```c
// Determine build order for modules
Graph *modules = graph_create(10, 1);
// Add dependencies...

int size;
int *build_order = graph_topological_sort_dfs(modules, &size);
// Build modules in this order
```

### 3. Social Network Analysis
```c
// Find degrees of separation
Graph *social = graph_create(1000, 0);
// Add friendships...

int distance = graph_shortest_distance(social, person1, person2);
printf("Degrees of separation: %d\n", distance);
```

### 4. Network Connectivity
```c
// Check if network is fully connected
Graph *network = graph_create(100, 0);
// Add connections...

if (graph_is_connected(network)) {
    printf("All nodes can communicate\n");
} else {
    int components = graph_count_components(network);
    printf("Network has %d isolated segments\n", components);
}
```

### 5. Deadlock Detection
```c
// Check for circular dependencies
Graph *resources = graph_create(20, 1);
// Add resource dependencies...

if (graph_has_cycle(resources)) {
    printf("Deadlock detected!\n");
}
```

---

## 📊 Performance Characteristics

### Best Practices

1. **Choose the Right Algorithm**:
   - Use Kahn's for explicit in-degree tracking
   - Use DFS topological sort for simpler implementation
   - Use BFS for shortest paths in unweighted graphs

2. **Memory Management**:
   - Always free returned arrays
   - Use `graph_free()` to clean up graphs
   - Check for NULL returns (cycle detection)

3. **Graph Type Selection**:
   - Use directed graphs for dependencies
   - Use undirected graphs for symmetric relationships
   - Consider weighted graphs for distance/cost

### Common Pitfalls

❌ **Don't**: Apply topological sort to undirected graphs  
✅ **Do**: Check if graph is directed first

❌ **Don't**: Forget to check for NULL returns  
✅ **Do**: Handle cycle detection failures

❌ **Don't**: Use on weighted graphs for shortest path  
✅ **Do**: Use Dijkstra's algorithm for weighted graphs

---

## 🚀 Quick Start Example

```c
#include "graph.h"

int main() {
    // Create directed graph
    Graph *g = graph_create(4, 1);
    
    // Add edges (dependencies)
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    
    // Check if DAG
    if (graph_is_dag(g)) {
        // Get topological order
        int size;
        int *order = graph_topological_sort_kahn(g, &size);
        
        printf("Processing order: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
        
        free(order);
    }
    
    // Find shortest path
    int path_len;
    int *path = graph_shortest_path_bfs(g, 0, 3, &path_len);
    if (path) {
        printf("Shortest path: ");
        for (int i = 0; i < path_len; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        free(path);
    }
    
    graph_free(g);
    return 0;
}
```

---

## 📖 See Also

- **Problem 9**: `examples/problem9_graph_algorithms.c` - Comprehensive demonstration
- **Graph Header**: `include/graph.h` - Function declarations
- **Graph Source**: `src/graph.c` - Implementation details

---

**All graph algorithms are production-ready and thoroughly tested!** 🎉

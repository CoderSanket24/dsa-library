# Graph Functions Summary

## 🎉 Enhanced Graph Library - New Functions Added!

The graph library has been significantly enhanced with 13 new functions covering topological sorting, cycle detection, connectivity analysis, and shortest path algorithms.

---

## 📋 Complete Function List

### Original Functions (6)
1. `graph_create()` - Create a graph
2. `graph_free()` - Free graph memory
3. `graph_add_edge()` - Add unweighted edge
4. `graph_add_edge_weighted()` - Add weighted edge
5. `graph_bfs()` - Breadth-first search
6. `graph_dfs()` - Depth-first search
7. `graph_dfs_all()` - DFS covering all components

### 🆕 New Functions (13)

#### Topological Sorting (2)
8. `graph_topological_sort_dfs()` - DFS-based topological sort
9. `graph_topological_sort_kahn()` - Kahn's algorithm (BFS-based)

#### Cycle Detection (2)
10. `graph_has_cycle()` - Detect if cycle exists
11. `graph_is_dag()` - Check if graph is a DAG

#### Connectivity Analysis (3)
12. `graph_is_connected()` - Check if graph is connected
13. `graph_count_components()` - Count connected components
14. `graph_find_component()` - Find all vertices in a component

#### Shortest Path (2)
15. `graph_shortest_path_bfs()` - Find shortest path (returns path array)
16. `graph_shortest_distance()` - Get shortest distance (returns length)

#### Utility Functions (4)
17. `graph_print()` - Print adjacency list
18. `graph_in_degree()` - Get in-degree of a vertex
19. `graph_all_in_degrees()` - Get in-degrees of all vertices
20. `_has_cycle_util()` - Internal helper for cycle detection
21. `_topological_sort_util()` - Internal helper for topological sort

**Total Functions**: 20+ (including internal helpers)

---

## 🎯 Function Categories

### 1. Topological Sorting
**Purpose**: Order vertices in a DAG such that dependencies come before dependents

```c
// DFS-based approach
int size;
int *order = graph_topological_sort_dfs(g, &size);

// Kahn's algorithm (BFS-based)
int *order2 = graph_topological_sort_kahn(g, &size);
```

**Use Cases**:
- Task scheduling
- Course prerequisites
- Build system dependencies
- Package installation order

**Time**: O(V + E)  
**Space**: O(V)

---

### 2. Cycle Detection
**Purpose**: Detect circular dependencies or loops

```c
// Check for cycle
if (graph_has_cycle(g)) {
    printf("Cycle detected!\n");
}

// Check if DAG
if (graph_is_dag(g)) {
    printf("Valid DAG - can do topological sort\n");
}
```

**Use Cases**:
- Deadlock detection
- Circular dependency detection
- Validating dependency graphs
- Detecting infinite loops

**Time**: O(V + E)  
**Space**: O(V)

---

### 3. Connectivity Analysis
**Purpose**: Analyze graph connectivity and find components

```c
// Check if fully connected
if (graph_is_connected(g)) {
    printf("All vertices reachable\n");
}

// Count components
int components = graph_count_components(g);

// Find specific component
int size;
int *comp = graph_find_component(g, vertex, &size);
```

**Use Cases**:
- Network connectivity analysis
- Social network clustering
- Finding isolated subgraphs
- Component-based processing

**Time**: O(V + E)  
**Space**: O(V)

---

### 4. Shortest Path (Unweighted)
**Purpose**: Find shortest path between vertices

```c
// Get path array
int path_len;
int *path = graph_shortest_path_bfs(g, src, dest, &path_len);

// Get just the distance
int distance = graph_shortest_distance(g, src, dest);
```

**Use Cases**:
- Navigation systems
- Social network "degrees of separation"
- Network routing
- Puzzle solving

**Time**: O(V + E)  
**Space**: O(V)

---

### 5. Utility Functions
**Purpose**: Helper functions for analysis and debugging

```c
// Print graph structure
graph_print(g);

// Get in-degree of vertex
int in_deg = graph_in_degree(g, vertex);

// Get all in-degrees
int *in_degrees = graph_all_in_degrees(g);
```

**Use Cases**:
- Debugging
- Graph visualization
- Dependency counting
- Finding source/sink nodes

---

## 🚀 Quick Examples

### Example 1: Course Scheduling
```c
Graph *courses = graph_create(5, 1); // directed
graph_add_edge(courses, 0, 1); // Course 0 before 1
graph_add_edge(courses, 0, 2);
graph_add_edge(courses, 1, 3);
graph_add_edge(courses, 2, 3);
graph_add_edge(courses, 3, 4);

// Check if valid schedule exists
if (graph_is_dag(courses)) {
    int size;
    int *order = graph_topological_sort_kahn(courses, &size);
    
    printf("Take courses in this order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
    
    free(order);
} else {
    printf("Circular dependency - cannot complete!\n");
}

graph_free(courses);
```

### Example 2: Network Connectivity
```c
Graph *network = graph_create(100, 0); // undirected
// Add connections...

if (graph_is_connected(network)) {
    printf("Network is fully connected\n");
} else {
    int components = graph_count_components(network);
    printf("Network has %d isolated segments\n", components);
}

graph_free(network);
```

### Example 3: Shortest Path
```c
Graph *map = graph_create(50, 0);
// Add roads...

int path_len;
int *path = graph_shortest_path_bfs(map, start, end, &path_len);

if (path) {
    printf("Shortest route: ");
    for (int i = 0; i < path_len; i++) {
        printf("%d ", path[i]);
    }
    printf("\nDistance: %d stops\n", path_len - 1);
    free(path);
} else {
    printf("No route available\n");
}

graph_free(map);
```

### Example 4: Deadlock Detection
```c
Graph *resources = graph_create(20, 1); // directed
// Add resource dependencies...

if (graph_has_cycle(resources)) {
    printf("DEADLOCK DETECTED!\n");
    printf("Cannot proceed - circular dependency\n");
} else {
    printf("Safe to proceed\n");
}

graph_free(resources);
```

---

## 📊 Algorithm Comparison

| Algorithm | Approach | Best For | Returns NULL on Cycle? |
|-----------|----------|----------|----------------------|
| **Topological Sort (DFS)** | Recursive DFS | Simple implementation | Yes |
| **Topological Sort (Kahn)** | BFS with queue | Explicit in-degree tracking | Yes |
| **Cycle Detection** | DFS/BFS | Fast detection | N/A |
| **Shortest Path** | BFS | Unweighted graphs | If unreachable |

---

## 🎓 Key Differences

### Topological Sort: DFS vs Kahn's

| Feature | DFS-Based | Kahn's Algorithm |
|---------|-----------|------------------|
| **Approach** | Recursive DFS | Iterative BFS |
| **Data Structure** | Stack | Queue |
| **In-Degree** | Not needed | Explicitly tracked |
| **Order** | Post-order | Level-by-level |
| **Complexity** | O(V + E) | O(V + E) |
| **Best For** | Simple cases | When in-degrees needed |

### Cycle Detection: Directed vs Undirected

| Graph Type | Method | Key Concept |
|------------|--------|-------------|
| **Directed** | Recursion stack | Back edge to ancestor |
| **Undirected** | Parent tracking | Edge to visited non-parent |

---

## ⚠️ Important Notes

### Memory Management
```c
// Always free returned arrays
int *result = graph_topological_sort_dfs(g, &size);
if (result) {
    // Use result...
    free(result); // Don't forget!
}

// Always free graphs
graph_free(g);
```

### NULL Returns
Functions return NULL when:
- Cycle detected (topological sort)
- Path doesn't exist (shortest path)
- Invalid parameters

Always check for NULL:
```c
int *order = graph_topological_sort_dfs(g, &size);
if (order == NULL) {
    printf("Cannot sort - cycle detected\n");
} else {
    // Use order...
    free(order);
}
```

### Graph Type Requirements
- **Topological Sort**: Requires directed graph
- **Is Connected**: Only for undirected graphs
- **Shortest Path**: Works for both types

---

## 📈 Performance Summary

All new algorithms have optimal time complexity:

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Topological Sort | O(V + E) | O(V) | Linear in graph size |
| Cycle Detection | O(V + E) | O(V) | Single pass |
| Connectivity | O(V + E) | O(V) | DFS-based |
| Shortest Path | O(V + E) | O(V) | BFS-based |
| In-Degree | O(V + E) | O(V) | Single scan |

**V** = number of vertices  
**E** = number of edges

---

## 🎯 Testing

Run the comprehensive test suite:
```bash
make examples
./examples/problem9_graph_algorithms
```

Tests include:
- ✅ Topological sorting (both algorithms)
- ✅ Cycle detection (directed & undirected)
- ✅ Connectivity analysis
- ✅ Shortest path finding
- ✅ Course scheduling example
- ✅ In-degree calculation
- ✅ Graph visualization

---

## 📚 Documentation

- **Detailed Guide**: `GRAPH_ALGORITHMS.md`
- **Problem Example**: `examples/problem9_graph_algorithms.c`
- **Header File**: `include/graph.h`
- **Implementation**: `src/graph.c`

---

## 🎉 Summary

**Before**: 7 basic functions (create, add, traverse)  
**After**: 20+ functions including advanced algorithms  

**New Capabilities**:
- ✅ Topological sorting (2 algorithms)
- ✅ Cycle detection
- ✅ Connectivity analysis
- ✅ Shortest path finding
- ✅ In-degree calculation
- ✅ Graph visualization

**All functions are production-ready, well-tested, and documented!** 🚀

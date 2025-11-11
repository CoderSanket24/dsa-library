/*
 * Problem 9: Graph Algorithms
 * 
 * Demonstrates various graph algorithms including:
 * - Topological Sorting (DFS-based)
 * - Cycle Detection
 * - Shortest Path (BFS)
 * 
 * Uses: Graph Library Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void print_array(int arr[], int n, const char *label) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void test_topological_sort() {
    printf("=== Test 1: Topological Sorting ===\n\n");
    
    // Create a DAG: 0 -> 1 -> 3
    //               |    |
    //               v    v
    //               2 -> 3
    printf("DAG Structure:\n");
    printf("  0 -> 1 -> 3\n");
    printf("  |    |\n");
    printf("  v    v\n");
    printf("  2 -> 3\n\n");
    
    Graph *g = graph_create(4, 1); // directed
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    
    // DFS-based topological sort
    int size;
    int *topo = graph_topological_sort_dfs(g, &size);
    if (topo) {
        print_array(topo, size, "Topological Sort (DFS)");
        free(topo);
    }
    
    printf("Is DAG? %s\n", graph_is_dag(g) ? "Yes" : "No");
    printf("Has cycle? %s\n\n", graph_has_cycle(g) ? "Yes" : "No");
    
    graph_free(g);
}

void test_cycle_detection() {
    printf("=== Test 2: Cycle Detection ===\n\n");
    
    // Directed graph with cycle
    printf("Directed Graph with Cycle:\n");
    printf("  0 -> 1 -> 2\n");
    printf("  ^         |\n");
    printf("  |_________|\n\n");
    
    Graph *g1 = graph_create(3, 1);
    graph_add_edge(g1, 0, 1);
    graph_add_edge(g1, 1, 2);
    graph_add_edge(g1, 2, 0); // creates cycle
    
    printf("Has cycle? %s\n", graph_has_cycle(g1) ? "Yes" : "No");
    printf("Is DAG? %s\n\n", graph_is_dag(g1) ? "Yes" : "No");
    
    int size;
    int *topo = graph_topological_sort_dfs(g1, &size);
    if (topo) {
        print_array(topo, size, "Topological Sort");
        free(topo);
    } else {
        printf("Topological Sort: Not possible (cycle detected)\n\n");
    }
    
    graph_free(g1);
    
    // Undirected graph with cycle
    printf("Undirected Graph with Cycle:\n");
    printf("  0 - 1\n");
    printf("  |   |\n");
    printf("  2 - 3\n\n");
    
    Graph *g2 = graph_create(4, 0);
    graph_add_edge(g2, 0, 1);
    graph_add_edge(g2, 1, 3);
    graph_add_edge(g2, 3, 2);
    graph_add_edge(g2, 2, 0);
    
    printf("Has cycle? %s\n\n", graph_has_cycle(g2) ? "Yes" : "No");
    
    graph_free(g2);
}



void test_shortest_path() {
    printf("=== Test 3: Shortest Path (Unweighted) ===\n\n");
    
    printf("Graph Structure:\n");
    printf("      0\n");
    printf("     / \\\n");
    printf("    1   2\n");
    printf("   / \\ / \\\n");
    printf("  3   4   5\n\n");
    
    Graph *g = graph_create(6, 0);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 1, 4);
    graph_add_edge(g, 2, 4);
    graph_add_edge(g, 2, 5);
    
    // Find shortest path from 0 to 5
    int path_len;
    int *path = graph_shortest_path_bfs(g, 0, 5, &path_len);
    if (path) {
        print_array(path, path_len, "Shortest path from 0 to 5");
        printf("Distance: %d\n\n", path_len - 1);
        free(path);
    }
    
    // Find shortest path from 3 to 5
    path = graph_shortest_path_bfs(g, 3, 5, &path_len);
    if (path) {
        print_array(path, path_len, "Shortest path from 3 to 5");
        printf("Distance: %d\n\n", path_len - 1);
        free(path);
    }
    
    // Test distance function
    printf("Distance from 0 to 3: %d\n", graph_shortest_distance(g, 0, 3));
    printf("Distance from 0 to 4: %d\n", graph_shortest_distance(g, 0, 4));
    printf("Distance from 3 to 5: %d\n\n", graph_shortest_distance(g, 3, 5));
    
    graph_free(g);
}

void test_course_schedule() {
    printf("=== Test 4: Course Schedule (Real-World Example) ===\n\n");
    
    printf("Course Prerequisites:\n");
    printf("  Course 0: No prerequisites\n");
    printf("  Course 1: Requires Course 0\n");
    printf("  Course 2: Requires Course 0\n");
    printf("  Course 3: Requires Courses 1 and 2\n");
    printf("  Course 4: Requires Course 3\n\n");
    
    Graph *g = graph_create(5, 1);
    graph_add_edge(g, 0, 1); // 0 must be taken before 1
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    
    printf("Can complete all courses? %s\n", graph_is_dag(g) ? "Yes" : "No (circular dependency)");
    
    int size;
    int *order = graph_topological_sort_dfs(g, &size);
    if (order) {
        printf("Course order: ");
        for (int i = 0; i < size; i++) {
            printf("Course %d", order[i]);
            if (i < size - 1) printf(" -> ");
        }
        printf("\n\n");
        free(order);
    }
    
    graph_free(g);
}

void test_in_degree() {
    printf("=== Test 5: In-Degree Calculation ===\n\n");
    
    printf("Directed Graph:\n");
    printf("  0 -> 1 -> 3\n");
    printf("  |    |\n");
    printf("  v    v\n");
    printf("  2 -> 3\n\n");
    
    Graph *g = graph_create(4, 1);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    
    int *in_degrees = graph_all_in_degrees(g);
    printf("In-degrees:\n");
    for (int i = 0; i < 4; i++) {
        printf("  Vertex %d: %d\n", i, in_degrees[i]);
    }
    printf("\n");
    
    free(in_degrees);
    graph_free(g);
}

void test_graph_print() {
    printf("=== Test 6: Graph Visualization ===\n\n");
    
    Graph *g = graph_create(4, 1);
    graph_add_edge_weighted(g, 0, 1, 5);
    graph_add_edge_weighted(g, 0, 2, 3);
    graph_add_edge_weighted(g, 1, 3, 2);
    graph_add_edge_weighted(g, 2, 3, 7);
    
    graph_print(g);
    printf("\n");
    
    graph_free(g);
}

int main() {
    printf("========================================\n");
    printf("   GRAPH ALGORITHMS DEMONSTRATION\n");
    printf("========================================\n\n");
    
    test_topological_sort();
    printf("========================================\n\n");
    
    test_cycle_detection();
    printf("========================================\n\n");
    
    test_shortest_path();
    printf("========================================\n\n");
    
    test_course_schedule();
    printf("========================================\n\n");
    
    test_in_degree();
    printf("========================================\n\n");
    
    test_graph_print();
    printf("========================================\n");
    
    printf("\n✓ All graph algorithms demonstrated!\n");
    printf("\nAlgorithms covered:\n");
    printf("  - Topological Sort (DFS)\n");
    printf("  - Cycle Detection (Directed & Undirected)\n");
    printf("  - Shortest Path (BFS)\n");
    printf("  - In-Degree Calculation\n");
    printf("  - Graph Visualization\n");
    
    return 0;
}

#include <stdio.h>
#include "dsa.h"

void printDSAInfo() {
    printf("DSA Library v%s\n", DSA_VERSION);
    printf("Data Structures Available:\n");
    printf("\nQueue Types:\n");
    printf("- Queue (Simple Linear Queue)\n");
    printf("- Circular Queue\n");
    printf("- Priority Queue\n");
    printf("- Deque (Double-ended Queue)\n");
    printf("\nOther Data Structures:\n");
    printf("- Stack (LIFO)\n");
    printf("- Singly Linked List\n");
    printf("- Doubly Linked List\n");
    printf("- Circular Linked List\n");
    printf("- Binary Search Tree (BST)\n");
    printf("- Graph (with BFS/DFS)\n");
    printf("\nAlgorithms Available:\n");
    printf("Searching:\n");
    printf("- Linear Search\n");
    printf("- Binary Search (Iterative & Recursive)\n");
    printf("Sorting:\n");
    printf("- Bubble Sort\n");
    printf("- Selection Sort\n");
    printf("- Insertion Sort\n");
    printf("- Merge Sort\n");
    printf("- Quick Sort\n");
    printf("- Heap Sort\n");
    printf("- Counting Sort\n");
    printf("\n");
}
#include <stdio.h>
#include "dsa.h"

void printDSAInfo() {
    printf("DSA Library v%s\n", DSA_VERSION);
    printf("Data Structures Available:\n");
    printf("- Queue (FIFO)\n");
    printf("- Stack (LIFO)\n");
    printf("- Linked List (Dynamic)\n");
    printf("- Binary Search Tree (BST)\n");
    printf("- Graph (Adjacency List)\n");
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
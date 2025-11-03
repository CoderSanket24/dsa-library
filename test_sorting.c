#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void testSortingAlgorithm(void (*sortFunc)(int[], int), const char* name, int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    copyArray(arr, temp, n);
    
    printf("=== %s ===\n", name);
    printf("Original: ");
    printArray(temp, n);
    
    clock_t start = clock();
    sortFunc(temp, n);
    clock_t end = clock();
    
    printf("Sorted:   ");
    printArray(temp, n);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", time_taken);
    printf("Correctly sorted: %s\n", isSorted(temp, n) ? "Yes" : "No");
    printf("\n");
    
    free(temp);
}

void testMergeSort(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    copyArray(arr, temp, n);
    
    printf("=== MERGE SORT ===\n");
    printf("Original: ");
    printArray(temp, n);
    
    clock_t start = clock();
    mergeSort(temp, 0, n - 1);
    clock_t end = clock();
    
    printf("Sorted:   ");
    printArray(temp, n);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", time_taken);
    printf("Correctly sorted: %s\n", isSorted(temp, n) ? "Yes" : "No");
    printf("\n");
    
    free(temp);
}

void testQuickSort(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    copyArray(arr, temp, n);
    
    printf("=== QUICK SORT ===\n");
    printf("Original: ");
    printArray(temp, n);
    
    clock_t start = clock();
    quickSort(temp, 0, n - 1);
    clock_t end = clock();
    
    printf("Sorted:   ");
    printArray(temp, n);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", time_taken);
    printf("Correctly sorted: %s\n", isSorted(temp, n) ? "Yes" : "No");
    printf("\n");
    
    free(temp);
}

void performanceComparison() {
    printf("=== PERFORMANCE COMPARISON ===\n");
    const int SIZE = 1000;
    int *arr = malloc(SIZE * sizeof(int));
    
    // Generate random array
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    
    printf("Testing with %d random elements (0-999)\n\n", SIZE);
    
    // Test all sorting algorithms
    testSortingAlgorithm(bubbleSort, "BUBBLE SORT", arr, SIZE);
    testSortingAlgorithm(selectionSort, "SELECTION SORT", arr, SIZE);
    testSortingAlgorithm(insertionSort, "INSERTION SORT", arr, SIZE);
    testMergeSort(arr, SIZE);
    testQuickSort(arr, SIZE);
    testSortingAlgorithm(heapSort, "HEAP SORT", arr, SIZE);
    testSortingAlgorithm(countingSort, "COUNTING SORT", arr, SIZE);
    
    free(arr);
}

void testSmallArray() {
    printf("SORTING ALGORITHMS TEST\n");
    printf("======================\n\n");
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Testing with small array:\n");
    printArray(arr, n);
    printf("\n");
    
    // Test all sorting algorithms with small array
    testSortingAlgorithm(bubbleSort, "BUBBLE SORT", arr, n);
    testSortingAlgorithm(selectionSort, "SELECTION SORT", arr, n);
    testSortingAlgorithm(insertionSort, "INSERTION SORT", arr, n);
    testMergeSort(arr, n);
    testQuickSort(arr, n);
    testSortingAlgorithm(heapSort, "HEAP SORT", arr, n);
    testSortingAlgorithm(countingSort, "COUNTING SORT", arr, n);
}

void testEdgeCases() {
    printf("=== EDGE CASES TEST ===\n");
    
    // Test with single element
    printf("Single element array:\n");
    int single[] = {42};
    testSortingAlgorithm(bubbleSort, "BUBBLE SORT", single, 1);
    
    // Test with already sorted array
    printf("Already sorted array:\n");
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(sorted) / sizeof(sorted[0]);
    testQuickSort(sorted, n);
    
    // Test with reverse sorted array
    printf("Reverse sorted array:\n");
    int reverse[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    n = sizeof(reverse) / sizeof(reverse[0]);
    testMergeSort(reverse, n);
    
    // Test with duplicate elements
    printf("Array with duplicates:\n");
    int duplicates[] = {5, 2, 8, 2, 9, 1, 5, 5, 2, 8};
    n = sizeof(duplicates) / sizeof(duplicates[0]);
    testSortingAlgorithm(heapSort, "HEAP SORT", duplicates, n);
}

int main() {
    testSmallArray();
    testEdgeCases();
    performanceComparison();
    
    printf("All sorting tests completed!\n");
    return 0;
}
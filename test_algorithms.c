#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "searching.h"
#include "sorting.h"

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("SEARCHING & SORTING ALGORITHMS DEMO\n");
    printf("===================================\n\n");
    
    // Create test array
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    printf("\n");
    
    // Test linear search on unsorted array
    printf("=== SEARCHING ON UNSORTED ARRAY ===\n");
    int key = 22;
    int result = linearSearch(arr, n, key);
    printf("Linear search for %d: %s at index %d\n", 
           key, (result != -1) ? "Found" : "Not found", result);
    
    key = 100;
    result = linearSearch(arr, n, key);
    printf("Linear search for %d: %s\n", 
           key, (result != -1) ? "Found" : "Not found");
    printf("\n");
    
    // Sort the array using quick sort
    printf("=== SORTING THE ARRAY ===\n");
    quickSort(arr, 0, n - 1);
    printf("After Quick Sort: ");
    printArray(arr, n);
    printf("\n");
    
    // Test binary search on sorted array
    printf("=== SEARCHING ON SORTED ARRAY ===\n");
    key = 22;
    result = binarySearchIterative(arr, n, key);
    printf("Binary search (iterative) for %d: %s at index %d\n", 
           key, (result != -1) ? "Found" : "Not found", result);
    
    result = binarySearchRecursive(arr, 0, n-1, key);
    printf("Binary search (recursive) for %d: %s at index %d\n", 
           key, (result != -1) ? "Found" : "Not found", result);
    
    key = 100;
    result = binarySearchIterative(arr, n, key);
    printf("Binary search for %d: %s\n", 
           key, (result != -1) ? "Found" : "Not found");
    printf("\n");
    
    // Demonstrate different sorting algorithms
    printf("=== COMPARING SORTING ALGORITHMS ===\n");
    int original[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    int temp[10];
    
    // Bubble Sort
    for (int i = 0; i < n; i++) temp[i] = original[i];
    printf("Bubble Sort: ");
    bubbleSort(temp, n);
    printArray(temp, n);
    
    // Selection Sort
    for (int i = 0; i < n; i++) temp[i] = original[i];
    printf("Selection Sort: ");
    selectionSort(temp, n);
    printArray(temp, n);
    
    // Insertion Sort
    for (int i = 0; i < n; i++) temp[i] = original[i];
    printf("Insertion Sort: ");
    insertionSort(temp, n);
    printArray(temp, n);
    
    // Merge Sort
    for (int i = 0; i < n; i++) temp[i] = original[i];
    printf("Merge Sort: ");
    mergeSort(temp, 0, n-1);
    printArray(temp, n);
    
    // Heap Sort
    for (int i = 0; i < n; i++) temp[i] = original[i];
    printf("Heap Sort: ");
    heapSort(temp, n);
    printArray(temp, n);
    
    printf("\nAll algorithms produce the same sorted result!\n");
    return 0;
}
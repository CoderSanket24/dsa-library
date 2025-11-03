#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "searching.h"

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testLinearSearch() {
    printf("=== LINEAR SEARCH TEST ===\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    printArray(arr, n);
    
    int key = 22;
    int result = linearSearch(arr, n, key);
    
    if (result != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Linear Search: Element %d not found\n", key);
    }
    
    // Test with non-existent element
    key = 100;
    result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Linear Search: Element %d not found\n", key);
    }
    printf("\n");
}

void testBinarySearch() {
    printf("=== BINARY SEARCH TEST ===\n");
    // Binary search requires sorted array
    int arr[] = {5, 11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Sorted Array: ");
    printArray(arr, n);
    
    int key = 22;
    
    // Test iterative binary search
    int result = binarySearchIterative(arr, n, key);
    if (result != -1) {
        printf("Binary Search (Iterative): Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search (Iterative): Element %d not found\n", key);
    }
    
    // Test recursive binary search
    result = binarySearchRecursive(arr, 0, n-1, key);
    if (result != -1) {
        printf("Binary Search (Recursive): Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search (Recursive): Element %d not found\n", key);
    }
    
    // Test with non-existent element
    key = 100;
    result = binarySearchIterative(arr, n, key);
    if (result != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search: Element %d not found\n", key);
    }
    printf("\n");
}

void performanceTest() {
    printf("=== PERFORMANCE COMPARISON ===\n");
    const int SIZE = 10000;
    int *arr = malloc(SIZE * sizeof(int));
    
    // Create sorted array for binary search
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i * 2; // Even numbers
    }
    
    int key = SIZE - 10; // Search for element near the end
    
    // Time linear search
    clock_t start = clock();
    int result1 = linearSearch(arr, SIZE, key);
    clock_t end = clock();
    double linear_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Time binary search
    start = clock();
    int result2 = binarySearchIterative(arr, SIZE, key);
    end = clock();
    double binary_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Array size: %d elements\n", SIZE);
    printf("Searching for: %d\n", key);
    printf("Linear Search: Found at index %d, Time: %f seconds\n", result1, linear_time);
    printf("Binary Search: Found at index %d, Time: %f seconds\n", result2, binary_time);
    
    if (binary_time > 0) {
        printf("Binary search is %.2fx faster\n", linear_time / binary_time);
    }
    
    free(arr);
    printf("\n");
}

int main() {
    printf("SEARCHING ALGORITHMS TEST\n");
    printf("========================\n\n");
    
    testLinearSearch();
    testBinarySearch();
    performanceTest();
    
    printf("All searching tests completed!\n");
    return 0;
}
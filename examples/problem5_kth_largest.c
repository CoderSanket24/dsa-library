/*
 * Problem 5: Find Kth Largest Element
 * 
 * Given an unsorted array, find the kth largest element.
 * Uses: Quick Sort, Selection Sort
 * 
 * Example: arr = [3,2,1,5,6,4], k = 2
 * Output: 5 (second largest element)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/sorting.h"

// Find kth largest element using sorting
int findKthLargest(int arr[], int n, int k) {
    // Create a copy to avoid modifying original
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    // Sort in ascending order
    quickSort(temp, 0, n - 1);
    
    // kth largest is at index (n - k)
    int result = temp[n - k];
    free(temp);
    return result;
}

// Find top K largest elements
void findTopKLargest(int arr[], int n, int k, int result[]) {
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    quickSort(temp, 0, n - 1);
    
    // Copy top k elements
    for (int i = 0; i < k; i++) {
        result[i] = temp[n - 1 - i];
    }
    free(temp);
}

// Find kth smallest element
int findKthSmallest(int arr[], int n, int k) {
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    quickSort(temp, 0, n - 1);
    int result = temp[k - 1];
    free(temp);
    return result;
}

// Sort array and find median
double findMedian(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    quickSort(temp, 0, n - 1);
    
    double median;
    if (n % 2 == 0) {
        median = (temp[n/2 - 1] + temp[n/2]) / 2.0;
    } else {
        median = temp[n/2];
    }
    
    free(temp);
    return median;
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("=== Problem 5: Find Kth Largest Element ===\n\n");
    
    // Test Case 1: Find kth largest
    printf("Test 1: Find Kth Largest Element\n");
    int arr1[] = {3, 2, 1, 5, 6, 4};
    int n1 = 6;
    printf("Array: ");
    printArray(arr1, n1);
    
    printf("2nd largest: %d\n", findKthLargest(arr1, n1, 2));
    printf("3rd largest: %d\n", findKthLargest(arr1, n1, 3));
    printf("1st largest: %d\n\n", findKthLargest(arr1, n1, 1));
    
    // Test Case 2: Top K elements
    printf("Test 2: Find Top K Largest Elements\n");
    int arr2[] = {7, 10, 4, 3, 20, 15};
    int n2 = 6;
    printf("Array: ");
    printArray(arr2, n2);
    
    int topK[3];
    findTopKLargest(arr2, n2, 3, topK);
    printf("Top 3 largest: ");
    printArray(topK, 3);
    printf("\n");
    
    // Test Case 3: Kth smallest
    printf("Test 3: Find Kth Smallest Element\n");
    int arr3[] = {7, 10, 4, 3, 20, 15};
    int n3 = 6;
    printf("Array: ");
    printArray(arr3, n3);
    printf("2nd smallest: %d\n", findKthSmallest(arr3, n3, 2));
    printf("4th smallest: %d\n\n", findKthSmallest(arr3, n3, 4));
    
    // Test Case 4: Find median
    printf("Test 4: Find Median\n");
    int arr4[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n4 = 8;
    printf("Array: ");
    printArray(arr4, n4);
    printf("Median: %.1f\n\n", findMedian(arr4, n4));
    
    int arr5[] = {5, 2, 8, 1, 9};
    int n5 = 5;
    printf("Array: ");
    printArray(arr5, n5);
    printf("Median: %.1f\n", findMedian(arr5, n5));
    
    return 0;
}

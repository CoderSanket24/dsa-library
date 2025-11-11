/*
 * Problem 6: Search in Rotated Sorted Array
 * 
 * A sorted array is rotated at some pivot. Find target element.
 * Uses: Binary Search (Modified)
 * 
 * Example: arr = [4,5,6,7,0,1,2], target = 0
 * Output: 4 (index of target)
 */

#include <stdio.h>
#include "../include/searching.h"

// Find pivot point (smallest element) in rotated array
int findPivot(int arr[], int low, int high) {
    if (high < low) return 0;
    if (high == low) return low;
    
    int mid = (low + high) / 2;
    
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid + 1;
    
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;
    
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    
    return findPivot(arr, mid + 1, high);
}

// Search in rotated sorted array
int searchRotated(int arr[], int n, int target) {
    int pivot = findPivot(arr, 0, n - 1);
    
    // If no rotation
    if (pivot == 0)
        return binarySearchIterative(arr, n, target);
    
    // If target is at pivot
    if (arr[pivot] == target)
        return pivot;
    
    // Decide which half to search
    if (arr[0] <= target) {
        return binarySearchRecursive(arr, 0, pivot - 1, target);
    }
    
    int result = binarySearchRecursive(arr, pivot, n - 1, target);
    return result;
}

// Find minimum in rotated sorted array
int findMin(int arr[], int n) {
    int pivot = findPivot(arr, 0, n - 1);
    return arr[pivot];
}

// Find maximum in rotated sorted array
int findMax(int arr[], int n) {
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == 0)
        return arr[n - 1];
    return arr[pivot - 1];
}

// Count rotations in rotated sorted array
int countRotations(int arr[], int n) {
    return findPivot(arr, 0, n - 1);
}

// Search in rotated array with duplicates (modified approach)
int searchRotatedWithDuplicates(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
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
    printf("=== Problem 6: Search in Rotated Sorted Array ===\n\n");
    
    // Test Case 1: Basic search
    printf("Test 1: Search in Rotated Array\n");
    int arr1[] = {4, 5, 6, 7, 0, 1, 2};
    int n1 = 7;
    printf("Array: ");
    printArray(arr1, n1);
    
    int target1 = 0;
    int result1 = searchRotated(arr1, n1, target1);
    printf("Search %d: Found at index %d\n", target1, result1);
    
    target1 = 3;
    result1 = searchRotated(arr1, n1, target1);
    printf("Search %d: %s\n\n", target1, result1 == -1 ? "Not found" : "Found");
    
    // Test Case 2: Find min and max
    printf("Test 2: Find Min and Max\n");
    int arr2[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int n2 = 9;
    printf("Array: ");
    printArray(arr2, n2);
    printf("Minimum: %d\n", findMin(arr2, n2));
    printf("Maximum: %d\n\n", findMax(arr2, n2));
    
    // Test Case 3: Count rotations
    printf("Test 3: Count Rotations\n");
    int arr3[] = {15, 18, 2, 3, 6, 12};
    int n3 = 6;
    printf("Array: ");
    printArray(arr3, n3);
    printf("Number of rotations: %d\n\n", countRotations(arr3, n3));
    
    // Test Case 4: No rotation
    printf("Test 4: No Rotation (Normal Sorted Array)\n");
    int arr4[] = {1, 2, 3, 4, 5, 6, 7};
    int n4 = 7;
    printf("Array: ");
    printArray(arr4, n4);
    int target4 = 5;
    int result4 = searchRotated(arr4, n4, target4);
    printf("Search %d: Found at index %d\n", target4, result4);
    printf("Number of rotations: %d\n\n", countRotations(arr4, n4));
    
    // Test Case 5: Multiple searches
    printf("Test 5: Multiple Searches\n");
    int arr5[] = {6, 7, 8, 1, 2, 3, 4, 5};
    int n5 = 8;
    printf("Array: ");
    printArray(arr5, n5);
    
    int targets[] = {1, 3, 6, 8, 9};
    for (int i = 0; i < 5; i++) {
        int result = searchRotated(arr5, n5, targets[i]);
        if (result != -1)
            printf("Search %d: Found at index %d\n", targets[i], result);
        else
            printf("Search %d: Not found\n", targets[i]);
    }
    
    return 0;
}

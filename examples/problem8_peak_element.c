/*
 * Problem 8: Find Peak Element
 * 
 * A peak element is greater than its neighbors. Find any peak.
 * Uses: Binary Search (Modified)
 * 
 * Example: arr = [1,2,3,1]
 * Output: 2 (index of peak element 3)
 */

#include <stdio.h>
#include "../include/searching.h"

// Find a peak element using binary search
int findPeakElement(int arr[], int n) {
    int low = 0, high = n - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // If mid element is less than next, peak is on right
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            // Peak is on left (including mid)
            high = mid;
        }
    }
    
    return low;
}

// Find all peak elements
int findAllPeaks(int arr[], int n, int peaks[]) {
    int count = 0;
    
    // First element
    if (n > 0 && (n == 1 || arr[0] >= arr[1])) {
        peaks[count++] = 0;
    }
    
    // Middle elements
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            peaks[count++] = i;
        }
    }
    
    // Last element
    if (n > 1 && arr[n - 1] >= arr[n - 2]) {
        peaks[count++] = n - 1;
    }
    
    return count;
}

// Find maximum element (global peak)
int findMaxElement(int arr[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// Find local minimum
int findLocalMinimum(int arr[], int n) {
    int low = 0, high = n - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // If mid element is greater than next, minimum is on right
        if (arr[mid] > arr[mid + 1]) {
            low = mid + 1;
        } else {
            // Minimum is on left (including mid)
            high = mid;
        }
    }
    
    return low;
}

// Check if array is mountain (increases then decreases)
int isMountainArray(int arr[], int n) {
    if (n < 3) return 0;
    
    int i = 0;
    
    // Walk up
    while (i + 1 < n && arr[i] < arr[i + 1]) {
        i++;
    }
    
    // Peak can't be first or last
    if (i == 0 || i == n - 1) return 0;
    
    // Walk down
    while (i + 1 < n && arr[i] > arr[i + 1]) {
        i++;
    }
    
    return i == n - 1;
}

// Find peak in mountain array
int findPeakInMountain(int arr[], int n) {
    int low = 0, high = n - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}

// Search in mountain array
int searchInMountain(int arr[], int n, int target) {
    // Find peak
    int peak = findPeakInMountain(arr, n);
    
    // Search in increasing part
    int result = binarySearchRecursive(arr, 0, peak, target);
    if (result != -1) return result;
    
    // Search in decreasing part (need to reverse logic)
    for (int i = peak + 1; i < n; i++) {
        if (arr[i] == target) return i;
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
    printf("=== Problem 8: Find Peak Element ===\n\n");
    
    // Test Case 1: Find a peak
    printf("Test 1: Find Peak Element\n");
    int arr1[] = {1, 2, 3, 1};
    int n1 = 4;
    printf("Array: ");
    printArray(arr1, n1);
    int peak1 = findPeakElement(arr1, n1);
    printf("Peak at index %d, value = %d\n\n", peak1, arr1[peak1]);
    
    // Test Case 2: Multiple peaks
    printf("Test 2: Find All Peaks\n");
    int arr2[] = {1, 3, 2, 4, 1, 5, 3};
    int n2 = 7;
    printf("Array: ");
    printArray(arr2, n2);
    
    int peaks[10];
    int peakCount = findAllPeaks(arr2, n2, peaks);
    printf("Peaks found at indices: ");
    for (int i = 0; i < peakCount; i++) {
        printf("%d (value=%d)", peaks[i], arr2[peaks[i]]);
        if (i < peakCount - 1) printf(", ");
    }
    printf("\n\n");
    
    // Test Case 3: Find maximum
    printf("Test 3: Find Maximum Element\n");
    int arr3[] = {5, 10, 20, 15};
    int n3 = 4;
    printf("Array: ");
    printArray(arr3, n3);
    int maxIdx = findMaxElement(arr3, n3);
    printf("Maximum at index %d, value = %d\n\n", maxIdx, arr3[maxIdx]);
    
    // Test Case 4: Mountain array
    printf("Test 4: Mountain Array Detection\n");
    int arr4[] = {0, 3, 2, 1};
    int n4 = 4;
    printf("Array: ");
    printArray(arr4, n4);
    printf("Is mountain? %s\n", isMountainArray(arr4, n4) ? "Yes" : "No");
    
    if (isMountainArray(arr4, n4)) {
        int mountainPeak = findPeakInMountain(arr4, n4);
        printf("Mountain peak at index %d, value = %d\n", mountainPeak, arr4[mountainPeak]);
    }
    printf("\n");
    
    int arr5[] = {0, 1, 0};
    int n5 = 3;
    printf("Array: ");
    printArray(arr5, n5);
    printf("Is mountain? %s\n\n", isMountainArray(arr5, n5) ? "Yes" : "No");
    
    // Test Case 5: Search in mountain
    printf("Test 5: Search in Mountain Array\n");
    int arr6[] = {1, 2, 3, 4, 5, 3, 1};
    int n6 = 7;
    printf("Array: ");
    printArray(arr6, n6);
    
    int target = 3;
    int result = searchInMountain(arr6, n6, target);
    printf("Search %d: Found at index %d\n", target, result);
    
    target = 5;
    result = searchInMountain(arr6, n6, target);
    printf("Search %d: Found at index %d\n", target, result);
    
    return 0;
}

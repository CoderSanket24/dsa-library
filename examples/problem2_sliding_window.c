/*
 * PROBLEM 2: Sliding Window Maximum
 * 
 * Difficulty: Medium
 * 
 * Problem Statement:
 * You are given an array of integers nums and an integer k. There is a sliding
 * window of size k which is moving from the left to the right. You can only see
 * the k numbers in the window. Return the max sliding window.
 * 
 * Example:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * 
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * Solution: Use Deque to maintain indices of useful elements
 */

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// Helper function to print array
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Sliding Window Maximum using Deque
void slidingWindowMaximum(int nums[], int n, int k, int result[]) {
    Deque dq;
    initDeque(&dq);
    int resultIndex = 0;
    
    // Process first k elements
    for (int i = 0; i < k && i < n; i++) {
        // Remove elements from rear while current element is greater
        int rear;
        while (!isDequeEmpty(&dq) && peekRear(&dq, &rear) && nums[rear] <= nums[i]) {
            deleteRear(&dq, &rear);
        }
        insertRear(&dq, i);
    }
    
    // Process remaining elements
    for (int i = k; i < n; i++) {
        // The front of deque contains index of maximum element
        int front;
        peekFront(&dq, &front);
        result[resultIndex++] = nums[front];
        
        // Remove elements outside current window
        while (!isDequeEmpty(&dq) && peekFront(&dq, &front) && front <= i - k) {
            deleteFront(&dq, &front);
        }
        
        // Remove elements from rear while current element is greater
        int rear;
        while (!isDequeEmpty(&dq) && peekRear(&dq, &rear) && nums[rear] <= nums[i]) {
            deleteRear(&dq, &rear);
        }
        
        insertRear(&dq, i);
    }
    
    // Add the maximum of last window
    int front;
    peekFront(&dq, &front);
    result[resultIndex++] = nums[front];
}

// Simpler approach: Find minimum in sliding window
void slidingWindowMinimum(int nums[], int n, int k, int result[]) {
    Deque dq;
    initDeque(&dq);
    int resultIndex = 0;
    
    for (int i = 0; i < k && i < n; i++) {
        int rear;
        while (!isDequeEmpty(&dq) && peekRear(&dq, &rear) && nums[rear] >= nums[i]) {
            deleteRear(&dq, &rear);
        }
        insertRear(&dq, i);
    }
    
    for (int i = k; i < n; i++) {
        int front;
        peekFront(&dq, &front);
        result[resultIndex++] = nums[front];
        
        while (!isDequeEmpty(&dq) && peekFront(&dq, &front) && front <= i - k) {
            deleteFront(&dq, &front);
        }
        
        int rear;
        while (!isDequeEmpty(&dq) && peekRear(&dq, &rear) && nums[rear] >= nums[i]) {
            deleteRear(&dq, &rear);
        }
        
        insertRear(&dq, i);
    }
    
    int front;
    peekFront(&dq, &front);
    result[resultIndex++] = nums[front];
}

// Calculate average of sliding window
void slidingWindowAverage(int nums[], int n, int k) {
    printf("Sliding Window Average (k=%d):\n", k);
    
    int sum = 0;
    // Calculate sum of first window
    for (int i = 0; i < k && i < n; i++) {
        sum += nums[i];
    }
    printf("Window [0-%d]: %.2f\n", k-1, (double)sum / k);
    
    // Slide the window
    for (int i = k; i < n; i++) {
        sum = sum - nums[i - k] + nums[i];
        printf("Window [%d-%d]: %.2f\n", i-k+1, i, (double)sum / k);
    }
}

int main() {
    printf("========================================================\n");
    printf("  PROBLEM 2: Sliding Window Maximum\n");
    printf("  Difficulty: Medium\n");
    printf("========================================================\n\n");
    
    // Test Case 1
    printf("--- Test Case 1 ---\n");
    int nums1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = 3;
    int result1[100];
    
    printf("Input: nums = ");
    printArray(nums1, n1);
    printf("Window size k = %d\n\n", k1);
    
    slidingWindowMaximum(nums1, n1, k1, result1);
    printf("Sliding Window Maximum: ");
    printArray(result1, n1 - k1 + 1);
    
    printf("\nSliding Window Minimum: ");
    slidingWindowMinimum(nums1, n1, k1, result1);
    printArray(result1, n1 - k1 + 1);
    
    printf("\n");
    slidingWindowAverage(nums1, n1, k1);
    
    // Test Case 2
    printf("\n\n--- Test Case 2 ---\n");
    int nums2[] = {4, 3, 11, 13, 8, 5, 6};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = 3;
    int result2[100];
    
    printf("Input: nums = ");
    printArray(nums2, n2);
    printf("Window size k = %d\n\n", k2);
    
    slidingWindowMaximum(nums2, n2, k2, result2);
    printf("Sliding Window Maximum: ");
    printArray(result2, n2 - k2 + 1);
    
    printf("\nSliding Window Minimum: ");
    slidingWindowMinimum(nums2, n2, k2, result2);
    printArray(result2, n2 - k2 + 1);
    
    // Test Case 3: Edge case with k=1
    printf("\n\n--- Test Case 3 (Edge Case: k=1) ---\n");
    int nums3[] = {7, 2, 4};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    int k3 = 1;
    int result3[100];
    
    printf("Input: nums = ");
    printArray(nums3, n3);
    printf("Window size k = %d\n\n", k3);
    
    slidingWindowMaximum(nums3, n3, k3, result3);
    printf("Sliding Window Maximum: ");
    printArray(result3, n3 - k3 + 1);
    
    printf("\n✓ Problem solved using Deque (Double-ended Queue)!\n");
    printf("  Time Complexity: O(n) - each element added/removed once\n");
    printf("  Space Complexity: O(k) - deque stores at most k elements\n");
    printf("\nKey Insight: Deque maintains indices of useful elements in\n");
    printf("             decreasing order of their values.\n");
    
    return 0;
}
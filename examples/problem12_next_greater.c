/*
 * Problem 12: Next Greater Element & Stack Monotonic Problems
 * 
 * Use stack to solve monotonic stack problems:
 * 1. Next Greater Element
 * 2. Next Smaller Element
 * 3. Previous Greater Element
 * 4. Stock Span Problem
 * 5. Largest Rectangle in Histogram
 * 
 * Uses: Stack Library Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"

// Find next greater element for each element
void nextGreaterElement(int arr[], int n, int result[]) {
    IntStack stack;
    intstack_init(&stack, n);
    
    // Initialize result with -1
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements smaller than current
        while (!intstack_is_empty(&stack) && intstack_peek(&stack) <= arr[i]) {
            intstack_pop(&stack);
        }
        
        // If stack not empty, top is next greater
        if (!intstack_is_empty(&stack)) {
            result[i] = intstack_peek(&stack);
        }
        
        // Push current element
        intstack_push(&stack, arr[i]);
    }
    
    intstack_free(&stack);
}

// Find next smaller element for each element
void nextSmallerElement(int arr[], int n, int result[]) {
    IntStack stack;
    intstack_init(&stack, n);
    
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        while (!intstack_is_empty(&stack) && intstack_peek(&stack) >= arr[i]) {
            intstack_pop(&stack);
        }
        
        if (!intstack_is_empty(&stack)) {
            result[i] = intstack_peek(&stack);
        }
        
        intstack_push(&stack, arr[i]);
    }
    
    intstack_free(&stack);
}

// Find previous greater element for each element
void previousGreaterElement(int arr[], int n, int result[]) {
    IntStack stack;
    intstack_init(&stack, n);
    
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    
    // Traverse from left to right
    for (int i = 0; i < n; i++) {
        while (!intstack_is_empty(&stack) && intstack_peek(&stack) <= arr[i]) {
            intstack_pop(&stack);
        }
        
        if (!intstack_is_empty(&stack)) {
            result[i] = intstack_peek(&stack);
        }
        
        intstack_push(&stack, arr[i]);
    }
    
    intstack_free(&stack);
}

// Stock Span Problem: days since last higher price
void calculateSpan(int prices[], int n, int span[]) {
    IntStack stack;  // Store indices
    intstack_init(&stack, n);
    
    for (int i = 0; i < n; i++) {
        // Pop elements with price <= current price
        while (!intstack_is_empty(&stack) && 
               prices[intstack_peek(&stack)] <= prices[i]) {
            intstack_pop(&stack);
        }
        
        // Calculate span
        if (intstack_is_empty(&stack)) {
            span[i] = i + 1;  // All previous days
        } else {
            span[i] = i - intstack_peek(&stack);
        }
        
        intstack_push(&stack, i);
    }
    
    intstack_free(&stack);
}

// Largest Rectangle in Histogram
int largestRectangleArea(int heights[], int n) {
    IntStack stack;
    intstack_init(&stack, n);
    
    int maxArea = 0;
    int i = 0;
    
    while (i < n) {
        if (intstack_is_empty(&stack) || 
            heights[i] >= heights[intstack_peek(&stack)]) {
            intstack_push(&stack, i);
            i++;
        } else {
            int top = intstack_pop(&stack);
            int width = intstack_is_empty(&stack) ? i : i - intstack_peek(&stack) - 1;
            int area = heights[top] * width;
            if (area > maxArea) maxArea = area;
        }
    }
    
    while (!intstack_is_empty(&stack)) {
        int top = intstack_pop(&stack);
        int width = intstack_is_empty(&stack) ? i : i - intstack_peek(&stack) - 1;
        int area = heights[top] * width;
        if (area > maxArea) maxArea = area;
    }
    
    intstack_free(&stack);
    return maxArea;
}

// Helper to print array
void printArray(int arr[], int n, const char* label) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            printf("-");
        } else {
            printf("%d", arr[i]);
        }
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Test 1: Next Greater Element
void test_next_greater() {
    printf("=== Test 1: Next Greater Element ===\n\n");
    
    int arr1[] = {4, 5, 2, 10, 8};
    int n1 = 5;
    int result1[5];
    
    nextGreaterElement(arr1, n1, result1);
    
    printf("Array:         [4, 5, 2, 10, 8]\n");
    printArray(result1, n1, "Next Greater");
    printf("\nExplanation:\n");
    printf("  4 -> 5 (next element greater than 4)\n");
    printf("  5 -> 10 (next element greater than 5)\n");
    printf("  2 -> 10 (next element greater than 2)\n");
    printf("  10 -> - (no greater element)\n");
    printf("  8 -> - (no greater element)\n\n");
    
    int arr2[] = {1, 3, 2, 4};
    int n2 = 4;
    int result2[4];
    
    nextGreaterElement(arr2, n2, result2);
    
    printf("Array:         [1, 3, 2, 4]\n");
    printArray(result2, n2, "Next Greater");
    printf("\n");
}

// Test 2: Next Smaller Element
void test_next_smaller() {
    printf("=== Test 2: Next Smaller Element ===\n\n");
    
    int arr[] = {4, 8, 5, 2, 25};
    int n = 5;
    int result[5];
    
    nextSmallerElement(arr, n, result);
    
    printf("Array:         [4, 8, 5, 2, 25]\n");
    printArray(result, n, "Next Smaller");
    printf("\nExplanation:\n");
    printf("  4 -> 2 (next element smaller than 4)\n");
    printf("  8 -> 5 (next element smaller than 8)\n");
    printf("  5 -> 2 (next element smaller than 5)\n");
    printf("  2 -> - (no smaller element)\n");
    printf("  25 -> - (no smaller element)\n\n");
}

// Test 3: Previous Greater Element
void test_previous_greater() {
    printf("=== Test 3: Previous Greater Element ===\n\n");
    
    int arr[] = {10, 4, 2, 20, 40, 12, 30};
    int n = 7;
    int result[7];
    
    previousGreaterElement(arr, n, result);
    
    printf("Array:            [10, 4, 2, 20, 40, 12, 30]\n");
    printArray(result, n, "Previous Greater");
    printf("\nExplanation:\n");
    printf("  10 -> - (no previous element)\n");
    printf("  4 -> 10 (previous element greater than 4)\n");
    printf("  2 -> 10 (previous element greater than 2)\n");
    printf("  20 -> - (no previous greater)\n");
    printf("  40 -> - (no previous greater)\n");
    printf("  12 -> 40 (previous element greater than 12)\n");
    printf("  30 -> 40 (previous element greater than 30)\n\n");
}

// Test 4: Stock Span Problem
void test_stock_span() {
    printf("=== Test 4: Stock Span Problem ===\n\n");
    
    printf("Problem: For each day, find how many consecutive days\n");
    printf("         (including current) had price <= current price\n\n");
    
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;
    int span[7];
    
    calculateSpan(prices, n, span);
    
    printf("Day:    ");
    for (int i = 0; i < n; i++) printf("%4d ", i + 1);
    printf("\n");
    
    printf("Price:  ");
    for (int i = 0; i < n; i++) printf("%4d ", prices[i]);
    printf("\n");
    
    printf("Span:   ");
    for (int i = 0; i < n; i++) printf("%4d ", span[i]);
    printf("\n\n");
    
    printf("Explanation:\n");
    printf("  Day 1: span=1 (only current day)\n");
    printf("  Day 2: span=1 (80 < 100)\n");
    printf("  Day 3: span=1 (60 < 80)\n");
    printf("  Day 4: span=2 (70 > 60, includes days 3-4)\n");
    printf("  Day 5: span=1 (60 < 70)\n");
    printf("  Day 6: span=4 (75 > 60,70,60, includes days 3-6)\n");
    printf("  Day 7: span=6 (85 > all except day 1)\n\n");
}

// Test 5: Largest Rectangle in Histogram
void test_largest_rectangle() {
    printf("=== Test 5: Largest Rectangle in Histogram ===\n\n");
    
    int heights1[] = {2, 1, 5, 6, 2, 3};
    int n1 = 6;
    int area1 = largestRectangleArea(heights1, n1);
    
    printf("Histogram: [2, 1, 5, 6, 2, 3]\n");
    printf("Visual:\n");
    printf("      6 #\n");
    printf("    5 # #\n");
    printf("    # # #\n");
    printf("    # # # 3\n");
    printf("  2 # # # #\n");
    printf("  # 1 # # #\n");
    printf("  ─────────\n");
    printf("Largest rectangle area: %d\n", area1);
    printf("(Rectangle: height=5, width=2, area=10)\n\n");
    
    int heights2[] = {2, 4};
    int n2 = 2;
    int area2 = largestRectangleArea(heights2, n2);
    
    printf("Histogram: [2, 4]\n");
    printf("Largest rectangle area: %d\n\n", area2);
    
    int heights3[] = {6, 2, 5, 4, 5, 1, 6};
    int n3 = 7;
    int area3 = largestRectangleArea(heights3, n3);
    
    printf("Histogram: [6, 2, 5, 4, 5, 1, 6]\n");
    printf("Largest rectangle area: %d\n", area3);
    printf("(Rectangle: height=4, width=3, area=12)\n\n");
}

// Test 6: Real-world application - Temperature analysis
void test_temperature_analysis() {
    printf("=== Test 6: Temperature Analysis ===\n\n");
    
    printf("Problem: For each day, find next day with higher temperature\n\n");
    
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = 8;
    int nextWarmer[8];
    
    // Find next greater (warmer day)
    nextGreaterElement(temperatures, n, nextWarmer);
    
    printf("Day:         ");
    for (int i = 0; i < n; i++) printf("%3d ", i + 1);
    printf("\n");
    
    printf("Temp (°F):   ");
    for (int i = 0; i < n; i++) printf("%3d ", temperatures[i]);
    printf("\n");
    
    printf("Next Warmer: ");
    for (int i = 0; i < n; i++) {
        if (nextWarmer[i] == -1) {
            printf("  - ");
        } else {
            printf("%3d ", nextWarmer[i]);
        }
    }
    printf("\n\n");
    
    printf("Days to wait for warmer weather:\n");
    for (int i = 0; i < n; i++) {
        if (nextWarmer[i] == -1) {
            printf("  Day %d: No warmer day ahead\n", i + 1);
        } else {
            // Find how many days to wait
            int daysToWait = 0;
            for (int j = i + 1; j < n; j++) {
                daysToWait++;
                if (temperatures[j] == nextWarmer[i]) break;
            }
            printf("  Day %d: Wait %d day(s) for %d°F\n", 
                   i + 1, daysToWait, nextWarmer[i]);
        }
    }
    printf("\n");
}

int main() {
    printf("========================================\n");
    printf("  NEXT GREATER ELEMENT & MONOTONIC STACK\n");
    printf("========================================\n\n");
    
    test_next_greater();
    printf("========================================\n\n");
    
    test_next_smaller();
    printf("========================================\n\n");
    
    test_previous_greater();
    printf("========================================\n\n");
    
    test_stock_span();
    printf("========================================\n\n");
    
    test_largest_rectangle();
    printf("========================================\n\n");
    
    test_temperature_analysis();
    printf("========================================\n");
    
    printf("\n✓ All monotonic stack problems demonstrated!\n");
    printf("\nMonotonic Stack Applications:\n");
    printf("  - Next/Previous Greater/Smaller Element\n");
    printf("  - Stock Span Problem\n");
    printf("  - Largest Rectangle in Histogram\n");
    printf("  - Temperature Analysis\n");
    printf("  - Time Complexity: O(n) for all problems\n");
    
    return 0;
}

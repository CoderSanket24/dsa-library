/*
 * Problem 7: Merge Overlapping Intervals
 * 
 * Given a collection of intervals, merge all overlapping intervals.
 * Uses: Sorting (to sort intervals by start time)
 * 
 * Example: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/sorting.h"

typedef struct {
    int start;
    int end;
} Interval;

// Helper function to sort intervals by start time
void sortIntervals(Interval intervals[], int n) {
    // Convert to array of starts for sorting
    int* starts = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        starts[i] = intervals[i].start;
    }
    
    // Bubble sort intervals based on start times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[j].start > intervals[j + 1].start) {
                // Swap intervals
                Interval temp = intervals[j];
                intervals[j] = intervals[j + 1];
                intervals[j + 1] = temp;
            }
        }
    }
    
    free(starts);
}

// Merge overlapping intervals
int mergeIntervals(Interval intervals[], int n, Interval result[]) {
    if (n == 0) return 0;
    
    // Sort intervals by start time
    sortIntervals(intervals, n);
    
    // Start with first interval
    result[0] = intervals[0];
    int resultIndex = 0;
    
    for (int i = 1; i < n; i++) {
        // If current interval overlaps with result[resultIndex]
        if (intervals[i].start <= result[resultIndex].end) {
            // Merge by updating end time
            if (intervals[i].end > result[resultIndex].end) {
                result[resultIndex].end = intervals[i].end;
            }
        } else {
            // No overlap, add new interval
            resultIndex++;
            result[resultIndex] = intervals[i];
        }
    }
    
    return resultIndex + 1;
}

// Insert a new interval and merge if needed
int insertInterval(Interval intervals[], int n, Interval newInterval, Interval result[]) {
    // Add new interval to array
    Interval* temp = (Interval*)malloc((n + 1) * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        temp[i] = intervals[i];
    }
    temp[n] = newInterval;
    
    // Merge all intervals
    int count = mergeIntervals(temp, n + 1, result);
    free(temp);
    return count;
}

// Check if intervals can be attended (no overlap)
int canAttendMeetings(Interval intervals[], int n) {
    if (n <= 1) return 1;
    
    sortIntervals(intervals, n);
    
    for (int i = 1; i < n; i++) {
        if (intervals[i].start < intervals[i - 1].end) {
            return 0; // Overlap found
        }
    }
    return 1; // No overlap
}

// Find minimum meeting rooms required
int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;
    
    // Create arrays for start and end times
    int* starts = (int*)malloc(n * sizeof(int));
    int* ends = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        starts[i] = intervals[i].start;
        ends[i] = intervals[i].end;
    }
    
    // Sort both arrays
    quickSort(starts, 0, n - 1);
    quickSort(ends, 0, n - 1);
    
    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;
    
    while (i < n) {
        if (starts[i] < ends[j]) {
            rooms++;
            if (rooms > maxRooms) maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }
    
    free(starts);
    free(ends);
    return maxRooms;
}

void printIntervals(Interval intervals[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("[%d,%d]", intervals[i].start, intervals[i].end);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("=== Problem 7: Merge Overlapping Intervals ===\n\n");
    
    // Test Case 1: Basic merge
    printf("Test 1: Merge Overlapping Intervals\n");
    Interval intervals1[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n1 = 4;
    printf("Input: ");
    printIntervals(intervals1, n1);
    
    Interval result1[10];
    int count1 = mergeIntervals(intervals1, n1, result1);
    printf("Merged: ");
    printIntervals(result1, count1);
    printf("\n");
    
    // Test Case 2: All overlapping
    printf("Test 2: All Overlapping Intervals\n");
    Interval intervals2[] = {{1,4}, {2,5}, {3,6}};
    int n2 = 3;
    printf("Input: ");
    printIntervals(intervals2, n2);
    
    Interval result2[10];
    int count2 = mergeIntervals(intervals2, n2, result2);
    printf("Merged: ");
    printIntervals(result2, count2);
    printf("\n");
    
    // Test Case 3: Insert interval
    printf("Test 3: Insert New Interval\n");
    Interval intervals3[] = {{1,3}, {6,9}};
    int n3 = 2;
    Interval newInterval = {2, 5};
    printf("Existing: ");
    printIntervals(intervals3, n3);
    printf("Insert: [%d,%d]\n", newInterval.start, newInterval.end);
    
    Interval result3[10];
    int count3 = insertInterval(intervals3, n3, newInterval, result3);
    printf("Result: ");
    printIntervals(result3, count3);
    printf("\n");
    
    // Test Case 4: Can attend all meetings
    printf("Test 4: Can Attend All Meetings?\n");
    Interval meetings1[] = {{0,30}, {5,10}, {15,20}};
    int m1 = 3;
    printf("Meetings: ");
    printIntervals(meetings1, m1);
    printf("Can attend all? %s\n\n", canAttendMeetings(meetings1, m1) ? "Yes" : "No");
    
    Interval meetings2[] = {{7,10}, {2,4}};
    int m2 = 2;
    printf("Meetings: ");
    printIntervals(meetings2, m2);
    printf("Can attend all? %s\n\n", canAttendMeetings(meetings2, m2) ? "Yes" : "No");
    
    // Test Case 5: Minimum meeting rooms
    printf("Test 5: Minimum Meeting Rooms Required\n");
    Interval meetings3[] = {{0,30}, {5,10}, {15,20}};
    int m3 = 3;
    printf("Meetings: ");
    printIntervals(meetings3, m3);
    printf("Minimum rooms needed: %d\n\n", minMeetingRooms(meetings3, m3));
    
    Interval meetings4[] = {{1,5}, {2,3}, {4,6}, {5,7}};
    int m4 = 4;
    printf("Meetings: ");
    printIntervals(meetings4, m4);
    printf("Minimum rooms needed: %d\n", minMeetingRooms(meetings4, m4));
    
    return 0;
}

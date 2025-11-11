# Searching & Sorting DSA Problems

## 🎯 Four Medium-Level Problems Using Searching & Sorting Libraries

This document focuses on the four problems that demonstrate the use of our Searching and Sorting libraries.

---

## Problem 5: Find Kth Largest Element 🔢

**File**: `examples/problem5_kth_largest.c`  
**Library Used**: Sorting (Quick Sort)  
**Difficulty**: Medium

### Problem Statement
Given an unsorted array, find the kth largest element efficiently.

### Approach
1. Sort the array using Quick Sort
2. Access kth largest at index `(n - k)`
3. Works for finding top K elements, kth smallest, and median

### Library Functions Used
```c
quickSort(arr, 0, n - 1);  // O(n log n) sorting
```

### Features Implemented
- ✅ Find kth largest element
- ✅ Find top K largest elements
- ✅ Find kth smallest element  
- ✅ Find median (handles even/odd length)

### Example
```
Input: [3, 2, 1, 5, 6, 4], k = 2
Output: 5 (second largest)

Input: [7, 10, 4, 3, 20, 15], k = 3
Top 3: [20, 15, 10]
```

### Complexity
- **Time**: O(n log n) - dominated by sorting
- **Space**: O(n) - temporary array

### Run
```bash
./examples/problem5_kth_largest
```

---

## Problem 6: Search in Rotated Sorted Array 🔄

**File**: `examples/problem6_rotated_search.c`  
**Library Used**: Searching (Binary Search)  
**Difficulty**: Medium

### Problem Statement
A sorted array is rotated at some pivot point. Find a target element in O(log n) time.

### Approach
1. Find the pivot point (smallest element)
2. Determine which half contains the target
3. Apply binary search on the appropriate half

### Library Functions Used
```c
binarySearchIterative(arr, n, target);
binarySearchRecursive(arr, low, high, target);
```

### Features Implemented
- ✅ Search in rotated array
- ✅ Find minimum element
- ✅ Find maximum element
- ✅ Count number of rotations
- ✅ Handle non-rotated arrays

### Example
```
Input: [4, 5, 6, 7, 0, 1, 2], target = 0
Output: 4 (index of target)

Input: [5, 6, 7, 8, 9, 1, 2, 3, 4]
Min: 1, Max: 9, Rotations: 5
```

### Complexity
- **Time**: O(log n) - binary search
- **Space**: O(log n) - recursive call stack

### Run
```bash
./examples/problem6_rotated_search
```

---

## Problem 7: Merge Overlapping Intervals 📅

**File**: `examples/problem7_merge_intervals.c`  
**Library Used**: Sorting (Quick Sort)  
**Difficulty**: Medium

### Problem Statement
Given a collection of intervals, merge all overlapping intervals.

### Approach
1. Sort intervals by start time
2. Iterate through sorted intervals
3. Merge overlapping intervals by comparing end times

### Library Functions Used
```c
quickSort(starts, 0, n - 1);  // Sort start times
quickSort(ends, 0, n - 1);    // Sort end times
```

### Features Implemented
- ✅ Merge overlapping intervals
- ✅ Insert new interval and merge
- ✅ Check if can attend all meetings
- ✅ Find minimum meeting rooms required

### Example
```
Input: [[1,3], [2,6], [8,10], [15,18]]
Output: [[1,6], [8,10], [15,18]]

Meetings: [[0,30], [5,10], [15,20]]
Can attend all? No
Minimum rooms: 2
```

### Complexity
- **Time**: O(n log n) - sorting dominates
- **Space**: O(n) - result array

### Run
```bash
./examples/problem7_merge_intervals
```

---

## Problem 8: Find Peak Element ⛰️

**File**: `examples/problem8_peak_element.c`  
**Library Used**: Searching (Binary Search)  
**Difficulty**: Medium

### Problem Statement
A peak element is greater than its neighbors. Find any peak in O(log n) time.

### Approach
1. Use modified binary search
2. If `arr[mid] < arr[mid+1]`, peak is on right
3. Otherwise, peak is on left (including mid)

### Library Functions Used
```c
binarySearchRecursive(arr, low, high, target);
```

### Features Implemented
- ✅ Find a peak element (O(log n))
- ✅ Find all peaks (O(n))
- ✅ Find maximum element
- ✅ Detect mountain array
- ✅ Search in mountain array

### Example
```
Input: [1, 2, 3, 1]
Output: 2 (index of peak 3)

Input: [1, 3, 2, 4, 1, 5, 3]
All peaks: indices 1, 3, 5 (values 3, 4, 5)

Mountain: [1, 2, 3, 4, 5, 3, 1]
Peak at index 4, value = 5
```

### Complexity
- **Time**: O(log n) - binary search for single peak
- **Space**: O(1) - constant space

### Run
```bash
./examples/problem8_peak_element
```

---

## Summary Comparison

| Problem | Algorithm | Primary Technique | Time | Space |
|---------|-----------|------------------|------|-------|
| **Problem 5** | Quick Sort | Sorting | O(n log n) | O(n) |
| **Problem 6** | Binary Search | Modified Search | O(log n) | O(log n) |
| **Problem 7** | Quick Sort | Interval Merging | O(n log n) | O(n) |
| **Problem 8** | Binary Search | Peak Finding | O(log n) | O(1) |

---

## Key Algorithms Demonstrated

### Sorting Algorithms
- **Quick Sort**: Efficient O(n log n) divide-and-conquer sorting
- **Application**: Enables kth element finding, interval merging

### Searching Algorithms
- **Binary Search**: O(log n) search in sorted data
- **Modified Binary Search**: Adapted for rotated arrays and peak finding
- **Application**: Efficient searching in special array structures

---

## Real-World Applications

### Problem 5 (Kth Largest)
- 📊 **Leaderboards**: Find top K players
- 📈 **Statistics**: Calculate percentiles
- 🎯 **Recommendations**: Top K products
- 💰 **Finance**: Median income calculations

### Problem 6 (Rotated Search)
- 🔄 **Circular Buffers**: Log rotation systems
- ⏰ **Time Series**: Rotated time data
- 📝 **Text Editors**: Circular undo/redo buffers
- 🎮 **Game Development**: Circular level progression

### Problem 7 (Merge Intervals)
- 📅 **Calendar Apps**: Meeting scheduling
- 🏨 **Booking Systems**: Room availability
- 🚗 **Resource Allocation**: Vehicle scheduling
- 📺 **Streaming**: Content time slot management

### Problem 8 (Peak Finding)
- 📡 **Signal Processing**: Find signal peaks
- 📈 **Stock Market**: Identify local maxima
- 🗺️ **Terrain Mapping**: Find mountain peaks
- 🔬 **Data Analysis**: Detect anomalies

---

## Build and Run All

### Build All Searching & Sorting Problems
```bash
make examples
```

### Run All Problems
```bash
# Individual runs
./examples/problem5_kth_largest
./examples/problem6_rotated_search
./examples/problem7_merge_intervals
./examples/problem8_peak_element

# Or run all 8 problems together
make run_examples
```

---

## Learning Outcomes

After solving these problems, you will understand:

1. **Sorting Applications**
   - How sorting simplifies complex problems
   - When to use O(n log n) solutions
   - Trade-offs between time and space

2. **Binary Search Variants**
   - Modified binary search for special cases
   - O(log n) solutions for non-standard problems
   - Peak finding and rotated array techniques

3. **Problem-Solving Patterns**
   - Sort first, then process
   - Divide and conquer strategies
   - Interval manipulation techniques

4. **Algorithm Analysis**
   - Time complexity analysis
   - Space complexity trade-offs
   - Choosing the right algorithm

---

**These four problems showcase the power of Searching and Sorting algorithms in solving real-world computational challenges!** 🚀

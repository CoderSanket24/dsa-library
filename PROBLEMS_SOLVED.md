# DSA Problems Solved Using Library

## ✅ Four Medium-Level Problems Implemented

---

## Queue-Based Problems

### Problem 1: Binary Tree Level Order Traversal
**File**: `examples/problem1_level_order_tree.c`  
**Difficulty**: Medium  
**Data Structure Used**: Simple Queue (for BFS)

**Problem**: Given a binary tree, traverse it level by level from left to right.

**Solution Approach**:
- Use Queue Library for Breadth-First Search (BFS)
- Process nodes level by level using queue functions
- Track level numbers with queueSize()

**Queue Library Functions Used**:
- `initQueue()` - Initialize queue
- `enqueue()` - Add node to queue
- `dequeue()` - Remove node from queue
- `isEmpty()` - Check if queue is empty
- `queueSize()` - Get current queue size for level tracking

**Features**:
- ✅ Level-by-level traversal
- ✅ Maximum depth calculation
- ✅ Right side view (rightmost node at each level)
- ✅ Count nodes per level
- ✅ Multiple test cases

**Complexity**:
- Time: O(n) where n = number of nodes
- Space: O(w) where w = maximum width of tree

**Run**: `./examples/problem1_level_order_tree`

---

### Problem 2: Sliding Window Maximum
**File**: `examples/problem2_sliding_window.c`  
**Difficulty**: Medium  
**Data Structure Used**: Deque (Double-ended Queue)

**Problem**: Find the maximum value in each sliding window of size k.

**Solution Approach**:
- Use Deque to maintain indices of useful elements
- Keep elements in decreasing order
- Remove elements outside window from front
- Remove smaller elements from rear

**Deque Library Functions Used**:
- `initDeque()` - Initialize deque
- `insertRear()` - Add indices
- `deleteRear()` - Remove smaller elements
- `deleteFront()` - Remove outside window
- `peekFront()` - Get maximum
- `peekRear()` - Check rear element
- `isDequeEmpty()` - Check if empty

**Features**:
- ✅ Sliding window maximum
- ✅ Sliding window minimum
- ✅ Sliding window average
- ✅ Multiple test cases including edge cases

**Complexity**:
- Time: O(n) - each element added/removed once
- Space: O(k) - deque stores at most k elements

**Run**: `./examples/problem2_sliding_window`

---

## Linked List-Based Problems

### Problem 3: Reverse Linked List
**File**: `examples/problem3_reverse_linked_list.c`  
**Difficulty**: Medium  
**Data Structure Used**: Singly & Doubly Linked Lists

**Problem**: Reverse a linked list using different approaches.

**Solution Approaches**:
1. **Iterative Reversal** - Use three pointers (prev, current, next)
2. **Recursive Reversal** - Reverse recursively
3. **Reverse in Groups of K** - Reverse K nodes at a time
4. **Palindrome Check** - Check if list is palindrome using reversal
5. **Reverse Doubly Linked List** - Swap prev and next pointers

**Linked List Library Functions Used**:
- `initSList()` - Initialize singly linked list
- `insertAtEndS()` - Build list
- `displayListS()` - Display list
- `freeListS()` - Free memory
- `initDList()` - Initialize doubly linked list
- `insertAtEndD()` - Add elements
- `displayForwardD()` - Display forward
- `displayBackwardD()` - Display backward
- `freeListD()` - Free memory

**Features**:
- ✅ Iterative reversal
- ✅ Recursive reversal
- ✅ Reverse in groups of K (K=2, K=3)
- ✅ Palindrome checking
- ✅ Doubly linked list reversal
- ✅ Multiple test cases

**Complexity**:
- Time: O(n) for all operations
- Space: O(1) iterative, O(n) recursive

**Run**: `./examples/problem3_reverse_linked_list`

---

### Problem 4: Detect and Remove Cycle in Linked List
**File**: `examples/problem4_detect_cycle.c`  
**Difficulty**: Medium  
**Data Structure Used**: Singly Linked List

**Problem**: Detect if a linked list contains a cycle and remove it.

**Solution Approach**:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare)
- Two pointers: slow (moves 1 step) and fast (moves 2 steps)
- If they meet, cycle exists
- Find cycle start and remove it

**Linked List Library Functions Used**:
- `initSList()` - Initialize list
- `insertAtEndS()` - Build list
- `displayListS()` - Display list
- `freeListS()` - Free memory

**Features**:
- ✅ Detect cycle (Floyd's algorithm)
- ✅ Find cycle start point
- ✅ Find cycle length
- ✅ Remove cycle
- ✅ Find middle of list
- ✅ Find Nth node from end
- ✅ Multiple test cases (cycle at different positions)

**Complexity**:
- Time: O(n) for all operations
- Space: O(1) - No extra space used

**Run**: `./examples/problem4_detect_cycle`

---

## Summary Table

| Problem | Data Structure | Key Algorithm | Time | Space |
|---------|---------------|---------------|------|-------|
| **Problem 1** | Queue | BFS | O(n) | O(w) |
| **Problem 2** | Deque | Monotonic Deque | O(n) | O(k) |
| **Problem 3** | Singly/Doubly List | Reversal | O(n) | O(1) |
| **Problem 4** | Singly List | Floyd's Cycle | O(n) | O(1) |

---

## How to Build and Run

### Build All Problems
```bash
make examples
```

### Run All Problems
```bash
make run_examples
```

### Run Individual Problems
```bash
./examples/problem1_level_order_tree
./examples/problem2_sliding_window
./examples/problem3_reverse_linked_list
./examples/problem4_detect_cycle
```

---

## Key Learnings

### Queue Problems (1-2)
- ✅ Queue perfect for BFS and level-order traversal
- ✅ Deque enables O(n) sliding window solutions
- ✅ Both-end operations crucial for optimization

### Linked List Problems (3-4)
- ✅ Pointer manipulation for reversal
- ✅ Floyd's algorithm for cycle detection
- ✅ Two-pointer technique for various problems
- ✅ Doubly linked list enables bidirectional traversal

---

## Real-World Applications

**Problem 1 (BFS)**: File systems, organization charts, social networks  
**Problem 2 (Sliding Window)**: Stock analysis, network monitoring, sensor data  
**Problem 3 (Reversal)**: Undo operations, data transformation, string manipulation  
**Problem 4 (Cycle Detection)**: Memory leak detection, infinite loop prevention, graph algorithms  

---

**All four problems demonstrate efficient use of our DSA library to solve real algorithmic challenges!** 🎉

--
-

## Searching & Sorting-Based Problems

### Problem 5: Find Kth Largest Element
**File**: `examples/problem5_kth_largest.c`  
**Difficulty**: Medium  
**Data Structure Used**: Array with Sorting

**Problem**: Given an unsorted array, find the kth largest element.

**Solution Approach**:
- Sort array using Quick Sort
- Access kth largest at index (n - k)
- Efficient for finding top K elements

**Sorting Library Functions Used**:
- `quickSort()` - Sort array in O(n log n)
- `bubbleSort()` - Alternative for small arrays

**Features**:
- ✅ Find kth largest element
- ✅ Find top K largest elements
- ✅ Find kth smallest element
- ✅ Find median (even and odd length arrays)
- ✅ Multiple test cases

**Complexity**:
- Time: O(n log n) - dominated by sorting
- Space: O(n) - temporary array for sorting

**Run**: `./examples/problem5_kth_largest`

---

### Problem 6: Search in Rotated Sorted Array
**File**: `examples/problem6_rotated_search.c`  
**Difficulty**: Medium  
**Data Structure Used**: Array with Binary Search

**Problem**: A sorted array is rotated at some pivot. Find a target element efficiently.

**Solution Approach**:
- Find pivot point (smallest element)
- Determine which half contains target
- Apply binary search on appropriate half

**Searching Library Functions Used**:
- `binarySearchIterative()` - Search in sorted portion
- `binarySearchRecursive()` - Recursive binary search

**Features**:
- ✅ Search in rotated array
- ✅ Find minimum element
- ✅ Find maximum element
- ✅ Count number of rotations
- ✅ Handle no rotation case
- ✅ Multiple search queries

**Complexity**:
- Time: O(log n) - binary search approach
- Space: O(log n) - recursive call stack

**Run**: `./examples/problem6_rotated_search`

---

### Problem 7: Merge Overlapping Intervals
**File**: `examples/problem7_merge_intervals.c`  
**Difficulty**: Medium  
**Data Structure Used**: Array of Intervals with Sorting

**Problem**: Given a collection of intervals, merge all overlapping intervals.

**Solution Approach**:
- Sort intervals by start time
- Iterate and merge overlapping intervals
- Track current merged interval

**Sorting Library Functions Used**:
- `quickSort()` - Sort interval start/end times
- Custom bubble sort for interval structures

**Features**:
- ✅ Merge overlapping intervals
- ✅ Insert new interval and merge
- ✅ Check if can attend all meetings (no overlap)
- ✅ Find minimum meeting rooms required
- ✅ Multiple test cases

**Complexity**:
- Time: O(n log n) - sorting dominates
- Space: O(n) - result array

**Run**: `./examples/problem7_merge_intervals`

---

### Problem 8: Find Peak Element
**File**: `examples/problem8_peak_element.c`  
**Difficulty**: Medium  
**Data Structure Used**: Array with Binary Search

**Problem**: A peak element is greater than its neighbors. Find any peak efficiently.

**Solution Approach**:
- Modified binary search
- If mid < mid+1, peak is on right
- Otherwise, peak is on left (including mid)
- Works because array has at least one peak

**Searching Library Functions Used**:
- `binarySearchRecursive()` - Search in mountain array
- Modified binary search for peak finding

**Features**:
- ✅ Find a peak element (O(log n))
- ✅ Find all peak elements
- ✅ Find maximum element (global peak)
- ✅ Detect mountain array
- ✅ Find peak in mountain array
- ✅ Search in mountain array

**Complexity**:
- Time: O(log n) - binary search for single peak
- Space: O(1) - constant space

**Run**: `./examples/problem8_peak_element`

---

## Updated Summary Table

| Problem | Data Structure | Key Algorithm | Time | Space |
|---------|---------------|---------------|------|-------|
| **Problem 1** | Queue | BFS | O(n) | O(w) |
| **Problem 2** | Deque | Monotonic Deque | O(n) | O(k) |
| **Problem 3** | Singly/Doubly List | Reversal | O(n) | O(1) |
| **Problem 4** | Singly List | Floyd's Cycle | O(n) | O(1) |
| **Problem 5** | Array + Sort | Quick Sort | O(n log n) | O(n) |
| **Problem 6** | Array + Search | Binary Search | O(log n) | O(log n) |
| **Problem 7** | Intervals + Sort | Merge Intervals | O(n log n) | O(n) |
| **Problem 8** | Array + Search | Peak Finding | O(log n) | O(1) |

---

## Updated Build and Run Instructions

### Build All 8 Problems
```bash
make examples
```

### Run All 8 Problems
```bash
make run_examples
```

### Run Individual Problems
```bash
# Queue-based problems
./examples/problem1_level_order_tree
./examples/problem2_sliding_window

# Linked List problems
./examples/problem3_reverse_linked_list
./examples/problem4_detect_cycle

# Sorting problems
./examples/problem5_kth_largest
./examples/problem7_merge_intervals

# Searching problems
./examples/problem6_rotated_search
./examples/problem8_peak_element
```

---

## Additional Key Learnings

### Sorting Problems (5, 7)
- ✅ Sorting enables efficient kth element finding
- ✅ Interval problems require sorting by start time
- ✅ Quick Sort provides O(n log n) performance
- ✅ Sorting simplifies complex problems

### Searching Problems (6, 8)
- ✅ Binary search works on rotated arrays with modification
- ✅ Peak finding uses binary search properties
- ✅ O(log n) solutions possible with sorted/partially sorted data
- ✅ Modified binary search solves many variants

---

## Updated Real-World Applications

**Problem 5 (Kth Largest)**: Top K queries, leaderboards, statistics, percentile calculations  
**Problem 6 (Rotated Search)**: Circular buffers, log rotation, time-series data  
**Problem 7 (Merge Intervals)**: Calendar scheduling, resource allocation, time slot management  
**Problem 8 (Peak Finding)**: Signal processing, stock market analysis, terrain mapping  

---

**All eight problems demonstrate comprehensive use of our DSA library across Queue, Linked List, Searching, and Sorting modules!** 🚀

# DSA Problems - Quick Reference Guide

## 🚀 All 8 Medium-Level Problems

### Quick Build & Run
```bash
# Build all problems
make examples

# Run all problems
make run_examples

# Clean and rebuild
make clean && make examples
```

---

## 📋 Problems Overview

| # | Problem | Library | Algorithm | Time | File |
|---|---------|---------|-----------|------|------|
| 1 | Level Order Tree | Queue | BFS | O(n) | `problem1_level_order_tree.c` |
| 2 | Sliding Window Max | Deque | Monotonic Deque | O(n) | `problem2_sliding_window.c` |
| 3 | Reverse Linked List | Linked List | Reversal | O(n) | `problem3_reverse_linked_list.c` |
| 4 | Detect Cycle | Linked List | Floyd's Algorithm | O(n) | `problem4_detect_cycle.c` |
| 5 | Kth Largest | Sorting | Quick Sort | O(n log n) | `problem5_kth_largest.c` |
| 6 | Rotated Search | Searching | Binary Search | O(log n) | `problem6_rotated_search.c` |
| 7 | Merge Intervals | Sorting | Interval Merge | O(n log n) | `problem7_merge_intervals.c` |
| 8 | Peak Element | Searching | Peak Finding | O(log n) | `problem8_peak_element.c` |

---

## 🎯 Run Individual Problems

### Queue Problems
```bash
./examples/problem1_level_order_tree    # BFS tree traversal
./examples/problem2_sliding_window      # Sliding window maximum
```

### Linked List Problems
```bash
./examples/problem3_reverse_linked_list # Reverse list operations
./examples/problem4_detect_cycle        # Floyd's cycle detection
```

### Sorting Problems
```bash
./examples/problem5_kth_largest         # Find kth largest element
./examples/problem7_merge_intervals     # Merge overlapping intervals
```

### Searching Problems
```bash
./examples/problem6_rotated_search      # Search in rotated array
./examples/problem8_peak_element        # Find peak elements
```

---

## 📚 Library Functions Used

### Queue Library (`queue.h`)
```c
initQueue()      // Initialize queue
enqueue()        // Add element
dequeue()        // Remove element
isEmpty()        // Check if empty
queueSize()      // Get size
```

### Deque Library (`deque.h`)
```c
initDeque()      // Initialize deque
insertRear()     // Add to rear
deleteRear()     // Remove from rear
deleteFront()    // Remove from front
peekFront()      // View front
peekRear()       // View rear
```

### Linked List Library (`singly_linked_list.h`, `doubly_linked_list.h`)
```c
initSList()      // Initialize singly list
insertAtEndS()   // Add to end
displayListS()   // Display list
freeListS()      // Free memory
initDList()      // Initialize doubly list
```

### Sorting Library (`sorting.h`)
```c
bubbleSort()     // O(n²) sorting
selectionSort()  // O(n²) sorting
insertionSort()  // O(n²) sorting
mergeSort()      // O(n log n) sorting
quickSort()      // O(n log n) sorting
heapSort()       // O(n log n) sorting
```

### Searching Library (`searching.h`)
```c
linearSearch()           // O(n) search
binarySearchIterative()  // O(log n) search
binarySearchRecursive()  // O(log n) search
```

---

## 🎓 Problem Categories

### By Data Structure
- **Queue**: Problems 1, 2
- **Linked List**: Problems 3, 4
- **Array + Sorting**: Problems 5, 7
- **Array + Searching**: Problems 6, 8

### By Algorithm Type
- **Graph Traversal**: Problem 1 (BFS)
- **Sliding Window**: Problem 2
- **Two Pointers**: Problems 3, 4
- **Divide & Conquer**: Problems 5, 6, 7, 8

### By Complexity
- **O(n)**: Problems 1, 2, 3, 4
- **O(n log n)**: Problems 5, 7
- **O(log n)**: Problems 6, 8

---

## 💡 Key Concepts Demonstrated

### Problem 1: BFS Traversal
- Level-order tree traversal
- Queue for BFS implementation
- Tracking levels and depth

### Problem 2: Monotonic Deque
- Sliding window optimization
- Maintaining monotonic property
- O(n) time for window problems

### Problem 3: List Reversal
- Iterative vs recursive reversal
- Reverse in groups
- Palindrome checking

### Problem 4: Cycle Detection
- Floyd's tortoise and hare
- Finding cycle start
- Removing cycles

### Problem 5: Selection Problems
- Kth largest/smallest
- Top K elements
- Median finding

### Problem 6: Modified Binary Search
- Search in rotated arrays
- Finding pivot points
- O(log n) in special arrays

### Problem 7: Interval Problems
- Sorting intervals
- Merging overlapping ranges
- Meeting room scheduling

### Problem 8: Peak Finding
- Binary search on peaks
- Mountain array detection
- Local vs global maxima

---

## 🔧 Makefile Targets

```bash
make              # Build library and main
make examples     # Build all 8 problems
make run_examples # Run all 8 problems
make clean        # Remove build artifacts
make distclean    # Remove everything
make help         # Show help message
```

---

## 📖 Documentation Files

- `README.md` - Main project documentation
- `PROBLEMS_SOLVED.md` - Detailed problem explanations
- `SEARCHING_SORTING_PROBLEMS.md` - Focus on problems 5-8
- `QUICK_REFERENCE.md` - This file
- `PROJECT_SUMMARY.md` - Project overview
- `QUEUE_TYPES.md` - Queue implementations

---

## 🎯 Real-World Applications

| Problem | Applications |
|---------|-------------|
| **Problem 1** | File systems, org charts, social networks |
| **Problem 2** | Stock analysis, network monitoring, sensor data |
| **Problem 3** | Undo operations, data transformation |
| **Problem 4** | Memory leak detection, infinite loop prevention |
| **Problem 5** | Leaderboards, statistics, percentiles |
| **Problem 6** | Circular buffers, log rotation, time-series |
| **Problem 7** | Calendar scheduling, resource allocation |
| **Problem 8** | Signal processing, stock analysis, terrain mapping |

---

## ✅ Testing

All problems include multiple test cases:
- ✅ Basic functionality tests
- ✅ Edge cases (empty, single element)
- ✅ Complex scenarios
- ✅ Performance demonstrations

---

## 🚀 Next Steps

1. **Study the code**: Read through each problem's implementation
2. **Run the examples**: Execute each problem to see output
3. **Modify and experiment**: Try different inputs
4. **Solve variations**: Extend problems with new features
5. **Optimize**: Try different approaches and compare

---

**Happy Coding! 🎉**

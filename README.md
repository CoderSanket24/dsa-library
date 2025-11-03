# DSA Library

A comprehensive C library implementing fundamental data structures and algorithms.

## Data Structures Included

### 1. Queue (FIFO - First In, First Out)
- `initQueue()` - Initialize queue
- `enqueue()` - Add element to rear
- `dequeue()` - Remove element from front
- `isEmpty()` - Check if queue is empty
- `isFull()` - Check if queue is full
- `displayQueue()` - Print queue contents

### 2. Stack (LIFO - Last In, First Out)
- `initStack()` - Initialize stack
- `push()` - Add element to top
- `pop()` - Remove element from top
- `peek()` - View top element without removing
- `isEmpty_stack()` - Check if stack is empty
- `isFull_stack()` - Check if stack is full
- `displayStack()` - Print stack contents

### 3. Linked List (Dynamic)
- `initList()` - Initialize list
- `insertAtBeginning()` - Insert at start
- `insertAtEnd()` - Insert at end
- `insertAtPosition()` - Insert at specific position
- `deleteValue()` - Delete by value
- `deleteAtPosition()` - Delete by position
- `search()` - Search for value
- `getSize()` - Get list size
- `displayList()` - Print list contents
- `freeList()` - Free memory

### 4. Binary Search Tree (BST)
- `initBST()` - Initialize BST
- `insertBST()` - Insert value
- `searchBST()` - Search for value
- `deleteBST()` - Delete value
- `inorderTraversal()` - In-order traversal
- `preorderTraversal()` - Pre-order traversal
- `postorderTraversal()` - Post-order traversal
- `findMin()` - Find minimum value
- `findMax()` - Find maximum value
- `freeBST()` - Free memory

### 5. Graph (Adjacency List)
- `createGraph()` - Create graph with V vertices
- `addEdge()` - Add edge between vertices
- `printGraph()` - Print adjacency list
- `freeGraph()` - Free memory

## Algorithms Included

### Searching Algorithms
- **Linear Search** - O(n) time complexity
  - `linearSearch()` - Search unsorted array sequentially
- **Binary Search** - O(log n) time complexity (requires sorted array)
  - `binarySearchIterative()` - Iterative implementation
  - `binarySearchRecursive()` - Recursive implementation

### Sorting Algorithms
- **Bubble Sort** - O(n²) time complexity
  - `bubbleSort()` - Simple comparison-based sort
- **Selection Sort** - O(n²) time complexity
  - `selectionSort()` - Find minimum and swap
- **Insertion Sort** - O(n²) time complexity, efficient for small arrays
  - `insertionSort()` - Insert elements in sorted position
- **Merge Sort** - O(n log n) time complexity, stable sort
  - `mergeSort()` - Divide and conquer approach
- **Quick Sort** - O(n log n) average time complexity
  - `quickSort()` - Partition-based sorting
- **Heap Sort** - O(n log n) time complexity
  - `heapSort()` - Binary heap-based sorting
- **Counting Sort** - O(n + k) time complexity for integer arrays
  - `countingSort()` - Non-comparison based sort

## Building the Library

```bash
# Build the static library
make

# Clean build files
make clean

# Build and run main demo
make && ./main

# Test individual components
make test_searching && ./test_searching
make test_sorting && ./test_sorting
make test_algorithms && ./test_algorithms
```

## Usage Example

```c
#include "dsa.h"

int main() {
    // Queue example
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    displayQueue(&q);
    
    // Stack example
    Stack s;
    initStack(&s);
    push(&s, 30);
    push(&s, 40);
    displayStack(&s);
    
    return 0;
}
```

## File Structure

```
├── Makefile              # Build configuration
├── README.md             # This file
├── dsa.h                # Main header file
├── dsa.c                # Utility functions
├── queue.h/.c           # Queue implementation
├── stack.h/.c           # Stack implementation
├── linkedlist.h/.c      # Linked list implementation
├── bst.h/.c             # Binary search tree implementation
├── graph.h/.c           # Graph implementation
├── searching.h/.c       # Searching algorithms
├── sorting.h/.c         # Sorting algorithms
├── main.c               # Demo program
├── test_*.c             # Individual test programs
└── test_algorithms.c    # Combined algorithms demo
```

## Features

- Memory-safe implementations
- Comprehensive error checking
- Clean, readable code
- Modular design
- Static library compilation
- Cross-platform compatibility

## Requirements

- GCC compiler
- Make utility
- Standard C library

## License

Open source - feel free to use and modify for educational purposes.
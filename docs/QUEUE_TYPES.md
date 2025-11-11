# Queue Types Implementation

## Overview

The DSA library now includes **4 different types of queues**, each optimized for specific use cases.

## Queue Types

### 1. Queue (Simple Linear Queue)
**File**: `queue.h` / `queue.c`

**Description**: Basic FIFO (First-In-First-Out) queue with linear array implementation.

**Operations**:
- `initQueue()` - Initialize queue
- `enqueue()` - Add element to rear
- `dequeue()` - Remove element from front
- `peekQueue()` - View front element
- `queueSize()` - Get current size
- `isEmpty()` - Check if empty
- `isFull()` - Check if full
- `displayQueue()` - Display contents
- `clearQueue()` - Clear all elements

**Time Complexity**:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

**Use Cases**:
- Task scheduling
- Print queue
- Breadth-first search

---

### 2. Circular Queue
**File**: `circular_queue.h` / `circular_queue.c`

**Description**: Queue with circular array implementation that reuses empty spaces efficiently.

**Operations**:
- `initCircularQueue()` - Initialize queue
- `circularEnqueue()` - Add element (wraps around)
- `circularDequeue()` - Remove element
- `circularPeek()` - View front element
- `circularQueueSize()` - Get current size
- `isCircularQueueEmpty()` - Check if empty
- `isCircularQueueFull()` - Check if full
- `displayCircularQueue()` - Display contents
- `clearCircularQueue()` - Clear all elements

**Time Complexity**:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

**Advantages**:
- Better space utilization
- No wasted space after dequeue
- Efficient for continuous operations

**Use Cases**:
- CPU scheduling (Round Robin)
- Buffer management
- Traffic light systems

---

### 3. Priority Queue
**File**: `priority_queue.h` / `priority_queue.c`

**Description**: Queue where elements are served based on priority (lower number = higher priority).

**Operations**:
- `initPriorityQueue()` - Initialize queue
- `priorityEnqueue(value, priority)` - Add with priority
- `priorityDequeue()` - Remove highest priority element
- `priorityPeek()` - View highest priority element
- `priorityQueueSize()` - Get current size
- `isPriorityQueueEmpty()` - Check if empty
- `isPriorityQueueFull()` - Check if full
- `displayPriorityQueue()` - Display with priorities
- `clearPriorityQueue()` - Clear all elements

**Time Complexity**:
- Enqueue: O(n) - maintains sorted order
- Dequeue: O(1) - highest priority at front
- Peek: O(1)

**Priority System**:
- Lower number = Higher priority
- Priority 1 > Priority 2 > Priority 3

**Use Cases**:
- Hospital emergency room
- Operating system task scheduling
- Network packet routing
- Event-driven simulation

---

### 4. Deque (Double-ended Queue)
**File**: `deque.h` / `deque.c`

**Description**: Queue that allows insertion and deletion from both ends.

**Operations**:
- `initDeque()` - Initialize deque
- `insertFront()` - Add element at front
- `insertRear()` - Add element at rear
- `deleteFront()` - Remove from front
- `deleteRear()` - Remove from rear
- `peekFront()` - View front element
- `peekRear()` - View rear element
- `dequeSize()` - Get current size
- `isDequeEmpty()` - Check if empty
- `isDequeFull()` - Check if full
- `displayDeque()` - Display contents
- `clearDeque()` - Clear all elements

**Time Complexity**:
- Insert (both ends): O(1)
- Delete (both ends): O(1)
- Peek (both ends): O(1)

**Use Cases**:
- Undo/Redo operations
- Browser history (forward/backward)
- Palindrome checking
- Sliding window problems

---

## Comparison Table

| Feature | Simple Queue | Circular Queue | Priority Queue | Deque |
|---------|-------------|----------------|----------------|-------|
| **Insert Front** | ❌ | ❌ | ❌ | ✅ |
| **Insert Rear** | ✅ | ✅ | ✅ | ✅ |
| **Delete Front** | ✅ | ✅ | ✅ | ✅ |
| **Delete Rear** | ❌ | ❌ | ❌ | ✅ |
| **Priority** | ❌ | ❌ | ✅ | ❌ |
| **Space Efficient** | ❌ | ✅ | ✅ | ✅ |
| **Complexity (Insert)** | O(1) | O(1) | O(n) | O(1) |
| **Complexity (Delete)** | O(1) | O(1) | O(1) | O(1) |

## Usage Examples

### Simple Queue
```c
Queue q;
initQueue(&q);
enqueue(&q, 10);
enqueue(&q, 20);
int value;
dequeue(&q, &value);  // value = 10
```

### Circular Queue
```c
CircularQueue cq;
initCircularQueue(&cq);
circularEnqueue(&cq, 10);
circularEnqueue(&cq, 20);
int value;
circularDequeue(&cq, &value);  // value = 10
circularEnqueue(&cq, 30);      // Reuses space
```

### Priority Queue
```c
PriorityQueue pq;
initPriorityQueue(&pq);
priorityEnqueue(&pq, 100, 3);  // Low priority
priorityEnqueue(&pq, 200, 1);  // High priority
int value;
priorityDequeue(&pq, &value);  // value = 200 (highest priority)
```

### Deque
```c
Deque dq;
initDeque(&dq);
insertRear(&dq, 10);
insertFront(&dq, 5);
int value;
deleteFront(&dq, &value);  // value = 5
deleteRear(&dq, &value);   // value = 10
```

## When to Use Which Queue?

### Use Simple Queue when:
- Basic FIFO operations needed
- Simple task scheduling
- Learning queue concepts

### Use Circular Queue when:
- Continuous enqueue/dequeue operations
- Fixed-size buffer needed
- Space efficiency is important

### Use Priority Queue when:
- Elements have different priorities
- Need to process important items first
- Implementing scheduling algorithms

### Use Deque when:
- Need insertion/deletion at both ends
- Implementing undo/redo
- Sliding window algorithms
- Need maximum flexibility

## Performance Summary

All queue types provide:
- ✅ Constant time O(1) for basic operations (except Priority Queue enqueue)
- ✅ Fixed memory allocation
- ✅ No dynamic memory overhead
- ✅ Cache-friendly array-based implementation

## Integration

All queue types are integrated into the main DSA library:
- Include: `#include "dsa.h"` (includes all queue types)
- Link: `-ldsa` (static library)
- Build: `make` (compiles all queue implementations)

---

**Total Queue Implementations: 4**  
**Total Queue Operations: 40+**  
**All tested and working! ✅**
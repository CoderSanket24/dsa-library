# DSA Problems Solved Using Queue Libraries

## ✅ Two Medium-Level Problems Implemented

### Problem 1: Binary Tree Level Order Traversal
**File**: `examples/problem1_level_order_tree.c`  
**Difficulty**: Medium  
**Queue Used**: Simple Queue (for BFS)

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
- ✅ Multiple test cases

**Complexity**:
- Time: O(n) where n = number of nodes
- Space: O(w) where w = maximum width of tree

**Run**: `./examples/problem1_level_order_tree`

---

### Problem 2: Sliding Window Maximum
**File**: `examples/problem2_sliding_window.c`  
**Difficulty**: Medium  
**Queue Used**: Deque (Double-ended Queue)

**Problem**: Find the maximum value in each sliding window of size k.

**Solution Approach**:
- Use Deque to maintain indices of useful elements
- Keep elements in decreasing order
- Remove elements outside window from front
- Remove smaller elements from rear

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

## How to Build and Run

```bash
# Build all examples including problems
make examples

# Run Problem 1
./examples/problem1_level_order_tree

# Run Problem 2
./examples/problem2_sliding_window
```

## Key Learnings

### Problem 1 (BFS)
- Queue is perfect for level-order traversal
- FIFO property ensures level-by-level processing
- Can calculate tree properties efficiently

### Problem 2 (Sliding Window)
- Deque enables O(n) solution (vs O(n*k) naive)
- Monotonic deque pattern is powerful
- Both-end operations are crucial

## Real-World Applications

**Problem 1**:
- File system traversal
- Organization hierarchy
- Social network analysis
- Game AI tree exploration

**Problem 2**:
- Stock price analysis
- Network traffic monitoring
- Sensor data processing
- Video frame analysis

---

**Both problems demonstrate efficient use of queue data structures to solve real algorithmic challenges!** 🎉
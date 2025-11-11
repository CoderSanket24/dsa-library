# DSA Library - Data Structures and Algorithms in C

A comprehensive, production-ready C library implementing fundamental data structures and algorithms with real-world applications.

## 📁 Project Structure

```
dsa-library/
├── src/                    # Source files (.c)
│   ├── queue.c
│   ├── stack.c
│   ├── linkedlist.c
│   ├── bst.c
│   ├── graph.c
│   ├── dsa.c
│   ├── searching.c
│   └── sorting.c
│
├── include/                # Header files (.h)
│   ├── queue.h
│   ├── stack.h
│   ├── linkedlist.h
│   ├── bst.h
│   ├── graph.h
│   ├── dsa.h
│   ├── searching.h
│   └── sorting.h
│

├── examples/               # Real-world applications
│   ├── example_expression.c
│   ├── example_scheduler.c
│   ├── example_social.c
│   ├── example_students.c
│   ├── example_palindrome.c
│   ├── example_topk.c
│   ├── example_undo.c
│   ├── Makefile
│   └── README.md
│
├── build/                  # Build artifacts (generated)
│   ├── *.o                # Object files
│   └── libdsa.a           # Static library
│
├── docs/                   # Documentation
│   ├── README.md          # User guide
│   ├── PROJECT_REPORT.md  # Technical report
│   └── PRESENTATION_GUIDE.md
│
├── Makefile               # Main build file
├── main.c                 # Demo program
└── demo.sh               # Interactive demo script
```

## 🚀 Quick Start

### Option 1: Run Complete Demo
```bash
chmod +x demo.sh
./demo.sh
```

### Option 2: Build and Test Manually
```bash
# Build library
make

# Run main demo
./main

# Build and run examples
make examples
cd examples && ./example_expression
```

## 📚 Data Structures

| Structure | Implementation | Time Complexity | Use Cases |
|-----------|---------------|-----------------|-----------|
| **Queue** | Array-based | O(1) enqueue/dequeue | Task scheduling, BFS |
| **Stack** | Array-based | O(1) push/pop | Expression eval, undo/redo |
| **Linked List** | Dynamic | O(1) insert at head | Dynamic storage, playlists |
| **BST** | Recursive tree | O(log n) average | Database indexing, search |
| **Graph** | Adjacency list | O(V+E) space | Social networks, maps |

## 🔍 Algorithms

### Searching
- **Linear Search**: O(n) - works on any array
- **Binary Search**: O(log n) - requires sorted array (iterative & recursive)

### Sorting
- **Simple**: Bubble, Selection, Insertion - O(n²)
- **Advanced**: Merge, Quick, Heap - O(n log n)
- **Special**: Counting Sort - O(n+k)

## 💡 DSA Problem Solutions

### Problem 1: Binary Tree Level Order Traversal (Medium)
- **Queue Used**: Simple Queue (BFS)
- **Features**: Level traversal, max depth, right side view
- **Functions**: `initQueue()`, `enqueue()`, `dequeue()`, `isEmpty()`, `queueSize()`

### Problem 2: Sliding Window Maximum (Medium)
- **Queue Used**: Deque (Double-ended Queue)
- **Features**: Max/min/average in sliding windows
- **Functions**: `initDeque()`, `insertRear()`, `deleteRear()`, `deleteFront()`, `peekFront()`, `peekRear()`

## 🛠️ Build Commands

```bash
# Show all available commands
make help

# Build library and main program
make

# Build all examples
make examples

# Run all examples
make run_examples

# Clean build artifacts
make clean
```

## 📖 Documentation

- **[User Guide](docs/README.md)** - Detailed usage instructions
- **[Project Report](docs/PROJECT_REPORT.md)** - Technical documentation
- **[Presentation Guide](docs/PRESENTATION_GUIDE.md)** - Presentation tips
- **[Examples Guide](examples/README.md)** - Application examples

## ✅ Validation

All components are validated through:
- Main demo program showing all features
- Real-world example applications
- Performance demonstrations
- Practical use case scenarios

## 📊 Performance

**Searching (10,000 elements):**
- Linear Search: 0.00001s
- Binary Search: 0.000001s (10x faster)

**Sorting (1,000 elements):**
- Quick Sort: 0.111ms (fastest comparison-based)
- Counting Sort: 0.025ms (fastest for integers)

## 🎯 Features

✅ Modular design with clean separation  
✅ Memory-safe implementations  
✅ Comprehensive error handling  
✅ Static library compilation  
✅ Cross-platform compatibility  
✅ Production-ready code quality  
✅ Extensive documentation  
✅ Real-world applications  

## 📝 Usage Example

```c
#include "dsa.h"

int main() {
    // Use Queue
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    
    // Use Stack
    Stack s;
    initStack(&s);
    push(&s, 20);
    
    // Use BST
    BST tree;
    initBST(&tree);
    insertBST(&tree, 50);
    
    // Use Sorting
    int arr[] = {5, 2, 8, 1, 9};
    quickSort(arr, 0, 4);
    
    return 0;
}
```

## 🔧 Requirements

- GCC compiler
- Make utility
- Linux/Unix environment

## 📄 License

Open source - free to use and modify for educational purposes.

## 👨‍💻 Author

Created as a course project for Data Structures and Algorithms.

---

**For detailed documentation, see the `docs/` directory.**
# DSA Library - Complete Index

## 📖 Start Here

**New to this project?** → Read [README.md](README.md)  
**Want quick overview?** → Read [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)  
**Need to navigate?** → Read [NAVIGATION.md](NAVIGATION.md)  
**Want to see structure?** → Read [STRUCTURE.md](STRUCTURE.md) or [DIRECTORY_TREE.txt](DIRECTORY_TREE.txt)

## 📚 All Documentation Files

### Root Level Documentation
| File | Purpose | When to Read |
|------|---------|--------------|
| [README.md](README.md) | Main project overview | First time users |
| [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) | Quick summary | Quick reference |
| [STRUCTURE.md](STRUCTURE.md) | File organization | Understanding layout |
| [NAVIGATION.md](NAVIGATION.md) | Navigation guide | Finding things |
| [INDEX.md](INDEX.md) | This file | Finding documentation |
| [DIRECTORY_TREE.txt](DIRECTORY_TREE.txt) | Visual tree | Visual reference |

### Documentation Directory (docs/)
| File | Purpose | When to Read |
|------|---------|--------------|
| [docs/README.md](docs/README.md) | Documentation hub | API reference |
| [docs/PROJECT_REPORT.md](docs/PROJECT_REPORT.md) | Technical report | Deep dive |
| [docs/PRESENTATION_GUIDE.md](docs/PRESENTATION_GUIDE.md) | Presentation tips | Before presenting |

### Examples Documentation
| File | Purpose | When to Read |
|------|---------|--------------|
| [examples/README.md](examples/README.md) | Examples guide | Using examples |

## 🗂️ Source Code Index

### Data Structure Headers (include/)
- [include/queue.h](include/queue.h) - Queue API
- [include/stack.h](include/stack.h) - Stack API
- [include/linkedlist.h](include/linkedlist.h) - Linked List API
- [include/bst.h](include/bst.h) - Binary Search Tree API
- [include/graph.h](include/graph.h) - Graph API
- [include/dsa.h](include/dsa.h) - Main library header

### Algorithm Headers (include/)
- [include/searching.h](include/searching.h) - Search algorithms API
- [include/sorting.h](include/sorting.h) - Sort algorithms API

### Data Structure Implementation (src/)
- [src/queue.c](src/queue.c) - Queue implementation
- [src/stack.c](src/stack.c) - Stack implementation
- [src/linkedlist.c](src/linkedlist.c) - Linked List implementation
- [src/bst.c](src/bst.c) - BST implementation
- [src/graph.c](src/graph.c) - Graph implementation
- [src/dsa.c](src/dsa.c) - Library utilities

### Algorithm Implementation (src/)
- [src/searching.c](src/searching.c) - Search algorithms
- [src/sorting.c](src/sorting.c) - Sort algorithms

## 🧪 Test Programs Index

### Test Files (tests/)
- [tests/test_queue.c](tests/test_queue.c) - Queue tests
- [tests/test_bst.c](tests/test_bst.c) - BST tests
- [tests/test_searching.c](tests/test_searching.c) - Search tests
- [tests/test_sorting.c](tests/test_sorting.c) - Sort tests
- [tests/test_algorithms.c](tests/test_algorithms.c) - Combined tests

### How to Run Tests
```bash
make tests              # Build all tests
./test_searching        # Run search tests
./test_sorting          # Run sort tests
./test_bst             # Run BST tests
```

## 💡 Examples Index

### Example Programs (examples/)
1. [examples/example_expression.c](examples/example_expression.c) - Expression Evaluator
   - **Uses**: Stack
   - **Real-world**: Calculators, compilers
   
2. [examples/example_scheduler.c](examples/example_scheduler.c) - Task Scheduler
   - **Uses**: Queue
   - **Real-world**: OS scheduling, print queues
   
3. [examples/example_social.c](examples/example_social.c) - Social Network
   - **Uses**: Graph
   - **Real-world**: Facebook, LinkedIn
   
4. [examples/example_students.c](examples/example_students.c) - Student Database
   - **Uses**: BST + Sorting
   - **Real-world**: School systems, databases
   
5. [examples/example_palindrome.c](examples/example_palindrome.c) - Palindrome Checker
   - **Uses**: Stack
   - **Real-world**: Data validation, DNA analysis
   
6. [examples/example_topk.c](examples/example_topk.c) - Top K Elements
   - **Uses**: Sorting
   - **Real-world**: Leaderboards, rankings
   
7. [examples/example_undo.c](examples/example_undo.c) - Undo/Redo System
   - **Uses**: Dual Stack
   - **Real-world**: Text editors, graphics software

### How to Run Examples
```bash
make examples                      # Build all examples
cd examples
./example_expression              # Run specific example
```

## 🔧 Build System Index

### Build Files
- [Makefile](Makefile) - Main build configuration
- [examples/Makefile](examples/Makefile) - Examples build configuration

### Build Commands
```bash
make              # Build library and main
make tests        # Build all tests
make examples     # Build all examples
make clean        # Clean build artifacts
make distclean    # Clean everything
make help         # Show help
```

## 🎬 Demo Files

### Demo Programs
- [main.c](main.c) - Main demo program
- [demo.sh](demo.sh) - Interactive demo script

### How to Run Demos
```bash
./main            # Run main demo
./demo.sh         # Run interactive demo
```

## 📊 Quick Reference Tables

### Data Structures Quick Reference
| Structure | Header | Source | Test | Time Complexity |
|-----------|--------|--------|------|-----------------|
| Queue | queue.h | queue.c | test_queue.c | O(1) |
| Stack | stack.h | stack.c | - | O(1) |
| Linked List | linkedlist.h | linkedlist.c | - | O(1) insert |
| BST | bst.h | bst.c | test_bst.c | O(log n) avg |
| Graph | graph.h | graph.c | - | O(V+E) space |

### Algorithms Quick Reference
| Algorithm | Type | Header | Source | Test | Complexity |
|-----------|------|--------|--------|------|------------|
| Linear Search | Search | searching.h | searching.c | test_searching.c | O(n) |
| Binary Search | Search | searching.h | searching.c | test_searching.c | O(log n) |
| Bubble Sort | Sort | sorting.h | sorting.c | test_sorting.c | O(n²) |
| Quick Sort | Sort | sorting.h | sorting.c | test_sorting.c | O(n log n) |
| Merge Sort | Sort | sorting.h | sorting.c | test_sorting.c | O(n log n) |
| Heap Sort | Sort | sorting.h | sorting.c | test_sorting.c | O(n log n) |
| Counting Sort | Sort | sorting.h | sorting.c | test_sorting.c | O(n+k) |

## 🎯 Common Tasks Index

### Task: Learn the Project
1. Read [README.md](README.md)
2. Run `./main`
3. Explore [examples/](examples/)
4. Read [docs/PROJECT_REPORT.md](docs/PROJECT_REPORT.md)

### Task: Use the Library
1. Include headers from `include/`
2. Link with `build/libdsa.a`
3. See [examples/](examples/) for usage
4. Check [docs/README.md](docs/README.md) for API

### Task: Present the Project
1. Read [docs/PRESENTATION_GUIDE.md](docs/PRESENTATION_GUIDE.md)
2. Practice with `./demo.sh`
3. Review [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)
4. Prepare examples

### Task: Extend the Project
1. Study existing code in `src/` and `include/`
2. Follow the same pattern
3. Update Makefile
4. Add tests and examples

## 🔍 Search Index

### By Topic

**Queue**:
- API: [include/queue.h](include/queue.h)
- Implementation: [src/queue.c](src/queue.c)
- Test: [tests/test_queue.c](tests/test_queue.c)
- Example: [examples/example_scheduler.c](examples/example_scheduler.c)

**Stack**:
- API: [include/stack.h](include/stack.h)
- Implementation: [src/stack.c](src/stack.c)
- Examples: [examples/example_expression.c](examples/example_expression.c), [examples/example_undo.c](examples/example_undo.c)

**Linked List**:
- API: [include/linkedlist.h](include/linkedlist.h)
- Implementation: [src/linkedlist.c](src/linkedlist.c)

**BST**:
- API: [include/bst.h](include/bst.h)
- Implementation: [src/bst.c](src/bst.c)
- Test: [tests/test_bst.c](tests/test_bst.c)
- Example: [examples/example_students.c](examples/example_students.c)

**Graph**:
- API: [include/graph.h](include/graph.h)
- Implementation: [src/graph.c](src/graph.c)
- Example: [examples/example_social.c](examples/example_social.c)

**Searching**:
- API: [include/searching.h](include/searching.h)
- Implementation: [src/searching.c](src/searching.c)
- Test: [tests/test_searching.c](tests/test_searching.c)

**Sorting**:
- API: [include/sorting.h](include/sorting.h)
- Implementation: [src/sorting.c](src/sorting.c)
- Test: [tests/test_sorting.c](tests/test_sorting.c)
- Examples: [examples/example_students.c](examples/example_students.c), [examples/example_topk.c](examples/example_topk.c)

## 📞 Getting Help

**Can't find something?**
1. Check this INDEX.md
2. Read [NAVIGATION.md](NAVIGATION.md)
3. See [STRUCTURE.md](STRUCTURE.md)
4. Browse [docs/README.md](docs/README.md)

**Build issues?**
1. Run `make clean && make`
2. Check [Makefile](Makefile)
3. See build/ directory

**Usage questions?**
1. Check [examples/](examples/)
2. Read [docs/README.md](docs/README.md)
3. See header files in [include/](include/)

## 🎓 Learning Path

### Beginner Path
1. [README.md](README.md) → Overview
2. [main.c](main.c) → Basic usage
3. [examples/](examples/) → Real applications
4. [include/](include/) → API reference

### Intermediate Path
1. [docs/PROJECT_REPORT.md](docs/PROJECT_REPORT.md) → Technical details
2. [src/](src/) → Implementation
3. [tests/](tests/) → Testing
4. Modify and extend

### Advanced Path
1. Study all source code
2. Add new features
3. Optimize performance
4. Create new examples

---

**This index provides complete navigation for the entire project!**
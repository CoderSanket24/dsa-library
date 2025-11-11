# DSA Library - Project Structure

## 📂 Directory Tree

```
dsa-library/
│
├── 📁 src/                          # Source Implementation Files
│   ├── queue.c                      # Queue implementation
│   ├── stack.c                      # Stack implementation
│   ├── linkedlist.c                 # Linked list implementation
│   ├── bst.c                        # Binary search tree implementation
│   ├── graph.c                      # Graph implementation
│   ├── dsa.c                        # Library utilities
│   ├── searching.c                  # Search algorithms
│   └── sorting.c                    # Sort algorithms
│
├── 📁 include/                      # Header Files (Public API)
│   ├── queue.h                      # Queue interface
│   ├── stack.h                      # Stack interface
│   ├── linkedlist.h                 # Linked list interface
│   ├── bst.h                        # BST interface
│   ├── graph.h                      # Graph interface
│   ├── dsa.h                        # Main library header
│   ├── searching.h                  # Search algorithms interface
│   └── sorting.h                    # Sort algorithms interface
│
├── 📁 tests/                        # Test Programs
│   ├── test_queue.c                 # Queue unit tests
│   ├── test_bst.c                   # BST unit tests
│   ├── test_searching.c             # Search algorithm tests
│   ├── test_sorting.c               # Sort algorithm tests
│   └── test_algorithms.c            # Combined algorithm tests
│
├── 📁 examples/                     # Real-World Applications
│   ├── example_expression.c         # Expression evaluator (Stack)
│   ├── example_scheduler.c          # Task scheduler (Queue)
│   ├── example_social.c             # Social network (Graph)
│   ├── example_students.c           # Student database (BST + Sort)
│   ├── example_palindrome.c         # Palindrome checker (Stack)
│   ├── example_topk.c               # Top K elements (Sorting)
│   ├── example_undo.c               # Undo/Redo system (Dual Stack)
│   ├── Makefile                     # Examples build file
│   └── README.md                    # Examples documentation
│
├── 📁 build/                        # Build Artifacts (Generated)
│   ├── *.o                          # Object files
│   └── libdsa.a                     # Static library
│
├── 📁 docs/                         # Documentation
│   ├── README.md                    # Documentation index
│   ├── PROJECT_REPORT.md            # Technical report
│   └── PRESENTATION_GUIDE.md        # Presentation guide
│
├── 📄 Makefile                      # Main build configuration
├── 📄 main.c                        # Main demo program
├── 📄 demo.sh                       # Interactive demo script
├── 📄 README.md                     # Project overview
└── 📄 STRUCTURE.md                  # This file
```

## 🗂️ File Organization

### Source Files (`src/`)
**Purpose**: Implementation of all data structures and algorithms  
**Access**: Private implementation details  
**Compiled to**: Object files in `build/`

### Header Files (`include/`)
**Purpose**: Public API declarations  
**Access**: Include in your programs  
**Usage**: `#include "queue.h"`

### Test Files (`tests/`)
**Purpose**: Validate correctness and performance  
**Access**: Standalone test programs  
**Run**: `./test_searching`, `./test_sorting`, etc.

### Example Files (`examples/`)
**Purpose**: Real-world problem solutions  
**Access**: Demonstration programs  
**Run**: `cd examples && ./example_expression`

### Build Directory (`build/`)
**Purpose**: Compiled artifacts  
**Generated**: Automatically by make  
**Contains**: Object files (*.o) and library (libdsa.a)

### Documentation (`docs/`)
**Purpose**: Comprehensive project documentation  
**Access**: Read for detailed information  
**Includes**: Technical reports, guides, API docs

## 🔄 Build Flow

```
Source Files (src/*.c)
         ↓
    [Compile with headers from include/]
         ↓
   Object Files (build/*.o)
         ↓
    [Archive into library]
         ↓
  Static Library (build/libdsa.a)
         ↓
    [Link with programs]
         ↓
  Executables (main, test_*, example_*)
```

## 📋 File Relationships

### Data Structure Files
```
queue.h + queue.c       → Queue implementation
stack.h + stack.c       → Stack implementation
linkedlist.h + linkedlist.c → Linked List implementation
bst.h + bst.c          → Binary Search Tree implementation
graph.h + graph.c      → Graph implementation
```

### Algorithm Files
```
searching.h + searching.c → Search algorithms
sorting.h + sorting.c     → Sort algorithms
```

### Main Library
```
dsa.h + dsa.c          → Library utilities and info
```

### Test Programs
```
test_queue.c           → Tests queue.h/c
test_bst.c            → Tests bst.h/c
test_searching.c      → Tests searching.h/c
test_sorting.c        → Tests sorting.h/c
test_algorithms.c     → Tests multiple algorithms
```

### Example Programs
```
example_expression.c   → Uses stack.h
example_scheduler.c    → Uses queue.h
example_social.c       → Uses graph.h
example_students.c     → Uses bst.h + sorting.h
example_palindrome.c   → Uses stack.h
example_topk.c        → Uses sorting.h
example_undo.c        → Uses stack.h
```

## 🎯 Navigation Guide

### I want to...

**...understand the project**
→ Start with `README.md`

**...see the code**
→ Browse `src/` and `include/`

**...run examples**
→ Go to `examples/` directory

**...read documentation**
→ Check `docs/` directory

**...run tests**
→ Use `tests/` programs

**...build the project**
→ Use root `Makefile`

**...present the project**
→ Read `docs/PRESENTATION_GUIDE.md`

## 🔧 Makefile Targets

```bash
make              # Build library and main
make tests        # Build all tests
make examples     # Build all examples
make clean        # Remove build artifacts
make distclean    # Remove everything
make help         # Show all targets
```

## 📊 File Statistics

- **Source Files**: 8 (.c files in src/)
- **Header Files**: 8 (.h files in include/)
- **Test Programs**: 5 (in tests/)
- **Example Programs**: 7 (in examples/)
- **Documentation**: 3 (in docs/)
- **Total Lines**: ~5000+ lines of code

## 🎨 Design Principles

1. **Separation of Concerns**: Headers separate from implementation
2. **Modularity**: Each data structure in its own file
3. **Reusability**: Static library for easy linking
4. **Testability**: Comprehensive test suite
5. **Documentation**: Clear docs and examples
6. **Organization**: Logical directory structure

## 🚀 Getting Started

1. **Clone/Download** the project
2. **Navigate** to root directory
3. **Run** `make` to build
4. **Execute** `./main` for demo
5. **Explore** examples and tests
6. **Read** documentation for details

---

**This structure ensures easy navigation, maintenance, and scalability!**
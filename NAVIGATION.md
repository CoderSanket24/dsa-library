# DSA Library - Quick Navigation Guide

## 🎯 I Want To...

### Get Started
```bash
# Read project overview
cat README.md

# Build everything
make

# Run demo
./main

# Run interactive demo
./demo.sh
```

### Understand the Code

**Data Structures:**
- Queue: `include/queue.h` + `src/queue.c`
- Stack: `include/stack.h` + `src/stack.c`
- Linked List: `include/linkedlist.h` + `src/linkedlist.c`
- BST: `include/bst.h` + `src/bst.c`
- Graph: `include/graph.h` + `src/graph.c`

**Algorithms:**
- Searching: `include/searching.h` + `src/searching.c`
- Sorting: `include/sorting.h` + `src/sorting.c`

### Run Tests
```bash
# Build all tests
make tests

# Run specific tests
./test_searching
./test_sorting
./test_bst
```

### See Real-World Examples
```bash
# Build examples
make examples

# Run examples
cd examples
./example_expression    # Calculator
./example_scheduler     # Task queue
./example_social        # Social network
./example_students      # Database
./example_palindrome    # String validation
./example_topk          # Rankings
./example_undo          # Undo/Redo
```

### Read Documentation
```bash
# Main documentation
cat docs/README.md

# Technical report
cat docs/PROJECT_REPORT.md

# Presentation guide
cat docs/PRESENTATION_GUIDE.md

# Project structure
cat STRUCTURE.md
```

### Build and Clean
```bash
# Build library
make

# Build tests
make tests

# Build examples
make examples

# Clean build files
make clean

# Clean everything
make distclean

# Show help
make help
```

## 📂 Directory Quick Reference

| Directory | Purpose | Key Files |
|-----------|---------|-----------|
| `src/` | Implementation | All .c files |
| `include/` | Public API | All .h files |
| `tests/` | Unit tests | test_*.c |
| `examples/` | Real-world apps | example_*.c |
| `build/` | Compiled files | *.o, libdsa.a |
| `docs/` | Documentation | *.md files |

## 🔍 Find Specific Information

### Algorithm Complexity
→ `docs/PROJECT_REPORT.md` (Algorithms section)

### API Reference
→ `docs/README.md` (API Documentation section)

### Usage Examples
→ `examples/` directory

### Performance Benchmarks
→ `docs/PROJECT_REPORT.md` (Performance Analysis section)

### Presentation Tips
→ `docs/PRESENTATION_GUIDE.md`

## 🚀 Common Tasks

### Task 1: Add New Data Structure
1. Create `include/mystructure.h`
2. Create `src/mystructure.c`
3. Update `Makefile` SOURCES and OBJECTS
4. Create `tests/test_mystructure.c`
5. Add to `include/dsa.h`

### Task 2: Create New Example
1. Create `examples/example_myapp.c`
2. Update `examples/Makefile`
3. Update `examples/README.md`

### Task 3: Run Full Demo
```bash
chmod +x demo.sh
./demo.sh
```

### Task 4: Prepare Presentation
1. Read `docs/PRESENTATION_GUIDE.md`
2. Test `./demo.sh`
3. Review `docs/PROJECT_REPORT.md`
4. Practice with examples

## 📊 File Count Summary

- **Source Files**: 8 (in `src/`)
- **Header Files**: 8 (in `include/`)
- **Test Programs**: 5 (in `tests/`)
- **Example Programs**: 7 (in `examples/`)
- **Documentation**: 4 (in `docs/` + root)
- **Build Files**: 1 Makefile + 1 in examples

## 🎓 Learning Path

### Beginner
1. Read `README.md`
2. Run `./main`
3. Explore `examples/`
4. Read header files in `include/`

### Intermediate
1. Read `docs/PROJECT_REPORT.md`
2. Study source files in `src/`
3. Run and modify tests
4. Create your own examples

### Advanced
1. Modify data structures
2. Add new algorithms
3. Optimize performance
4. Extend functionality

## 🔗 Quick Links

- **Main README**: `README.md`
- **Project Structure**: `STRUCTURE.md`
- **Documentation Hub**: `docs/README.md`
- **Examples Guide**: `examples/README.md`
- **Build System**: `Makefile`
- **Demo Script**: `demo.sh`

## 💡 Tips

1. **Always build first**: `make` before running programs
2. **Check docs**: Most questions answered in `docs/`
3. **Use examples**: Learn by seeing real applications
4. **Run tests**: Validate your changes
5. **Read headers**: API is in `include/` files

## 🆘 Troubleshooting

**Build fails?**
```bash
make clean
make
```

**Can't find library?**
```bash
# Library is in build/libdsa.a
# Make sure to build first: make
```

**Example won't run?**
```bash
# Build examples first
make examples
cd examples
./example_name
```

**Need help?**
```bash
make help
```

---

**Happy Coding! 🚀**
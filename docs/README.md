# DSA Library Documentation

Welcome to the comprehensive documentation for the DSA Library project.

## 📚 Documentation Files

### 1. [Project Report](PROJECT_REPORT.md)
**Complete technical documentation including:**
- Detailed implementation of each data structure
- Algorithm complexity analysis
- Performance benchmarks
- Testing methodology
- Project architecture
- Learning outcomes

**Read this for:** Technical details, implementation specifics, performance analysis

### 2. [Presentation Guide](PRESENTATION_GUIDE.md)
**Step-by-step presentation guide including:**
- Slide-by-slide breakdown (15-20 min presentation)
- Demo scripts and commands
- Key talking points
- Question handling tips
- Evaluation criteria

**Read this for:** Preparing your project presentation or demo

## 🚀 Quick Links

### Getting Started
- [Main README](../README.md) - Project overview and quick start
- [Examples Guide](../examples/README.md) - Real-world applications

### For Users
- **Installation**: See main README
- **API Reference**: Check header files in `include/` directory
- **Examples**: Browse `examples/` directory

### For Developers
- **Source Code**: `src/` directory
- **Headers**: `include/` directory
- **Tests**: `tests/` directory
- **Build System**: Root `Makefile`

## 📖 API Documentation

### Data Structures

#### Queue (queue.h)
```c
void initQueue(Queue *q);
bool enqueue(Queue *q, int value);
bool dequeue(Queue *q, int *removed);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void displayQueue(Queue *q);
```

#### Stack (stack.h)
```c
void initStack(Stack *s);
bool push(Stack *s, int value);
bool pop(Stack *s, int *popped);
bool peek(Stack *s, int *top_value);
bool isEmpty_stack(Stack *s);
bool isFull_stack(Stack *s);
void displayStack(Stack *s);
```

#### Linked List (linkedlist.h)
```c
void initList(LinkedList *list);
bool insertAtBeginning(LinkedList *list, int value);
bool insertAtEnd(LinkedList *list, int value);
bool insertAtPosition(LinkedList *list, int value, int position);
bool deleteValue(LinkedList *list, int value);
bool deleteAtPosition(LinkedList *list, int position);
bool search(LinkedList *list, int value);
int getSize(LinkedList *list);
void displayList(LinkedList *list);
void freeList(LinkedList *list);
```

#### Binary Search Tree (bst.h)
```c
void initBST(BST *bst);
bool insertBST(BST *bst, int value);
bool searchBST(BST *bst, int value);
bool deleteBST(BST *bst, int value);
void inorderTraversal(BST *bst);
void preorderTraversal(BST *bst);
void postorderTraversal(BST *bst);
int findMin(BST *bst);
int findMax(BST *bst);
void freeBST(BST *bst);
```

#### Graph (graph.h)
```c
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);
```

### Algorithms

#### Searching (searching.h)
```c
int linearSearch(int arr[], int n, int key);
int binarySearchIterative(int arr[], int n, int key);
int binarySearchRecursive(int arr[], int low, int high, int key);
```

#### Sorting (sorting.h)
```c
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void countingSort(int arr[], int n);
```

## 🎓 Learning Resources

### Understanding Time Complexity
- **O(1)**: Constant time - Queue/Stack operations
- **O(log n)**: Logarithmic - Binary search, BST operations
- **O(n)**: Linear - Linear search, array traversal
- **O(n log n)**: Linearithmic - Efficient sorting (merge, quick, heap)
- **O(n²)**: Quadratic - Simple sorting (bubble, selection, insertion)

### Best Practices
1. **Always initialize** data structures before use
2. **Check return values** for error handling
3. **Free memory** when done with dynamic structures
4. **Choose appropriate** data structure for your use case
5. **Consider complexity** when selecting algorithms

## 🔍 Troubleshooting

### Common Issues

**Build Errors:**
```bash
# Clean and rebuild
make clean
make
```

**Linking Errors:**
```bash
# Ensure library is built first
make
# Then build your program
gcc -Iinclude myprogram.c -Lbuild -ldsa -o myprogram
```

**Runtime Errors:**
- Check array bounds
- Verify initialization
- Ensure proper memory management

## 📞 Support

For questions or issues:
1. Check the documentation files
2. Review example programs
3. Examine test programs for usage patterns
4. Read inline code comments

## 🎯 Next Steps

1. **New Users**: Start with [main README](../README.md)
2. **Developers**: Read [Project Report](PROJECT_REPORT.md)
3. **Presenters**: Study [Presentation Guide](PRESENTATION_GUIDE.md)
4. **Learners**: Explore [examples](../examples/)

---

**Happy Coding! 🚀**
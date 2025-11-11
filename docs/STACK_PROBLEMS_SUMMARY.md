# Stack Problems Summary - Problems 11 & 12

## ✅ Two New Stack Problems Added!

### Problem 11: Valid Parentheses & Expression Evaluation
**File**: `examples/problem11_valid_parentheses.c`

#### Features
- ✅ Validate balanced parentheses/brackets
- ✅ Infix to Postfix conversion
- ✅ Postfix expression evaluation
- ✅ Longest valid parentheses substring
- ✅ Minimum removals to make valid
- ✅ Code syntax validation

#### Test Cases (6 tests)
1. **Basic Validation** - Check if brackets are balanced
2. **Expression Conversion** - Infix to Postfix
3. **Postfix Evaluation** - Calculate results
4. **Longest Valid** - Find longest valid substring
5. **Minimum Removals** - Count invalid brackets
6. **Code Validator** - Real-world syntax checking

#### Applications
- 🔧 Compiler design (expression parsing)
- 💻 Code editors (syntax validation)
- 🧮 Calculator applications
- 📝 Text editors (bracket matching)

---

### Problem 12: Next Greater Element & Monotonic Stack
**File**: `examples/problem12_next_greater.c`

#### Features
- ✅ Next Greater Element
- ✅ Next Smaller Element
- ✅ Previous Greater Element
- ✅ Stock Span Problem
- ✅ Largest Rectangle in Histogram
- ✅ Temperature Analysis

#### Test Cases (6 tests)
1. **Next Greater** - Find next larger element
2. **Next Smaller** - Find next smaller element
3. **Previous Greater** - Find previous larger element
4. **Stock Span** - Days since last higher price
5. **Largest Rectangle** - Maximum area in histogram
6. **Temperature Analysis** - Days until warmer weather

#### Applications
- 📈 Stock market analysis
- 🌡️ Weather forecasting
- 📊 Data visualization
- 🏗️ Architecture (building heights)

---

## 🎯 Key Concepts

### Monotonic Stack
A stack that maintains elements in monotonic (increasing or decreasing) order.

**Time Complexity**: O(n) - Each element pushed and popped at most once
**Space Complexity**: O(n) - Stack storage

### Stack Operations Used
```c
// CharStack for parentheses
charstack_init(&stack, capacity);
charstack_push(&stack, char);
charstack_pop(&stack);
charstack_peek(&stack);
charstack_is_empty(&stack);

// IntStack for monotonic problems
intstack_init(&stack, capacity);
intstack_push(&stack, value);
intstack_pop(&stack);
intstack_peek(&stack);
intstack_is_empty(&stack);
```

---

## 📊 Problem Comparison

| Problem | Algorithm | Time | Space | Difficulty |
|---------|-----------|------|-------|------------|
| **Problem 11** | Stack Matching | O(n) | O(n) | Medium |
| **Problem 12** | Monotonic Stack | O(n) | O(n) | Medium |

---

## 🚀 Build & Run

```bash
# Build both problems
make examples/problem11_valid_parentheses
make examples/problem12_next_greater

# Run Problem 11
./examples/problem11_valid_parentheses

# Run Problem 12
./examples/problem12_next_greater

# Run all problems
make run_examples
```

---

## 💡 Sample Output

### Problem 11 - Valid Parentheses
```
"()" -> Valid ✓
"()[]{}" -> Valid ✓
"(]" -> Invalid ✗
"([)]" -> Invalid ✗

Infix:   A+B*C
Postfix: ABC*+

Postfix: 23+
Result:  5
```

### Problem 12 - Next Greater Element
```
Array:         [4, 5, 2, 10, 8]
Next Greater:  [5, 10, 10, -, -]

Stock Prices:  [100, 80, 60, 70, 60, 75, 85]
Span:          [1, 1, 1, 2, 1, 4, 6]

Histogram:     [2, 1, 5, 6, 2, 3]
Max Area:      10
```

---

## 🎓 Learning Outcomes

### Problem 11 Teaches
- Stack-based parsing
- Expression conversion algorithms
- Bracket matching techniques
- Compiler design basics

### Problem 12 Teaches
- Monotonic stack pattern
- O(n) optimization techniques
- Stock market algorithms
- Histogram problems

---

## 📈 Real-World Impact

### Problem 11 Applications
- **Compilers**: Parse expressions and validate syntax
- **IDEs**: Real-time bracket matching
- **Calculators**: Evaluate mathematical expressions
- **Text Editors**: Auto-complete brackets

### Problem 12 Applications
- **Trading**: Stock span analysis
- **Weather**: Temperature trend prediction
- **Architecture**: Building design optimization
- **Data Viz**: Histogram analysis

---

## ✅ Files Added

- ✅ `examples/problem11_valid_parentheses.c` (~300 lines)
- ✅ `examples/problem12_next_greater.c` (~400 lines)
- ✅ `STACK_PROBLEMS_SUMMARY.md` - This file
- ✅ Updated `Makefile`
- ✅ Updated `.gitignore`

---

## 🎉 Project Status: 12 Problems Complete!

1. Level Order Tree (Queue/BFS)
2. Sliding Window (Deque)
3. Reverse Linked List
4. Detect Cycle (Floyd's)
5. Kth Largest (Sorting)
6. Rotated Search (Binary Search)
7. Merge Intervals (Sorting)
8. Peak Element (Binary Search)
9. Graph Algorithms (Topological, Cycle, Shortest Path)
10. Dijkstra's Algorithm (Weighted Shortest Path)
11. **Valid Parentheses** ⭐ NEW!
12. **Next Greater Element** ⭐ NEW!

**All 12 problems compile and run successfully!** 🎉

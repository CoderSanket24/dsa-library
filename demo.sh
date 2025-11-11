#!/bin/bash

# DSA Library Comprehensive Demo Script
# This script demonstrates all features of the library

echo "╔════════════════════════════════════════════════════════════╗"
echo "║     DSA LIBRARY - COMPREHENSIVE DEMONSTRATION              ║"
echo "║     Data Structures & Algorithms in C                      ║"
echo "╚════════════════════════════════════════════════════════════╝"
echo ""

# Function to pause between demos
pause() {
    echo ""
    echo "Press Enter to continue..."
    read
    clear
}

# Build the library
echo "Step 1: Building the DSA Library..."
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
make clean > /dev/null 2>&1
make
echo ""
echo "✓ Library built successfully!"
pause

# Run main demo
echo "Step 2: Running Main Demo (All Data Structures)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./main
pause

# Build examples
echo "Step 3: Building Real-World Examples"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
make examples
echo ""
echo "✓ All examples built successfully!"
pause

# Run example 1: Expression Evaluator
echo "Example 1: Expression Evaluator (Stack Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_expression
pause

# Run example 2: Task Scheduler
echo "Example 2: Task Scheduler (Queue Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_scheduler
pause

# Run example 3: Social Network
echo "Example 3: Social Network (Graph Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_social
pause

# Run example 4: Student Database
echo "Example 4: Student Database (BST + Sorting Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_students
pause

# Run example 5: Palindrome Checker
echo "Example 5: Palindrome Checker (Stack Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_palindrome
pause

# Run example 6: Top K Elements
echo "Example 6: Top K Elements (Sorting Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_topk
pause

# Run example 7: Undo/Redo System
echo "Example 7: Undo/Redo System (Dual Stack Application)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
./examples/example_undo
pause

# Summary
clear
echo "╔════════════════════════════════════════════════════════════╗"
echo "║                    DEMO COMPLETED!                         ║"
echo "╚════════════════════════════════════════════════════════════╝"
echo ""
echo "Summary of DSA Library Features:"
echo ""
echo "✓ Data Structures Implemented:"
echo "  • Queue (FIFO)"
echo "  • Stack (LIFO)"
echo "  • Linked List"
echo "  • Binary Search Tree"
echo "  • Graph (Adjacency List)"
echo ""
echo "✓ Algorithms Implemented:"
echo "  • Searching: Linear, Binary (Iterative & Recursive)"
echo "  • Sorting: Bubble, Selection, Insertion, Merge, Quick, Heap, Counting"
echo ""
echo "✓ Real-World Applications:"
echo "  • Expression Evaluator"
echo "  • Task Scheduler"
echo "  • Social Network"
echo "  • Student Database"
echo "  • Palindrome Checker"
echo "  • Top K Elements Finder"
echo "  • Undo/Redo System"
echo ""
echo "✓ Testing & Validation:"
echo "  • Unit tests for all data structures"
echo "  • Performance benchmarks"
echo "  • Edge case testing"
echo ""
echo "For more information, see:"
echo "  • README.md - User documentation"
echo "  • PROJECT_REPORT.md - Detailed project report"
echo "  • examples/README.md - Example applications guide"
echo ""
echo "Thank you for exploring the DSA Library!"
echo ""
/*
 * PROBLEM: Undo/Redo System
 * 
 * Real-world application: Text editors, graphics software, version control
 * 
 * This program uses TWO STACKS to implement undo/redo functionality.
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX_OPERATIONS 100

typedef struct {
    char operation[50];
    int value;
} Operation;

Operation operations[MAX_OPERATIONS];
int opCount = 0;

Stack undoStack;
Stack redoStack;
int currentState = 0;

void initEditor() {
    initStack(&undoStack);
    initStack(&redoStack);
    currentState = 0;
    printf("✓ Text Editor initialized\n");
}

void performOperation(const char* op, int value) {
    operations[opCount].value = value;
    strncpy(operations[opCount].operation, op, 49);
    operations[opCount].operation[49] = '\0';
    
    push(&undoStack, opCount);
    opCount++;
    
    // Clear redo stack when new operation is performed
    initStack(&redoStack);
    
    currentState += value;
    printf("→ Performed: %s (value: %d) | Current state: %d\n", 
           op, value, currentState);
}

void undo() {
    int opIndex;
    if (pop(&undoStack, &opIndex)) {
        push(&redoStack, opIndex);
        currentState -= operations[opIndex].value;
        printf("← Undo: %s | Current state: %d\n", 
               operations[opIndex].operation, currentState);
    } else {
        printf("✗ Nothing to undo!\n");
    }
}

void redo() {
    int opIndex;
    if (pop(&redoStack, &opIndex)) {
        push(&undoStack, opIndex);
        currentState += operations[opIndex].value;
        printf("→ Redo: %s | Current state: %d\n", 
               operations[opIndex].operation, currentState);
    } else {
        printf("✗ Nothing to redo!\n");
    }
}

void showState() {
    printf("Current state value: %d\n", currentState);
}

int main() {
    printf("=== UNDO/REDO SYSTEM ===\n");
    printf("Real-world use: Text editors, graphics software, IDEs\n\n");
    
    initEditor();
    printf("\n");
    
    printf("--- Performing Operations ---\n");
    performOperation("Add 10", 10);
    performOperation("Add 5", 5);
    performOperation("Add 8", 8);
    performOperation("Subtract 3", -3);
    performOperation("Add 7", 7);
    
    printf("\n--- Current State ---\n");
    showState();
    
    printf("\n--- Undo Operations ---\n");
    undo();
    undo();
    undo();
    
    printf("\n--- Current State ---\n");
    showState();
    
    printf("\n--- Redo Operations ---\n");
    redo();
    redo();
    
    printf("\n--- Current State ---\n");
    showState();
    
    printf("\n--- New Operation (clears redo stack) ---\n");
    performOperation("Add 15", 15);
    
    printf("\n--- Try to Redo (should fail) ---\n");
    redo();
    
    printf("\n--- Undo All ---\n");
    while (!isEmpty_stack(&undoStack)) {
        undo();
    }
    
    printf("\n--- Try to Undo More (should fail) ---\n");
    undo();
    
    printf("\n✓ Two stacks enable efficient undo/redo functionality!\n");
    printf("  Time Complexity: O(1) for each operation\n");
    
    return 0;
}
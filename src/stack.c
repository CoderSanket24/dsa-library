#include <stdio.h>
#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty_stack(Stack *s) {
    return s->top == -1;
}

bool isFull_stack(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

bool push(Stack *s, int value) {
    if (isFull_stack(s))
        return false;
    
    s->data[++s->top] = value;
    return true;
}

bool pop(Stack *s, int *popped) {
    if (isEmpty_stack(s))
        return false;
    
    *popped = s->data[s->top--];
    return true;
}

bool peekStack(Stack *s, int *top_value) {
    if (isEmpty_stack(s))
        return false;
    
    *top_value = s->data[s->top];
    return true;
}

void displayStack(Stack *s) {
    if (isEmpty_stack(s)) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
bool isEmpty_stack(Stack *s);
bool isFull_stack(Stack *s);
bool push(Stack *s, int value);
bool pop(Stack *s, int *popped);
bool peekStack(Stack *s, int *top_value);
void displayStack(Stack *s);

#endif
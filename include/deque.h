#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

#define MAX_DEQUE_SIZE 100

typedef struct {
    int data[MAX_DEQUE_SIZE];
    int front;
    int rear;
    int count;
} Deque;

// Basic operations
void initDeque(Deque *dq);
bool isDequeEmpty(Deque *dq);
bool isDequeFull(Deque *dq);

// Insert operations
bool insertFront(Deque *dq, int value);
bool insertRear(Deque *dq, int value);

// Delete operations
bool deleteFront(Deque *dq, int *removed);
bool deleteRear(Deque *dq, int *removed);

// Peek operations
bool peekFront(Deque *dq, int *value);
bool peekRear(Deque *dq, int *value);

// Utility operations
int dequeSize(Deque *dq);
void displayDeque(Deque *dq);
void clearDeque(Deque *dq);

#endif
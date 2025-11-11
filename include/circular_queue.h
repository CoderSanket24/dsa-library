#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

#define MAX_CIRCULAR_QUEUE_SIZE 100

typedef struct {
    int data[MAX_CIRCULAR_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

// Basic operations
void initCircularQueue(CircularQueue *q);
bool isCircularQueueEmpty(CircularQueue *q);
bool isCircularQueueFull(CircularQueue *q);
bool circularEnqueue(CircularQueue *q, int value);
bool circularDequeue(CircularQueue *q, int *removed);
bool circularPeek(CircularQueue *q, int *value);
int circularQueueSize(CircularQueue *q);
void displayCircularQueue(CircularQueue *q);
void clearCircularQueue(CircularQueue *q);

#endif
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Basic operations
void initQueue(Queue *q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
bool enqueue(Queue *q, int value);
bool dequeue(Queue *q, int *removed);
bool peekQueue(Queue *q, int *value);
int queueSize(Queue *q);
void displayQueue(Queue *q);
void clearQueue(Queue *q);

#endif
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

#define MAX_PRIORITY_QUEUE_SIZE 100

typedef struct {
    int value;
    int priority;
} PQElement;

typedef struct {
    PQElement data[MAX_PRIORITY_QUEUE_SIZE];
    int size;
} PriorityQueue;

// Basic operations
void initPriorityQueue(PriorityQueue *pq);
bool isPriorityQueueEmpty(PriorityQueue *pq);
bool isPriorityQueueFull(PriorityQueue *pq);
bool priorityEnqueue(PriorityQueue *pq, int value, int priority);
bool priorityDequeue(PriorityQueue *pq, int *removed);
bool priorityPeek(PriorityQueue *pq, int *value);
int priorityQueueSize(PriorityQueue *pq);
void displayPriorityQueue(PriorityQueue *pq);
void clearPriorityQueue(PriorityQueue *pq);

#endif
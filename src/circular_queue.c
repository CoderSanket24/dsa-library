#include <stdio.h>
#include "circular_queue.h"

void initCircularQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isCircularQueueEmpty(CircularQueue *q) {
    return q->count == 0;
}

bool isCircularQueueFull(CircularQueue *q) {
    return q->count == MAX_CIRCULAR_QUEUE_SIZE;
}

bool circularEnqueue(CircularQueue *q, int value) {
    if (isCircularQueueFull(q))
        return false;
    
    q->rear = (q->rear + 1) % MAX_CIRCULAR_QUEUE_SIZE;
    q->data[q->rear] = value;
    q->count++;
    return true;
}

bool circularDequeue(CircularQueue *q, int *removed) {
    if (isCircularQueueEmpty(q))
        return false;
    
    *removed = q->data[q->front];
    q->front = (q->front + 1) % MAX_CIRCULAR_QUEUE_SIZE;
    q->count--;
    return true;
}

bool circularPeek(CircularQueue *q, int *value) {
    if (isCircularQueueEmpty(q))
        return false;
    
    *value = q->data[q->front];
    return true;
}

int circularQueueSize(CircularQueue *q) {
    return q->count;
}

void displayCircularQueue(CircularQueue *q) {
    if (isCircularQueueEmpty(q)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    
    printf("Circular Queue: ");
    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->data[index]);
        index = (index + 1) % MAX_CIRCULAR_QUEUE_SIZE;
    }
    printf("\n");
}

void clearCircularQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}
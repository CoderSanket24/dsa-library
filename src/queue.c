#include <stdio.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

bool isFull(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

bool enqueue(Queue *q, int value) {
    if (isFull(q))
        return false;
    
    if (q->front == -1)
        q->front = 0;
    q->data[++q->rear] = value;
    return true;
}

bool dequeue(Queue *q, int *removed) {
    if (isEmpty(q))
        return false;
    
    *removed = q->data[q->front++];
    
    // Reset queue when empty
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return true;
}

bool peekQueue(Queue *q, int *value) {
    if (isEmpty(q))
        return false;
    
    *value = q->data[q->front];
    return true;
}

int queueSize(Queue *q) {
    if (isEmpty(q))
        return 0;
    return q->rear - q->front + 1;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void clearQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
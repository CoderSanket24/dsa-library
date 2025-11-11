#include <stdio.h>
#include "priority_queue.h"

void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

bool isPriorityQueueEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

bool isPriorityQueueFull(PriorityQueue *pq) {
    return pq->size == MAX_PRIORITY_QUEUE_SIZE;
}

bool priorityEnqueue(PriorityQueue *pq, int value, int priority) {
    if (isPriorityQueueFull(pq))
        return false;
    
    // Find position to insert (higher priority = lower number = higher precedence)
    int i = pq->size - 1;
    
    // Shift elements with lower priority (higher number) to the right
    while (i >= 0 && pq->data[i].priority > priority) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }
    
    // Insert new element
    pq->data[i + 1].value = value;
    pq->data[i + 1].priority = priority;
    pq->size++;
    return true;
}

bool priorityDequeue(PriorityQueue *pq, int *removed) {
    if (isPriorityQueueEmpty(pq))
        return false;
    
    // Remove element with highest priority (at index 0)
    *removed = pq->data[0].value;
    
    // Shift remaining elements
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    
    pq->size--;
    return true;
}

bool priorityPeek(PriorityQueue *pq, int *value) {
    if (isPriorityQueueEmpty(pq))
        return false;
    
    *value = pq->data[0].value;
    return true;
}

int priorityQueueSize(PriorityQueue *pq) {
    return pq->size;
}

void displayPriorityQueue(PriorityQueue *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    
    printf("Priority Queue (value:priority): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d:%d ", pq->data[i].value, pq->data[i].priority);
    }
    printf("\n");
}

void clearPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}
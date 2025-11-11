#include <stdio.h>
#include "deque.h"

void initDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

bool isDequeEmpty(Deque *dq) {
    return dq->count == 0;
}

bool isDequeFull(Deque *dq) {
    return dq->count == MAX_DEQUE_SIZE;
}

bool insertFront(Deque *dq, int value) {
    if (isDequeFull(dq))
        return false;
    
    dq->front = (dq->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    dq->data[dq->front] = value;
    dq->count++;
    
    if (dq->count == 1)
        dq->rear = dq->front;
    
    return true;
}

bool insertRear(Deque *dq, int value) {
    if (isDequeFull(dq))
        return false;
    
    dq->rear = (dq->rear + 1) % MAX_DEQUE_SIZE;
    dq->data[dq->rear] = value;
    dq->count++;
    
    if (dq->count == 1)
        dq->front = dq->rear;
    
    return true;
}

bool deleteFront(Deque *dq, int *removed) {
    if (isDequeEmpty(dq))
        return false;
    
    *removed = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX_DEQUE_SIZE;
    dq->count--;
    
    return true;
}

bool deleteRear(Deque *dq, int *removed) {
    if (isDequeEmpty(dq))
        return false;
    
    *removed = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    dq->count--;
    
    return true;
}

bool peekFront(Deque *dq, int *value) {
    if (isDequeEmpty(dq))
        return false;
    
    *value = dq->data[dq->front];
    return true;
}

bool peekRear(Deque *dq, int *value) {
    if (isDequeEmpty(dq))
        return false;
    
    *value = dq->data[dq->rear];
    return true;
}

int dequeSize(Deque *dq) {
    return dq->count;
}

void displayDeque(Deque *dq) {
    if (isDequeEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    
    printf("Deque: ");
    int index = dq->front;
    for (int i = 0; i < dq->count; i++) {
        printf("%d ", dq->data[index]);
        index = (index + 1) % MAX_DEQUE_SIZE;
    }
    printf("\n");
}

void clearDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}
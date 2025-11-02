#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    initQueue(&q);
    
    printf("Testing Queue Operations:\n");
    printf("========================\n");
    
    // Test enqueue
    printf("Enqueuing: 5, 10, 15, 20\n");
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    displayQueue(&q);
    
    // Test dequeue
    int value;
    printf("\nDequeuing elements:\n");
    while (!isEmpty(&q)) {
        if (dequeue(&q, &value)) {
            printf("Dequeued: %d\n", value);
            displayQueue(&q);
        }
    }
    
    printf("\nTrying to dequeue from empty queue:\n");
    if (!dequeue(&q, &value)) {
        printf("Cannot dequeue from empty queue\n");
    }
    
    return 0;
}
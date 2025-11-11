#include <stdio.h>
#include "queue.h"

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

bool isFull(Queue *q)
{
    return q->rear == MAX_QUEUE_SIZE - 1;
}

bool enqueue(Queue *q, int value)
{
    if (isFull(q))
        return false;

    if (q->front == -1)
        q->front = 0;
    q->data[++q->rear] = value;
    return true;
}

bool dequeue(Queue *q, int *removed)
{
    if (isEmpty(q))
        return false;

    *removed = q->data[q->front++];
    return true;
}

void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

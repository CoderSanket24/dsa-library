/*
 * PROBLEM: Task Scheduler / Job Queue
 * 
 * Real-world application: Operating systems, print queues, customer service systems
 * 
 * This program uses a QUEUE to manage tasks in a First-Come-First-Served manner.
 */

#include <stdio.h>
#include <string.h>
#include "queue.h"

typedef struct {
    int taskId;
    char description[50];
} Task;

Task tasks[100];
int taskCount = 0;

void addTask(Queue* q, int id, const char* desc) {
    if (enqueue(q, taskCount)) {
        tasks[taskCount].taskId = id;
        strncpy(tasks[taskCount].description, desc, 49);
        tasks[taskCount].description[49] = '\0';
        taskCount++;
        printf("✓ Task %d added: %s\n", id, desc);
    } else {
        printf("✗ Queue is full!\n");
    }
}

void processTask(Queue* q) {
    int taskIndex;
    if (dequeue(q, &taskIndex)) {
        printf("→ Processing Task %d: %s\n", 
               tasks[taskIndex].taskId, 
               tasks[taskIndex].description);
        printf("  [Task completed]\n");
    } else {
        printf("✗ No tasks to process!\n");
    }
}

int main() {
    printf("=== TASK SCHEDULER SYSTEM ===\n");
    printf("Real-world use: OS process scheduling, print queues, customer service\n\n");
    
    Queue taskQueue;
    initQueue(&taskQueue);
    
    printf("--- Adding Tasks to Queue ---\n");
    addTask(&taskQueue, 101, "Process customer order #1234");
    addTask(&taskQueue, 102, "Send email notification");
    addTask(&taskQueue, 103, "Generate monthly report");
    addTask(&taskQueue, 104, "Backup database");
    addTask(&taskQueue, 105, "Update inventory");
    
    printf("\n--- Processing Tasks (FIFO Order) ---\n");
    processTask(&taskQueue);
    processTask(&taskQueue);
    
    printf("\n--- Adding More Tasks ---\n");
    addTask(&taskQueue, 106, "Clean temporary files");
    addTask(&taskQueue, 107, "Send reminder emails");
    
    printf("\n--- Processing Remaining Tasks ---\n");
    while (!isEmpty(&taskQueue)) {
        processTask(&taskQueue);
    }
    
    printf("\n--- Trying to Process Empty Queue ---\n");
    processTask(&taskQueue);
    
    printf("\n✓ Queue ensures fair First-Come-First-Served task processing!\n");
    return 0;
}
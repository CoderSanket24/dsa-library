#include <stdio.h>
#include "queue.h"
#include "circular_queue.h"
#include "priority_queue.h"
#include "deque.h"
#include "stack.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "circular_linked_list.h"
#include "bst.h"
#include "graph.h"

void testQueue() {
    printf("=== QUEUE TESTS ===\n\n");
    
    // Test Simple Queue
    printf("--- Simple Queue ---\n");
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);
    printf("Size: %d\n", queueSize(&q));
    int removed;
    if (dequeue(&q, &removed))
        printf("Dequeued: %d\n", removed);
    displayQueue(&q);
    
    // Test Circular Queue
    printf("\n--- Circular Queue ---\n");
    CircularQueue cq;
    initCircularQueue(&cq);
    circularEnqueue(&cq, 10);
    circularEnqueue(&cq, 20);
    circularEnqueue(&cq, 30);
    displayCircularQueue(&cq);
    printf("Size: %d\n", circularQueueSize(&cq));
    if (circularDequeue(&cq, &removed))
        printf("Dequeued: %d\n", removed);
    circularEnqueue(&cq, 40);  // Circular behavior
    displayCircularQueue(&cq);
    
    // Test Priority Queue
    printf("\n--- Priority Queue ---\n");
    PriorityQueue pq;
    initPriorityQueue(&pq);
    priorityEnqueue(&pq, 100, 3);  // value, priority
    priorityEnqueue(&pq, 200, 1);  // Higher priority (lower number)
    priorityEnqueue(&pq, 300, 2);
    displayPriorityQueue(&pq);
    printf("Size: %d\n", priorityQueueSize(&pq));
    if (priorityDequeue(&pq, &removed))
        printf("Dequeued (highest priority): %d\n", removed);
    displayPriorityQueue(&pq);
    
    // Test Deque
    printf("\n--- Deque (Double-ended Queue) ---\n");
    Deque dq;
    initDeque(&dq);
    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 1);
    displayDeque(&dq);
    printf("Size: %d\n", dequeSize(&dq));
    if (deleteFront(&dq, &removed))
        printf("Deleted from front: %d\n", removed);
    if (deleteRear(&dq, &removed))
        printf("Deleted from rear: %d\n", removed);
    displayDeque(&dq);
    
    printf("\n");
}

void testStack() {
    printf("=== STACK TEST ===\n");
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    displayStack(&s);

    int popped;
    if (pop(&s, &popped))
        printf("Popped: %d\n", popped);
    displayStack(&s);
    printf("\n");
}

void testLinkedList() {
    printf("=== LINKED LIST TESTS ===\n\n");
    
    // Test Singly Linked List
    printf("--- Singly Linked List ---\n");
    Node* slist = initSList();
    insertAtEndS(&slist, 10);
    insertAtEndS(&slist, 20);
    insertAtBeginningS(&slist, 5);
    insertAtPositionS(&slist, 15, 2);
    printf("List: ");
    displayListS(&slist);
    printf("Size: %d\n", getSizeS(&slist));
    printf("Search 15: %s\n", searchS(&slist, 15) ? "Found" : "Not found");
    freeListS(&slist);
    
    // Test Doubly Linked List
    printf("\n--- Doubly Linked List ---\n");
    DNode* dlist = initDList();
    insertAtEndD(&dlist, 10);
    insertAtEndD(&dlist, 20);
    insertAtBeginningD(&dlist, 5);
    printf("Forward: ");
    displayForwardD(&dlist);
    printf("Backward: ");
    displayBackwardD(&dlist);
    printf("Size: %d\n", getSizeD(&dlist));
    freeListD(&dlist);
    
    // Test Circular Linked List
    printf("\n--- Circular Linked List ---\n");
    CNode* clist = initCList();
    insertAtEndC(&clist, 10);
    insertAtEndC(&clist, 20);
    insertAtEndC(&clist, 30);
    printf("List: ");
    displayListC(&clist);
    printf("Size: %d\n", getSizeC(&clist));
    freeListC(&clist);
    printf("\n");
}

void testBST() {
    printf("=== BINARY SEARCH TREE TEST ===\n");
    BST bst;
    initBST(&bst);

    insertBST(&bst, 50);
    insertBST(&bst, 30);
    insertBST(&bst, 70);
    insertBST(&bst, 20);
    insertBST(&bst, 40);
    insertBST(&bst, 60);
    insertBST(&bst, 80);

    inorderTraversal(&bst);
    preorderTraversal(&bst);
    postorderTraversal(&bst);

    printf("Search 40: %s\n", searchBST(&bst, 40) ? "Found" : "Not found");
    printf("Min: %d, Max: %d\n", findMin(&bst), findMax(&bst));

    deleteBST(&bst, 30);
    printf("After deleting 30: ");
    inorderTraversal(&bst);
    freeBST(&bst);
    printf("\n");
}

void visit_node(int v) {
    printf("%d ", v);
}

void testGraph() {
    printf("=== GRAPH TEST ===\n");
    
    // Create undirected graph with 5 vertices
    Graph* graph = graph_create(5, 0);  // 0 = undirected
    
    // Add edges
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 4);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 1, 4);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 3, 4);
    
    printf("BFS from vertex 0: ");
    graph_bfs(graph, 0, visit_node);
    printf("\n");
    
    printf("DFS from vertex 0: ");
    graph_dfs(graph, 0, visit_node);
    printf("\n");
    
    graph_free(graph);
    printf("\n");
}

int main() {
    printf("DSA Library Demo\n");
    printf("================\n\n");

    testQueue();
    testStack();
    testLinkedList();
    testBST();
    testGraph();

    printf("All tests completed!\n");
    return 0;
}

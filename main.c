#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "linkedlist.h"
#include "bst.h"
#include "graph.h"

void testQueue() {
    printf("=== QUEUE TEST ===\n");
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    int removed;
    if (dequeue(&q, &removed))
        printf("Dequeued: %d\n", removed);
    displayQueue(&q);
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
    printf("=== LINKED LIST TEST ===\n");
    LinkedList list;
    initList(&list);

    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtBeginning(&list, 5);
    insertAtPosition(&list, 15, 2);
    displayList(&list);

    printf("Size: %d\n", getSize(&list));
    printf("Search 15: %s\n", search(&list, 15) ? "Found" : "Not found");

    deleteValue(&list, 15);
    displayList(&list);
    freeList(&list);
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

void testGraph() {
    printf("=== GRAPH TEST ===\n");
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    freeGraph(graph);
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

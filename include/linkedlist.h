#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
    int size;
} LinkedList;

void initList(LinkedList *list);
bool insertAtBeginning(LinkedList *list, int value);
bool insertAtEnd(LinkedList *list, int value);
bool insertAtPosition(LinkedList *list, int value, int position);
bool deleteValue(LinkedList *list, int value);
bool deleteAtPosition(LinkedList *list, int position);
bool search(LinkedList *list, int value);
int getSize(LinkedList *list);
void displayList(LinkedList *list);
void freeList(LinkedList *list);

#endif
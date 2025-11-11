#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void initList(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

bool insertAtBeginning(LinkedList *list, int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) return false;
    
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return true;
}

bool insertAtEnd(LinkedList *list, int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) return false;
    
    newNode->data = value;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        ListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
    return true;
}

bool insertAtPosition(LinkedList *list, int value, int position) {
    if (position < 0 || position > list->size) return false;
    
    if (position == 0) return insertAtBeginning(list, value);
    
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) return false;
    
    newNode->data = value;
    
    ListNode* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
    return true;
}

bool deleteValue(LinkedList *list, int value) {
    if (list->head == NULL) return false;
    
    if (list->head->data == value) {
        ListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return true;
    }
    
    ListNode* current = list->head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next == NULL) return false;
    
    ListNode* temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
    return true;
}

bool deleteAtPosition(LinkedList *list, int position) {
    if (position < 0 || position >= list->size || list->head == NULL) return false;
    
    if (position == 0) {
        ListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return true;
    }
    
    ListNode* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    ListNode* temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
    return true;
}

bool search(LinkedList *list, int value) {
    ListNode* current = list->head;
    while (current != NULL) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

int getSize(LinkedList *list) {
    return list->size;
}

void displayList(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("List: ");
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) printf("-> ");
        current = current->next;
    }
    printf("\n");
}

void freeList(LinkedList *list) {
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}
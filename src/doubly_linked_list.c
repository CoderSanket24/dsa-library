#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

DNode* initDList() {
    return NULL;
}

void insertAtBeginningD(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
    printf("Inserted %d at beginning.\n", data);
}

void insertAtEndD(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("Inserted %d as first node.\n", data);
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end.\n", data);
}

void insertAtPositionD(DNode** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginningD(head, data);
        return;
    }

    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    DNode* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Inserted %d at position %d.\n", data, position);
}

void deleteAtBeginningD(DNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);
}

void deleteAtEndD(DNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;

    printf("Deleted node with value %d from end.\n", temp->data);
    free(temp);
}

void deleteAtPositionD(DNode** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    DNode* temp = *head;

    for (int i = 0; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted node with value %d at position %d.\n", temp->data, position);
    free(temp);
}

int searchD(DNode** head, int value) {
    DNode* temp = *head;
    int position = 0;

    while (temp != NULL) {
        if (temp->data == value)
            return position;
        temp = temp->next;
        position++;
    }

    return -1;
}

int getSizeD(DNode** head) {
    int count = 0;
    DNode* temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayForwardD(DNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = *head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

void displayBackwardD(DNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) printf(" <-> ");
        temp = temp->prev;
    }
    printf("\n");
}

void freeListD(DNode** head) {
    DNode* temp = *head;
    while (temp != NULL) {
        DNode* current = temp->next;  
        free(temp);                    
        temp = current;               
    }
    *head = NULL;
    printf("Freed all nodes.\n");
}

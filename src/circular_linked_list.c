#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

CNode* initCList() {
    return NULL;
}

void insertAtBeginningC(CNode** head, int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        CNode* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    printf("Inserted %d at beginning.\n", data);
}

void insertAtEndC(CNode** head, int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    CNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;

    printf("Inserted %d at end.\n", data);
}

void insertAtPositionC(CNode** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0 || *head == NULL) {
        insertAtBeginningC(head, data);
        return;
    }

    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    CNode* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != *head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", data, position);
}

void deleteAtBeginningC(CNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    CNode* temp = *head;

    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    CNode* last = *head;
    while (last->next != *head)
        last = last->next;

    last->next = (*head)->next;
    *head = (*head)->next;
    free(temp);

    printf("Deleted node at beginning.\n");
}

void deleteAtEndC(CNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    CNode* temp = *head;
    CNode* prev = NULL;

    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);

    printf("Deleted node at end.\n");
}

void deleteAtPositionC(CNode** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginningC(head);
        return;
    }

    CNode* temp = *head;
    CNode* prev = NULL;

    for (int i = 0; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

int searchC(CNode** head, int value) {
    if (*head == NULL)
        return -1;

    CNode* temp = *head;
    int pos = 0;

    do {
        if (temp->data == value)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != *head);

    return -1;
}

int getSizeC(CNode** head) {
    if (*head == NULL)
        return 0;

    int count = 0;
    CNode* temp = *head;
    do {
        count++;
        temp = temp->next;
    } while (temp != *head);

    return count;
}

void displayListC(CNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    CNode* temp = *head;
    printf("Circular List: ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != *head) printf(" -> ");
    } while (temp != *head);
    printf(" -> (back to head)\n");
}

void freeListC(CNode** head) {
    if (*head == NULL)
        return;

    CNode* temp = *head;
    CNode* current;

    do {
        current = temp->next;
        free(temp);
        temp = current;
    } while (temp != *head);

    *head = NULL;
    printf("Freed all nodes.\n");
}
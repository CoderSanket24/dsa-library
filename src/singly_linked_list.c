#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

Node* initSList() {
    return NULL;
}

void insertAtBeginningS(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEndS(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPositionS(Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginningS(head, data);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginningS(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted node at beginning.\n");
}

void deleteAtEndS(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Deleted last remaining node.\n");
        return;
    }

    Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Deleted node at end.\n");
}

void deleteAtPositionS(Node** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginningS(head);
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

void deleteValueS(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int searchS(Node** head, int value) {
    Node* temp = *head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == value)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int getSizeS(Node** head) {
    int count = 0;
    Node* temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayListS(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void freeListS(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

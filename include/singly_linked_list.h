#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initSList();
void insertAtBeginningS(Node** head, int data);
void insertAtEndS(Node** head, int data);
void insertAtPositionS(Node** head, int data, int position);
void deleteAtBeginningS(Node** head);
void deleteAtEndS(Node** head);
void deleteAtPositionS(Node** head, int position);
int searchS(Node** head, int value);
int getSizeS(Node** head);
void displayListS(Node** head);
void freeListS(Node** head);

#endif

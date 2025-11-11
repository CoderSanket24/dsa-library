#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;


DNode* initDList();
void insertAtBeginningD(DNode** head, int data);
void insertAtEndD(DNode** head, int data);
void insertAtPositionD(DNode** head, int data, int position);
void deleteAtBeginningD(DNode** head);
void deleteAtEndD(DNode** head);
void deleteAtPositionD(DNode** head, int position);
int searchD(DNode** head, int value);
int getSizeD(DNode** head);
void displayForwardD(DNode** head);
void displayBackwardD(DNode** head);
void freeListD(DNode** head);


#endif

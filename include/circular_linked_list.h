#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;


CNode* initCList();
void insertAtBeginningC(CNode** head, int data);
void insertAtEndC(CNode** head, int data);
void insertAtPositionC(CNode** head, int data, int position);
void deleteAtBeginningC(CNode** head);
void deleteAtEndC(CNode** head);
void deleteAtPositionC(CNode** head, int position);
int searchC(CNode** head, int value);
int getSizeC(CNode** head);
void displayListC(CNode** head);
void freeListC(CNode** head);


#endif

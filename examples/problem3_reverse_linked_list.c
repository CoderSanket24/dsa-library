/*
 * PROBLEM 3: Reverse Linked List (Multiple Approaches)
 * 
 * Difficulty: Medium
 * 
 * Problem Statement:
 * Given a linked list, reverse it using different approaches:
 * 1. Iterative reversal (Singly Linked List)
 * 2. Recursive reversal (Singly Linked List)
 * 3. Reverse in groups of K (Singly Linked List)
 * 4. Reverse doubly linked list
 * 
 * Example:
 * Input:  1 -> 2 -> 3 -> 4 -> 5
 * Output: 5 -> 4 -> 3 -> 2 -> 1
 * 
 * Input (K=2):  1 -> 2 -> 3 -> 4 -> 5
 * Output:       2 -> 1 -> 4 -> 3 -> 5
 * 
 * Solution: Use Singly and Doubly Linked List Libraries
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"
#include "doubly_linked_list.h"

// Helper function to create a list with values
Node* createSinglyList(int arr[], int n) {
    Node* head = initSList();
    for (int i = 0; i < n; i++) {
        insertAtEndS(&head, arr[i]);
    }
    return head;
}

// Iterative reversal of singly linked list
Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Recursive reversal helper
Node* reverseRecursiveHelper(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* rest = reverseRecursiveHelper(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return rest;
}

// Reverse in groups of K
Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    
    // Reverse first k nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    // Recursively reverse remaining list
    if (next != NULL) {
        head->next = reverseInGroups(next, k);
    }
    
    return prev;
}

// Check if list is palindrome using reversal
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;
    
    // Find middle
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node* secondHalf = reverseIterative(slow->next);
    Node* firstHalf = head;
    
    // Compare
    bool result = true;
    Node* temp = secondHalf;
    while (temp != NULL) {
        if (firstHalf->data != temp->data) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    
    // Restore list (optional)
    slow->next = reverseIterative(secondHalf);
    
    return result;
}

// Reverse doubly linked list
DNode* reverseDoubly(DNode* head) {
    DNode* temp = NULL;
    DNode* current = head;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL)
        head = temp->prev;
    
    return head;
}

int main() {
    printf("========================================================\n");
    printf("  PROBLEM 3: Reverse Linked List\n");
    printf("  Difficulty: Medium\n");
    printf("  Using: Singly & Doubly Linked List Libraries\n");
    printf("========================================================\n\n");
    
    // Test 1: Iterative Reversal
    printf("--- Test 1: Iterative Reversal ---\n");
    int arr1[] = {1, 2, 3, 4, 5};
    Node* list1 = createSinglyList(arr1, 5);
    printf("Original: ");
    displayListS(&list1);
    
    list1 = reverseIterative(list1);
    printf("Reversed: ");
    displayListS(&list1);
    freeListS(&list1);
    
    // Test 2: Recursive Reversal
    printf("\n--- Test 2: Recursive Reversal ---\n");
    int arr2[] = {10, 20, 30, 40, 50};
    Node* list2 = createSinglyList(arr2, 5);
    printf("Original: ");
    displayListS(&list2);
    
    list2 = reverseRecursiveHelper(list2);
    printf("Reversed: ");
    displayListS(&list2);
    freeListS(&list2);
    
    // Test 3: Reverse in Groups of K
    printf("\n--- Test 3: Reverse in Groups of K=2 ---\n");
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* list3 = createSinglyList(arr3, 8);
    printf("Original: ");
    displayListS(&list3);
    
    list3 = reverseInGroups(list3, 2);
    printf("Reversed (K=2): ");
    displayListS(&list3);
    freeListS(&list3);
    
    printf("\n--- Test 4: Reverse in Groups of K=3 ---\n");
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* list4 = createSinglyList(arr4, 9);
    printf("Original: ");
    displayListS(&list4);
    
    list4 = reverseInGroups(list4, 3);
    printf("Reversed (K=3): ");
    displayListS(&list4);
    freeListS(&list4);
    
    // Test 5: Palindrome Check
    printf("\n--- Test 5: Palindrome Check ---\n");
    int arr5[] = {1, 2, 3, 2, 1};
    Node* list5 = createSinglyList(arr5, 5);
    printf("List: ");
    displayListS(&list5);
    printf("Is Palindrome: %s\n", isPalindrome(list5) ? "Yes" : "No");
    freeListS(&list5);
    
    int arr6[] = {1, 2, 3, 4, 5};
    Node* list6 = createSinglyList(arr6, 5);
    printf("\nList: ");
    displayListS(&list6);
    printf("Is Palindrome: %s\n", isPalindrome(list6) ? "Yes" : "No");
    freeListS(&list6);
    
    // Test 6: Reverse Doubly Linked List
    printf("\n--- Test 6: Reverse Doubly Linked List ---\n");
    DNode* dlist = initDList();
    insertAtEndD(&dlist, 10);
    insertAtEndD(&dlist, 20);
    insertAtEndD(&dlist, 30);
    insertAtEndD(&dlist, 40);
    insertAtEndD(&dlist, 50);
    
    printf("Original: ");
    displayForwardD(&dlist);
    
    dlist = reverseDoubly(dlist);
    printf("Reversed: ");
    displayForwardD(&dlist);
    printf("Backward: ");
    displayBackwardD(&dlist);
    freeListD(&dlist);
    
    printf("\n✓ Problem solved using Linked List Libraries!\n");
    printf("  Singly Linked List Functions Used:\n");
    printf("  - initSList()        : Initialize list\n");
    printf("  - insertAtEndS()     : Add elements\n");
    printf("  - displayListS()     : Display list\n");
    printf("  - freeListS()        : Free memory\n");
    printf("\n  Doubly Linked List Functions Used:\n");
    printf("  - initDList()        : Initialize list\n");
    printf("  - insertAtEndD()     : Add elements\n");
    printf("  - displayForwardD()  : Display forward\n");
    printf("  - displayBackwardD() : Display backward\n");
    printf("  - freeListD()        : Free memory\n");
    printf("\n  Time Complexity: O(n) for all operations\n");
    printf("  Space Complexity: O(1) iterative, O(n) recursive\n");
    
    return 0;
}
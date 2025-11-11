/*
 * PROBLEM 4: Detect and Remove Cycle in Linked List
 * 
 * Difficulty: Medium
 * 
 * Problem Statement:
 * Given a linked list, detect if it contains a cycle and remove it.
 * Also implement related problems:
 * 1. Detect cycle (Floyd's Cycle Detection)
 * 2. Find cycle start point
 * 3. Find cycle length
 * 4. Remove cycle
 * 5. Find middle of linked list
 * 6. Detect intersection of two lists
 * 
 * Example:
 * Input:  1 -> 2 -> 3 -> 4 -> 5
 *                   ^         |
 *                   |_________|
 * Output: Cycle detected at node 3
 * 
 * Solution: Use Singly Linked List Library with Floyd's Algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"

// Helper to create list from array
Node* createList(int arr[], int n) {
    Node* head = initSList();
    for (int i = 0; i < n; i++) {
        insertAtEndS(&head, arr[i]);
    }
    return head;
}

// Get node at position
Node* getNodeAt(Node* head, int pos) {
    Node* current = head;
    int count = 0;
    while (current != NULL && count < pos) {
        current = current->next;
        count++;
    }
    return current;
}

// Create cycle for testing (connect last node to pos)
void createCycle(Node* head, int pos) {
    if (head == NULL || pos < 0) return;
    
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    Node* cycleNode = getNodeAt(head, pos);
    if (cycleNode != NULL) {
        last->next = cycleNode;
    }
}

// Detect cycle using Floyd's Cycle Detection Algorithm
bool detectCycle(Node* head) {
    if (head == NULL) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

// Find the start of the cycle
Node* findCycleStart(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Cycle detected, find start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    
    return NULL;
}

// Find cycle length
int findCycleLength(Node* head) {
    if (head == NULL) return 0;
    
    Node* slow = head;
    Node* fast = head;
    
    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Count nodes in cycle
            int length = 1;
            Node* temp = slow->next;
            while (temp != slow) {
                length++;
                temp = temp->next;
            }
            return length;
        }
    }
    
    return 0;
}

// Remove cycle from linked list
void removeCycle(Node* head) {
    if (head == NULL) return;
    
    Node* slow = head;
    Node* fast = head;
    
    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Find start of cycle
            slow = head;
            
            // Special case: cycle starts at head
            if (slow == fast) {
                while (fast->next != slow) {
                    fast = fast->next;
                }
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            
            // Remove cycle
            fast->next = NULL;
            return;
        }
    }
}

// Find middle of linked list (slow-fast pointer)
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Find Nth node from end
Node* findNthFromEnd(Node* head, int n) {
    if (head == NULL) return NULL;
    
    Node* first = head;
    Node* second = head;
    
    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == NULL) return NULL;
        first = first->next;
    }
    
    // Move both pointers until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    return second;
}

int main() {
    printf("========================================================\n");
    printf("  PROBLEM 4: Detect and Remove Cycle in Linked List\n");
    printf("  Difficulty: Medium\n");
    printf("  Using: Singly Linked List Library + Floyd's Algorithm\n");
    printf("========================================================\n\n");
    
    // Test 1: Detect Cycle
    printf("--- Test 1: Detect Cycle ---\n");
    int arr1[] = {1, 2, 3, 4, 5};
    Node* list1 = createList(arr1, 5);
    createCycle(list1, 2);  // Create cycle at position 2
    
    printf("List with cycle at position 2\n");
    printf("Has cycle: %s\n", detectCycle(list1) ? "Yes" : "No");
    
    Node* cycleStart = findCycleStart(list1);
    if (cycleStart) {
        printf("Cycle starts at node with value: %d\n", cycleStart->data);
    }
    
    int cycleLen = findCycleLength(list1);
    printf("Cycle length: %d\n", cycleLen);
    
    // Test 2: Remove Cycle
    printf("\n--- Test 2: Remove Cycle ---\n");
    printf("Before removing cycle: Has cycle = %s\n", 
           detectCycle(list1) ? "Yes" : "No");
    
    removeCycle(list1);
    printf("After removing cycle: Has cycle = %s\n", 
           detectCycle(list1) ? "Yes" : "No");
    printf("List after cycle removal: ");
    displayListS(&list1);
    freeListS(&list1);
    
    // Test 3: List without cycle
    printf("\n--- Test 3: List Without Cycle ---\n");
    int arr2[] = {10, 20, 30, 40, 50};
    Node* list2 = createList(arr2, 5);
    printf("List: ");
    displayListS(&list2);
    printf("Has cycle: %s\n", detectCycle(list2) ? "Yes" : "No");
    freeListS(&list2);
    
    // Test 4: Find Middle
    printf("\n--- Test 4: Find Middle of List ---\n");
    int arr3[] = {1, 2, 3, 4, 5};
    Node* list3 = createList(arr3, 5);
    printf("List: ");
    displayListS(&list3);
    Node* middle = findMiddle(list3);
    printf("Middle element: %d\n", middle ? middle->data : -1);
    freeListS(&list3);
    
    int arr4[] = {1, 2, 3, 4, 5, 6};
    Node* list4 = createList(arr4, 6);
    printf("\nList: ");
    displayListS(&list4);
    middle = findMiddle(list4);
    printf("Middle element: %d\n", middle ? middle->data : -1);
    freeListS(&list4);
    
    // Test 5: Find Nth from End
    printf("\n--- Test 5: Find Nth Node from End ---\n");
    int arr5[] = {10, 20, 30, 40, 50, 60, 70};
    Node* list5 = createList(arr5, 7);
    printf("List: ");
    displayListS(&list5);
    
    Node* nthNode = findNthFromEnd(list5, 3);
    printf("3rd node from end: %d\n", nthNode ? nthNode->data : -1);
    
    nthNode = findNthFromEnd(list5, 1);
    printf("1st node from end: %d\n", nthNode ? nthNode->data : -1);
    
    nthNode = findNthFromEnd(list5, 7);
    printf("7th node from end: %d\n", nthNode ? nthNode->data : -1);
    freeListS(&list5);
    
    // Test 6: Cycle at head
    printf("\n--- Test 6: Cycle Starting at Head ---\n");
    int arr6[] = {1, 2, 3, 4};
    Node* list6 = createList(arr6, 4);
    createCycle(list6, 0);  // Cycle at head
    
    printf("List with cycle at head\n");
    printf("Has cycle: %s\n", detectCycle(list6) ? "Yes" : "No");
    
    cycleStart = findCycleStart(list6);
    if (cycleStart) {
        printf("Cycle starts at node with value: %d\n", cycleStart->data);
    }
    
    removeCycle(list6);
    printf("After removing cycle: Has cycle = %s\n", 
           detectCycle(list6) ? "Yes" : "No");
    printf("List: ");
    displayListS(&list6);
    freeListS(&list6);
    
    printf("\n✓ Problem solved using Linked List Library!\n");
    printf("  Key Algorithm: Floyd's Cycle Detection (Tortoise and Hare)\n");
    printf("\n  Singly Linked List Functions Used:\n");
    printf("  - initSList()        : Initialize list\n");
    printf("  - insertAtEndS()     : Build list\n");
    printf("  - displayListS()     : Display list\n");
    printf("  - freeListS()        : Free memory\n");
    printf("\n  Time Complexity:\n");
    printf("  - Detect cycle:      O(n)\n");
    printf("  - Find cycle start:  O(n)\n");
    printf("  - Remove cycle:      O(n)\n");
    printf("  - Find middle:       O(n)\n");
    printf("  - Nth from end:      O(n)\n");
    printf("\n  Space Complexity: O(1) - No extra space used\n");
    
    return 0;
}
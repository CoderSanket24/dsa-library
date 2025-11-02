#include <stdio.h>
#include "bst.h"

int main() {
    BST bst;
    initBST(&bst);
    
    printf("Testing Binary Search Tree Operations:\n");
    printf("=====================================\n");
    
    // Insert values
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Inserting values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        insertBST(&bst, values[i]);
    }
    printf("\n\n");
    
    // Display traversals
    inorderTraversal(&bst);
    preorderTraversal(&bst);
    postorderTraversal(&bst);
    
    // Test search
    printf("\nSearch operations:\n");
    printf("Search 40: %s\n", searchBST(&bst, 40) ? "Found" : "Not found");
    printf("Search 100: %s\n", searchBST(&bst, 100) ? "Found" : "Not found");
    
    // Min and Max
    printf("Min value: %d\n", findMin(&bst));
    printf("Max value: %d\n", findMax(&bst));
    
    // Delete operations
    printf("\nDeleting 20, 30, 50:\n");
    deleteBST(&bst, 20);
    printf("After deleting 20: ");
    inorderTraversal(&bst);
    
    deleteBST(&bst, 30);
    printf("After deleting 30: ");
    inorderTraversal(&bst);
    
    deleteBST(&bst, 50);
    printf("After deleting 50: ");
    inorderTraversal(&bst);
    
    freeBST(&bst);
    return 0;
}
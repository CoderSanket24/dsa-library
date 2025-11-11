/*
 * PROBLEM 1: Binary Tree Level Order Traversal
 * 
 * Difficulty: Medium
 * 
 * Problem Statement:
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
 * 
 * Example:
 * Input Tree:
 *       3
 *      / \
 *     9  20
 *       /  \
 *      15   7
 * 
 * Output: [[3], [9, 20], [15, 7]]
 * 
 * Solution: Use Queue Library for BFS (Breadth-First Search)
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Tree node structure
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Helper: Store tree node pointers in an array for queue indexing
TreeNode* nodeArray[1000];
int nodeCount = 0;

// Create a new tree node
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Add node to array and return its index
int addNodeToArray(TreeNode* node) {
    nodeArray[nodeCount] = node;
    return nodeCount++;
}

// Level order traversal using Queue Library
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    printf("Level Order Traversal:\n");
    
    // Initialize queue from our library
    Queue q;
    initQueue(&q);
    
    // Reset node array
    nodeCount = 0;
    
    // Add root to queue (store index)
    int rootIndex = addNodeToArray(root);
    enqueue(&q, rootIndex);
    
    int level = 0;
    while (!isEmpty(&q)) {
        // Get current level size
        int levelSize = queueSize(&q);
        printf("Level %d: ", level);
        
        // Process all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            int nodeIndex;
            dequeue(&q, &nodeIndex);
            TreeNode* current = nodeArray[nodeIndex];
            
            printf("%d ", current->val);
            
            // Add children to queue
            if (current->left != NULL) {
                int leftIndex = addNodeToArray(current->left);
                enqueue(&q, leftIndex);
            }
            if (current->right != NULL) {
                int rightIndex = addNodeToArray(current->right);
                enqueue(&q, rightIndex);
            }
        }
        printf("\n");
        level++;
    }
}

// Calculate maximum depth using Queue Library
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    
    Queue q;
    initQueue(&q);
    
    nodeCount = 0;
    int rootIndex = addNodeToArray(root);
    enqueue(&q, rootIndex);
    
    int depth = 0;
    while (!isEmpty(&q)) {
        int levelSize = queueSize(&q);
        depth++;
        
        for (int i = 0; i < levelSize; i++) {
            int nodeIndex;
            dequeue(&q, &nodeIndex);
            TreeNode* current = nodeArray[nodeIndex];
            
            if (current->left != NULL) {
                int leftIndex = addNodeToArray(current->left);
                enqueue(&q, leftIndex);
            }
            if (current->right != NULL) {
                int rightIndex = addNodeToArray(current->right);
                enqueue(&q, rightIndex);
            }
        }
    }
    return depth;
}

// Find right side view using Queue Library
void rightSideView(TreeNode* root) {
    if (root == NULL) return;
    
    printf("Right Side View: ");
    
    Queue q;
    initQueue(&q);
    
    nodeCount = 0;
    int rootIndex = addNodeToArray(root);
    enqueue(&q, rootIndex);
    
    while (!isEmpty(&q)) {
        int levelSize = queueSize(&q);
        
        for (int i = 0; i < levelSize; i++) {
            int nodeIndex;
            dequeue(&q, &nodeIndex);
            TreeNode* current = nodeArray[nodeIndex];
            
            // Print the last node of each level
            if (i == levelSize - 1)
                printf("%d ", current->val);
            
            if (current->left != NULL) {
                int leftIndex = addNodeToArray(current->left);
                enqueue(&q, leftIndex);
            }
            if (current->right != NULL) {
                int rightIndex = addNodeToArray(current->right);
                enqueue(&q, rightIndex);
            }
        }
    }
    printf("\n");
}

// Count nodes at each level using Queue Library
void countNodesPerLevel(TreeNode* root) {
    if (root == NULL) return;
    
    printf("Nodes per level: ");
    
    Queue q;
    initQueue(&q);
    
    nodeCount = 0;
    int rootIndex = addNodeToArray(root);
    enqueue(&q, rootIndex);
    
    while (!isEmpty(&q)) {
        int levelSize = queueSize(&q);
        printf("%d ", levelSize);
        
        for (int i = 0; i < levelSize; i++) {
            int nodeIndex;
            dequeue(&q, &nodeIndex);
            TreeNode* current = nodeArray[nodeIndex];
            
            if (current->left != NULL) {
                int leftIndex = addNodeToArray(current->left);
                enqueue(&q, leftIndex);
            }
            if (current->right != NULL) {
                int rightIndex = addNodeToArray(current->right);
                enqueue(&q, rightIndex);
            }
        }
    }
    printf("\n");
}

// Free tree memory
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("========================================================\n");
    printf("  PROBLEM 1: Binary Tree Level Order Traversal\n");
    printf("  Difficulty: Medium\n");
    printf("  Using: Queue Library Functions\n");
    printf("========================================================\n\n");
    
    // Create example tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    
    printf("Tree Structure:\n");
    printf("       3\n");
    printf("      / \\\n");
    printf("     9  20\n");
    printf("       /  \\\n");
    printf("      15   7\n\n");
    
    // Perform level order traversal
    levelOrderTraversal(root);
    
    // Calculate max depth
    printf("\nMaximum Depth: %d\n", maxDepth(root));
    
    // Get right side view
    printf("\n");
    rightSideView(root);
    
    // Count nodes per level
    printf("\n");
    countNodesPerLevel(root);
    
    // Test with another tree
    printf("\n\n--- Test Case 2 ---\n");
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);
    root2->right->right = createNode(6);
    root2->left->left->left = createNode(7);
    
    printf("Tree Structure:\n");
    printf("         1\n");
    printf("       /   \\\n");
    printf("      2     3\n");
    printf("     / \\     \\\n");
    printf("    4   5     6\n");
    printf("   /\n");
    printf("  7\n\n");
    
    levelOrderTraversal(root2);
    printf("\nMaximum Depth: %d\n", maxDepth(root2));
    rightSideView(root2);
    countNodesPerLevel(root2);
    
    // Clean up
    freeTree(root);
    freeTree(root2);
    
    printf("\n✓ Problem solved using Queue Library!\n");
    printf("  Queue Functions Used:\n");
    printf("  - initQueue()    : Initialize queue\n");
    printf("  - enqueue()      : Add node to queue\n");
    printf("  - dequeue()      : Remove node from queue\n");
    printf("  - isEmpty()      : Check if queue is empty\n");
    printf("  - queueSize()    : Get current queue size\n");
    printf("\n  Time Complexity: O(n) where n is number of nodes\n");
    printf("  Space Complexity: O(w) where w is maximum width of tree\n");
    
    return 0;
}
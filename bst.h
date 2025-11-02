#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct {
    BSTNode* root;
} BST;

void initBST(BST *bst);
bool insertBST(BST *bst, int value);
bool searchBST(BST *bst, int value);
bool deleteBST(BST *bst, int value);
void inorderTraversal(BST *bst);
void preorderTraversal(BST *bst);
void postorderTraversal(BST *bst);
int findMin(BST *bst);
int findMax(BST *bst);
void freeBST(BST *bst);

#endif
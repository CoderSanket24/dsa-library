#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static BSTNode* createNode(int value) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (!newNode) return NULL;
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

static BSTNode* insertNode(BSTNode* root, int value) {
    if (root == NULL) return createNode(value);
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

static BSTNode* searchNode(BSTNode* root, int value) {
    if (root == NULL || root->data == value) return root;
    
    if (value < root->data) return searchNode(root->left, value);
    return searchNode(root->right, value);
}

static BSTNode* findMinNode(BSTNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

static BSTNode* deleteNode(BSTNode* root, int value) {
    if (root == NULL) return root;
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        
        BSTNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

static void inorder(BSTNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

static void preorder(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

static void postorder(BSTNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

static void freeNodes(BSTNode* root) {
    if (root != NULL) {
        freeNodes(root->left);
        freeNodes(root->right);
        free(root);
    }
}

void initBST(BST *bst) {
    bst->root = NULL;
}

bool insertBST(BST *bst, int value) {
    bst->root = insertNode(bst->root, value);
    return true;
}

bool searchBST(BST *bst, int value) {
    return searchNode(bst->root, value) != NULL;
}

bool deleteBST(BST *bst, int value) {
    if (!searchBST(bst, value)) return false;
    bst->root = deleteNode(bst->root, value);
    return true;
}

void inorderTraversal(BST *bst) {
    printf("Inorder: ");
    inorder(bst->root);
    printf("\n");
}

void preorderTraversal(BST *bst) {
    printf("Preorder: ");
    preorder(bst->root);
    printf("\n");
}

void postorderTraversal(BST *bst) {
    printf("Postorder: ");
    postorder(bst->root);
    printf("\n");
}

int findMin(BST *bst) {
    BSTNode* minNode = findMinNode(bst->root);
    return minNode ? minNode->data : -1;
}

int findMax(BST *bst) {
    BSTNode* current = bst->root;
    if (!current) return -1;
    
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

void freeBST(BST *bst) {
    freeNodes(bst->root);
    bst->root = NULL;
}
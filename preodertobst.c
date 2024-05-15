#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into BST
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(data);

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    // return the (unchanged) node pointer
    return root;
}

// Function to construct BST from preorder traversal
struct TreeNode* constructBST(int preorder[], int size) {
    struct TreeNode* root = NULL;
    int i;
    for (i = 0; i < size; i++)
        root = insertNode(root, preorder[i]);
    return root;
}

// Function to perform inorder traversal of BST (for testing)
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Test the implementation
int main() {
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    // Construct the BST
    struct TreeNode* root = constructBST(preorder, size);

    // Print the inorder traversal of the constructed BST
    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);

    return 0;
}

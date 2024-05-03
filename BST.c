#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* left;
    struct node* right;
    int data;
};

struct node* createnode(int data) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->right = root->left = NULL;
    root->data = data;
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct node* root) {
    static struct node* prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}

struct node* search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == root->data) {
        return root;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

struct node* searchITR(struct node* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return root;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return NULL;
}

void insert(struct node* root, int key) {
    struct node* prev = NULL;
    struct node* newNode = createnode(key);
    
    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    
    if (prev == NULL) {
        root = newNode;
    }
    else if (key < prev->data) {
        prev->left = newNode;
    }
    else {
        prev->right = newNode;
    }
}

struct node* inOrderPredecessor(struct node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* deletenode(struct node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->data) {
        root->left = deletenode(root->left, value);
    } else if (value > root->data) {
        root->right = deletenode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletenode(root->left, iPre->data);
    }
    return root;
}

int main() {
    struct node* p = createnode(5);
    struct node* p2 = createnode(3);
    struct node* p3 = createnode(6);
    struct node* p4 = createnode(1);
    struct node* p5 = createnode(4);

    p->right = p3;
    p->left = p2;
    p2->right = p5;
    p2->left = p4;

    printf("Inorder traversal of BST:\n");
    inorder(p);

    if (isBST(p) == 1) {
        printf("\nThe tree is BST\n");
    } else {
        printf("\nThe tree is not BST\n");
    }

    struct node* n = search(p, 7);
    if (n != NULL) {
        printf("Found %d\n", n->data);
    } else {
        printf("Element not found\n");
    }

    struct node* r = searchITR(p, 4);
    if (r != NULL) {
        printf("Found %d\n", r->data);
    } else {
        printf("Element not found\n");
    }

    insert(p, 7);
    printf("%d ", p->right->right->data);

    printf("\n");
    printf("Inorder traversal after insertion:\n");
    inorder(p);

    printf("\n");
    deletenode(p, 4);
    printf("Inorder traversal after deletion:\n");
    inorder(p);

    return 0;
}


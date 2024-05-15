#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct btrees{
    int data;
    struct btrees* left;
    struct btrees* right;
};
int count=0;

struct btrees* create(int data){
count++;
    struct btrees* new=malloc(sizeof(struct btrees));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;

}

void preorder(struct btrees* head){
  
    if(head!=NULL){
        printf(" %d ",head->data);
        preorder(head->left);
        preorder(head->right);
    }
    }

void inorder(struct btrees* head,int *max,int*min,int *key){
   
    if(head!=NULL){
        inorder(head->left,max,min,key);
        if(head->data>*max){
            *max=head->data;
        }
        if(head->data<*min){
            *min=head->data;
        }
        if(head->data==*key){
            printf("elemenent found");
        }
        else{
            printf("elememt not found");
        }
        printf(" %d ",head->data);
        inorder(head->right,max,min,key);

    }
}
void postorder(struct btrees* head){
    
    if(head!=NULL){
        postorder(head->left);
        postorder(head->right);
        printf(" %d ",head->data);

    }
}

int sizeofbinary(struct btrees* root){
    if(root==NULL) return 0;
    else return(sizeofbinary(root->left)+1+sizeofbinary(root->right));
}

void deletebinarytree(struct btrees* root){
    if(root == NULL) 
        return;
    
    deletebinarytree(root->left);
    deletebinarytree(root->right);
    free(root);
}


struct btrees* insert(struct btrees* root, int key){
    if(root == NULL){
        return create(key);
    }
    
    struct btrees *prev = NULL;
    struct btrees *temp = root;
    
    while(temp != NULL){
        prev = temp;
        if(key == temp->data){
            return root; // Assuming duplicate keys are not allowed
        }
        else if(key < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    
    struct btrees* new = create(key);
    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
    
    return root;
}

struct btrees* inorderPredecessor(struct btrees* root) {
    struct btrees* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

struct btrees* deletenode(struct btrees* root, int value) {
    if (root == NULL)
        return NULL;
    
    if (value < root->data)
        root->left = deletenode(root->left, value);
    else if (value > root->data)
        root->right = deletenode(root->right, value);
    else {
        if (root->left == NULL) {
            struct btrees* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct btrees* temp = root->left;
            free(root);
            return temp;
        }
        
        struct btrees* temp = inorderPredecessor(root->left);
        root->data = temp->data;
        root->left = deletenode(root->left, temp->data);
    }
    return root;
}

struct btrees* constructBinaryTree(int* preorder, int preStart, int preEnd, int* postorder, int postStart, int postEnd) {
    if (preStart > preEnd || postStart > postEnd)
        return NULL;

    struct btrees* root = newNode(preorder[preStart]);

    if (preStart == preEnd)
        return root;

    int leftSubtreeRootVal = preorder[preStart + 1];
    int leftSubtreeSize = 0;
    for (int i = postStart; i <= postEnd; ++i) {
        if (postorder[i] == leftSubtreeRootVal) {
            leftSubtreeSize = i - postStart + 1;
            break;
        }
    }

    root->left = constructBinaryTree(preorder, preStart + 1, preStart + leftSubtreeSize, postorder, postStart, postStart + leftSubtreeSize - 1);
    root->right = constructBinaryTree(preorder, preStart + leftSubtreeSize + 1, preEnd, postorder, postStart + leftSubtreeSize, postEnd - 1);

    return root;
}

// Function to find the depth of a given node in the binary tree
int findDepth(struct btrees* root, int key, int depth) {
    if (root == NULL)
        return 0;

    if (root->val == key)
        return depth;

    int leftDepth = findDepth(root->left, key, depth + 1);
    int rightDepth = findDepth(root->right, key, depth + 1);

    return (leftDepth != 0) ? leftDepth : rightDepth;
}




int main(){
    // struct btrees* root=NULL;
    // root=create(22);
    // struct btrees* l1=create(18);
    // struct btrees* l2=create(26);
    // struct btrees* r1=create(16);
    // struct btrees* r2=create(15);
    // struct btrees* r3=create(24);
    // struct btrees* r4=create(28);

    // root->left=l1;
    // root->right=l2;
    // l1->left=r1;
    // l1->right=r2;
    // l2->right=r4;
    // l2->left=r3;

//     printf(".......postorder traversal......\n");
// postorder(root);

//  printf("........preorder traversal......\n");
// preorder(root);

//  printf(".........inorder traversal......\n");

// int min=INT_MIN;
// int max=INT_MAX;
int key=33;
// inorder(root,&min,&max,&key);


 
//  insert(root,key);
//  postorder(root);

//  deletenode(root,key);
//  postorder(root);

 int preorder[] = {1, 2, 4, 5, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct btrees* root = constructBinaryTree(preorder, 0, n - 1, postorder, 0, n - 1);

    int key = 5;
    int depth = findDepth(root, key, 1);
    if (depth != 0)
        printf("Depth of node with value %d is %d\n", key, depth);
    else
        printf("Node with value %d not found\n", key);

    return 0;



//  postorder(root);



    
    
}
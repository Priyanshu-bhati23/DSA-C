#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};


struct node* createnode(int data){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->right=NULL;
    p->left=NULL;
};

int max(int a, int b){
    return (a > b) ? a : b;
}

int countLeafNodes(struct node* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
     int a=countLeafNodes(root->left) + countLeafNodes(root->right);
return a;
}


int countNonLeafNodes(struct node* root) {
    if (root == NULL)
        return 0;
    
    // If the current node is not a leaf node, count it
    if (root->left != NULL || root->right != NULL)
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    else
        return 0; // If it's a leaf node, return 0
}




void preorder(struct node*root){
    if(root!=NULL){
printf(" %d ",root->data);
preorder(root->left);
preorder(root->right);
    }
}

void inorder(struct node*root){
    if(root!=NULL){

inorder(root->left);
printf(" %d ",root->data);
inorder(root->right);
    }
}

void postorder(struct node*root){
    if(root!=NULL){

postorder(root->left);
postorder(root->right);
printf(" %d ",root->data);
    }
}

int height(struct node* root){
    if(root == NULL)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}

int countNodesWithOnlyRightChild(struct node* root) {
    if (root == NULL)
        return 0;

    int count = 0;

    // Check if the current node has only right child
    if (root->left == NULL && root->right != NULL)
        count++;

    // Recursively check left and right subtrees
    count += countNodesWithOnlyRightChild(root->left);
    count += countNodesWithOnlyRightChild(root->right);

    return count;
}



//          4(p)
//      /       \
//     2(p2)       7(p3)
//    /     \       /       \
//    1(p4) 3(p5) 5(p6)  6(p7()
int main()
{
struct node* p=createnode(4);
struct node* p2=createnode(2);
struct node* p3=createnode(7);
struct node* p4=createnode(1);
struct node* p5=createnode(3);
struct node* p6=createnode(5);
struct node* p7=createnode(6);
struct node* p8=createnode(8);

p->left=p2;
p->right=p3;
p2->left=p4;
p2->right=p5;
p3->left=p6;
p3->right=p7;
 p7->right=p8;

preorder(p);
printf("\n");
inorder(p);
printf("\n");
postorder(p);

 printf("Number of leaf nodes: %d\n", countLeafNodes(p));
    printf("Height of the tree: %d\n", height(p));
    int count = countNodesWithOnlyRightChild(p);
    printf("Number of nodes having only the right child: %d\n", count);
    printf("Number of nonleaf nodes: %d\n", countNonLeafNodes(p));
}


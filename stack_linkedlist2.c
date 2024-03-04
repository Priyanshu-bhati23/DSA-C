#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *add;
};

struct node *top = NULL;

void push(int x) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->add = top;
    top = newnode;
}

void pop() {
    struct node *temp;
    temp = top;
    if (top == NULL) {
        printf("The stack is empty\n");
    }
    else {
        printf("Popped element: %d\n", temp->data);
        top = top->add;
        free(temp);
    }
}

void display() {
    struct node *temp;
    temp = top;
    if (top == NULL) {
        printf("The stack is empty\n");
    }
    else {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->add;
        }
        printf("\n");
    }
}

void peak() {
    if (top == NULL) {
        printf("The stack is empty\n");
    }
    else {
        printf("The element at the top is %d\n", top->data);
    }
}

int main() {
    int choice, data;
    
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peak\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peak();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

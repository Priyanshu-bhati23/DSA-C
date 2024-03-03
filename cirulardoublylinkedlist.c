#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *ladd;
    int data;
    struct node *radd;
};

struct node *start = NULL;

void create() {
    int n;
    char ch;
    struct node *temp, *new1;
    
    printf("Enter an element: ");
    scanf("%d", &n);
    start = (struct node*)malloc(sizeof(struct node));
    start->ladd = start->radd = NULL;
    start->data = n;
    temp = start;

    printf("Want to continue? (Y/N): ");
    scanf(" %c", &ch);
    
    while(ch == 'Y' || ch == 'y') {
        printf("Enter the data to be inserted in the next node: ");
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->ladd = new1->radd = NULL;
        scanf("%d", &n);
        new1->data = n;
        temp->radd = new1;
        new1->ladd = temp;
        temp = temp->radd;
        temp->radd = start;
        start->ladd = temp;
        
        printf("Want to continue? (Y/N): ");
        scanf(" %c", &ch);
    }
}

void display() {
    struct node *temp;
    if(start == NULL) {
        printf("The list is empty\n");
    } else {
        temp = start;
        do {
            printf("%5d", temp->data);
            temp = temp->radd;
        } while(temp != start);
        printf("\n");
    }
}

void reverse_display() {
    struct node *temp;
    if(start == NULL) {
        printf("The list is empty\n");
    } else {
        temp = start->ladd;
        do {
            printf("%5d", temp->data);
            temp = temp->ladd;
        } while(temp != start->ladd);
        printf("\n");
    }
}

void insert_first() {
    int n;
    struct node *new1;
    if(start == NULL) {
        printf("The list is empty\n");
    } else {
        printf("Enter an element: ");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->ladd = new1->radd = NULL;
        new1->data = n;
        new1->radd = start;
        start->ladd->radd = new1;
        new1->ladd = start->ladd;
        start->ladd = new1;
        start = new1;
    }
}

void insert_last() {
    int n;
    struct node *new1;
    if(start == NULL) {
        printf("The list is empty\n");
    } else {
        printf("Enter an element: ");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->ladd = new1->radd = NULL;
        new1->data = n;
        new1->ladd = start->ladd;
        start->ladd->radd = new1;
        new1->radd = start;
        start->ladd = new1;
    }
}

void delete_first() {
    struct node *temp;
    if(start == NULL) {
        printf("The list is empty\n");
    } else {
        temp = start;
        start = start->radd;
        start->ladd = temp->ladd;
        temp->ladd->radd = start;
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

void delete_last() {
    struct node *temp;
    if(start == NULL) {
        printf("The list is empty\n");
    } else {
        temp = start->ladd;
        temp->ladd->radd = start;
        start->ladd = temp->ladd;
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

int main() {
    int choice;
    do {
        // Display menu options
        printf("..........DOUBLE LINKED LIST...........\n");
        printf("1. Create\n");
        printf("2. Insert First\n");
        printf("3. Insert Last\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Display\n");
        printf("7. Reverse Display\n");
        printf("8. Exit\n");
        printf(".......................................\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Perform actions based on user's choice
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                insert_first();
                break;
            case 3:
                insert_last();
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                display();
                break;
            case 7:
                reverse_display();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 8.\n");
                break;
        }

    } while(choice != 8); // Loop until the user chooses to exit
    return 0;
}

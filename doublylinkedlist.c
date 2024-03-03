
#include<stdio.h>
#include<stdlib.h> // Include stdlib.h for malloc function
#include<conio.h>

// Define the structure of the doubly linked list node
struct node {
    struct node* ladd; // Pointer to the previous node
    int data; // Data stored in the node
    struct node* radd; // Pointer to the next node
};

// Global pointers to track the start, temporary node, new node, next node, and previous node
struct node* start = NULL, *temp, *new1, *next, *prev;

// Function to create a doubly linked list
void create() {
    int n;
    char ch;
    printf("Enter the data to be inserted: ");
    scanf("%d", &n);
    // Allocate memory for the first node
    start = (struct node*)malloc(sizeof(struct node));
    start->ladd = start->radd = NULL; // Initialize both pointers to NULL
    start->data = n;
    temp = start; // Set temp to point to the start node
    printf("Do you want to continue? (Y/N): ");
    ch = getche(); // Get a character from the user
    // Loop to continue adding nodes
    while(ch == 'Y' || ch == 'y') {
        // Allocate memory for a new node
        new1 = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &n);
        temp->radd = new1; // Connect the current node to the new node
        new1->ladd = temp; // Connect the new node to the current node
        new1->radd = NULL; // Set the next pointer of the new node to NULL
        new1->data = n; // Assign data to the new node
        printf("Do you want to continue? (Y/N): ");
        ch = getche(); // Get a character from the user
        temp = new1; // Move temp to the new node
    }
}

// Function to insert a node at the beginning of the list
void insert_first() {
    int n;
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        printf("Enter the element to be stored: ");
        scanf("%d", &n);
        // Allocate memory for the new node
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->ladd = new1->radd = NULL; // Initialize pointers of the new node to NULL
        new1->data = n; // Assign data to the new node
        new1->radd = start; // Connect the new node to the start of the list
        start->ladd = new1; // Connect the previous start node to the new node
        start = new1; // Update the start pointer to point to the new node
    }
}

// Function to insert a node at the end of the list
void insert_last() {
    int n;
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        printf("Enter the data to be inserted: ");
        scanf("%d", &n);
        temp = start; // Set temp to start
        while(temp->radd != NULL) { // Traverse to the last node
            temp = temp->radd;
        }
        // Allocate memory for the new node
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n; // Assign data to the new node
        new1->ladd = temp; // Connect the new node to the last node
        new1->radd = NULL; // Set the next pointer of the new node to NULL
        temp->radd = new1; // Connect the last node to the new node
    }
}

// Function to insert a node at a specified position in the list
void insert_middle() {
    int n, pos, i = 1;
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        printf("Enter the data: ");
        scanf("%d", &n);
        printf("Enter the position: ");
        scanf("%d", &pos);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->radd = new1->ladd = NULL;
        next = start;
        // Traverse to the specified position
        while(i < pos) {
            prev = next;
            next = next->radd;
            i++;
        }
        new1->data = n; // Assign data to the new node
        new1->ladd = prev; // Connect the new node to the previous node
        prev->radd = new1; // Connect the previous node to the new node
        new1->radd = next; // Connect the new node to the next node
        next->ladd = new1; // Connect the next node to the new node
    }
}

// Function to delete the first node in the list
void delete_first() {
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        temp = start; // Store the start node in temp
        start = start->radd; // Move start to the next node
        printf("The deleted data is %d\n", temp->data); // Print the deleted data
        free(temp); // Free the memory of the deleted node
    }
}

// Function to delete the last node in the list
void delete_last() {
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        temp = start;
        while(temp->radd != NULL) {
            prev = temp;
            temp = temp->radd;
        }
        printf("Deleted node is %d\n", temp->data);
        prev->radd = NULL;
        free(temp);
    }
}

// Function to delete a node at a specified position in the list
void delete_middle() {
    int pos, i = 1;
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        printf("Enter the position: ");
        scanf("%d", &pos);
        next = start;
        while(i < pos) {
            prev = next;
            next = next->radd;
            i++;
        }
        temp = next;
        next = next->radd;
        prev->radd = next;
        next->ladd = prev;
        printf("The deleted data is %d\n", temp->data);
        free(temp);
    }
}

// Function to display the doubly linked list
void display() {
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        temp = start;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->radd;
        }
        printf("\n");
    }
}

// Function to display the doubly linked list in reverse
void reverse() {
    if(start == NULL) {
        printf("The list is empty\n");
    }
    else {
        temp = start;
        // Traverse to the last node
        while(temp->radd != NULL) {
            temp = temp->radd;
        }
        // Traverse backwards from the last node and print data
        while(temp != NULL) {
            printf("%d \n", temp->data);
            temp = temp->ladd;
        }
    }
}






void main() {
    int choice;
    do {
        // Display menu options
        printf("..........DOUBLE LINKED LIST...........\n");
        printf("1. Create\n");
        printf("2. Insert First\n");
        printf("3. Insert Middle\n");
        printf("4. Insert Last\n");
        printf("5. Delete First\n");
        printf("6. Delete Middle\n");
        printf("7. Delete Last\n");
        printf("8. Display\n");
        printf("9. Reverse Display\n");
        printf("10. Exit\n");
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
                insert_middle();
                break;
            case 4:
                insert_last();
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_middle();
                break;
            case 7:
                delete_last();
                break;
            case 8:
                display();
                break;
            case 9:
                reverse();
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 10.\n");
                break;
        }

    } while(choice != 10); // Loop until the user chooses to exit
}

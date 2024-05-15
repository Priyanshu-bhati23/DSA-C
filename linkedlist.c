#include<stdio.h>
#include<stdlib.h>

struct linkedlist {
    int data;
    struct linkedlist* next;
};

struct linkedlist* create(int data) {
    struct linkedlist* new_node = malloc(sizeof(struct linkedlist));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print(struct linkedlist* head) {
    if(head == NULL) {
        printf("The list is empty\n");
    } else {
        struct linkedlist* temp = head;
        while(temp != NULL) {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct linkedlist* insert_first(struct linkedlist* head, int data) {
    struct linkedlist* first = malloc(sizeof(struct linkedlist));
    first->data = data;
    first->next = head;
    head = first;
    return head;
}

struct linkedlist* insert_last(struct linkedlist* head, int data) {
    struct linkedlist* last = malloc(sizeof(struct linkedlist));
    last->data = data;
    last->next = NULL;
    if (head == NULL) {
        head = last;
        return head;
    }
    struct linkedlist* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = last;
    return head;
}

struct linkedlist* insert_middle(struct linkedlist* head, int pos, int data) {
    if(head == NULL) {
        printf("List does not exist\n");
        return head;
    }
    struct linkedlist* middle = malloc(sizeof(struct linkedlist));
    middle->data = data;
    struct linkedlist* temp = head;
    struct linkedlist* q = NULL;
    int k = 1;
    while (temp != NULL && k < pos) {
        q = temp;
        temp = temp->next;
        k++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(middle);
        return head;
    }
    q->next = middle;
    middle->next = temp;
    return head;
}

//reversw

struct linkedlist* reversal(struct linkedlist* head){
    struct linkedlist* temp=NULL,*nextnode=NULL;
    while(head){
        nextnode=head->next;
        head->next=temp;
        temp=head;
        head=nextnode;
    }
    return temp;
}

int main() {
    struct linkedlist* head = malloc(sizeof(struct linkedlist));
    head->data = 3;
    head->next = NULL;

    struct linkedlist* new1 = create(2);
    struct linkedlist* new2 = create(4);
    struct linkedlist* new3 = create(5);
    struct linkedlist* new4 = create(6);

    head->next = new1;
    head->next->next = new2;
    head->next->next->next = new3;
    head->next->next->next->next = new4;

    head = insert_first(head, 23);
    head = insert_first(head, 24);
    print(head);

    head = insert_last(head, 23);
    head = insert_last(head, 24);
    print(head);

    head = insert_middle(head, 3, 20);
    print(head);

struct linkedlist*temp=reversal(head);
    print(temp);

    return 0;
}

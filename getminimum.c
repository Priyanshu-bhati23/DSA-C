#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100;

struct stackarr{
int *arr;
int top;
int capacity;
};

struct stackarr* createarray(){
    struct stackarr*s=malloc(sizeof(struct stackarr ));
    s->capacity=MAX_SIZE;
    s->arr=(int*)malloc(s->capacity*sizeof(int));
    s->top==-1;
    return s;
}

void push(struct stackarr*s,int data){
    if(s->top==-1){
        printf("stack is full");
    }
    else{
        s->top++;
        s->arr[s->top]=data;
            }
}

int  pop(struct stackarr*s){
    if(s->top==s->capacity-1){
        printf("stack underflow");
    }
    else{
        int popped=s->arr[s->top];
        return popped;
    }
}

int getMinimum(struct stackarr*s){
    if(s->top==-1){
        printf("stack is empty\n");
        return -1;
    }
    else{
        int min=s->arr[0];
        for(int i=1;i<s->top;i++){
            if(s->arr[i]<min){
                min=s->arr[i];
            }
        }
        return min;
    }
}

int main(){
    struct stackarr* stack = createarray();

    push(stack, 3);
    push(stack, 5);
    push(stack, 2);
    push(stack, 1);

    printf("Minimum element: %d\n", getMinimum(stack)); // Output: 1

    pop(stack);
    pop(stack);

    printf("Minimum element after popping: %d\n", getMinimum(stack)); // Output: 2

    free(stack->arr);
    free(stack);

    return 0;
}
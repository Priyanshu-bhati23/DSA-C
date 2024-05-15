#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

struct stackarray{
    int top;
    char *arr;
    int capacity;
};

struct stackarray* create(){
    struct stackarray* s = malloc(sizeof(struct stackarray));
    s->capacity = MAX_SIZE;
    s->top = -1;
    s->arr = malloc(s->capacity * sizeof(char));
    return s;
}

void push(struct stackarray* s, char ch){
    s->top++;
    s->arr[s->top] = ch;
}

char pop(struct stackarray* s){
    char ch = s->arr[s->top];
    s->top--;
    return ch;
}

bool isMatchingPair(char character1, char character2){
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}

bool isBalanced(char str[]){
    struct stackarray* stack = create();
    int i = 0;
    while (str[i]){
        if (str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(stack, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if (stack->top == -1 || !isMatchingPair(pop(stack), str[i])){
                return false;
            }
        }
        i++;
    }
    return (stack->top == -1); // Stack should be empty for balanced parentheses
}//RETURN 1

int main() {
    char str[100];
    printf("Enter a string with parentheses: ");
    scanf("%s", str);
    if (isBalanced(str)){
        printf("The parentheses are balanced.\n");
    }
    else{
        printf("The parentheses are not balanced.\n");
    }
    return 0;
}

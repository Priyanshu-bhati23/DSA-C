#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to get the top item of the stack without removing it
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return -1;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, k;

    for (i = 0, k = -1; infix[i]; ++i) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) &&
                   precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    // Pop the remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[++k] = pop(stack);
    }

    postfix[++k] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[100];
    char postfix[100];

    // Input infix expression
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove newline character

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

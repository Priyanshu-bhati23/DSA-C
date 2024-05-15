#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top;
    char items[100];
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to check if the parentheses in the expression are balanced
int isBalanced(char* expression) {
    struct Stack* stack = createStack();
    int i;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            if (isEmpty(stack)) {
                return 0; // Unbalanced expression
            }
            pop(stack);
        }
    }

    return isEmpty(stack) ? 1 : 0; // Return 1 if stack is empty, 0 otherwise
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = '\0'; // Remove newline character

    if (isBalanced(expression)) {
        printf("Parentheses are balanced\n");
    } else {
        printf("Parentheses are not balanced\n");
    }

    return 0;
}

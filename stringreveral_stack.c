#include<stdio.h>
#include<string.h>

#define SIZE 1000

int top = -1, count = 0;
char stack[SIZE];
char output[SIZE];

void push(char temp) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = temp;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        output[count++] = stack[top--];
    }
}

int main() {
    char str[SIZE];
    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    // Remove newline character from fgets
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    // Push characters onto the stack
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    // Pop characters from the stack and store in output
    for (int i = 0; i < strlen(str); i++) {
        pop();
    }

    // Print reversed string
    printf("Reversed string: %s\n", output);

    return 0;
}

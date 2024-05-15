#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX],postfix[MAX];
int top=-1;

int precednce(char symbol)
{
    switch(symbol)
    {
        case '^':
        return 3;
        case '/':
        case '*':
        return 2;
        case '+':
        case '-':
        return 1;
        default:
        return 0;

    }
}


void inToPost(){
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++){
           symbol=infix[i];
           switch(symbol){
            case '(':
            push(symbol);
            break;
            case')':
            while(next=pop()!='(')
            postfix[j++]=next;
            break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while(!isEmpty()&&precedence(stack[top])>=precedence(symbol))
                  postfix[j++]=pop();
                  push(symbol); break;
            default:
            postfix[j++]=symbol;
           }

    }
}


int main(){
    printf("enter the infix expression");
    gets(infix); 

    inToPost();
}
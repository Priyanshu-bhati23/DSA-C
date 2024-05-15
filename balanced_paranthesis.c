#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
char e[20],stack[20];
int i,top=-1;


void push(char e){
top++;
stack[top]=e;
}

void pop(){
    top--;
}

int main(){
    printf("Enter the expression\n");
    scanf("%s",&e);
    for(i=0;e[i]='\0';i++){
        if(e[i]=='('){
            push(e[i]);
        }
        else if(e[i]==')'){
pop();
        }
        
    }
    if(top==-1){
        printf("paarthesis are blanced");

    }
    else{
        printf("not balanced");
    }
}

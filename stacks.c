//  Direct	applications
//  • Balancing	of	symbols
//  • Infix-to-postfix	conversion
//  • Evaluation	of	postfix	expression
//  • Implementing	function	calls	(including	recursion)
//  • Finding	of	spans	(finding	spans	in	stock	markets,	refer	to	Problems	section)
//  • Page-visited	history	in	a	Web	browser	[Back	Buttons]
//  • Undo	sequence	in	a	text	editor
//  • Matching	Tags	in	HTML	and	XM


//array implemenattaion
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100;

struct arraystack{
    int top;
    int capacity;
    int *arr;

};
struct arraystack* createstack(){
    struct arraystack *s=malloc(sizeof(struct arraystack));
    if(!s) return NULL;

    s->capacity=MAX_SIZE;
    s->top=-1;
    s->arr=malloc(s->capacity * sizeof(int));
    if(!s->arr) return NULL;
    return s;
   
}

int isEmptyStack(struct arraystack* s){
    if(s->top==-1) return 1;
    else return 0;
}

int isFullStack(struct arraystack *s){
if(s->top=s->capacity-1) return 1;
else return 0;
}

void push(struct arraystack*s,int data)
{
if(s->top==s->capacity-1){
    printf("satck is full \n");
}
else{
    s->top++;
    s->arr[s->top]=data;
}
}

int pop(struct arraystack*s){
    if(s->top==-1){
        printf("stack already empty");
    }
    else{
        
        return (" %d ",s->arr[s->top--]);
    }
}

int main(){
    struct arraystack* stack = createstack();

    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,6);
    push(stack,7);
    push(stack,8);

    printf("popped element is %d ",pop(stack));
}
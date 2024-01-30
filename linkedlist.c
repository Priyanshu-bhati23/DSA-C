#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *add;
};struct node *start=NULL,*temp,*new1,*next,*prev,*arr[50];
 


void create(){
    int n;
    char ch;
    printf("ENTER THE first elemet TO BE STORED:");
    scanf("%d",&n);
    start=(struct node*)(malloc(sizeof(struct node)));
    start->add=NULL;
    start->data=n;
    temp=start;
    printf("\n do you want to continue:" );
    ch=getche();
while(ch=='y'||ch=='Y')
{
printf("\n ENTER THE next elemet TO BE STORED:");
scanf("%d",&n);
new1=(struct node*)(malloc(sizeof(struct node)));
new1->data=n;
new1->add=NULL;
temp->add=new1;
temp=temp->add;

printf("\n  do you want to continue");
ch=getche();

}
    
}

void display()
{
temp=start;
if(start==NULL){
    printf("THE LIST IS EMPTY");
}

else{
while(temp!=NULL){
    printf("%d  ",temp->data);
    temp=temp->add;
}
}

}

void insert_first()

{
   

    if(start==NULL){
        printf("\n LIST NOT FOUND");
    }

else{
     int n;
    printf("enter the number to be stored in start");
scanf("%d",&n);
new1=(struct node*)(malloc(sizeof(struct node)));
new1->add=start;
new1->data=n;
start=new1;
}

}

void insert_last()

{
    int n;
if(start==NULL){
    printf(" \n THE LIST IS EMPTY");
}
else{
   
    printf("\n enter the number to be inserted");
     scanf("%d",&n);
    new1=(struct node *)(malloc(sizeof(struct node)));
    new1->data=n;
    new1->add=NULL;
    temp=start;
    while(temp->add!=NULL){
        temp=temp->add;
    }
    temp->add=new1;
   }
   
}

 void insert_middle()
{
int n,pos,i=1;
if(start==NULL)
printf("\n LIST NOT FOUND");
else
{
    printf("enter element to insert");
    scanf("%d",&n);
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    printf("\n enter the position where the node should be inserted");
    scanf("%d",&pos);
next=start;
while(i<pos)
{
prev=next;
next=next->add;
i++;
}
prev->add=new1;
new1->add=next;
}
}


void delete_first(){

    if(start==NULL){
        printf("THE LSIT IS NOT PREENET");
    }
    else{
temp=start;
start=start->add;
printf("the elemet removed is %d",temp->data);
free(temp);

    }
}



void delete_middle(){
    int pos,i=1;
    if(start==NULL){
        printf("THE LSIT IS NOT PREENET");
    }
    else{

        printf("enter the position");
        scanf("%d",&pos);
        temp=start;
        while(i<pos){
        prev=temp;
        temp=temp->add;
        i++;
        }
        next=temp->add;
        prev->add=next;
        printf("the deleteed elememt is %d",temp->data);
        free(temp);

}
}



void delete_last(){
 if(start==NULL){
        printf("THE LSIT IS NOT PREENET");
    }
    else
    {
temp=start;
while(temp->add!=NULL){

prev=temp;
    temp=temp->add;
}
prev->add=NULL;
printf("the elemet removed is %d",temp->data);
free(temp);
    }

}


void search()
{
    int key,f=0;
    printf("enter the key");
    scanf("%d",&key);
    if(start==NULL){
        printf("THE LSIT IS NOT PREENET");
    }
    else
    {
        temp=start;
        while(temp!=NULL){
           if(temp->data==key)
           {
            f=1;
            break;
           }
           temp=temp->add;

         
        }
          if(f==1){
            printf("searching success");
           }
           else{
            printf("seraching not success");
           }
         
}
}

void count()
{
    int count=0;
 if(start==NULL){
        printf("THE LSIT IS NOT PREENET");
    }
    else
    {
temp=start;
while(temp!=NULL)
{
count++;
temp=temp->add;
}
printf("the count is %d",count);
    }
}

void sort()
{
    int temp1;

if(start==NULL){
        printf("THE LSIT IS NOT PREENET");
    }
    else
    {
    prev=start;
    while(prev!=NULL){
next=prev->add;
while(next!=NULL){

    if(next->data < prev->data)
    {
        temp1=prev->data;
        prev->data=next->data;
        next->data=temp1;
    }
    next=next->add;
}
prev=prev->add;
    }
    }

}

void reverse_travserse()
{
int i;
if(start==NULL){
    printf("THE LIST IS NOT PRESENT");
}
else{
    i=0;
    next=start;
    while(next!=NULL)
    {
        arr[i]=next;
        next=next->add;
        i++;

    }
    i--;
    while(i>0)
    {
        printf("%d",arr[i]->data);
        i--;
    }
}
}









int main()
{

int choice;
do{
printf("\n--------LINKEDLIST---------");
printf("\n1.CREATE");
printf("\n2.DISPLAY");
printf("\n3.INSERT FIRST");
printf("\n4.INSERT MIDDLE");
printf("\n5.INSERT LAST");
printf("\n6.DELETE FIRST");
printf("\n7.DELETE MIDDLE");
printf("\n8.DELETE LAST");
printf("\n9.SEARCH");
printf("\n10.COUNT");
printf("\n11.SORT");
printf("\n11.REVERSE TRAVERSE");

printf("\n11.EXIT");


printf("\n ENTER YOUR CHOICE");
scanf("%d",&choice);
switch(choice)
{
    case 1: create();
    break;
    case 2: display();
    break;
    case 3: insert_first();
    break;
    case 4: insert_middle();
    break;
     case 5: insert_last();
     break;
    case 6: delete_first();
    break;
    case 7: delete_middle();
    break;
    case 8: delete_last();
    break;
    case 9: search();
    break;
     case 10: count();
    break;
    case 11: sort();
    break;
     case 12: reverse_travserse();
    break;
    
    default:printf("invalid case");
}
} while(choice!=13);


return 0;
}
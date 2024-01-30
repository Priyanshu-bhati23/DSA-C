#include<stdio.h>

int  linear_search(int *arr,int size,int key){

for(int i=0;i<size;i++){
if(arr[i]==key){
    return i;
    break;
}


}
}

int main(){
    int arr[] = {23,45,67,89,12};
    int key;
    printf("enter the key");
    scanf("%d",&key);
    int index=linear_search(arr,5,key);
     printf("the index is %d",index);
}
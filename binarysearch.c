#include<stdio.h>
int  binarysearch(int *arr,int e,int s, int key){
printf("entering the function;");
int mid=s+(e-s)/2;
while (s<=e)
{
    if(arr[mid]==key){
        return mid;

    }
    if(mid<key){
        s=mid+1;
    }
    if(mid>key){
        e=mid-1;
    }
}





}



int main(){
int key;
printf("enter the key");
scanf("%d",&key);
int arr[5]={1,2,3,4,5};
int index=binarysearch(arr,4,0,key);
printf("%d",index);

}
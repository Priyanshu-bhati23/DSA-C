#include<stdio.h>
int  binarysearch(int arr[],int s, int e ,int key){
    while(s<e){
    int mid=(s+e)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        e=mid-1;
        }
        else{
            s=mid+1;
        }

}
}

int main(){
    int arr[]={2,3,1,2,2,0,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=n-1;
int key=5;
int index=binarysearch(arr,s,e,key);
if(index){
    printf("element found at index %d",index);
}
    else{
        printf("element not found \n");
    }
}


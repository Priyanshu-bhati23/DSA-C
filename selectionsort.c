#include<stdio.h>

void selectionsort(int arr[],int n)
{
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[i]){
          int temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
    }
}
}



int main(){
    printf("..................Selection Sort................\n");
    int arr[]={56,21,43,68,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("..............array before sorting..........\n");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    

    printf("..............array after sorting..........\n");
    selectionsort(arr,n);
    for(int j=0;j<n;j++){
        printf(" %d ",arr[j]);
    }
}
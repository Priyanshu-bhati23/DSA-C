#include<stdio.h>
void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>0){
            if(arr[j]>arr[j+1]){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1]=temp;
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
    insertionsort(arr,n);
    for(int j=0;j<n;j++){
        printf(" %d ",arr[j]);
    }
}
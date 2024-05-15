#include<stdio.h>
void bubblesort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){//comparison between n-1 and n-i-1
               if(arr[j]>arr[j+1]){//comparison bewtween j and j+1
                int temp=arr[j+1];
                arr[j+1]=arr[j];
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
    bubblesort(arr,n);
    for(int j=0;j<n;j++){
        printf(" %d ",arr[j]);
    }

}
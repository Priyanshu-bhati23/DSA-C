#include<stdio.h>

int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int i=s+1;
    for(int j=s+1;j<=e;j++){
        if(arr[j]<=pivot){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    
    int temp=arr[s];
    arr[s]=arr[i-1];
    arr[i-1]=temp;
    return i-1;

}





void quicksort(int arr[],int n,int s,int e)
{
if(s<e){
    int p=partition(arr,s,e);
    quicksort(arr,n,s,p-1);
    quicksort(arr,n,p+1,e);

}
}





int main(){
    printf("..................Selection Sort................\n");
    int arr[]={56,21,43,68,99};
    int s=0;
    
    int n=sizeof(arr)/sizeof(arr[0]);
    int e=n-1;
    printf("..............array before sorting..........\n");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    

    printf("..............array after sorting..........\n");
    quicksort(arr,n,s,e);
    for(int j=0;j<n;j++){
        printf(" %d ",arr[j]);
    }
}
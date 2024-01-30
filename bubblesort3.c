#include<stdio.h>

void bubblesort(int arr[],int n)
{
int temp;
for(int i=0;i<n-1;i++){

    for(int j=0;j<n-i-1;j++){

        if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}


}

int main(){

    int arr[]={22,44,55,66,77};
    int n=5;

    printf("\n unsorted array is");

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    bubblesort(arr,n);


    printf("\n sorted array is");

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
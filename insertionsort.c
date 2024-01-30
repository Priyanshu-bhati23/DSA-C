#include <stdio.h>

void insertionSort(int arr[], int n) {

    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0){

            if(arr[j]>temp){
            arr[j+1]=arr[j];
            }  // Shift the 

            else{
            break;
            }

            j--;
        }
        arr[j+1] =temp;
    }
    
   


    }
     


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Call the insertionSort function
    insertionSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

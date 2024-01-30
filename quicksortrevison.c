#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int s, int e) {
    int pivot = arr[s]; 
    int i = s + 1;

    for (int j = s + 1; j <= e; j++) {
        if (arr[j] <= pivot) {
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    
    int temp = arr[s];
    arr[s] = arr[i - 1];
    arr[i - 1] = temp;

    return i - 1; 
}








void quicksort(int arr[], int n, int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e);

        quicksort(arr, n, s, p - 1);
        quicksort(arr, n, p + 1, e);
    }
}

int main() {
    printf("Enter the size\n");
    int n;
    scanf("%d", &n);
    int s = 0, e = n - 1;
    int arr[n];

    printf("\nArray before sorting");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    printf("\nArray after sorting");
    quicksort(arr, n, s, e);

    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    return 0;
}




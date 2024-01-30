#include <stdio.h>

int partition(int arr[], int s, int e) {
    int pivot = arr[s]; // Choose the pivot as the first element
    int i = s + 1;

    for (int j = s + 1; j <= e; j++) {
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp
            i++;
        }
    }

    // Swap arr[s] and arr[i-1] to place the pivot in its correct position
    int temp = arr[s];
    arr[s] = arr[i - 1];
    arr[i - 1] = temp;

    return i - 1; // Return the index of the pivot
}

void quicksort(int arr[], int n, int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e);

        quicksort(arr, n, s, p - 1);
        quicksort(arr, n, p + 1, e);
    }
}

int main() {
    int arr[6] = {22, 66, 21, 20, 9, 7};
    int s = 0, e = 5;

    printf("Original array:\n");
    for (int i = 0; i < 6; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 6, s, e);

    printf("Sorted array:\n");
    for (int i = 0; i < 6; i++) {
        printf(" %d ", arr[i]);
    }

    return 0;
}
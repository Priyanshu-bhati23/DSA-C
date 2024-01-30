#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int n, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = (int *)malloc(len1 * sizeof(int));
    int *second = (int *)malloc(len2 * sizeof(int));

    int mainarrayindex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainarrayindex++];
    }

    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainarrayindex++];
    }

    // merge
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainarrayindex++] = first[index1++];
        } else {
            arr[mainarrayindex++] = second[index2++];
        }
    }

    // Copy remaining elements from the first array
    while (index1 < len1) {
        arr[mainarrayindex++] = first[index1++];
    }

    // Copy remaining elements from the second array
    while (index2 < len2) {
        arr[mainarrayindex++] = second[index2++];
    }

    // Deallocate memory
    free(first);
    free(second);
}

void mergesort(int arr[], int n, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s + e) / 2;

    mergesort(arr, n, s, mid);
    mergesort(arr, n, mid + 1, e);

    merge(arr, n, s, e);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    mergesort(arr, n, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}











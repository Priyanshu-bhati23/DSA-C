#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int k) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    if (i + 1 == k) {
        return arr[i + 1];
    } else if (i + 1 < k) {
        return partition(arr, i + 2, high, k);
    } else {
        return partition(arr, low, i, k);
    }
}



int kthSmallest(int arr[], int n, int k) {
    return partition(arr, 0, n - 1, k);
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Kth smallest element is %d\n", kthSmallest(arr, n, k));
    return 0;
}

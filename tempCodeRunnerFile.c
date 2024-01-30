#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int n, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = (int *)malloc(len1 * sizeof(int));
    int *arr2 = (int *)malloc(len2 * sizeof(int));

    int mainarrayindex = s;
    for (int i = 0; i < len1; i++) {
        arr1[i] = arr[mainarrayindex++];
    }
    for (int i = 0; i < len2; i++) {
        arr2[i] = arr[mainarrayindex++];
    }

    // Merge
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;

    while (index1 < len1 && index2 < len2) {
        if (arr1[index1] < arr2[index2]) {
            arr[mainarrayindex++] = arr1[index1++];
        } else {
            arr[mainarrayindex++] = arr2[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainarrayindex++] = arr1[index1++];
    }

    while (index2 < len2) {
        arr[mainarrayindex++] = arr2[index2++];
    }

    free(arr1);
    free(arr2);
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
    mergesort(arr, n, s, e);

    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    return 0;
}

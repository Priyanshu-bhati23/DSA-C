#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int s, int mid, int e) {
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = (int*)malloc(len1 * sizeof(int));
    int *second = (int*)malloc(len2 * sizeof(int));

    for(int i = 0; i < len1; i++)
        first[i] = arr[s + i];
    
    for(int i = 0; i < len2; i++)
        second[i] = arr[mid + 1 + i];

    int index1 = 0;
    int index2 = 0;
    int mainarrayindex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= second[index2]) {
            arr[mainarrayindex++] = first[index1++];
        } else {
            arr[mainarrayindex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainarrayindex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainarrayindex++] = second[index2++];
    }

    free(first);
    free(second);
}

void mergesort(int arr[], int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

int main() {
    printf("..................Merge Sort................\n");
    int arr[] = {56, 21, 43, 68, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("..............Array before sorting..........\n");
    for(int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    
    mergesort(arr, 0, n - 1);

    printf("\n..............Array after sorting..........\n");
    for(int j = 0; j < n; j++) {
        printf(" %d ", arr[j]);
    }

    return 0;
}

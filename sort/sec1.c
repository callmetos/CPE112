#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int ls = m - l + 1;
    int rs = r - m;

    int la[ls], ra[rs];

    for (int i = 0; i < ls; i++)
        la[i] = arr[l + i];
    for (int i = 0; i < rs; i++)
        ra[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < ls && j < rs) {
        arr[k] = (la[i] <= ra[j]) ? la[i++] : ra[j++];
        k++;
    }

    while (i < ls) arr[k++] = la[i++];
    while (j < rs) arr[k++] = ra[j++];
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pi = par(arr, l, h);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int par(int arr[], int l, int h) {
    int pi = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] <= pi) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;


    mergeSort(arr, 0, n - 1);
    printf("Merge sorted array: ");
    printArray(arr, n);

    // Reset array
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Quicksort
    quickSort(arr2, 0, n - 1);
    printf("Quick sorted array: ");
    printArray(arr2, n);

    return 0;
}

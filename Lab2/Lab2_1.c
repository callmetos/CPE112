//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <stdlib.h>

void printArrayElements(int n, int *arr, int mode) {
    int i , count = 0;

    if (mode == 0) {
        for (i = 0; i < n; i += 2) {
            printf("%d ", *(arr + i));
            count ++ ;
        }
    } else if (mode == 1) {
        for (i = 1; i < n; i += 2) {
            printf("%d ", *(arr + i));
            count ++ ;
        }
    }
    if (count == 0) {
        printf("none");
    }
    printf("\n");
}

int main() {
    int n, mode, i;

    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    scanf("%d", &mode);
    printArrayElements(n, arr, mode);

    free(arr);

    return 0;
}

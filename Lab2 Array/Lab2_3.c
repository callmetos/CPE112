//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <stdlib.h>

int main() {

    long long *arr1 = (long long *)malloc(1000000 * sizeof(long long));

    if (arr1 == NULL) {
        printf("Memory allocation failed for arr1.\n");
        return 1;
    }

    long long *arr2 = (long long *)calloc(1000000, sizeof(long long));

    if (arr2 == NULL) {
        printf("Memory allocation failed for arr2.\n");
        free(arr1);
        return 1;
    }

    long long sum = 0, diff = 0;
    for (int i = 1; i <= 1000000; i++) {
        arr1[i - 1] = i;
        arr2[i - 1] = -i;
        sum += i;
        diff -= i;
    }

    printf("%lld \n", sum);
    printf("%lld \n", diff);

    free(arr1);
    free(arr2);

    return 0;
}


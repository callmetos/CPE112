#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int set[n];
    int setSize = 0;

    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            set[setSize++] = a[i];
        }
    }

    printf("%d\n", setSize);
    for (int i = 0; i < setSize; ++i) {
        printf("%d ", set[i]);
    }
    printf("\n");

    return 0;
}


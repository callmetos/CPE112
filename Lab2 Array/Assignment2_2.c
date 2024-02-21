//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <limits.h>
int minJumps(int arr[], int n) {
    int jumps[n];
    jumps[0] = 0;

    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX ;
        for (int j = 0; j < i; j++) {
            if (j + arr[j] >= i) {
                if (jumps[j] != INT_MAX && jumps[j] + 1 < jumps[i]) {
                    jumps[i] = jumps[j] + 1;
                }
            }
        }
    }

    return (jumps[n - 1] != INT_MAX) ? jumps[n - 1] : -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minJumps(arr, n);

    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("Not Possible\n");
    }

    return 0;
}


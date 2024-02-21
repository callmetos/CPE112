//Channathat Ueanapaphon 66070503413
#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int m, int n, int B[MAX_SIZE][MAX_SIZE], int k, int l) {
    if (n != k) {
        printf("Not Compatible\n");
        return;
    }

    int C[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            C[i][j] = 0;
            for (int x = 0; x < n; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, k, l;
    scanf("%d %d", &m, &n);

    int A[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    scanf("%d %d", &k, &l);

    int B[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiplyMatrices(A, m, n, B, k, l);

    return 0;
}

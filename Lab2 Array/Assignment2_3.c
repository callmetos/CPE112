//Channathat Ueanapaphon 66070503413
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    //symmetric
    int is_symmetric = 1;
    for (int i = 0; i < n && is_symmetric; ++i) {
        for (int j = 0; j < m && is_symmetric; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                is_symmetric = 0;
            }
        }
    }

    //skew-symmetric
    int is_skew_symmetric = 1;
    for (int i = 0; i < n && is_skew_symmetric; ++i) {
        for (int j = 0; j < m && is_skew_symmetric; ++j) {
            if (i != j && matrix[i][j] != -matrix[j][i]) {
                is_skew_symmetric = 0;
            }
        }
    }

    if (is_symmetric) {
        printf("The matrix is symmetric\n");
    } else if (is_skew_symmetric) {
        printf("The matrix is skew-symmetric\n");
    } else {
        printf("None\n");
    }

    return 0;
}

//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("ERROR\n");
        return 0;
    }

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    int primarySum = 0;
    for (int i = 0; i < rows; i++) {
        primarySum += matrix[i][i];
    }


    int secondarySum = 0;
    for (int i = 0; i < rows; i++) {
        secondarySum += matrix[i][rows - 1 - i];
    }


    printf("Primary: %d\nSecondary: %d\n", primarySum, secondarySum);


    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}



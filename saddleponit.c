#include <stdio.h>
#include <stdlib.h>

int findSaddlePoint(int **matrix, int rows, int cols) {
    int i, j, min_row, col_index, min_val;

    for (i = 0; i < rows; i++) {
        min_row = matrix[i][0];
        col_index = 0;
        for (j = 0; j < cols; j++) {
            if (min_row > matrix[i][j]) {
                min_row = matrix[i][j];
                col_index = j;
            }
        }

        min_val = min_row;
        for (j = 0; j < cols; j++) {
            if (min_val < matrix[j][col_index]) {
                break;
            }
        }

        if (min_val == min_row) {
            return min_row;
        }
    }

    return -1;
}

int main() {
    int **matrix, rows, cols, i, j;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int saddle_point = findSaddlePoint(matrix, rows, cols);

    if (saddle_point == -1) {
        printf("No saddle point found\n");
    } else {
        printf("Saddle point is %d\n", saddle_point);
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
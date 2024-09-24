#include <stdio.h>

void inverseMatrix(int matrix[3][3]) {
    int det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
              - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2])
              + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

    if (det == 0) {
        printf("The matrix is singular, and its inverse does not exist.\n");
        return;
    }

    double inv[3][3];

    inv[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) / (double)det;
    inv[0][1] = -(matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]) / (double)det;
    inv[0][2] = (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]) / (double)det;

    inv[1][0] = -(matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) / (double)det;
    inv[1][1] = (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]) / (double)det;
    inv[1][2] = -(matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]) / (double)det;

    inv[2][0] = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) / (double)det;
    inv[2][1] = -(matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]) / (double)det;
    inv[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) / (double)det;

    // Print the inverse matrix
    printf("Inverse Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%.2f\t", inv[i][j]);
        printf("\n");
    }
}

int main() {
    int matrix[3][3];

    // Input the elements of the 3x3 matrix
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j]);

    // Calculate and print the inverse matrix
    inverseMatrix(matrix);

    return 0;
}
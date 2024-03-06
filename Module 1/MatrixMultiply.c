#include <stdio.h>

void multiplyMatrices(int (*matrix1), int (*matrix2), int (*result), int row, int col) {
    int i, j, k;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            *(result + i * col + j) = 0;
            for (k = 0; k < col; k++) {
                *(result + i * col + j) += *(matrix1 + i * col + k) * *(matrix2 + k * col + j);
            }
        }
    }
}


int main() {
	int row,col;
	printf("Enter the size of rows :");
	scanf("%d",&row);
	printf("Enter the size of columns :");
	scanf("%d",&col);
    int matrix1[row][col];
    int matrix2[row][col];
    int result[row][col];
    printf("Enter elements in first matrix of size %dx%d\n", row, col);
	int i = 0, j = 0;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", (*(matrix1 + i) + j));
        }
    }
    printf("Enter elements in second matrix of size %dx%d\n", row, col);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", (*(matrix2 + i) + j));
        }
    
    }

    multiplyMatrices(matrix1, matrix2, result, row, col);
    printf("Product of Matrices:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("\n%d", result[i][j]);
        }
    
    }



    return 0;
}


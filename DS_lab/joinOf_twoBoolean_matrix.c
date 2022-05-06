/**** algorithm ( Join of two boolean matrices ) ****/
#include <stdio.h>

int main(void)
{
    int rows, columns; // variables to store the number of rows and columns of matrix the user wants
    printf("Enter the rows for matrix: ");
    scanf("%d", &rows);
    printf("Enter the columns for matrix: ");
    scanf("%d", &columns);

    // make two arrays A and B with the provided rows and columns
    int A[rows][columns], B[rows][columns];

    // entering data for matrix A
    printf("\nEnter data for boolean matrix A:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // entering data for matrix B
    printf("\nEnter data for boolean matrix A:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // displaying data of matrix A
    printf("\nMatrix A:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    // displaying data of matrix B
    printf("Matrix B:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    // displaying the join of the matrices A and B
    printf("\nJoin of matrices A and B:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", A[i][j] || B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
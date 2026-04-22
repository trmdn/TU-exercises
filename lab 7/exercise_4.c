// Bonus Exercise

#include <stdio.h>
#include <stdbool.h>

#define N 3

int main(){
    int matrix[N][N];
    int i, j;

    printf("Enter elements of the matrix (%dx%dx):\n", N, N);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Main diagonal (i == j)

    printf("\nMain diagonal: ");
    for(i = 0; i < N; i++){
        printf("%d", matrix[i][i]);
    }

    // Secondary diagonal (i + j == N - 1)

    printf("\nSecondary diagonal: ");
    for(i = 0; i < N; i++){
        printf("%d", matrix[i][N - 1 - i]);
    }

    // Elements above the main diagonal (j > i)

    printf("\nElements of the main diagonal: ");
    for(i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            printf("%d", matrix[i][j]);
        }
    }

    // Elements below the main diagonal (i > j)

    printf("\nElements below the main diagonal: ");
    for(i = 1; i < N; i++){
        for(j = 0; j < i; j++){
            printf("%d ", matrix[i][j]);
        }
    }

    int target_sum = 0;
    bool is_magic = true;

    for(j = 0; j < N; j++) target_sum += matrix[0][j];

    for(i = 1; i < N; i++){
        int row_sum = 0;
        for(j = 0; j < N; j++) row_sum += matrix[i][j];
        if (row_sum != target_sum) is_magic = false;
    }

    for (j = 0; j < N; j++){
        int col_sum = 0;
        for (i = 0; i < N; i++) col_sum += matrix[i][j];
        if (col_sum != target_sum) is_magic = false;
    }

    int diag1 = 0, diag2 = 0;
    for(int i = 0; i < N; i++){
        diag1 += matrix[i][i];
        diag2 += matrix[i][N - 1 - i];
    }

    if (diag1 != target_sum || diag2 != target_sum) is_magic = false;

    if(is_magic){
        printf("\n\nResult: square is magical! (Sum: %d)\n", target_sum);
    } else{
        printf("\n\nResult: square is NOT magical.\n");
    }

    return 0;
}
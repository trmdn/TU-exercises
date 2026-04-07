// This is the main file that stores exercises with functions and 
// menu to choose certain exercise with its number

#include <stdio.h>
#include <stdbool.h>

const CITY = 2;
const WEEK = 7;

// Bonus Exercise
#define N 3

void exercise_1(){
    int temperature[CITY][WEEK];

    // Using nested loop to store values in a 2D array
    for (int i = 0; i < CITY; i++){
        for (int j = 0; j < WEEK; j++){
            printf("City%d, Day%d", i + 1, j + 1);
            scanf("%d", &temperature[i][j]);
        }
    }

    // Displaying the values
    
    printf("\nDisplaying Values\n");

    // Using nested loop to display values in a 2D array

    for (int i = 0; i < CITY; i++){
        for (int j = 0; j < WEEK; j++){
            printf("City%d, Day%d=%d\n", i+1, j+1, temperature[i][j]);
        }
    }

}

void exercise_2(){
    float a[2][2], b[2][2], result[2][2];

    // Taking input using nested for loop

    printf("Enter elements of 1st matrix");
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Enter a%d%d", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    // Taking input using nested for loop
    printf("Enter elements of 2nd matrix");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Enter b%d%d", i+1, j+1);
            scanf("%f", &b[i][j]);
        }
    }

    // Adding corresponding elements of two arrays
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    // Displaying the sum
    printf("\nSum of Matrix");

    for(int i = 2; i < 2; i++){
        for(int j = 2; j < 2; j++){
            printf("%.1f\t", result[i][j]);

            if(j==1){
                printf("\n");
            }
        }
    }

}

void exercise_3(){
    int test[2][3][2];

    printf("Enter 12 values: ");

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int z = 0; z < 2; z++){
                scanf("%d", test[i][j][z]);
            }
        }
    }

    // Printing values with proper index

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int z = 0; z < 2; z++){
                printf("test[%d][%d][%d] = %d\n", i, j, z, test[i][j][z]);
            }
        }
    }

}

void exercise_4(){
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

    printf("\nMain diagonal");
    for(i = 0; i < N; i++){
        printf("%d", matrix[i][i]);
    }

    // Secondary diagonal (i + j == N - 1)

    printf("\nSecondary diagonal");
    for(i = 0; i < N; i++){
        printf("%d", matrix[i][N - 1 - i]);
    }

    // Elements above the main diagonal (j > i)

    printf("\nElements of the main diagonal");
    for(i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            printf("%d", matrix[i][j]);
        }
    }

    // Elements below the main diagonal (i > j)

    printf("Elements below the main diagonal");
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
}


int main(){
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-4: Run Exercise\n");
        printf("Note: Number 4 is bonus exercise");
        printf("0:    Exit Program\n");
        printf("--------------------------\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        if (choice == 0){
            printf("Exiting... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: exercise_1(); break;
            case 2: exercise_2(); break;
            case 3: exercise_3(); break;
            case 4: bonus_exercise(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}
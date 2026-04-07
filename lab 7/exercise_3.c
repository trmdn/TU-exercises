// C program to store and enter 12 values entered by user

#include <stdio.h>

int main(){

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

    return 0;
}
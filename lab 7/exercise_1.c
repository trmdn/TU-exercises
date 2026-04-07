// C program to store temprerature of two cities of a week and display it.

#include <stdio.h>

const CITY = 2;
const WEEK = 7;

int main(){

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
    
    return 0;
}